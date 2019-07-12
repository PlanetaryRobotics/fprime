// ====================================================================== 
// \title  SensorDriverComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for SensorDriver component base class
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

#ifndef SENSORDRIVER_COMP_HPP_
#define SENSORDRIVER_COMP_HPP_

#include <Fw/Cfg/Config.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Drv/DataTypes/DataBuffer.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Svc/Cycle/TimerVal.hpp>
#include <Svc/Ping/PingPortAc.hpp>
#include <Drv/DataTypes/DataBufferPortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Drv/SpiDriverPorts/SpiReadWritePortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>
#include <Svc/Cycle/CyclePortAc.hpp>
#include <Fw/Time/TimePortAc.hpp>

namespace Drv {

  //! \class SensorDriverComponentBase
  //! \brief Auto-generated base for SensorDriver component
  //!
  class SensorDriverComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class SensorDriverComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return BufferIn[portNum]
    //!
    Drv::InputDataBufferPort* get_BufferIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return SpiRead[portNum]
    //!
    Drv::InputSpiReadWritePort* get_SpiRead_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return Sched[portNum]
    //!
    Svc::InputSchedPort* get_Sched_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return PingIn[portNum]
    //!
    Svc::InputPingPort* get_PingIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to PingOut[portNum]
    //!
    void set_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputPingPort *port /*!< The port*/
    );

    //! Connect port to BufferOut[portNum]
    //!
    void set_BufferOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputDataBufferPort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTlmPort *port /*!< The port*/
    );

    //! Connect port to SpiWrite[portNum]
    //!
    void set_SpiWrite_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputSpiReadWritePort *port /*!< The port*/
    );

    //! Connect port to CycleOut[portNum]
    //!
    void set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputCyclePort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to PingOut[portNum]
    //!
    void set_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to BufferOut[portNum]
    //!
    void set_BufferOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to SpiWrite[portNum]
    //!
    void set_SpiWrite_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to CycleOut[portNum]
    //!
    void set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

#if FW_OBJECT_NAMES == 1
    //! Construct a SensorDriverComponentBase object
    //!
    SensorDriverComponentBase(
        const char* compName /*!< Component name*/
    );
#else
    //! Construct a SensorDriverComponentBase object
    //!
    SensorDriverComponentBase(void);
