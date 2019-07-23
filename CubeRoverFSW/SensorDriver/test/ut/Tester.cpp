// ======================================================================
// \title  SensorDriver.hpp
// \author sisyphuslaetus
// \brief  cpp file for SensorDriver test harness implementation class
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

#include "Tester.hpp"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10
#define QUEUE_DEPTH 10

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  Tester ::
    Tester(void) :
#if FW_OBJECT_NAMES == 1
      SensorDriverGTestBase("Tester", MAX_HISTORY_SIZE),
      component("SensorDriver")
#else
      SensorDriverGTestBase(MAX_HISTORY_SIZE),
      component()
#endif
  {
    this->initComponents();
    this->connectPorts();
  }

  Tester ::
    ~Tester(void)
  {

  }

  // ----------------------------------------------------------------------
  // Tests
  // ----------------------------------------------------------------------

  void Tester ::
    testTipOver
  {
    // TODO
  }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_PingOut_handler(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    this->pushFromPortEntry_PingOut(key);
  }

  void Tester ::
    from_BufferOut_handler(
        const NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    this->pushFromPortEntry_BufferOut(buff);
  }

  void Tester ::
    from_Tlm_handler(
        const NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    this->pushFromPortEntry_Tlm(id, timeTag, val);
  }

  void Tester ::
    from_SpiWrite_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &writeBuffer,
        Fw::Buffer &readBuffer
    )
  {
    this->pushFromPortEntry_SpiWrite(writeBuffer, readBuffer);
  }

  void Tester ::
    from_CycleOut_handler(
        const NATIVE_INT_TYPE portNum,
        Svc::TimerVal &cycleStart
    )
  {
    this->pushFromPortEntry_CycleOut(cycleStart);
  }

  void Tester ::
    from_Time_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Time &time
    )
  {
    this->pushFromPortEntry_Time(time);
  }

  // ----------------------------------------------------------------------
  // Helper methods
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts(void)
  {

    // BufferIn
    this->connect_to_BufferIn(
        0,
        this->component.get_BufferIn_InputPort(0)
    );

    // SpiRead
    for (NATIVE_INT_TYPE i = 0; i < 2; ++i) {
      this->connect_to_SpiRead(
          i,
          this->component.get_SpiRead_InputPort(i)
      );
    }

    // Sched
    this->connect_to_Sched(
        0,
        this->component.get_Sched_InputPort(0)
    );

    // PingIn
    this->connect_to_PingIn(
        0,
        this->component.get_PingIn_InputPort(0)
    );

    // PingOut
    this->component.set_PingOut_OutputPort(
        0,
        this->get_from_PingOut(0)
    );

    // BufferOut
    this->component.set_BufferOut_OutputPort(
        0,
        this->get_from_BufferOut(0)
    );

    // Tlm
    this->component.set_Tlm_OutputPort(
        0,
        this->get_from_Tlm(0)
    );

    // SpiWrite
    for (NATIVE_INT_TYPE i = 0; i < 2; ++i) {
      this->component.set_SpiWrite_OutputPort(
          i,
          this->get_from_SpiWrite(i)
      );
    }

    // CycleOut
    this->component.set_CycleOut_OutputPort(
        0,
        this->get_from_CycleOut(0)
    );

    // Time
    this->component.set_Time_OutputPort(
        0,
        this->get_from_Time(0)
    );

    // Time
    this->component.set_Time_OutputPort(
        0,
        this->get_from_Time(0)
    );

    // Log
    this->component.set_Log_OutputPort(
        0,
        this->get_from_Log(0)
    );

    // LogText
    this->component.set_LogText_OutputPort(
        0,
        this->get_from_LogText(0)
    );

  }

  void Tester ::
    initComponents(void)
  {
    this->init();
    this->component.init(
        QUEUE_DEPTH, INSTANCE
    );
  }

} // end namespace Drv
