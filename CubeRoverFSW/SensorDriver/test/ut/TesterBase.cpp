// ======================================================================
// \title  SensorDriver/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for SensorDriver component test harness base class
//
// \copyright
// Copyright 2009-2016, by the California Institute of Technology.
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

#include <stdlib.h>
#include <string.h>
#include "TesterBase.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SensorDriverTesterBase ::
    SensorDriverTesterBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
#if FW_OBJECT_NAMES == 1
      Fw::PassiveComponentBase(compName)
#else
      Fw::PassiveComponentBase()
#endif
  {
    // Initialize event histories
#if FW_ENABLE_TEXT_LOGGING
    this->textLogHistory = new History<TextLogEntry>(maxHistorySize);
#endif
    this->eventHistory_TILT_LIMIT_REACHED =
      new History<EventEntry_TILT_LIMIT_REACHED>(maxHistorySize);
    this->eventHistory_TILT_RATE_LIMIT_REACHED =
      new History<EventEntry_TILT_RATE_LIMIT_REACHED>(maxHistorySize);
    this->eventHistory_INVALID_SYSTEM_BUFFER =
      new History<EventEntry_INVALID_SYSTEM_BUFFER>(maxHistorySize);
    // Initialize histories for typed user output ports
    this->fromPortHistory_PingOut =
      new History<FromPortEntry_PingOut>(maxHistorySize);
    this->fromPortHistory_BufferOut =
      new History<FromPortEntry_BufferOut>(maxHistorySize);
    this->fromPortHistory_Tlm =
      new History<FromPortEntry_Tlm>(maxHistorySize);
    this->fromPortHistory_SpiWrite =
      new History<FromPortEntry_SpiWrite>(maxHistorySize);
    this->fromPortHistory_CycleOut =
      new History<FromPortEntry_CycleOut>(maxHistorySize);
    this->fromPortHistory_Time =
      new History<FromPortEntry_Time>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  SensorDriverTesterBase ::
    ~SensorDriverTesterBase(void) 
  {
    // Destroy event histories
#if FW_ENABLE_TEXT_LOGGING
    delete this->textLogHistory;
#endif
    delete this->eventHistory_TILT_LIMIT_REACHED;
    delete this->eventHistory_TILT_RATE_LIMIT_REACHED;
    delete this->eventHistory_INVALID_SYSTEM_BUFFER;
  }

  void SensorDriverTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port PingOut

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_PingOut();
        ++_port
    ) {

      this->m_from_PingOut[_port].init();
      this->m_from_PingOut[_port].addCallComp(
          this,
          from_PingOut_static
      );
      this->m_from_PingOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_PingOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_PingOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port BufferOut

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_BufferOut();
        ++_port
    ) {

      this->m_from_BufferOut[_port].init();
      this->m_from_BufferOut[_port].addCallComp(
          this,
          from_BufferOut_static
      );
      this->m_from_BufferOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_BufferOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_BufferOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port Tlm

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Tlm();
        ++_port
    ) {

      this->m_from_Tlm[_port].init();
      this->m_from_Tlm[_port].addCallComp(
          this,
          from_Tlm_static
      );
      this->m_from_Tlm[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Tlm[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Tlm[_port].setObjName(_portName);
#endif

    }

    // Attach input port SpiWrite

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_SpiWrite();
        ++_port
    ) {

      this->m_from_SpiWrite[_port].init();
      this->m_from_SpiWrite[_port].addCallComp(
          this,
          from_SpiWrite_static
      );
      this->m_from_SpiWrite[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_SpiWrite[%d]",
          this->m_objName,
          _port
      );
      this->m_from_SpiWrite[_port].setObjName(_portName);
#endif

    }

    // Attach input port CycleOut

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CycleOut();
        ++_port
    ) {

      this->m_from_CycleOut[_port].init();
      this->m_from_CycleOut[_port].addCallComp(
          this,
          from_CycleOut_static
      );
      this->m_from_CycleOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CycleOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CycleOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port Time

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Time();
        ++_port
    ) {

      this->m_from_Time[_port].init();
      this->m_from_Time[_port].addCallComp(
          this,
          from_Time_static
      );
      this->m_from_Time[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Time[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Time[_port].setObjName(_portName);
#endif

    }

    // Attach input port Time

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Time();
        ++_port
    ) {

      this->m_from_Time[_port].init();
      this->m_from_Time[_port].addCallComp(
          this,
          from_Time_static
      );
      this->m_from_Time[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Time[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Time[_port].setObjName(_portName);
#endif

    }

    // Attach input port Log

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Log();
        ++_port
    ) {

      this->m_from_Log[_port].init();
      this->m_from_Log[_port].addCallComp(
          this,
          from_Log_static
      );
      this->m_from_Log[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Log[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Log[_port].setObjName(_portName);
#endif

    }

    // Attach input port LogText

#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_LogText();
        ++_port
    ) {

      this->m_from_LogText[_port].init();
      this->m_from_LogText[_port].addCallComp(
          this,
          from_LogText_static
      );
      this->m_from_LogText[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_LogText[%d]",
          this->m_objName,
          _port
      );
      this->m_from_LogText[_port].setObjName(_portName);
#endif

    }
#endif

    // Initialize output port BufferIn

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_BufferIn();
        ++_port
    ) {
      this->m_to_BufferIn[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_BufferIn[%d]",
          this->m_objName,
          _port
      );
      this->m_to_BufferIn[_port].setObjName(_portName);
#endif

    }

    // Initialize output port SpiRead

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_SpiRead();
        ++_port
    ) {
      this->m_to_SpiRead[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_SpiRead[%d]",
          this->m_objName,
          _port
      );
      this->m_to_SpiRead[_port].setObjName(_portName);
#endif

    }

    // Initialize output port Sched

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_Sched();
        ++_port
    ) {
      this->m_to_Sched[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_Sched[%d]",
          this->m_objName,
          _port
      );
      this->m_to_Sched[_port].setObjName(_portName);
#endif

    }

    // Initialize output port PingIn

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_PingIn();
        ++_port
    ) {
      this->m_to_PingIn[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_PingIn[%d]",
          this->m_objName,
          _port
      );
      this->m_to_PingIn[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_from_PingOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_PingOut);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_from_BufferOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_BufferOut);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_to_BufferIn(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_BufferIn);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_from_Tlm(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Tlm);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_to_SpiRead(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_SpiRead);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_from_SpiWrite(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_SpiWrite);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_to_Sched(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_Sched);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_from_CycleOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CycleOut);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_to_PingIn(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_PingIn);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_from_Time(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Time);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_from_Time(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Time);
  }

  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_from_Log(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Log);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE SensorDriverTesterBase ::
    getNum_from_LogText(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_LogText);
  }