#endif

    //! Initialize a SensorDriverComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a SensorDriverComponentBase object
    //!
    virtual ~SensorDriverComponentBase(void);

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port BufferIn
    //
    virtual void BufferIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::DataBuffer &buff /*!< A data buffer*/
    ) = 0;

    //! Handler for input port SpiRead
    //
    virtual void SpiRead_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &writeBuffer, 
        Fw::Buffer &readBuffer 
    ) = 0;

    //! Handler for input port Sched
    //
    virtual void Sched_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    ) = 0;

    //! Handler for input port PingIn
    //
    virtual void PingIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< Value to return to pinger*/
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port BufferIn
    //!
    void BufferIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::DataBuffer &buff /*!< A data buffer*/
    );

    //! Handler base-class function for input port SpiRead
    //!
    void SpiRead_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &writeBuffer, 
        Fw::Buffer &readBuffer 
    );

    //! Handler base-class function for input port Sched
    //!
    void Sched_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    );

    //! Handler base-class function for input port PingIn
    //!
    void PingIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< Value to return to pinger*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for typed async input ports.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port BufferIn
    //!
    virtual void BufferIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::DataBuffer &buff /*!< A data buffer*/
    );

    //! Pre-message hook for async input port SpiRead
    //!
    virtual void SpiRead_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &writeBuffer, 
        Fw::Buffer &readBuffer 
    );

    //! Pre-message hook for async input port Sched
    //!
    virtual void Sched_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    );

    //! Pre-message hook for async input port PingIn
    //!
    virtual void PingIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< Value to return to pinger*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port PingOut
    //!
    void PingOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< Value to return to pinger*/
    );

    //! Invoke output port BufferOut
    //!
    void BufferOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::DataBuffer &buff /*!< A data buffer*/
    );

    //! Invoke output port Tlm
    //!
    void Tlm_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwChanIdType id, /*!< Telemetry Channel ID*/
        Fw::Time &timeTag, /*!< Time Tag*/
        Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
    );

    //! Invoke output port SpiWrite
    //!
    void SpiWrite_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &writeBuffer, 
        Fw::Buffer &readBuffer 
    );

    //! Invoke output port CycleOut
    //!
    void CycleOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< Cycle start timer value*/
    );

    //! Invoke output port Time
    //!
    void Time_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Time &time /*!< The U32 cmd argument*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of BufferIn input ports
    //!
    //! \return The number of BufferIn input ports
    //!
    NATIVE_INT_TYPE getNum_BufferIn_InputPorts(void);

    //! Get the number of SpiRead input ports
    //!
    //! \return The number of SpiRead input ports
    //!
    NATIVE_INT_TYPE getNum_SpiRead_InputPorts(void);

    //! Get the number of Sched input ports
    //!
    //! \return The number of Sched input ports
    //!
    NATIVE_INT_TYPE getNum_Sched_InputPorts(void);

    //! Get the number of PingIn input ports
    //!
    //! \return The number of PingIn input ports
    //!
    NATIVE_INT_TYPE getNum_PingIn_InputPorts(void);

  
    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------
    
    enum {
       NUM_BUFFERIN_INPUT_PORTS = 1,
       NUM_SPIREAD_INPUT_PORTS = 2,
       NUM_SCHED_INPUT_PORTS = 1,
       NUM_PINGIN_INPUT_PORTS = 1,
    };
  
  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of PingOut output ports
    //!
    //! \return The number of PingOut output ports
    //!
    NATIVE_INT_TYPE getNum_PingOut_OutputPorts(void);

    //! Get the number of BufferOut output ports
    //!
    //! \return The number of BufferOut output ports
    //!
    NATIVE_INT_TYPE getNum_BufferOut_OutputPorts(void);

    //! Get the number of Tlm output ports
    //!
    //! \return The number of Tlm output ports
    //!
    NATIVE_INT_TYPE getNum_Tlm_OutputPorts(void);

    //! Get the number of SpiWrite output ports
    //!
    //! \return The number of SpiWrite output ports
    //!
    NATIVE_INT_TYPE getNum_SpiWrite_OutputPorts(void);

    //! Get the number of CycleOut output ports
    //!
    //! \return The number of CycleOut output ports
    //!
    NATIVE_INT_TYPE getNum_CycleOut_OutputPorts(void);

    //! Get the number of Time output ports
    //!
    //! \return The number of Time output ports
    //!
    NATIVE_INT_TYPE getNum_Time_OutputPorts(void);

  
    enum {
       NUM_PINGOUT_OUTPUT_PORTS = 1,
       NUM_BUFFEROUT_OUTPUT_PORTS = 1,
       NUM_TLM_OUTPUT_PORTS = 1,
       NUM_SPIWRITE_OUTPUT_PORTS = 2,
       NUM_CYCLEOUT_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
    };
  
  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port PingOut is connected
    //!
    //! \return Whether port PingOut is connected
    //!
    bool isConnected_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port BufferOut is connected
    //!
    //! \return Whether port BufferOut is connected
    //!
    bool isConnected_BufferOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Tlm is connected
    //!
    //! \return Whether port Tlm is connected
    //!
    bool isConnected_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port SpiWrite is connected
    //!
    //! \return Whether port SpiWrite is connected
    //!
    bool isConnected_SpiWrite_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port CycleOut is connected
    //!
    //! \return Whether port CycleOut is connected
    //!
    bool isConnected_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Time is connected
    //!
    //! \return Whether port Time is connected
    //!
    bool isConnected_Time_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------


  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port BufferIn
    //!
    Drv::InputDataBufferPort m_BufferIn_InputPort[NUM_BUFFERIN_INPUT_PORTS];

    //! Input port SpiRead
    //!
    Drv::InputSpiReadWritePort m_SpiRead_InputPort[NUM_SPIREAD_INPUT_PORTS];

    //! Input port Sched
    //!
    Svc::InputSchedPort m_Sched_InputPort[NUM_SCHED_INPUT_PORTS];

    //! Input port PingIn
    //!
    Svc::InputPingPort m_PingIn_InputPort[NUM_PINGIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port PingOut
    //!
    Svc::OutputPingPort m_PingOut_OutputPort[NUM_PINGOUT_OUTPUT_PORTS];

    //! Output port BufferOut
    //!
    Drv::OutputDataBufferPort m_BufferOut_OutputPort[NUM_BUFFEROUT_OUTPUT_PORTS];

    //! Output port Tlm
    //!
    Fw::OutputTlmPort m_Tlm_OutputPort[NUM_TLM_OUTPUT_PORTS];

    //! Output port SpiWrite
    //!
    Drv::OutputSpiReadWritePort m_SpiWrite_OutputPort[NUM_SPIWRITE_OUTPUT_PORTS];

    //! Output port CycleOut
    //!
    Svc::OutputCyclePort m_CycleOut_OutputPort[NUM_CYCLEOUT_OUTPUT_PORTS];

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port BufferIn
    //!
    static void m_p_BufferIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::DataBuffer &buff /*!< A data buffer*/
    );

    //! Callback for port SpiRead
    //!
    static void m_p_SpiRead_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &writeBuffer, 
        Fw::Buffer &readBuffer 
    );

    //! Callback for port Sched
    //!
    static void m_p_Sched_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    );

    //! Callback for port PingIn
    //!
    static void m_p_PingIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< Value to return to pinger*/
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Message dispatch functions
    // ----------------------------------------------------------------------

    //! Called in the message loop to dispatch a message from the queue
    //!
    virtual MsgDispatchStatus doDispatch(void);



  };  

} // end namespace Drv
#endif
