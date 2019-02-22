#ifndef _ROS_command2ros_DigCommand_h
#define _ROS_command2ros_DigCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace command2ros
{

  class DigCommand : public ros::Msg
  {
    public:
      typedef int32_t _serialID_type;
      _serialID_type serialID;
      typedef int32_t _digDirection_type;
      _digDirection_type digDirection;
      typedef int32_t _stop_type;
      _stop_type stop;

    DigCommand():
      serialID(0),
      digDirection(0),
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
      } u_digDirection;
      u_digDirection.real = this->digDirection;
      *(outbuffer + offset + 0) = (u_digDirection.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_digDirection.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_digDirection.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_digDirection.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->digDirection);
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
      } u_digDirection;
      u_digDirection.base = 0;
      u_digDirection.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_digDirection.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_digDirection.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_digDirection.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->digDirection = u_digDirection.real;
      offset += sizeof(this->digDirection);
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

    const char * getType(){ return "command2ros/DigCommand"; };
    const char * getMD5(){ return "4862b33fb504b4f8782f9383dc79dd77"; };

  };

}
#endif