#endif

  // ----------------------------------------------------------------------
  // Connectors for to ports 
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    connect_to_BufferIn(
        const NATIVE_INT_TYPE portNum,
        Drv::InputDataBufferPort *const BufferIn
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_BufferIn(),static_cast<AssertArg>(portNum));
    this->m_to_BufferIn[portNum].addCallPort(BufferIn);
  }

  void SensorDriverTesterBase ::
    connect_to_SpiRead(
        const NATIVE_INT_TYPE portNum,
        Drv::InputSpiReadWritePort *const SpiRead
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_SpiRead(),static_cast<AssertArg>(portNum));
    this->m_to_SpiRead[portNum].addCallPort(SpiRead);
  }

  void SensorDriverTesterBase ::
    connect_to_Sched(
        const NATIVE_INT_TYPE portNum,
        Svc::InputSchedPort *const Sched
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_Sched(),static_cast<AssertArg>(portNum));
    this->m_to_Sched[portNum].addCallPort(Sched);
  }

  void SensorDriverTesterBase ::
    connect_to_PingIn(
        const NATIVE_INT_TYPE portNum,
        Svc::InputPingPort *const PingIn
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_PingIn(),static_cast<AssertArg>(portNum));
    this->m_to_PingIn[portNum].addCallPort(PingIn);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    invoke_to_BufferIn(
        const NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    FW_ASSERT(portNum < this->getNum_to_BufferIn(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_BufferIn(),static_cast<AssertArg>(portNum));
    this->m_to_BufferIn[portNum].invoke(
        buff
    );
  }

  void SensorDriverTesterBase ::
    invoke_to_SpiRead(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &writeBuffer,
        Fw::Buffer &readBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_to_SpiRead(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_SpiRead(),static_cast<AssertArg>(portNum));
    this->m_to_SpiRead[portNum].invoke(
        writeBuffer, readBuffer
    );
  }

  void SensorDriverTesterBase ::
    invoke_to_Sched(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(portNum < this->getNum_to_Sched(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_Sched(),static_cast<AssertArg>(portNum));
    this->m_to_Sched[portNum].invoke(
        context
    );
  }

  void SensorDriverTesterBase ::
    invoke_to_PingIn(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(portNum < this->getNum_to_PingIn(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_PingIn(),static_cast<AssertArg>(portNum));
    this->m_to_PingIn[portNum].invoke(
        key
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool SensorDriverTesterBase ::
    isConnected_to_BufferIn(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_BufferIn(), static_cast<AssertArg>(portNum));
    return this->m_to_BufferIn[portNum].isConnected();
  }

  bool SensorDriverTesterBase ::
    isConnected_to_SpiRead(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_SpiRead(), static_cast<AssertArg>(portNum));
    return this->m_to_SpiRead[portNum].isConnected();
  }

  bool SensorDriverTesterBase ::
    isConnected_to_Sched(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_Sched(), static_cast<AssertArg>(portNum));
    return this->m_to_Sched[portNum].isConnected();
  }

  bool SensorDriverTesterBase ::
    isConnected_to_PingIn(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_PingIn(), static_cast<AssertArg>(portNum));
    return this->m_to_PingIn[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------
 
  Svc::InputPingPort *SensorDriverTesterBase ::
    get_from_PingOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_PingOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_PingOut[portNum];
  }

  Drv::InputDataBufferPort *SensorDriverTesterBase ::
    get_from_BufferOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_BufferOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_BufferOut[portNum];
  }

  Fw::InputTlmPort *SensorDriverTesterBase ::
    get_from_Tlm(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Tlm(),static_cast<AssertArg>(portNum));
    return &this->m_from_Tlm[portNum];
  }

  Drv::InputSpiReadWritePort *SensorDriverTesterBase ::
    get_from_SpiWrite(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_SpiWrite(),static_cast<AssertArg>(portNum));
    return &this->m_from_SpiWrite[portNum];
  }

  Svc::InputCyclePort *SensorDriverTesterBase ::
    get_from_CycleOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CycleOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_CycleOut[portNum];
  }

  Fw::InputTimePort *SensorDriverTesterBase ::
    get_from_Time(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Time(),static_cast<AssertArg>(portNum));
    return &this->m_from_Time[portNum];
  }

  Fw::InputTimePort *SensorDriverTesterBase ::
    get_from_Time(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Time(),static_cast<AssertArg>(portNum));
    return &this->m_from_Time[portNum];
  }

  Fw::InputLogPort *SensorDriverTesterBase ::
    get_from_Log(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Log(),static_cast<AssertArg>(portNum));
    return &this->m_from_Log[portNum];
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  Fw::InputLogTextPort *SensorDriverTesterBase ::
    get_from_LogText(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_LogText(),static_cast<AssertArg>(portNum));
    return &this->m_from_LogText[portNum];
  }
