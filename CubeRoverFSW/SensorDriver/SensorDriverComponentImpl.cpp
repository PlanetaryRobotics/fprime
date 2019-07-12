// ======================================================================
// \title  SensorDriverImpl.cpp
// \author sisyphuslaetus
// \brief  cpp file for SensorDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
//
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ======================================================================


#include <CubeRoverFSW/SensorDriver/SensorDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

extern "C"{
  #include "accel_adxl312.h"
  #include "L3GD20H.h"
  #include "spi.h"
}

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SensorDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    SensorDriverComponentImpl(
        const char *const compName
    ) :
      SensorDriverComponentBase(compName)
#else
    SensorDriverImpl(void)
#endif
  {

  }

  }
  /*Setting up accelerometer settings for data acquisition*/
  const accel_data_rate_t accel_sample_rate = ACCEL_100HZ;
  const accel_low_power_mode_t accel_power_mode = ACCEL_STD_POWER;
  const accel_range_t accel_sample_range = ACCEL_RANGE_2G;

  /*Setting gyroscope settings for data acquisition*/
  const Gyro_Range_t gyro_range = L3DS20_RANGE_250DPS;

  //Ask Lou what the filt limit should be
  const float32 tilt_limit = 30;
  const float32 tilt_rate_limit = 50;

  const float32 timestep = 0.01;

  //Initialised to value that is not possible to
  //signal that there are no previous values.
  float32 previous_x_accel = 100;
  float32 previous_y_accel = 100;
  float32 previous_z_accel = 100;

  float32 previous_x_vel = 100;
  float32 previous_y_vel = 100;
  float32 previous_z_vel = 100;

  float32 x_dist = 0;
  float32 y_dist = 0;
  float32 z_dist = 0;

  float32 previous_wRoll;
  float32 previous_wPitch;
  float32 previous_wYaw;

  float32 roll = 0; //about x
  float32 pitch = 0; //about y
  float32 yaw = 0; //about z

  void SensorDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    SensorDriverComponentBase::init(queueDepth, instance);
  }

  SensorDriverComponentImpl ::
    ~SensorDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void SensorDriverComponentImpl ::
    BufferIn_handler(
        const NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    /*if robot about to move, reset all data*/
    /*signal byte is the first byte of the system task buffer
    that dictates to either change the range or reset the measurements*/
    int32 signal_byte = buff[0];
    /*if signal_byte is 9, then change range*/
    /*range_byte is the second  byte determines what the range is changed to*
    1 = ACCEL_RANGE_0_5G,///< +/- 0.5g. Requires adxl313
    2 = ACCEL_RANGE_1G,  ///< +/- 1g. Requires adxl313
    3 = ACCEL_RANGE_2G,  ///< +/- 2g. Requires adxl313
    4 = ACCEL_RANGE_4G,  ///< +/- 4g. Requires adxl313
    5 = ACCEL_RANGE_1_5G,///< +/- 1.5g. Requires adxl312
    6 = ACCEL_RANGE_3G,  ///< +/- 2g. Requires adxl312
    7 = ACCEL_RANGE_6G,  ///< +/- 6g. Requires adxl312
    8 = ACCEL_RANGE_12G  ///< +/-  12g. Requires adxl312*/
    int32 range_byte = buff[1];
    if(signal_byte = 9)
    {
      switch(range_byte){
        case 1: accel_sample_range = ACCEL_RANGE_0_5G;
                break;
        case 2: accel_sample_range = ACCEL_RANGE_1G;
                break;
        case 3: accel_sample_range = ACCEL_RANGE_2G;
                break;
        case 4: accel_sample_range = ACCEL_RANGE_4G;
                break;
        case 5: accel_sample_range = ACCEL_RANGE_1_5G;
                break;
        case 6: accel_sample_range = ACCEL_RANGE_3G;
                break;
        case 7: accel_sample_range = ACCEL_RANGE_6G;
                break;
        case 8: accel_sample_range = ACCEL_RANGE_12G;
                break;
        default: accel_sample_range = ACCEL_RANGE_2G;
                break;
      }
      /*if signal byte is 8 then reset measurements*/
      else if(signal_byte = 8)
      {
         previous_x_accel = 100;
         previous_y_accel = 100;
         previous_z_accel = 100;

         previous_x_vel = 100;
         previous_y_vel = 100;
         previous_z_vel = 100;

         x_dist = 0;
         y_dist = 0;
         z_dist = 0;

         roll = 0; //about x
         pitch = 0; //about y
         yaw = 0; //about z
      }
      /*checks case if data from system buffer is invalid*/
      else
      {
         this->INVALID_SYSTEM_BUFFER(signal_byte, range_byte);
      }
    }
  }

  void SensorDriverComponentImpl ::
    SpiRead_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &writeBuffer,
        Fw::Buffer &readBuffer
    )
  {
    float32 x_accel;
    float32 y_accel;
    float32 z_accel;

    float32 wRoll; //angular velocity about x
    float32 wPitch; //angular velocity about y
    float32 wYaw; //angular velocity about z

    /*Initialize IMU chips and setup default behavior*/
    /*Choose range and sampling rate*/
    /*******************************/
    spiInit();
    /*returns 0 if it's okay and returns 1 if there's an error*/
    int accel_status = accel_init();
    int gyro_status = gyro_init(gyro_range);

    /*checking if accelerometer and gyroscope have initialized correctly*/
    if(accel_status == 1)
    {
      this->ACCEL_INIT_ERROR();
    }
    if(gyro_status == 1)
    {
      this->GYRO_INIT_ERROR();
    }

    /*Change settings*/
    /*Sampling rae, range,...etc*/
    /*******************************/
    accel_start_sampling(accel_sample_rate, accel_power_mode, accel_sample_range);
    gyro_start_sampling();

    /*Parsing Data from read buffer*/
    /******************************/
    accel_data_t *accelerations;
    accel_get_data(accelerations);
    x_accel = accelerations->x;
    y_accel = accelerations->y;
    z_accel = accelerations->z;

    gyro_data_t *angular_velocities;
    gyro_read_data(angular_velocities);
    wRoll = angular_velocities->x;
    wPitch = angular_velocities->y;
    wYaw = angular_velocities->z;

    /*Safeguarding against tipover due to tilt rate*/
    if(wRoll >= tilt_rate_limit || wPitch >= tilt_rate_limit)
    {
      this->TILT_RATE_LIMIT_REACHED(wRoll, wPitch, wYaw);
    }

    /*checking if it's the first data point (ie doesn't have a previous point to reference)*/
    if(previous_x_accel != 100 && previous_y_accel != 100 && previous_z_accel != 100)
    {
      /*finding distance from accelerometer data******************************************/
      /*Integrating acceleration to get velocity*/
      float32 cur_x_vel = previous_x_accel*timestep + ((abs(previous_x_accel-x_accel)*timestep)/2);
      float32 cur_y_vel = previous_y_accel*timestep + ((abs(previous_y_accel-x_accel)*timestep)/2);
      float32 cur_z_vel = previous_z_accel*timestep + ((abs(previous_z_accel-x_accel)*timestep)/2);

      /*Integrating velocity to get distance*/
      x_dist += previous_x_vel*timestep + ((abs(previous_x_vel-cur_x_vel)*timestep)/2);
      y_dist += previous_y_vel*timestep + ((abs(previous_y_vel-cur_y_vel)*timestep)/2);
      z_dist += previous_z_vel*timestep + ((abs(previous_z_vel-cur_z_vel)*timestep)/2);

      /*Setting current values as previous values for the next iteration of data reading*/
      previous_x_accel = x_accel;
      previous_y_accel = y_accel;
      previous_z_accel = z_accel;

      previous_x_vel = cur_x_vel;
      previous_y_vel = cur_y_vel;
      previous_z_vel = cur_z_vel;
      /************************************************************************************/

      /*finding angle from gyroscope data**************************************************/
      roll += previous_wRoll*timestep + ((abs(previous_wRoll-wRoll)*timestep)/2);
      pitch += previous_wPitch*timestep + ((abs(previous_wPitch-wPitch)*timestep)/2);
      yaw += previous_wYaw*timestep + ((abs(previous_wYaw-wYaw)*timestep)/2);

      previous_wRoll = wRoll;
      previous_wPitch = wPitch;
      previous_wYaw = wYaw;
      /*************************************************************************************/
    }
    /*if there is no previous point, then just set current value as the previous value
    *in order to use it in next iteration*/
    else
    {
      previous_x_accel = x_accel;
      previous_y_accel = y_accel;
      previous_z_accel = z_accel;

      previous_x_vel = cur_x_vel;
      previous_y_vel = cur_y_vel;
      previous_z_vel = cur_z_vel;

      previous_wRoll = wRoll;
      previous_wPitch = wPitch;
      previous_wYaw = wYaw;
    }

    /*Send error to system task if tilt exceeds
     *some limit or rate of movement exceeds some limit*/
     /*****************************/
     if(roll >= tilt_limit || pitch >= tilt_limit)
     {
       this->TILT_LIMIT_REACHED(roll, pitch, yaw);
     }
 }

  void SensorDriverComponentImpl ::
    Sched_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
  }

  void SensorDriverComponentImpl ::
    PingIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    // TODO
  }

} // end namespace Drv
