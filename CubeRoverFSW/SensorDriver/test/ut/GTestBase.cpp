// ======================================================================
// \title  SensorDriver/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for SensorDriver component Google Test harness base class
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

#include "GTestBase.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  SensorDriverGTestBase ::
    SensorDriverGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) : 
        SensorDriverTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  SensorDriverGTestBase ::
    ~SensorDriverGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assertEvents_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventsSize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all event histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventsSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: TILT_LIMIT_REACHED
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assertEvents_TILT_LIMIT_REACHED_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_TILT_LIMIT_REACHED->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event TILT_LIMIT_REACHED\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_TILT_LIMIT_REACHED->size() << "\n";
  }

  void SensorDriverGTestBase ::
    assertEvents_TILT_LIMIT_REACHED(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32 pitch,
        const F32 roll,
        const F32 yaw
    ) const
  {
    ASSERT_GT(this->eventHistory_TILT_LIMIT_REACHED->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event TILT_LIMIT_REACHED\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_TILT_LIMIT_REACHED->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_TILT_LIMIT_REACHED& e =
      this->eventHistory_TILT_LIMIT_REACHED->at(index);
    ASSERT_EQ(pitch, e.pitch)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument pitch at index "
      << index
      << " in history of event TILT_LIMIT_REACHED\n"
      << "  Expected: " << pitch << "\n"
      << "  Actual:   " << e.pitch << "\n";
    ASSERT_EQ(roll, e.roll)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument roll at index "
      << index
      << " in history of event TILT_LIMIT_REACHED\n"
      << "  Expected: " << roll << "\n"
      << "  Actual:   " << e.roll << "\n";
    ASSERT_EQ(yaw, e.yaw)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument yaw at index "
      << index
      << " in history of event TILT_LIMIT_REACHED\n"
      << "  Expected: " << yaw << "\n"
      << "  Actual:   " << e.yaw << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: TILT_RATE_LIMIT_REACHED
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assertEvents_TILT_RATE_LIMIT_REACHED_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_TILT_RATE_LIMIT_REACHED->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event TILT_RATE_LIMIT_REACHED\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_TILT_RATE_LIMIT_REACHED->size() << "\n";
  }

  void SensorDriverGTestBase ::
    assertEvents_TILT_RATE_LIMIT_REACHED(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32 pitch,
        const F32 roll,
        const F32 yaw
    ) const
  {
    ASSERT_GT(this->eventHistory_TILT_RATE_LIMIT_REACHED->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event TILT_RATE_LIMIT_REACHED\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_TILT_RATE_LIMIT_REACHED->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_TILT_RATE_LIMIT_REACHED& e =
      this->eventHistory_TILT_RATE_LIMIT_REACHED->at(index);
    ASSERT_EQ(pitch, e.pitch)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument pitch at index "
      << index
      << " in history of event TILT_RATE_LIMIT_REACHED\n"
      << "  Expected: " << pitch << "\n"
      << "  Actual:   " << e.pitch << "\n";
    ASSERT_EQ(roll, e.roll)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument roll at index "
      << index
      << " in history of event TILT_RATE_LIMIT_REACHED\n"
      << "  Expected: " << roll << "\n"
      << "  Actual:   " << e.roll << "\n";
    ASSERT_EQ(yaw, e.yaw)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument yaw at index "
      << index
      << " in history of event TILT_RATE_LIMIT_REACHED\n"
      << "  Expected: " << yaw << "\n"
      << "  Actual:   " << e.yaw << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: ACCEL_INIT_ERROR
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assertEvents_ACCEL_INIT_ERROR_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventsSize_ACCEL_INIT_ERROR)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event ACCEL_INIT_ERROR\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventsSize_ACCEL_INIT_ERROR << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: GYRO_INIT_ERROR
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assertEvents_GYRO_INIT_ERROR_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventsSize_GYRO_INIT_ERROR)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event GYRO_INIT_ERROR\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventsSize_GYRO_INIT_ERROR << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: INVALID_SYSTEM_BUFFER
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assertEvents_INVALID_SYSTEM_BUFFER_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_INVALID_SYSTEM_BUFFER->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event INVALID_SYSTEM_BUFFER\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_INVALID_SYSTEM_BUFFER->size() << "\n";
  }

  void SensorDriverGTestBase ::
    assertEvents_INVALID_SYSTEM_BUFFER(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const int32 signalbyte,
        const int32 rangebyte
    ) const
  {
    ASSERT_GT(this->eventHistory_INVALID_SYSTEM_BUFFER->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event INVALID_SYSTEM_BUFFER\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_INVALID_SYSTEM_BUFFER->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_INVALID_SYSTEM_BUFFER& e =
      this->eventHistory_INVALID_SYSTEM_BUFFER->at(index);
    ASSERT_EQ(signalbyte, e.signalbyte)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument signalbyte at index "
      << index
      << " in history of event INVALID_SYSTEM_BUFFER\n"
      << "  Expected: " << signalbyte << "\n"
      << "  Actual:   " << e.signalbyte << "\n";
    ASSERT_EQ(rangebyte, e.rangebyte)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument rangebyte at index "
      << index
      << " in history of event INVALID_SYSTEM_BUFFER\n"
      << "  Expected: " << rangebyte << "\n"
      << "  Actual:   " << e.rangebyte << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assertFromPortHistory_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistorySize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all from port histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistorySize << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: PingOut
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assert_from_PingOut_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_PingOut->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_PingOut\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_PingOut->size() << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: BufferOut
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assert_from_BufferOut_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_BufferOut->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_BufferOut\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_BufferOut->size() << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: Tlm
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assert_from_Tlm_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_Tlm->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_Tlm\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_Tlm->size() << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: SpiWrite
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assert_from_SpiWrite_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_SpiWrite->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_SpiWrite\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_SpiWrite->size() << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: CycleOut
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assert_from_CycleOut_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_CycleOut->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_CycleOut\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_CycleOut->size() << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: Time
  // ----------------------------------------------------------------------

  void SensorDriverGTestBase ::
    assert_from_Time_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_Time->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_Time\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_Time->size() << "\n";
  }

} // end namespace Drv