#endif

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    from_PingOut_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(callComp);
    SensorDriverTesterBase* _testerBase = 
      static_cast<SensorDriverTesterBase*>(callComp);
    _testerBase->from_PingOut_handlerBase(
        portNum,
        key
    );
  }

  void SensorDriverTesterBase ::
    from_BufferOut_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    FW_ASSERT(callComp);
    SensorDriverTesterBase* _testerBase = 
      static_cast<SensorDriverTesterBase*>(callComp);
    _testerBase->from_BufferOut_handlerBase(
        portNum,
        buff
    );
  }

  void SensorDriverTesterBase ::
    from_Tlm_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    FW_ASSERT(callComp);
    SensorDriverTesterBase* _testerBase = 
      static_cast<SensorDriverTesterBase*>(callComp);
    _testerBase->from_Tlm_handlerBase(
        portNum,
        id, timeTag, val
    );
  }

  void SensorDriverTesterBase ::
    from_SpiWrite_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &writeBuffer,
        Fw::Buffer &readBuffer
    )
  {
    FW_ASSERT(callComp);
    SensorDriverTesterBase* _testerBase = 
      static_cast<SensorDriverTesterBase*>(callComp);
    _testerBase->from_SpiWrite_handlerBase(
        portNum,
        writeBuffer, readBuffer
    );
  }

  void SensorDriverTesterBase ::
    from_CycleOut_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        Svc::TimerVal &cycleStart
    )
  {
    FW_ASSERT(callComp);
    SensorDriverTesterBase* _testerBase = 
      static_cast<SensorDriverTesterBase*>(callComp);
    _testerBase->from_CycleOut_handlerBase(
        portNum,
        cycleStart
    );
  }

  void SensorDriverTesterBase ::
    from_Time_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        Fw::Time &time
    )
  {
    FW_ASSERT(callComp);
    SensorDriverTesterBase* _testerBase = 
      static_cast<SensorDriverTesterBase*>(callComp);
    _testerBase->from_Time_handlerBase(
        portNum,
        time
    );
  }

  void SensorDriverTesterBase ::
    from_Log_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {
    SensorDriverTesterBase* _testerBase =
      static_cast<SensorDriverTesterBase*>(component);
    _testerBase->dispatchEvents(id, timeTag, severity, args);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void SensorDriverTesterBase ::
    from_LogText_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::TextLogSeverity severity,
        Fw::TextLogString &text
    )
  {
    SensorDriverTesterBase* _testerBase =
      static_cast<SensorDriverTesterBase*>(component);
    _testerBase->textLogIn(id,timeTag,severity,text);
  }
