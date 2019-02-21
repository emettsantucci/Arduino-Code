#include <Sabertooth.h>
#include <SoftwareSerial.h>
#include <ros.h>

/**
 * This is the code to run on the Arduinos.
 * Assume that all the motors in arrays appear in the following order:
 * Left Front, Left Middle, Left Back,
 * Right Front, Right Middle, Right Back.
 * 
 * This code is designed to run on two separate Arduinos,
 * the right side and left side controlled independentally.
 * 
 * Sabertooth documentation and libraries can be found here: https://www.dimensionengineering.com/software/SabertoothArduinoLibrary/html/index.html
 * We are using packetized serial which means we specify the address of a Sabertooth address and then we can run the motors all from one pin.
 * 
 * Stepper Motors run using frequency modulation. Higher frequency = faster steps = faster turning.
 */

//Use for testing and calibrating. For normal operation, make these false.
//Open Serial Monitor to see details.
const bool TEST_MOTORS = false;
const bool CALIBRATE_ENCODER = false;
const int ENCODER_TO_CALIBRATE = 2;//0-2 from front to back.

const int ARDUINO_NUM = 0;//0 is left arduino, 1 is right.

//In order to output human readable, useful data goes on the Serial Monitor
//Control for the Sabertooths goes on pin 14.
SoftwareSerial SWSerial(NOT_A_PIN, 14);

/**
 * split into two arrays of length 3 because each Arduino gets one array.
 * The array that the Arduino gets in decided by ARDUINO_NUM. This pattern continues for all constants
 */
Sabertooth ST[2][3] = {{Sabertooth(128, SWSerial), Sabertooth(133, SWSerial), Sabertooth(129, SWSerial)},
                       {Sabertooth(130, SWSerial), Sabertooth(131, SWSerial), Sabertooth(132, SWSerial)}};
//6 motor controllers (LF, LM, LB, RF, RM, RB)

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
const int ENCODER_PINS[3] = {A0, A1, A0};

//the factor to adjust the drive motors' speeds by to try and keep them turning at the same speed.
const float SPEED_ADJUST[2][6] = {{1, 1, 1,  //Left Drive
                                   1, 1, 1}, //Left Art
                                  {1, 1, 1,  //Right Drive
                                   1, 1, 1}};//Right Art
//If the motors are wired backwards to how we expect,
//change the corresponding float to negative.

//Stepper motor controller pins.
const int STEPPER_PUL[2] = {11, 13};
const int STEPPER_DIR[2] = {10, 12};

//Bucket Chain Motor Controller
Sabertooth ChainMotor = Sabertooth(134, SWSerial);

const int DRIVE = 1;//drive motors are on M1 on Sabertooth
const int ARTICULATION = 2;//articulation motors are on M2
const int DRIVE_SPEED = 50;//50/127 default speed for drive motors
const int TURN_SPEED = 50;//50/127 default speed for articulation motors
const int DIG_SPEED = 50;//50/127 default speed for digger and dumper
const int STEPPER_SPEED = 10;//10/100 default speed for raising and lowering digger and dumper

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
  
  SWSerial.begin(9600);
  Serial.begin(9600);//Used for human-readable feedback. Open Serial Monitor to view.
  Serial.println("I am a robot... Bleep Bloop.");
  for(int i=0; i<3; i++){
    runWheelMotor(i, DRIVE, 0);
    runWheelMotor(i, ARTICULATION, 0);
  }
  runDigMotor(0, 0);
  runDigMotor(1, 0);
  delay(1000);
  if(TEST_MOTORS)
    testDrive(DRIVE_SPEED);
  if(CALIBRATE_ENCODER)
    calibrateEncoder(ENCODER_TO_CALIBRATE);
}

void loop() {
}

void calibrateEncoder(int controller){
  int encoderVal = analogRead(ENCODER_PINS[controller]);
  while(encoderVal != 359){
    runWheelMotor(controller, ARTICULATION, -10);
    String str = "Current Angle: ";
    Serial.println(str + encoderVal);
  }
}

void testDrive(int vel){
  String str = "Driving motor ";
  for(int i = 0; i < 3; i++){
    runWheelMotor(i, DRIVE, vel);
    Serial.println(str+i);
    delay(500);
    runWheelMotor(i, DRIVE, -vel);
    delay(500);
    runWheelMotor(i, DRIVE, 0);
  }
}

void testStepper(int vel){
  runStepperMotor(0, vel);
  runStepperMotor(1, vel);
  delay(5000);
  runStepperMotor(0, -vel);
  runStepperMotor(1, -vel);
  delay(5000);
}

void testDig(int vel){
  runDigMotor(0, vel);
  delay(1000);
  runDigMotor(0, -vel);
  delay(1000);
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
    runWheelMotor(i, DRIVE, driveSpeed);
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
    runWheelMotor(i, DRIVE, driveSpeed);
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
          runWheelMotor(i, ARTICULATION, TURN_SPEED);
          runWheelMotor(i, DRIVE, DRIVE_SPEED);//check the drive directions
        }
        else{
          runWheelMotor(i, ARTICULATION, -TURN_SPEED);
          runWheelMotor(i, DRIVE, -DRIVE_SPEED);
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
 * @param vel Speed of the motor (-127 - 127)
 */
void runWheelMotor(int controller, int motorNum, int vel){
  if(!enabled[ARDUINO_NUM][controller])
    return;
  if(motorNum == ARTICULATION)
    ST[ARDUINO_NUM][controller].motor(ARTICULATION, SPEED_ADJUST[ARDUINO_NUM][controller+3] * vel);
  else
    ST[ARDUINO_NUM][controller].motor(DRIVE, SPEED_ADJUST[ARDUINO_NUM][controller] * vel);
}

/**
 * method to run a stepper 
 */
void runStepperMotor(int stepper, int vel){
  int d = getStepperDelay(vel);
  if(d < 0)
    digitalWrite(STEPPER_DIR[stepper], LOW);
  else
    digitalWrite(STEPPER_DIR[stepper], HIGH);
  if(abs(d) < 5)
    return;
  digitalWrite(STEPPER_PUL[stepper], HIGH);
  delayMicroseconds(d);
  digitalWrite(STEPPER_PUL[stepper], LOW);
  delayMicroseconds(d);
}

/**
 * helper method to find the required delay for a proper frequency output
 */
int getStepperDelay(int vel){
  if(vel > 100)
    vel = 100;
  int delayMin = 5;//200kHz max
  int delayCur = delayMin * (100 - abs(vel));
  return delayCur;
}

void runDigMotor(int motorNum, int vel){
  ChainMotor.motor(motorNum, vel);
}
