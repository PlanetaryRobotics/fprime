// ====================================================================== 
// \title  SensorDriverComponentAc.hpp
// \author Auto-generated
// \brief  cpp file for SensorDriver component base class
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

#include <stdio.h>
#include <Fw/Cfg/Config.hpp>
#include <CubeRoverFSW/SensorDriver/SensorDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/EightyCharString.hpp>
#endif


namespace Drv {

  // ----------------------------------------------------------------------
  // Anonymous namespace to prevent name collisions
  // ----------------------------------------------------------------------

  namespace {

    typedef enum {
      SENSORDRIVER_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
      BUFFERIN_DATABUFFER,
      SPIREAD_SPIREADWRITE,
      SCHED_SCHED,
      PINGIN_PING
    } MsgTypeEnum;

    // Get the max size by doing a union of the input port serialization sizes.

    typedef union {
      BYTE port1[Drv::InputDataBufferPort::SERIALIZED_SIZE];
      BYTE port2[Drv::InputSpiReadWritePort::SERIALIZED_SIZE];
      BYTE port3[Svc::InputSchedPort::SERIALIZED_SIZE];
      BYTE port4[Svc::InputPingPort::SERIALIZED_SIZE];
    } BuffUnion;

    // Define a message buffer class large enough to handle all the
    // asynchronous inputs to the component

    class ComponentIpcSerializableBuffer : 
      public Fw::SerializeBufferBase
    {

      public:

        enum {
          // Max. message size = size of data + message id + port
          SERIALIZATION_SIZE =
            sizeof(BuffUnion) +
            sizeof(NATIVE_INT_TYPE) +
            sizeof(NATIVE_INT_TYPE)
        };

        NATIVE_UINT_TYPE getBuffCapacity(void) const {
          return sizeof(m_buff);
        }

        U8* getBuffAddr(void) {
          return m_buff;
        }

        const U8* getBuffAddr(void) const {
          return m_buff;
        }

      private:
        // Should be the max of all the input ports serialized sizes...
        U8 m_buff[SERIALIZATION_SIZE];

    };

  }

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Drv::InputDataBufferPort *SensorDriverComponentBase ::
    get_BufferIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_BufferIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_BufferIn_InputPort[portNum];
  }

  Drv::InputSpiReadWritePort *SensorDriverComponentBase ::
    get_SpiRead_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_SpiRead_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_SpiRead_InputPort[portNum];
  }

  Svc::InputSchedPort *SensorDriverComponentBase ::
    get_Sched_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_Sched_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_Sched_InputPort[portNum];
  }

  Svc::InputPingPort *SensorDriverComponentBase ::
    get_PingIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_PingIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_PingIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void SensorDriverComponentBase ::
    set_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Svc::InputPingPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_PingOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_PingOut_OutputPort[portNum].addCallPort(port);
  }

  void SensorDriverComponentBase ::
    set_BufferOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputDataBufferPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_BufferOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_BufferOut_OutputPort[portNum].addCallPort(port);
  }

  void SensorDriverComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTlmPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_Tlm_OutputPort[portNum].addCallPort(port);
  }

  void SensorDriverComponentBase ::
    set_SpiWrite_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputSpiReadWritePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_SpiWrite_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_SpiWrite_OutputPort[portNum].addCallPort(port);
  }

  void SensorDriverComponentBase ::
    set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Svc::InputCyclePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_CycleOut_OutputPort[portNum].addCallPort(port);
  }

  void SensorDriverComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_Time_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void SensorDriverComponentBase ::
    set_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_PingOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_PingOut_OutputPort[portNum].registerSerialPort(port);
  }

  void SensorDriverComponentBase ::
    set_BufferOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_BufferOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_BufferOut_OutputPort[portNum].registerSerialPort(port);
  }

  void SensorDriverComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_Tlm_OutputPort[portNum].registerSerialPort(port);
  }

  void SensorDriverComponentBase ::
    set_SpiWrite_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_SpiWrite_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_SpiWrite_OutputPort[portNum].registerSerialPort(port);
  }

  void SensorDriverComponentBase ::
    set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_CycleOut_OutputPort[portNum].registerSerialPort(port);
  }

  void SensorDriverComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_Time_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SensorDriverComponentBase ::