#endif

  void SensorDriverTesterBase ::
    from_Time_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        Fw::Time& time
    )
  {
    SensorDriverTesterBase* _testerBase =
      static_cast<SensorDriverTesterBase*>(component);
    time = _testerBase->m_testTime;
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    clearFromPortHistory(void)
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_PingOut->clear();
    this->fromPortHistory_BufferOut->clear();
    this->fromPortHistory_Tlm->clear();
    this->fromPortHistory_SpiWrite->clear();
    this->fromPortHistory_CycleOut->clear();
    this->fromPortHistory_Time->clear();
  }

  // ---------------------------------------------------------------------- 
  // From port: PingOut
  // ---------------------------------------------------------------------- 

  void SensorDriverTesterBase ::
    pushFromPortEntry_PingOut(
        U32 key
    )
  {
    FromPortEntry_PingOut _e = {
      key
    };
    this->fromPortHistory_PingOut->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ---------------------------------------------------------------------- 
  // From port: BufferOut
  // ---------------------------------------------------------------------- 

  void SensorDriverTesterBase ::
    pushFromPortEntry_BufferOut(
        Drv::DataBuffer &buff
    )
  {
    FromPortEntry_BufferOut _e = {
      buff
    };
    this->fromPortHistory_BufferOut->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ---------------------------------------------------------------------- 
  // From port: Tlm
  // ---------------------------------------------------------------------- 

  void SensorDriverTesterBase ::
    pushFromPortEntry_Tlm(
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    FromPortEntry_Tlm _e = {
      id, timeTag, val
    };
    this->fromPortHistory_Tlm->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ---------------------------------------------------------------------- 
  // From port: SpiWrite
  // ---------------------------------------------------------------------- 

  void SensorDriverTesterBase ::
    pushFromPortEntry_SpiWrite(
        Fw::Buffer &writeBuffer,
        Fw::Buffer &readBuffer
    )
  {
    FromPortEntry_SpiWrite _e = {
      writeBuffer, readBuffer
    };
    this->fromPortHistory_SpiWrite->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ---------------------------------------------------------------------- 
  // From port: CycleOut
  // ---------------------------------------------------------------------- 

  void SensorDriverTesterBase ::
    pushFromPortEntry_CycleOut(
        Svc::TimerVal &cycleStart
    )
  {
    FromPortEntry_CycleOut _e = {
      cycleStart
    };
    this->fromPortHistory_CycleOut->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ---------------------------------------------------------------------- 
  // From port: Time
  // ---------------------------------------------------------------------- 

  void SensorDriverTesterBase ::
    pushFromPortEntry_Time(
        Fw::Time &time
    )
  {
    FromPortEntry_Time _e = {
      time
    };
    this->fromPortHistory_Time->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    from_PingOut_handlerBase(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(portNum < this->getNum_from_PingOut(),static_cast<AssertArg>(portNum));
    this->from_PingOut_handler(
        portNum,
        key
    );
  }

  void SensorDriverTesterBase ::
    from_BufferOut_handlerBase(
        const NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    FW_ASSERT(portNum < this->getNum_from_BufferOut(),static_cast<AssertArg>(portNum));
    this->from_BufferOut_handler(
        portNum,
        buff
    );
  }

  void SensorDriverTesterBase ::
    from_Tlm_handlerBase(
        const NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    FW_ASSERT(portNum < this->getNum_from_Tlm(),static_cast<AssertArg>(portNum));
    this->from_Tlm_handler(
        portNum,
        id, timeTag, val
    );
  }

  void SensorDriverTesterBase ::
    from_SpiWrite_handlerBase(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &writeBuffer,
        Fw::Buffer &readBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_from_SpiWrite(),static_cast<AssertArg>(portNum));
    this->from_SpiWrite_handler(
        portNum,
        writeBuffer, readBuffer
    );
  }

  void SensorDriverTesterBase ::
    from_CycleOut_handlerBase(
        const NATIVE_INT_TYPE portNum,
        Svc::TimerVal &cycleStart
    )
  {
    FW_ASSERT(portNum < this->getNum_from_CycleOut(),static_cast<AssertArg>(portNum));
    this->from_CycleOut_handler(
        portNum,
        cycleStart
    );
  }

  void SensorDriverTesterBase ::
    from_Time_handlerBase(
        const NATIVE_INT_TYPE portNum,
        Fw::Time &time
    )
  {
    FW_ASSERT(portNum < this->getNum_from_Time(),static_cast<AssertArg>(portNum));
    this->from_Time_handler(
        portNum,
        time
    );
  }

  // ----------------------------------------------------------------------
  // History 
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    clearHistory()
  {
    this->textLogHistory->clear();
    this->clearEvents();
    this->clearFromPortHistory();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    setTestTime(const Fw::Time& time)
  {
    this->m_testTime = time;
  }

  // ----------------------------------------------------------------------
  // Event dispatch
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    dispatchEvents(
        const FwEventIdType id,
        Fw::Time &timeTag,
        const Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {

    args.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);
    switch (id - idBase) {

      case SensorDriverComponentBase::EVENTID_TILT_LIMIT_REACHED: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 3,_numArgs,3);
        
#endif    
        F32 pitch;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(pitch);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        F32 roll;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(roll);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        F32 yaw;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(yaw);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_TILT_LIMIT_REACHED(pitch, roll, yaw);

        break;

      }

      case SensorDriverComponentBase::EVENTID_TILT_RATE_LIMIT_REACHED: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 3,_numArgs,3);
        
#endif    
        F32 pitch;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(pitch);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        F32 roll;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(roll);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        F32 yaw;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(yaw);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_TILT_RATE_LIMIT_REACHED(pitch, roll, yaw);

        break;

      }

      case SensorDriverComponentBase::EVENTID_ACCEL_INIT_ERROR: 
      {

#if FW_AMPCS_COMPATIBLE
        // For AMPCS, decode zero arguments
        Fw::SerializeStatus _zero_status = Fw::FW_SERIALIZE_OK;
        U8 _noArgs;
        _zero_status = args.deserialize(_noArgs);
        FW_ASSERT(
            _zero_status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_zero_status)
        );
#endif    
        this->logIn_ACTIVITY_HI_ACCEL_INIT_ERROR();

        break;

      }

      case SensorDriverComponentBase::EVENTID_GYRO_INIT_ERROR: 
      {

#if FW_AMPCS_COMPATIBLE
        // For AMPCS, decode zero arguments
        Fw::SerializeStatus _zero_status = Fw::FW_SERIALIZE_OK;
        U8 _noArgs;
        _zero_status = args.deserialize(_noArgs);
        FW_ASSERT(
            _zero_status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_zero_status)
        );
#endif    
        this->logIn_ACTIVITY_HI_GYRO_INIT_ERROR();

        break;

      }

      case SensorDriverComponentBase::EVENTID_INVALID_SYSTEM_BUFFER: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 2,_numArgs,2);
        
#endif    
        int32 signalbyte;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(int32),_argSize,sizeof(int32));
        }
