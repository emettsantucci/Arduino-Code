#ifndef _ROS_command2ros_DumpCommand_h
#define _ROS_command2ros_DumpCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace command2ros
{

  class DumpCommand : public ros::Msg
  {
    public:
      typedef int32_t _serialID_type;
      _serialID_type serialID;
      typedef int32_t _beltDirection_type;
      _beltDirection_type beltDirection;
      typedef int32_t _speed_type;
      _speed_type speed;
      typedef int32_t _stop_type;
      _stop_type stop;

    DumpCommand():
      serialID(0),
      beltDirection(0),
      speed(0),
      stop(0)
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
      } u_beltDirection;
      u_beltDirection.real = this->beltDirection;
      *(outbuffer + offset + 0) = (u_beltDirection.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_beltDirection.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_beltDirection.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_beltDirection.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->beltDirection);
      union {
        int32_t real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
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
      } u_beltDirection;
      u_beltDirection.base = 0;
      u_beltDirection.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_beltDirection.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_beltDirection.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_beltDirection.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->beltDirection = u_beltDirection.real;
      offset += sizeof(this->beltDirection);
      union {
        int32_t real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
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
     return offset;
    }

    const char * getType(){ return "command2ros/DumpCommand"; };
    const char * getMD5(){ return "e87491cc34c1854735f35cc4cf2c8a23"; };

  };

}
#endif