#if FW_OBJECT_NAMES == 1
    SensorDriverComponentBase(const char* compName) :
      Fw::ActiveComponentBase(compName)
#else
    SensorDriverComponentBase() :
      Fw::ActiveComponentBase()
#endif
  {

  
  
  }

  void SensorDriverComponentBase ::
    init(
        NATIVE_INT_TYPE queueDepth,
        NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class
    Fw::ActiveComponentBase::init(instance);

    // Connect input port BufferIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_BufferIn_InputPorts();
        port++
    ) {

      this->m_BufferIn_InputPort[port].init();
      this->m_BufferIn_InputPort[port].addCallComp(
          this,
          m_p_BufferIn_in
      );
      this->m_BufferIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_BufferIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_BufferIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port SpiRead
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_SpiRead_InputPorts();
        port++
    ) {

      this->m_SpiRead_InputPort[port].init();
      this->m_SpiRead_InputPort[port].addCallComp(
          this,
          m_p_SpiRead_in
      );
      this->m_SpiRead_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_SpiRead_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_SpiRead_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port Sched
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_Sched_InputPorts();
        port++
    ) {

      this->m_Sched_InputPort[port].init();
      this->m_Sched_InputPort[port].addCallComp(
          this,
          m_p_Sched_in
      );
      this->m_Sched_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Sched_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_Sched_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port PingIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_PingIn_InputPorts();
        port++
    ) {

      this->m_PingIn_InputPort[port].init();
      this->m_PingIn_InputPort[port].addCallComp(
          this,
          m_p_PingIn_in
      );
      this->m_PingIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_PingIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_PingIn_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port PingOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_PingOut_OutputPorts();
        port++
    ) {
      this->m_PingOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_PingOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_PingOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port BufferOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_BufferOut_OutputPorts();
        port++
    ) {
      this->m_BufferOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_BufferOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_BufferOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port Tlm
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_Tlm_OutputPorts();
        port++
    ) {
      this->m_Tlm_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Tlm_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_Tlm_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port SpiWrite
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_SpiWrite_OutputPorts();
        port++
    ) {
      this->m_SpiWrite_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_SpiWrite_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_SpiWrite_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port CycleOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_CycleOut_OutputPorts();
        port++
    ) {
      this->m_CycleOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CycleOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_CycleOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port Time
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_Time_OutputPorts();
        port++
    ) {
      this->m_Time_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Time_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_Time_OutputPort[port].setObjName(portName);
#endif

    }

    Os::Queue::QueueStatus qStat =
    this->createQueue(
        queueDepth,
        ComponentIpcSerializableBuffer::SERIALIZATION_SIZE
    );
    FW_ASSERT(
        Os::Queue::QUEUE_OK == qStat,
        static_cast<AssertArg>(qStat)
    );

  }

  SensorDriverComponentBase::
    ~SensorDriverComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void SensorDriverComponentBase ::
    PingOut_out(
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(portNum < this->getNum_PingOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_PingOut_OutputPort[portNum].invoke(key);
  }

  void SensorDriverComponentBase ::
    BufferOut_out(
        NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    FW_ASSERT(portNum < this->getNum_BufferOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_BufferOut_OutputPort[portNum].invoke(buff);
  }

  void SensorDriverComponentBase ::
    Tlm_out(
        NATIVE_INT_TYPE portNum,
        FwChanIdType id, Fw::Time &timeTag, Fw::TlmBuffer &val
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_Tlm_OutputPort[portNum].invoke(id, timeTag, val);
  }

  void SensorDriverComponentBase ::
    SpiWrite_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_SpiWrite_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_SpiWrite_OutputPort[portNum].invoke(writeBuffer, readBuffer);
  }

  void SensorDriverComponentBase ::
    CycleOut_out(
        NATIVE_INT_TYPE portNum,
        Svc::TimerVal &cycleStart
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_CycleOut_OutputPort[portNum].invoke(cycleStart);
  }

  void SensorDriverComponentBase ::
    Time_out(
        NATIVE_INT_TYPE portNum,
        Fw::Time &time
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_Time_OutputPort[portNum].invoke(time);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_PingOut_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_PingOut_OutputPort
    );
  }

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_BufferOut_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_BufferOut_OutputPort
    );
  }

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_BufferIn_InputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_BufferIn_InputPort
    );
  }

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_Tlm_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_Tlm_OutputPort
    );
  }

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_SpiRead_InputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_SpiRead_InputPort
    );
  }

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_SpiWrite_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_SpiWrite_OutputPort
    );
  }

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_Sched_InputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_Sched_InputPort
    );
  }

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_CycleOut_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_CycleOut_OutputPort
    );
  }

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_PingIn_InputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_PingIn_InputPort
    );
  }

  NATIVE_INT_TYPE SensorDriverComponentBase ::
    getNum_Time_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_Time_OutputPort
    );
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool SensorDriverComponentBase ::
    isConnected_PingOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_PingOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_PingOut_OutputPort[portNum].isConnected();
  }

  bool SensorDriverComponentBase ::
    isConnected_BufferOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_BufferOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_BufferOut_OutputPort[portNum].isConnected();
  }

  bool SensorDriverComponentBase ::
    isConnected_Tlm_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Tlm_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_Tlm_OutputPort[portNum].isConnected();
  }

  bool SensorDriverComponentBase ::
    isConnected_SpiWrite_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_SpiWrite_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_SpiWrite_OutputPort[portNum].isConnected();
  }

  bool SensorDriverComponentBase ::
    isConnected_CycleOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CycleOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_CycleOut_OutputPort[portNum].isConnected();
  }

  bool SensorDriverComponentBase ::
    isConnected_Time_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Time_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_Time_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void SensorDriverComponentBase ::
    m_p_BufferIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    FW_ASSERT(callComp);
    SensorDriverComponentBase* compPtr =
      (SensorDriverComponentBase*) callComp;
    compPtr->BufferIn_handlerBase(portNum, buff);
  }

  void SensorDriverComponentBase ::
    m_p_SpiRead_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer
    )
  {
    FW_ASSERT(callComp);
    SensorDriverComponentBase* compPtr =
      (SensorDriverComponentBase*) callComp;
    compPtr->SpiRead_handlerBase(portNum, writeBuffer, readBuffer);
  }

  void SensorDriverComponentBase ::
    m_p_Sched_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(callComp);
    SensorDriverComponentBase* compPtr =
      (SensorDriverComponentBase*) callComp;
    compPtr->Sched_handlerBase(portNum, context);
  }

  void SensorDriverComponentBase ::
    m_p_PingIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(callComp);
    SensorDriverComponentBase* compPtr =
      (SensorDriverComponentBase*) callComp;
    compPtr->PingIn_handlerBase(portNum, key);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void SensorDriverComponentBase ::
    BufferIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_BufferIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Call pre-message hook
    BufferIn_preMsgHook(
        portNum,
        buff
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(BUFFERIN_DATABUFFER)
    );
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    _status = msg.serialize(portNum);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    // Serialize argument buff
    _status = msg.serialize(buff);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

      
    // send message
    Os::Queue::QueueBlocking _block = 
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<AssertArg>(qStatus)
    );      
      
  }

  void SensorDriverComponentBase ::
    SpiRead_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_SpiRead_InputPorts(),static_cast<AssertArg>(portNum));

    // Call pre-message hook
    SpiRead_preMsgHook(
        portNum,
        writeBuffer, readBuffer
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(SPIREAD_SPIREADWRITE)
    );
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    _status = msg.serialize(portNum);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    // Serialize argument writeBuffer
    _status = msg.serialize(writeBuffer);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    // Serialize argument readBuffer
    _status = msg.serialize(readBuffer);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

      
    // send message
    Os::Queue::QueueBlocking _block = 
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<AssertArg>(qStatus)
    );      
      
  }

  void SensorDriverComponentBase ::
    Sched_handlerBase(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_Sched_InputPorts(),static_cast<AssertArg>(portNum));

    // Call pre-message hook
    Sched_preMsgHook(
        portNum,
        context
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(SCHED_SCHED)
    );
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    _status = msg.serialize(portNum);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    // Serialize argument context
    _status = msg.serialize(context);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

      
    // send message
    Os::Queue::QueueBlocking _block = 
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<AssertArg>(qStatus)
    );      
      
  }

  void SensorDriverComponentBase ::
    PingIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_PingIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Call pre-message hook
    PingIn_preMsgHook(
        portNum,
        key
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(PINGIN_PING)
    );
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    _status = msg.serialize(portNum);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    // Serialize argument key
    _status = msg.serialize(key);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

      
    // send message
    Os::Queue::QueueBlocking _block = 
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<AssertArg>(qStatus)
    );      
      
  }

  // ----------------------------------------------------------------------
  // Pre-message hooks for async input ports
  // ----------------------------------------------------------------------

  void SensorDriverComponentBase ::
    BufferIn_preMsgHook(
        NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    // Default: no-op
  }

  void SensorDriverComponentBase ::
    SpiRead_preMsgHook(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer
    )
  {
    // Default: no-op
  }

  void SensorDriverComponentBase ::
    Sched_preMsgHook(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // Default: no-op
  }

  void SensorDriverComponentBase ::
    PingIn_preMsgHook(
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    // Default: no-op
  }

  // ----------------------------------------------------------------------
  // Message dispatch method for active and queued components. Called
  // by active component thread or implementation code for queued components
  // ----------------------------------------------------------------------

  Fw::QueuedComponentBase::MsgDispatchStatus SensorDriverComponentBase ::
    doDispatch(void)
  {
    ComponentIpcSerializableBuffer msg;
    NATIVE_INT_TYPE priority;

    Os::Queue::QueueStatus msgStatus = this->m_queue.receive(msg,priority,Os::Queue::QUEUE_BLOCKING);
    FW_ASSERT(
        msgStatus == Os::Queue::QUEUE_OK,
        static_cast<AssertArg>(msgStatus)
    );

    // Reset to beginning of buffer
    msg.resetDeser();

    NATIVE_INT_TYPE desMsg;
    Fw::SerializeStatus deserStatus = msg.deserialize(desMsg);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(deserStatus)
    );

    MsgTypeEnum msgType = static_cast<MsgTypeEnum>(desMsg);

    if (msgType == SENSORDRIVER_COMPONENT_EXIT) {
      return MSG_DISPATCH_EXIT;
    }

    NATIVE_INT_TYPE portNum;
    deserStatus = msg.deserialize(portNum);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(deserStatus)
    );

    switch (msgType) {

      // Handle async input port BufferIn
      case BUFFERIN_DATABUFFER: {

        // Deserialize argument buff
        Drv::DataBuffer buff;
        deserStatus = msg.deserialize(buff);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(deserStatus)
        );

        // Call handler function
        this->BufferIn_handler(
            portNum,
            buff
        );

        break;

      }

      // Handle async input port SpiRead
      case SPIREAD_SPIREADWRITE: {

        // Deserialize argument writeBuffer
        Fw::Buffer writeBuffer;
        deserStatus = msg.deserialize(writeBuffer);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(deserStatus)
        );

        // Deserialize argument readBuffer
        Fw::Buffer readBuffer;
        deserStatus = msg.deserialize(readBuffer);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(deserStatus)
        );

        // Call handler function
        this->SpiRead_handler(
            portNum,
            writeBuffer, readBuffer
        );

        break;

      }

      // Handle async input port Sched
      case SCHED_SCHED: {

        // Deserialize argument context
        NATIVE_UINT_TYPE context;
        deserStatus = msg.deserialize(context);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(deserStatus)
        );

        // Call handler function
        this->Sched_handler(
            portNum,
            context
        );

        break;

      }

      // Handle async input port PingIn
      case PINGIN_PING: {

        // Deserialize argument key
        U32 key;
        deserStatus = msg.deserialize(key);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(deserStatus)
        );

        // Call handler function
        this->PingIn_handler(
            portNum,
            key
        );

        break;

      }

      default:
        return MSG_DISPATCH_ERROR;

    }

    return MSG_DISPATCH_OK;

  }

} // end namespace Drv