#endif      
        _status = args.deserialize(signalbyte);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        int32 rangebyte;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(int32),_argSize,sizeof(int32));
        }
#endif      
        _status = args.deserialize(rangebyte);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_LO_INVALID_SYSTEM_BUFFER(signalbyte, rangebyte);

        break;

      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void SensorDriverTesterBase ::
    clearEvents(void)
  {
    this->eventsSize = 0;
    this->eventHistory_TILT_LIMIT_REACHED->clear();
    this->eventHistory_TILT_RATE_LIMIT_REACHED->clear();
    this->eventsSize_ACCEL_INIT_ERROR = 0;
    this->eventsSize_GYRO_INIT_ERROR = 0;
    this->eventHistory_INVALID_SYSTEM_BUFFER->clear();
  }

#if FW_ENABLE_TEXT_LOGGING

  // ----------------------------------------------------------------------
  // Text events 
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    textLogIn(
        const U32 id,
        Fw::Time &timeTag,
        const Fw::TextLogSeverity severity,
        const Fw::TextLogString &text
    )
  {
    TextLogEntry e = { id, timeTag, severity, text };
    textLogHistory->push_back(e);
  }

  void SensorDriverTesterBase ::
    printTextLogHistoryEntry(
        const TextLogEntry& e,
        FILE* file
    )
  {
    const char *severityString = "UNKNOWN";
    switch (e.severity) {
      case Fw::LOG_FATAL:
        severityString = "FATAL";
        break;
      case Fw::LOG_WARNING_HI:
        severityString = "WARNING_HI";
        break;
      case Fw::LOG_WARNING_LO:
        severityString = "WARNING_LO";
        break;
      case Fw::LOG_COMMAND:
        severityString = "COMMAND";
        break;
      case Fw::LOG_ACTIVITY_HI:
        severityString = "ACTIVITY_HI";
        break;
      case Fw::LOG_ACTIVITY_LO:
        severityString = "ACTIVITY_LO";
        break;
      case Fw::LOG_DIAGNOSTIC:
       severityString = "DIAGNOSTIC";
        break;
      default:
        severityString = "SEVERITY ERROR";
        break;
    }

    fprintf(
        file,
        "EVENT: (%d) (%d:%d,%d) %s: %s\n",
        e.id,
        const_cast<TextLogEntry&>(e).timeTag.getTimeBase(),
        const_cast<TextLogEntry&>(e).timeTag.getSeconds(),
        const_cast<TextLogEntry&>(e).timeTag.getUSeconds(),
        severityString,
        e.text.toChar()
    );

  }

  void SensorDriverTesterBase ::
    printTextLogHistory(FILE *file) 
  {
    for (U32 i = 0; i < this->textLogHistory->size(); ++i) {
      this->printTextLogHistoryEntry(
          this->textLogHistory->at(i), 
          file
      );
    }
  }

