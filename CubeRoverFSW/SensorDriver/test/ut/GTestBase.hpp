// ======================================================================
// \title  SensorDriver/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for SensorDriver component Google Test harness base class
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

#ifndef SensorDriver_GTEST_BASE_HPP
#define SensorDriver_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for event history assertions 
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_TILT_LIMIT_REACHED_SIZE(size) \
  this->assertEvents_TILT_LIMIT_REACHED_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_TILT_LIMIT_REACHED(index, _pitch, _roll, _yaw) \
  this->assertEvents_TILT_LIMIT_REACHED(__FILE__, __LINE__, index, _pitch, _roll, _yaw)

#define ASSERT_EVENTS_TILT_RATE_LIMIT_REACHED_SIZE(size) \
  this->assertEvents_TILT_RATE_LIMIT_REACHED_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_TILT_RATE_LIMIT_REACHED(index, _pitch, _roll, _yaw) \
  this->assertEvents_TILT_RATE_LIMIT_REACHED(__FILE__, __LINE__, index, _pitch, _roll, _yaw)

#define ASSERT_EVENTS_ACCEL_INIT_ERROR_SIZE(size) \
  this->assertEvents_ACCEL_INIT_ERROR_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_GYRO_INIT_ERROR_SIZE(size) \
  this->assertEvents_GYRO_INIT_ERROR_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_INVALID_SYSTEM_BUFFER_SIZE(size) \
  this->assertEvents_INVALID_SYSTEM_BUFFER_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_INVALID_SYSTEM_BUFFER(index, _signalbyte, _rangebyte) \
  this->assertEvents_INVALID_SYSTEM_BUFFER(__FILE__, __LINE__, index, _signalbyte, _rangebyte)

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_PingOut_SIZE(size) \
  this->assert_from_PingOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_PingOut(index, _key) \
  { \
    ASSERT_GT(this->fromPortHistory_PingOut->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_PingOut\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_PingOut->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_PingOut& _e = \
      this->fromPortHistory_PingOut->at(index); \
    ASSERT_EQ(_key, _e.key) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument key at index " \
    << index \
    << " in history of from_PingOut\n" \
    << "  Expected: " << _key << "\n" \
    << "  Actual:   " << _e.key << "\n"; \
  }

#define ASSERT_from_BufferOut_SIZE(size) \
  this->assert_from_BufferOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_BufferOut(index, _buff) \
  { \
    ASSERT_GT(this->fromPortHistory_BufferOut->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_BufferOut\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_BufferOut->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_BufferOut& _e = \
      this->fromPortHistory_BufferOut->at(index); \
    ASSERT_EQ(_buff, _e.buff) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument buff at index " \
    << index \
    << " in history of from_BufferOut\n" \
    << "  Expected: " << _buff << "\n" \
    << "  Actual:   " << _e.buff << "\n"; \
  }

#define ASSERT_from_Tlm_SIZE(size) \
  this->assert_from_Tlm_size(__FILE__, __LINE__, size)

#define ASSERT_from_Tlm(index, _id, _timeTag, _val) \
  { \
    ASSERT_GT(this->fromPortHistory_Tlm->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_Tlm\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_Tlm->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_Tlm& _e = \
      this->fromPortHistory_Tlm->at(index); \
    ASSERT_EQ(_id, _e.id) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument id at index " \
    << index \
    << " in history of from_Tlm\n" \
    << "  Expected: " << _id << "\n" \
    << "  Actual:   " << _e.id << "\n"; \
    ASSERT_EQ(_timeTag, _e.timeTag) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument timeTag at index " \
    << index \
    << " in history of from_Tlm\n" \
    << "  Expected: " << _timeTag << "\n" \
    << "  Actual:   " << _e.timeTag << "\n"; \
    ASSERT_EQ(_val, _e.val) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument val at index " \
    << index \
    << " in history of from_Tlm\n" \
    << "  Expected: " << _val << "\n" \
    << "  Actual:   " << _e.val << "\n"; \
  }

#define ASSERT_from_SpiWrite_SIZE(size) \
  this->assert_from_SpiWrite_size(__FILE__, __LINE__, size)

#define ASSERT_from_SpiWrite(index, _writeBuffer, _readBuffer) \
  { \
    ASSERT_GT(this->fromPortHistory_SpiWrite->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_SpiWrite\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_SpiWrite->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_SpiWrite& _e = \
      this->fromPortHistory_SpiWrite->at(index); \
    ASSERT_EQ(_writeBuffer, _e.writeBuffer) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument writeBuffer at index " \
    << index \
    << " in history of from_SpiWrite\n" \
    << "  Expected: " << _writeBuffer << "\n" \
    << "  Actual:   " << _e.writeBuffer << "\n"; \
    ASSERT_EQ(_readBuffer, _e.readBuffer) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument readBuffer at index " \
    << index \
    << " in history of from_SpiWrite\n" \
    << "  Expected: " << _readBuffer << "\n" \
    << "  Actual:   " << _e.readBuffer << "\n"; \
  }

#define ASSERT_from_CycleOut_SIZE(size) \
  this->assert_from_CycleOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_CycleOut(index, _cycleStart) \
  { \
    ASSERT_GT(this->fromPortHistory_CycleOut->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_CycleOut\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_CycleOut->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_CycleOut& _e = \
      this->fromPortHistory_CycleOut->at(index); \
    ASSERT_EQ(_cycleStart, _e.cycleStart) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument cycleStart at index " \
    << index \
    << " in history of from_CycleOut\n" \
    << "  Expected: " << _cycleStart << "\n" \
    << "  Actual:   " << _e.cycleStart << "\n"; \
  }

#define ASSERT_from_Time_SIZE(size) \
  this->assert_from_Time_size(__FILE__, __LINE__, size)

#define ASSERT_from_Time(index, _time) \
  { \
    ASSERT_GT(this->fromPortHistory_Time->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_Time\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_Time->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_Time& _e = \
      this->fromPortHistory_Time->at(index); \
    ASSERT_EQ(_time, _e.time) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument time at index " \
    << index \
    << " in history of from_Time\n" \
    << "  Expected: " << _time << "\n" \
    << "  Actual:   " << _e.time << "\n"; \
  }

namespace Drv {

  //! \class SensorDriverGTestBase
  //! \brief Auto-generated base class for SensorDriver component Google Test harness
  //!
  class SensorDriverGTestBase :
    public SensorDriverTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object SensorDriverGTestBase
      //!
      SensorDriverGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object SensorDriverGTestBase
      //!
      virtual ~SensorDriverGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // Events
      // ----------------------------------------------------------------------

      void assertEvents_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: TILT_LIMIT_REACHED
      // ----------------------------------------------------------------------

      void assertEvents_TILT_LIMIT_REACHED_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_TILT_LIMIT_REACHED(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32 pitch, /*!< current pitch*/
          const F32 roll, /*!< current roll*/
          const F32 yaw /*!< current yaw*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: TILT_RATE_LIMIT_REACHED
      // ----------------------------------------------------------------------

      void assertEvents_TILT_RATE_LIMIT_REACHED_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_TILT_RATE_LIMIT_REACHED(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32 pitch, /*!< current angular velocity about the x axis*/
          const F32 roll, /*!< current angular velocity about the y axis*/
          const F32 yaw /*!< current angular velocity about the z axis*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: ACCEL_INIT_ERROR
      // ----------------------------------------------------------------------

      void assertEvents_ACCEL_INIT_ERROR_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: GYRO_INIT_ERROR
      // ----------------------------------------------------------------------

      void assertEvents_GYRO_INIT_ERROR_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: INVALID_SYSTEM_BUFFER
      // ----------------------------------------------------------------------

      void assertEvents_INVALID_SYSTEM_BUFFER_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_INVALID_SYSTEM_BUFFER(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const int32 signalbyte, /*!< byte that signals which operation to do*/
          const int32 rangebyte /*!< byte that denotes what range to choose*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From ports 
      // ----------------------------------------------------------------------

      void assertFromPortHistory_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: PingOut 
      // ----------------------------------------------------------------------

      void assert_from_PingOut_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: BufferOut 
      // ----------------------------------------------------------------------

      void assert_from_BufferOut_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: Tlm 
      // ----------------------------------------------------------------------

      void assert_from_Tlm_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: SpiWrite 
      // ----------------------------------------------------------------------

      void assert_from_SpiWrite_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: CycleOut 
      // ----------------------------------------------------------------------

      void assert_from_CycleOut_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: Time 
      // ----------------------------------------------------------------------

      void assert_from_Time_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

  };

} // end namespace Drv

#endif
