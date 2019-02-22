#ifndef _ROS_command2ros_ImageProc_h
#define _ROS_command2ros_ImageProc_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace command2ros
{

  class ImageProc : public ros::Msg
  {
    public:
      typedef int32_t _serialID_type;
      _serialID_type serialID;
      typedef int32_t _xCoordMainBeaconCenter_type;
      _xCoordMainBeaconCenter_type xCoordMainBeaconCenter;
      typedef int32_t _yCoordMainBeaconCenter_type;
      _yCoordMainBeaconCenter_type yCoordMainBeaconCenter;
      typedef int32_t _xCoordMainBeaconLB_type;
      _xCoordMainBeaconLB_type xCoordMainBeaconLB;
      typedef int32_t _yCoordMainBeaconLB_type;
      _yCoordMainBeaconLB_type yCoordMainBeaconLB;
      typedef int32_t _xCoordMainBeaconUB_type;
      _xCoordMainBeaconUB_type xCoordMainBeaconUB;
      typedef int32_t _yCoordMainBeaconUB_type;
      _yCoordMainBeaconUB_type yCoordMainBeaconUB;
      typedef int32_t _xCoordSternBeaconCenter_type;
      _xCoordSternBeaconCenter_type xCoordSternBeaconCenter;
      typedef int32_t _yCoordSternBeaconCenter_type;
      _yCoordSternBeaconCenter_type yCoordSternBeaconCenter;
      typedef int32_t _xCoordSternBeaconLB_type;
      _xCoordSternBeaconLB_type xCoordSternBeaconLB;
      typedef int32_t _yCoordSternBeaconLB_type;
      _yCoordSternBeaconLB_type yCoordSternBeaconLB;
      typedef int32_t _xCoordSternBeaconUB_type;
      _xCoordSternBeaconUB_type xCoordSternBeaconUB;
      typedef int32_t _yCoordSternBeaconUB_type;
      _yCoordSternBeaconUB_type yCoordSternBeaconUB;
      typedef int32_t _xCoordBowBeaconCenter_type;
      _xCoordBowBeaconCenter_type xCoordBowBeaconCenter;
      typedef int32_t _yCoordBowBeaconCenter_type;
      _yCoordBowBeaconCenter_type yCoordBowBeaconCenter;
      typedef int32_t _xCoordBowBeaconLB_type;
      _xCoordBowBeaconLB_type xCoordBowBeaconLB;
      typedef int32_t _yCoordBowBeaconLB_type;
      _yCoordBowBeaconLB_type yCoordBowBeaconLB;
      typedef int32_t _xCoordBowBeaconUB_type;
      _xCoordBowBeaconUB_type xCoordBowBeaconUB;
      typedef int32_t _yCoordBowBeaconUB_type;
      _yCoordBowBeaconUB_type yCoordBowBeaconUB;
      typedef int32_t _xCoordFrontBeaconCenter_type;
      _xCoordFrontBeaconCenter_type xCoordFrontBeaconCenter;
      typedef int32_t _yCoordFrontBeaconCenter_type;
      _yCoordFrontBeaconCenter_type yCoordFrontBeaconCenter;
      typedef int32_t _xCoordFrontBeaconLB_type;
      _xCoordFrontBeaconLB_type xCoordFrontBeaconLB;
      typedef int32_t _yCoordFrontBeaconLB_type;
      _yCoordFrontBeaconLB_type yCoordFrontBeaconLB;
      typedef int32_t _xCoordFrontBeaconUB_type;
      _xCoordFrontBeaconUB_type xCoordFrontBeaconUB;
      typedef int32_t _yCoordFrontBeaconUB_type;
      _yCoordFrontBeaconUB_type yCoordFrontBeaconUB;

    ImageProc():
      serialID(0),
      xCoordMainBeaconCenter(0),
      yCoordMainBeaconCenter(0),
      xCoordMainBeaconLB(0),
      yCoordMainBeaconLB(0),
      xCoordMainBeaconUB(0),
      yCoordMainBeaconUB(0),
      xCoordSternBeaconCenter(0),
      yCoordSternBeaconCenter(0),
      xCoordSternBeaconLB(0),
      yCoordSternBeaconLB(0),
      xCoordSternBeaconUB(0),
      yCoordSternBeaconUB(0),
      xCoordBowBeaconCenter(0),
      yCoordBowBeaconCenter(0),
      xCoordBowBeaconLB(0),
      yCoordBowBeaconLB(0),
      xCoordBowBeaconUB(0),
      yCoordBowBeaconUB(0),
      xCoordFrontBeaconCenter(0),
      yCoordFrontBeaconCenter(0),
      xCoordFrontBeaconLB(0),
      yCoordFrontBeaconLB(0),
      xCoordFrontBeaconUB(0),
      yCoordFrontBeaconUB(0)
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
      } u_xCoordMainBeaconCenter;
      u_xCoordMainBeaconCenter.real = this->xCoordMainBeaconCenter;
      *(outbuffer + offset + 0) = (u_xCoordMainBeaconCenter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordMainBeaconCenter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordMainBeaconCenter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordMainBeaconCenter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordMainBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordMainBeaconCenter;
      u_yCoordMainBeaconCenter.real = this->yCoordMainBeaconCenter;
      *(outbuffer + offset + 0) = (u_yCoordMainBeaconCenter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordMainBeaconCenter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordMainBeaconCenter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordMainBeaconCenter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordMainBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordMainBeaconLB;
      u_xCoordMainBeaconLB.real = this->xCoordMainBeaconLB;
      *(outbuffer + offset + 0) = (u_xCoordMainBeaconLB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordMainBeaconLB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordMainBeaconLB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordMainBeaconLB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordMainBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordMainBeaconLB;
      u_yCoordMainBeaconLB.real = this->yCoordMainBeaconLB;
      *(outbuffer + offset + 0) = (u_yCoordMainBeaconLB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordMainBeaconLB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordMainBeaconLB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordMainBeaconLB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordMainBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordMainBeaconUB;
      u_xCoordMainBeaconUB.real = this->xCoordMainBeaconUB;
      *(outbuffer + offset + 0) = (u_xCoordMainBeaconUB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordMainBeaconUB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordMainBeaconUB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordMainBeaconUB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordMainBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordMainBeaconUB;
      u_yCoordMainBeaconUB.real = this->yCoordMainBeaconUB;
      *(outbuffer + offset + 0) = (u_yCoordMainBeaconUB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordMainBeaconUB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordMainBeaconUB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordMainBeaconUB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordMainBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordSternBeaconCenter;
      u_xCoordSternBeaconCenter.real = this->xCoordSternBeaconCenter;
      *(outbuffer + offset + 0) = (u_xCoordSternBeaconCenter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordSternBeaconCenter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordSternBeaconCenter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordSternBeaconCenter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordSternBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordSternBeaconCenter;
      u_yCoordSternBeaconCenter.real = this->yCoordSternBeaconCenter;
      *(outbuffer + offset + 0) = (u_yCoordSternBeaconCenter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordSternBeaconCenter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordSternBeaconCenter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordSternBeaconCenter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordSternBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordSternBeaconLB;
      u_xCoordSternBeaconLB.real = this->xCoordSternBeaconLB;
      *(outbuffer + offset + 0) = (u_xCoordSternBeaconLB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordSternBeaconLB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordSternBeaconLB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordSternBeaconLB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordSternBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordSternBeaconLB;
      u_yCoordSternBeaconLB.real = this->yCoordSternBeaconLB;
      *(outbuffer + offset + 0) = (u_yCoordSternBeaconLB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordSternBeaconLB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordSternBeaconLB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordSternBeaconLB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordSternBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordSternBeaconUB;
      u_xCoordSternBeaconUB.real = this->xCoordSternBeaconUB;
      *(outbuffer + offset + 0) = (u_xCoordSternBeaconUB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordSternBeaconUB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordSternBeaconUB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordSternBeaconUB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordSternBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordSternBeaconUB;
      u_yCoordSternBeaconUB.real = this->yCoordSternBeaconUB;
      *(outbuffer + offset + 0) = (u_yCoordSternBeaconUB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordSternBeaconUB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordSternBeaconUB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordSternBeaconUB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordSternBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordBowBeaconCenter;
      u_xCoordBowBeaconCenter.real = this->xCoordBowBeaconCenter;
      *(outbuffer + offset + 0) = (u_xCoordBowBeaconCenter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordBowBeaconCenter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordBowBeaconCenter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordBowBeaconCenter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordBowBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordBowBeaconCenter;
      u_yCoordBowBeaconCenter.real = this->yCoordBowBeaconCenter;
      *(outbuffer + offset + 0) = (u_yCoordBowBeaconCenter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordBowBeaconCenter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordBowBeaconCenter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordBowBeaconCenter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordBowBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordBowBeaconLB;
      u_xCoordBowBeaconLB.real = this->xCoordBowBeaconLB;
      *(outbuffer + offset + 0) = (u_xCoordBowBeaconLB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordBowBeaconLB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordBowBeaconLB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordBowBeaconLB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordBowBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordBowBeaconLB;
      u_yCoordBowBeaconLB.real = this->yCoordBowBeaconLB;
      *(outbuffer + offset + 0) = (u_yCoordBowBeaconLB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordBowBeaconLB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordBowBeaconLB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordBowBeaconLB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordBowBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordBowBeaconUB;
      u_xCoordBowBeaconUB.real = this->xCoordBowBeaconUB;
      *(outbuffer + offset + 0) = (u_xCoordBowBeaconUB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordBowBeaconUB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordBowBeaconUB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordBowBeaconUB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordBowBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordBowBeaconUB;
      u_yCoordBowBeaconUB.real = this->yCoordBowBeaconUB;
      *(outbuffer + offset + 0) = (u_yCoordBowBeaconUB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordBowBeaconUB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordBowBeaconUB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordBowBeaconUB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordBowBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordFrontBeaconCenter;
      u_xCoordFrontBeaconCenter.real = this->xCoordFrontBeaconCenter;
      *(outbuffer + offset + 0) = (u_xCoordFrontBeaconCenter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordFrontBeaconCenter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordFrontBeaconCenter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordFrontBeaconCenter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordFrontBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordFrontBeaconCenter;
      u_yCoordFrontBeaconCenter.real = this->yCoordFrontBeaconCenter;
      *(outbuffer + offset + 0) = (u_yCoordFrontBeaconCenter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordFrontBeaconCenter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordFrontBeaconCenter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordFrontBeaconCenter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordFrontBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordFrontBeaconLB;
      u_xCoordFrontBeaconLB.real = this->xCoordFrontBeaconLB;
      *(outbuffer + offset + 0) = (u_xCoordFrontBeaconLB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordFrontBeaconLB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordFrontBeaconLB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordFrontBeaconLB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordFrontBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordFrontBeaconLB;
      u_yCoordFrontBeaconLB.real = this->yCoordFrontBeaconLB;
      *(outbuffer + offset + 0) = (u_yCoordFrontBeaconLB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordFrontBeaconLB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordFrontBeaconLB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordFrontBeaconLB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordFrontBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordFrontBeaconUB;
      u_xCoordFrontBeaconUB.real = this->xCoordFrontBeaconUB;
      *(outbuffer + offset + 0) = (u_xCoordFrontBeaconUB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xCoordFrontBeaconUB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xCoordFrontBeaconUB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xCoordFrontBeaconUB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xCoordFrontBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordFrontBeaconUB;
      u_yCoordFrontBeaconUB.real = this->yCoordFrontBeaconUB;
      *(outbuffer + offset + 0) = (u_yCoordFrontBeaconUB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yCoordFrontBeaconUB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yCoordFrontBeaconUB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yCoordFrontBeaconUB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yCoordFrontBeaconUB);
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
      } u_xCoordMainBeaconCenter;
      u_xCoordMainBeaconCenter.base = 0;
      u_xCoordMainBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordMainBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordMainBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordMainBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordMainBeaconCenter = u_xCoordMainBeaconCenter.real;
      offset += sizeof(this->xCoordMainBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordMainBeaconCenter;
      u_yCoordMainBeaconCenter.base = 0;
      u_yCoordMainBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordMainBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordMainBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordMainBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordMainBeaconCenter = u_yCoordMainBeaconCenter.real;
      offset += sizeof(this->yCoordMainBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordMainBeaconLB;
      u_xCoordMainBeaconLB.base = 0;
      u_xCoordMainBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordMainBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordMainBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordMainBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordMainBeaconLB = u_xCoordMainBeaconLB.real;
      offset += sizeof(this->xCoordMainBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordMainBeaconLB;
      u_yCoordMainBeaconLB.base = 0;
      u_yCoordMainBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordMainBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordMainBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordMainBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordMainBeaconLB = u_yCoordMainBeaconLB.real;
      offset += sizeof(this->yCoordMainBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordMainBeaconUB;
      u_xCoordMainBeaconUB.base = 0;
      u_xCoordMainBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordMainBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordMainBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordMainBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordMainBeaconUB = u_xCoordMainBeaconUB.real;
      offset += sizeof(this->xCoordMainBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordMainBeaconUB;
      u_yCoordMainBeaconUB.base = 0;
      u_yCoordMainBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordMainBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordMainBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordMainBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordMainBeaconUB = u_yCoordMainBeaconUB.real;
      offset += sizeof(this->yCoordMainBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordSternBeaconCenter;
      u_xCoordSternBeaconCenter.base = 0;
      u_xCoordSternBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordSternBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordSternBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordSternBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordSternBeaconCenter = u_xCoordSternBeaconCenter.real;
      offset += sizeof(this->xCoordSternBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordSternBeaconCenter;
      u_yCoordSternBeaconCenter.base = 0;
      u_yCoordSternBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordSternBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordSternBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordSternBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordSternBeaconCenter = u_yCoordSternBeaconCenter.real;
      offset += sizeof(this->yCoordSternBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordSternBeaconLB;
      u_xCoordSternBeaconLB.base = 0;
      u_xCoordSternBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordSternBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordSternBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordSternBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordSternBeaconLB = u_xCoordSternBeaconLB.real;
      offset += sizeof(this->xCoordSternBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordSternBeaconLB;
      u_yCoordSternBeaconLB.base = 0;
      u_yCoordSternBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordSternBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordSternBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordSternBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordSternBeaconLB = u_yCoordSternBeaconLB.real;
      offset += sizeof(this->yCoordSternBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordSternBeaconUB;
      u_xCoordSternBeaconUB.base = 0;
      u_xCoordSternBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordSternBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordSternBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordSternBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordSternBeaconUB = u_xCoordSternBeaconUB.real;
      offset += sizeof(this->xCoordSternBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordSternBeaconUB;
      u_yCoordSternBeaconUB.base = 0;
      u_yCoordSternBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordSternBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordSternBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordSternBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordSternBeaconUB = u_yCoordSternBeaconUB.real;
      offset += sizeof(this->yCoordSternBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordBowBeaconCenter;
      u_xCoordBowBeaconCenter.base = 0;
      u_xCoordBowBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordBowBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordBowBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordBowBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordBowBeaconCenter = u_xCoordBowBeaconCenter.real;
      offset += sizeof(this->xCoordBowBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordBowBeaconCenter;
      u_yCoordBowBeaconCenter.base = 0;
      u_yCoordBowBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordBowBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordBowBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordBowBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordBowBeaconCenter = u_yCoordBowBeaconCenter.real;
      offset += sizeof(this->yCoordBowBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordBowBeaconLB;
      u_xCoordBowBeaconLB.base = 0;
      u_xCoordBowBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordBowBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordBowBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordBowBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordBowBeaconLB = u_xCoordBowBeaconLB.real;
      offset += sizeof(this->xCoordBowBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordBowBeaconLB;
      u_yCoordBowBeaconLB.base = 0;
      u_yCoordBowBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordBowBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordBowBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordBowBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordBowBeaconLB = u_yCoordBowBeaconLB.real;
      offset += sizeof(this->yCoordBowBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordBowBeaconUB;
      u_xCoordBowBeaconUB.base = 0;
      u_xCoordBowBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordBowBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordBowBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordBowBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordBowBeaconUB = u_xCoordBowBeaconUB.real;
      offset += sizeof(this->xCoordBowBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordBowBeaconUB;
      u_yCoordBowBeaconUB.base = 0;
      u_yCoordBowBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordBowBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordBowBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordBowBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordBowBeaconUB = u_yCoordBowBeaconUB.real;
      offset += sizeof(this->yCoordBowBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordFrontBeaconCenter;
      u_xCoordFrontBeaconCenter.base = 0;
      u_xCoordFrontBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordFrontBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordFrontBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordFrontBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordFrontBeaconCenter = u_xCoordFrontBeaconCenter.real;
      offset += sizeof(this->xCoordFrontBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordFrontBeaconCenter;
      u_yCoordFrontBeaconCenter.base = 0;
      u_yCoordFrontBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordFrontBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordFrontBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordFrontBeaconCenter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordFrontBeaconCenter = u_yCoordFrontBeaconCenter.real;
      offset += sizeof(this->yCoordFrontBeaconCenter);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordFrontBeaconLB;
      u_xCoordFrontBeaconLB.base = 0;
      u_xCoordFrontBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordFrontBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordFrontBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordFrontBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordFrontBeaconLB = u_xCoordFrontBeaconLB.real;
      offset += sizeof(this->xCoordFrontBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordFrontBeaconLB;
      u_yCoordFrontBeaconLB.base = 0;
      u_yCoordFrontBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordFrontBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordFrontBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordFrontBeaconLB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordFrontBeaconLB = u_yCoordFrontBeaconLB.real;
      offset += sizeof(this->yCoordFrontBeaconLB);
      union {
        int32_t real;
        uint32_t base;
      } u_xCoordFrontBeaconUB;
      u_xCoordFrontBeaconUB.base = 0;
      u_xCoordFrontBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xCoordFrontBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xCoordFrontBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xCoordFrontBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xCoordFrontBeaconUB = u_xCoordFrontBeaconUB.real;
      offset += sizeof(this->xCoordFrontBeaconUB);
      union {
        int32_t real;
        uint32_t base;
      } u_yCoordFrontBeaconUB;
      u_yCoordFrontBeaconUB.base = 0;
      u_yCoordFrontBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yCoordFrontBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yCoordFrontBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yCoordFrontBeaconUB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yCoordFrontBeaconUB = u_yCoordFrontBeaconUB.real;
      offset += sizeof(this->yCoordFrontBeaconUB);
     return offset;
    }

    const char * getType(){ return "command2ros/ImageProc"; };
    const char * getMD5(){ return "f2ea9ff816ec0817c4f491b59af280e4"; };

  };

}
#endif