#endif

  // ----------------------------------------------------------------------
  // Event: TILT_LIMIT_REACHED 
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    logIn_ACTIVITY_HI_TILT_LIMIT_REACHED(
        F32 pitch,
        F32 roll,
        F32 yaw
    )
  {
    EventEntry_TILT_LIMIT_REACHED e = {
      pitch, roll, yaw
    };
    eventHistory_TILT_LIMIT_REACHED->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: TILT_RATE_LIMIT_REACHED 
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    logIn_ACTIVITY_HI_TILT_RATE_LIMIT_REACHED(
        F32 pitch,
        F32 roll,
        F32 yaw
    )
  {
    EventEntry_TILT_RATE_LIMIT_REACHED e = {
      pitch, roll, yaw
    };
    eventHistory_TILT_RATE_LIMIT_REACHED->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: ACCEL_INIT_ERROR 
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    logIn_ACTIVITY_HI_ACCEL_INIT_ERROR(
        void
    )
  {
    ++this->eventsSize_ACCEL_INIT_ERROR;
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: GYRO_INIT_ERROR 
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    logIn_ACTIVITY_HI_GYRO_INIT_ERROR(
        void
    )
  {
    ++this->eventsSize_GYRO_INIT_ERROR;
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: INVALID_SYSTEM_BUFFER 
  // ----------------------------------------------------------------------

  void SensorDriverTesterBase ::
    logIn_ACTIVITY_LO_INVALID_SYSTEM_BUFFER(
        int32 signalbyte,
        int32 rangebyte
    )
  {
    EventEntry_INVALID_SYSTEM_BUFFER e = {
      signalbyte, rangebyte
    };
    eventHistory_INVALID_SYSTEM_BUFFER->push_back(e);
    ++this->eventsSize;
  }

} // end namespace Drv
