#include <Sabertooth.h>
#include <ros.h>

/**
 * This is the code to run on the Arduinos.
 * Assume that all the motors in arrays appear in the following order:
 * Left Front, Left Middle, Left Back,
 * Right Front, Right Middle, Right Back.
 * 
 * This code is designed to run on two separate Arduinos,
 * the right side and left side controlled independentally.
 */

const bool TEST_MOTORS = true;

const int ARDUINO_NUM = 0;//0 is left arduino, 1 is right.

/**
 * split into two arrays of length 3 because each Arduino gets one array.
 * The array that the Arduino gets in decided by ARDUINO_NUM. This pattern continues for all constants
 */
Sabertooth ST[2][3] = {{Sabertooth(128), Sabertooth(131), Sabertooth(132)},
                       {Sabertooth(129), Sabertooth(130), Sabertooth(133)}};
//6 motor controllers (LF, LM, LB, RF, RM, RB)

const boolean POLARITY[2][6] = {{true, true, true,//Left Drive Motors
                                 true, true, true},//Left Art Motors
                                {true, true, true,//Right Drive
                                 true, true, true}};//Right Art
//If the motors are wired backwards to how we expect,
//change the corresponding boolean to false.

//Array of booleans to tell if a particular wheel is supposed to run or not
boolean enabled[2][3] = {{true, true, true},
                         {true, true, true}};

//the encoders send values between 0 and 1024. This will convert it to degrees
const double ENCODER_SCALE = 360/1024;

//Angles for wheels to be in when in different states
const int PACKED_ANGLES[3] = {0, 0, 0};
const int TURN_ANGLES[3] = {135, 180, 135};
const int DRIVE_ANGLES[3] = {180, 180, 180};
const int SIDE_DRIVE_ANGLES[3] = {90, 90, 90};

//Left wheels from front to back
//turn CCW, CW, CW
//Right side is opposite
const bool TURN_CW[3] = {false, true, true};

//True zero of the encoders.
//Zero is taken to be the packed in state.
const int TRUE_ZERO[2][3] = {{0, 0, 0},
                             {0, 0, 0}};

//The analog pins where the encoders are plugged into
const int ENCODER_PINS[3] = {A0, A1, A2};

//the factor to adjust the drive motors' speeds by to try and keep them turning at the same speed.
const int SPEED_ADJUST[2][3] = {{1, 1, 1},
                                {1, 1, 1}};

const int DRIVE = 1;//drive motors are on M1 on Sabertooth
const int ARTICULATION = 2;//articulation motors are on M2
const int DRIVE_SPEED = 50;//50/127 default speed for drive motors
const int TURN_SPEED = 50;//50/127 default speed for articulation motors

/*ROS setup*/
/*void commandCb(const messageClass::message& msg){
  //handle command
}*/
//ros::Subscriber RX("Receiver", &commandCb); 
//ros::Publisher TX("Transmitter", );

void setup() {
  /*nh.initNode();
  nh.subscribe(RX);
  ng.advertise(TX);*/
  
  SabertoothTXPinSerial.begin(9600);
  if(TEST_MOTORS)
    test(0, true);
}

void loop() {
  
}

void test(int currentSpeed, bool forward){
  if(currentSpeed > DRIVE_SPEED)
    forward = false;
  if(currentSpeed < 10)
    forward = true;
  if(forward)
    currentSpeed++;
  else
    currentSpeed--;
  for(int i = 0; i < 3; i++){
    for(int j = 1; j < 3; j++){
      runMotor(i, j, currentSpeed);
    }
  }
  delay(25);
  test(currentSpeed, forward);
}

/**
 * function to turn the robot in place
 * @param right whether we want to turn right or left
 */
void turnInPlace(bool right){
  alignWheels(TURN_ANGLES);
  int driveSpeed = DRIVE_SPEED;
  if(right && ARDUINO_NUM == 1 || !right && ARDUINO_NUM == 0)
    driveSpeed = -driveSpeed;
  for(int i = 0; i < 3; i++){
    runMotor(i, DRIVE, driveSpeed);
  }
}

/**
 * function to drive the robot forward
 * @param forward whether we want to go forward or backward
 */
void driveStraight(bool forward){
  alignWheels(DRIVE_ANGLES);
  int driveSpeed = DRIVE_SPEED;
  if(!forward)
    driveSpeed = -driveSpeed;
  for(int i = 0; i < 3; i++){
    driveSpeed *= SPEED_ADJUST[ARDUINO_NUM][i];
    runMotor(i, DRIVE, driveSpeed);
  }
}

/**
 * Align the wheels to the specified angles
 * @param angles the angles to align the wheels to
 */
void alignWheels(const int angles[3]){
  bool complete = false;
  bool aligned[3] = {false, false, false};
  for(int i = 0; i < 3; i++)//if a wheel is disabled, we do not want to try to align it
    if(!enabled[ARDUINO_NUM][i])
      aligned[i] = true;
  while(!complete){
    for(int i = 0; i < 3; i++){
      if(aligned[i])
        continue;
      if(abs((TRUE_ZERO[ARDUINO_NUM][i] + analogRead(ENCODER_PINS[i]) * ENCODER_SCALE) - angles[i]) < 3)//CHECK THIS
        aligned[i] = true;
      else{
      //CHECK THIS TOO (I think this actually works)
        bool cw = true;
        if((TRUE_ZERO[ARDUINO_NUM][i] + analogRead(ENCODER_PINS[i]) * ENCODER_SCALE) > angles[i])
          cw = !cw;
        if(!TURN_CW[i])
          cw = !cw;
        if(ARDUINO_NUM == 1)
          cw = !cw;
        if(cw){
          runMotor(i, ARTICULATION, TURN_SPEED);
          runMotor(i, DRIVE, DRIVE_SPEED);//check the drive directions
        }
        else{
          runMotor(i, ARTICULATION, -TURN_SPEED);
          runMotor(i, DRIVE, -DRIVE_SPEED);
        }
      }
    }
    if(aligned[0] && aligned[1] && aligned[2])
      complete = true;
  }
}

/**
 * runs a motor
 * @param controller The number of the controller to run (0-2)
 * @param motorNum DRIVE or ARTICULATION
 * @param vel Speed of the motor (-127-127)
 */
void runMotor(int controller, int motorNum, int vel){
  if(!enabled[ARDUINO_NUM][controller])
    return;
  int offset = 0;
  if(motorNum == ARTICULATION)
    offset = 3;
  if(POLARITY[ARDUINO_NUM][controller+offset])
    ST[ARDUINO_NUM][controller].motor(motorNum, vel);
  else
    ST[ARDUINO_NUM][controller].motor(motorNum, -vel);
}
