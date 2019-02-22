#ifndef _ROS_command2ros_MovementCommand_h
#define _ROS_command2ros_MovementCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace command2ros
{

  class MovementCommand : public ros::Msg
  {
    public:
      typedef int32_t _serialID_type;
      _serialID_type serialID;
      typedef int32_t _driveDirection_type;
      _driveDirection_type driveDirection;
      typedef int32_t _stop_type;
      _stop_type stop;
      typedef int32_t _packIn_type;
      _packIn_type packIn;
      typedef int32_t _packOut_type;
      _packOut_type packOut;
      typedef int32_t _pause_type;
      _pause_type pause;
      typedef const char* _msg_type;
      _msg_type msg;

    MovementCommand():
      serialID(0),
      driveDirection(0),
      stop(0),
      packIn(0),
      packOut(0),
      pause(0),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_serialID;
      u_serialID.real = this->serialID;
      *(outbuffer + offset + 0) = (u_serialID.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_serialID.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_serialID.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_serialID.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->serialID);
      union {
        int32_t real;
        uint32_t base;
      } u_driveDirection;
      u_driveDirection.real = this->driveDirection;
      *(outbuffer + offset + 0) = (u_driveDirection.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_driveDirection.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_driveDirection.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_driveDirection.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->driveDirection);
      union {
        int32_t real;
        uint32_t base;
      } u_stop;
      u_stop.real = this->stop;
      *(outbuffer + offset + 0) = (u_stop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stop.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop);
      union {
        int32_t real;
        uint32_t base;
      } u_packIn;
      u_packIn.real = this->packIn;
      *(outbuffer + offset + 0) = (u_packIn.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_packIn.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_packIn.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_packIn.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->packIn);
      union {
        int32_t real;
        uint32_t base;
      } u_packOut;
      u_packOut.real = this->packOut;
      *(outbuffer + offset + 0) = (u_packOut.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_packOut.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_packOut.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_packOut.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->packOut);
      union {
        int32_t real;
        uint32_t base;
      } u_pause;
      u_pause.real = this->pause;
      *(outbuffer + offset + 0) = (u_pause.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pause.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pause.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pause.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pause);
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_serialID;
      u_serialID.base = 0;
      u_serialID.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_serialID.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_serialID.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_serialID.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->serialID = u_serialID.real;
      offset += sizeof(this->serialID);
      union {
        int32_t real;
        uint32_t base;
      } u_driveDirection;
      u_driveDirection.base = 0;
      u_driveDirection.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_driveDirection.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_driveDirection.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_driveDirection.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->driveDirection = u_driveDirection.real;
      offset += sizeof(this->driveDirection);
      union {
        int32_t real;
        uint32_t base;
      } u_stop;
      u_stop.base = 0;
      u_stop.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stop.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stop.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stop.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stop = u_stop.real;
      offset += sizeof(this->stop);
      union {
        int32_t real;
        uint32_t base;
      } u_packIn;
      u_packIn.base = 0;
      u_packIn.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_packIn.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_packIn.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_packIn.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->packIn = u_packIn.real;
      offset += sizeof(this->packIn);
      union {
        int32_t real;
        uint32_t base;
      } u_packOut;
      u_packOut.base = 0;
      u_packOut.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_packOut.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_packOut.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_packOut.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->packOut = u_packOut.real;
      offset += sizeof(this->packOut);
      union {
        int32_t real;
        uint32_t base;
      } u_pause;
      u_pause.base = 0;
      u_pause.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pause.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pause.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pause.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pause = u_pause.real;
      offset += sizeof(this->pause);
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return "command2ros/MovementCommand"; };
    const char * getMD5(){ return "62f81c30816c871b5beea98372924f12"; };

  };

}
#endif