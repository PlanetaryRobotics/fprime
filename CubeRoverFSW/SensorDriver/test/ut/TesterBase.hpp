// ======================================================================
// \title  SensorDriver/test/ut/TesterBase.hpp
// \author Auto-generated
// \brief  hpp file for SensorDriver component test harness base class
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

#ifndef SensorDriver_TESTER_BASE_HPP
#define SensorDriver_TESTER_BASE_HPP

#include <CubeRoverFSW/SensorDriver/SensorDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <stdio.h>
#include <Fw/Port/InputSerializePort.hpp>

namespace Drv {

  //! \class SensorDriverTesterBase
  //! \brief Auto-generated base class for SensorDriver component test harness
  //!
  class SensorDriverTesterBase :
    public Fw::PassiveComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Initialization
      // ----------------------------------------------------------------------

      //! Initialize object SensorDriverTesterBase
      //!
      virtual void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

    public:

      // ----------------------------------------------------------------------
      // Connectors for 'to' ports
      // Connect these output ports to the input ports under test
      // ----------------------------------------------------------------------

      //! Connect BufferIn to to_BufferIn[portNum]
      //!
      void connect_to_BufferIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Drv::InputDataBufferPort *const BufferIn /*!< The port*/
      );

      //! Connect SpiRead to to_SpiRead[portNum]
      //!
      void connect_to_SpiRead(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Drv::InputSpiReadWritePort *const SpiRead /*!< The port*/
      );

      //! Connect Sched to to_Sched[portNum]
      //!
      void connect_to_Sched(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::InputSchedPort *const Sched /*!< The port*/
      );

      //! Connect PingIn to to_PingIn[portNum]
      //!
      void connect_to_PingIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::InputPingPort *const PingIn /*!< The port*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for 'from' ports
      // Connect these input ports to the output ports under test
      // ----------------------------------------------------------------------

      //! Get the port that receives input from PingOut
      //!
      //! \return from_PingOut[portNum]
      //!
      Svc::InputPingPort* get_from_PingOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from BufferOut
      //!
      //! \return from_BufferOut[portNum]
      //!
      Drv::InputDataBufferPort* get_from_BufferOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Tlm
      //!
      //! \return from_Tlm[portNum]
      //!
      Fw::InputTlmPort* get_from_Tlm(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from SpiWrite
      //!
      //! \return from_SpiWrite[portNum]
      //!
      Drv::InputSpiReadWritePort* get_from_SpiWrite(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from CycleOut
      //!
      //! \return from_CycleOut[portNum]
      //!
      Svc::InputCyclePort* get_from_CycleOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Time
      //!
      //! \return from_Time[portNum]
      //!
      Fw::InputTimePort* get_from_Time(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Time
      //!
      //! \return from_Time[portNum]
      //!
      Fw::InputTimePort* get_from_Time(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Log
      //!
      //! \return from_Log[portNum]
      //!
      Fw::InputLogPort* get_from_Log(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the port that receives input from LogText
      //!
      //! \return from_LogText[portNum]
      //!
      Fw::InputLogTextPort* get_from_LogText(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );
#endif

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object SensorDriverTesterBase
      //!
      SensorDriverTesterBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object SensorDriverTesterBase
      //!
      virtual ~SensorDriverTesterBase(void);

      // ----------------------------------------------------------------------
      // Test history
      // ----------------------------------------------------------------------

    protected:

      //! \class History
      //! \brief A history of port inputs
      //!
      template <typename T> class History {

        public:

          //! Create a History
          //!
          History(
              const U32 maxSize /*!< The maximum history size*/
          ) : 
              numEntries(0), 
              maxSize(maxSize) 
          { 
            this->entries = new T[maxSize];
          }

          //! Destroy a History
          //!
          ~History() {
            delete[] this->entries;
          }

          //! Clear the history
          //!
          void clear() { this->numEntries = 0; }

          //! Push an item onto the history
          //!
          void push_back(
              T entry /*!< The item*/
          ) {
            FW_ASSERT(this->numEntries < this->maxSize);
            entries[this->numEntries++] = entry;
          }

          //! Get an item at an index
          //!
          //! \return The item at index i
          //!
          T at(
              const U32 i /*!< The index*/
          ) const {
            FW_ASSERT(i < this->numEntries);
            return entries[i];
          }

          //! Get the number of entries in the history
          //!
          //! \return The number of entries in the history
          //!
          U32 size(void) const { return this->numEntries; }

        private:

          //! The number of entries in the history
          //!
          U32 numEntries;

          //! The maximum history size
          //!
          const U32 maxSize;

          //! The entries
          //!
          T *entries;

      };

      //! Clear all history
      //!
      void clearHistory(void);

    protected:

      // ----------------------------------------------------------------------
      // Handler prototypes for typed from ports
      // ----------------------------------------------------------------------

      //! Handler prototype for from_PingOut
      //!
      virtual void from_PingOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      ) = 0;

      //! Handler base function for from_PingOut
      //!
      void from_PingOut_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      );

      //! Handler prototype for from_BufferOut
      //!
      virtual void from_BufferOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Drv::DataBuffer &buff /*!< A data buffer*/
      ) = 0;

      //! Handler base function for from_BufferOut
      //!
      void from_BufferOut_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Drv::DataBuffer &buff /*!< A data buffer*/
      );

      //! Handler prototype for from_Tlm
      //!
      virtual void from_Tlm_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwChanIdType id, /*!< Telemetry Channel ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
      ) = 0;

      //! Handler base function for from_Tlm
      //!
      void from_Tlm_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwChanIdType id, /*!< Telemetry Channel ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
      );

      //! Handler prototype for from_SpiWrite
      //!
      virtual void from_SpiWrite_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &writeBuffer, 
          Fw::Buffer &readBuffer 
      ) = 0;

      //! Handler base function for from_SpiWrite
      //!
      void from_SpiWrite_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &writeBuffer, 
          Fw::Buffer &readBuffer 
      );

      //! Handler prototype for from_CycleOut
      //!
      virtual void from_CycleOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::TimerVal &cycleStart /*!< Cycle start timer value*/
      ) = 0;

      //! Handler base function for from_CycleOut
      //!
      void from_CycleOut_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::TimerVal &cycleStart /*!< Cycle start timer value*/
      );

      //! Handler prototype for from_Time
      //!
      virtual void from_Time_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      ) = 0;

      //! Handler base function for from_Time
      //!
      void from_Time_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Histories for typed from ports
      // ----------------------------------------------------------------------

      //! Clear from port history
      //!
      void clearFromPortHistory(void);

      //! The total number of from port entries
      //!
      U32 fromPortHistorySize;

      //! Push an entry on the history for from_PingOut
      void pushFromPortEntry_PingOut(
          U32 key /*!< Value to return to pinger*/
      );

      //! A history entry for from_PingOut
      //!
      typedef struct {
        U32 key;
      } FromPortEntry_PingOut;

      //! The history for from_PingOut
      //!
      History<FromPortEntry_PingOut> 
        *fromPortHistory_PingOut;

      //! Push an entry on the history for from_BufferOut
      void pushFromPortEntry_BufferOut(
          Drv::DataBuffer &buff /*!< A data buffer*/
      );

      //! A history entry for from_BufferOut
      //!
      typedef struct {
        Drv::DataBuffer buff;
      } FromPortEntry_BufferOut;

      //! The history for from_BufferOut
      //!
      History<FromPortEntry_BufferOut> 
        *fromPortHistory_BufferOut;

      //! Push an entry on the history for from_Tlm
      void pushFromPortEntry_Tlm(
          FwChanIdType id, /*!< Telemetry Channel ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
      );

      //! A history entry for from_Tlm
      //!
      typedef struct {
        FwChanIdType id;
        Fw::Time timeTag;
        Fw::TlmBuffer val;
      } FromPortEntry_Tlm;

      //! The history for from_Tlm
      //!
      History<FromPortEntry_Tlm> 
        *fromPortHistory_Tlm;

      //! Push an entry on the history for from_SpiWrite
      void pushFromPortEntry_SpiWrite(
          Fw::Buffer &writeBuffer, 
          Fw::Buffer &readBuffer 
      );

      //! A history entry for from_SpiWrite
      //!
      typedef struct {
        Fw::Buffer writeBuffer;
        Fw::Buffer readBuffer;
      } FromPortEntry_SpiWrite;

      //! The history for from_SpiWrite
      //!
      History<FromPortEntry_SpiWrite> 
        *fromPortHistory_SpiWrite;

      //! Push an entry on the history for from_CycleOut
      void pushFromPortEntry_CycleOut(
          Svc::TimerVal &cycleStart /*!< Cycle start timer value*/
      );

      //! A history entry for from_CycleOut
      //!
      typedef struct {
        Svc::TimerVal cycleStart;
      } FromPortEntry_CycleOut;

      //! The history for from_CycleOut
      //!
      History<FromPortEntry_CycleOut> 
        *fromPortHistory_CycleOut;

      //! Push an entry on the history for from_Time
      void pushFromPortEntry_Time(
          Fw::Time &time /*!< The U32 cmd argument*/
      );

      //! A history entry for from_Time
      //!
      typedef struct {
        Fw::Time time;
      } FromPortEntry_Time;

      //! The history for from_Time
      //!
      History<FromPortEntry_Time> 
        *fromPortHistory_Time;

    protected:

      // ----------------------------------------------------------------------
      // Invocation functions for to ports
      // ----------------------------------------------------------------------

      //! Invoke the to port connected to BufferIn
      //!
      void invoke_to_BufferIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Drv::DataBuffer &buff /*!< A data buffer*/
      );

      //! Invoke the to port connected to SpiRead
      //!
      void invoke_to_SpiRead(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &writeBuffer, 
          Fw::Buffer &readBuffer 
      );

      //! Invoke the to port connected to Sched
      //!
      void invoke_to_Sched(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

      //! Invoke the to port connected to PingIn
      //!
      void invoke_to_PingIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for port counts
      // ----------------------------------------------------------------------

      //! Get the number of from_PingOut ports
      //!
      //! \return The number of from_PingOut ports
      //!
      NATIVE_INT_TYPE getNum_from_PingOut(void) const;

      //! Get the number of from_BufferOut ports
      //!
      //! \return The number of from_BufferOut ports
      //!
      NATIVE_INT_TYPE getNum_from_BufferOut(void) const;

      //! Get the number of to_BufferIn ports
      //!
      //! \return The number of to_BufferIn ports
      //!
      NATIVE_INT_TYPE getNum_to_BufferIn(void) const;

      //! Get the number of from_Tlm ports
      //!
      //! \return The number of from_Tlm ports
      //!
      NATIVE_INT_TYPE getNum_from_Tlm(void) const;

      //! Get the number of to_SpiRead ports
      //!
      //! \return The number of to_SpiRead ports
      //!
      NATIVE_INT_TYPE getNum_to_SpiRead(void) const;

      //! Get the number of from_SpiWrite ports
      //!
      //! \return The number of from_SpiWrite ports
      //!
      NATIVE_INT_TYPE getNum_from_SpiWrite(void) const;

      //! Get the number of to_Sched ports
      //!
      //! \return The number of to_Sched ports
      //!
      NATIVE_INT_TYPE getNum_to_Sched(void) const;

      //! Get the number of from_CycleOut ports
      //!
      //! \return The number of from_CycleOut ports
      //!
      NATIVE_INT_TYPE getNum_from_CycleOut(void) const;

      //! Get the number of to_PingIn ports
      //!
      //! \return The number of to_PingIn ports
      //!
      NATIVE_INT_TYPE getNum_to_PingIn(void) const;

      //! Get the number of from_Time ports
      //!
      //! \return The number of from_Time ports
      //!
      NATIVE_INT_TYPE getNum_from_Time(void) const;

      //! Get the number of from_Time ports
      //!
      //! \return The number of from_Time ports
      //!
      NATIVE_INT_TYPE getNum_from_Time(void) const;

      //! Get the number of from_Log ports
      //!
      //! \return The number of from_Log ports
      //!
      NATIVE_INT_TYPE getNum_from_Log(void) const;

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the number of from_LogText ports
      //!
      //! \return The number of from_LogText ports
      //!
      NATIVE_INT_TYPE getNum_from_LogText(void) const;
#endif

    protected:

      // ----------------------------------------------------------------------
      // Connection status for to ports
      // ----------------------------------------------------------------------

      //! Check whether port is connected
      //!
      //! Whether to_BufferIn[portNum] is connected
      //!
      bool isConnected_to_BufferIn(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_SpiRead[portNum] is connected
      //!
      bool isConnected_to_SpiRead(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_Sched[portNum] is connected
      //!
      bool isConnected_to_Sched(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_PingIn[portNum] is connected
      //!
      bool isConnected_to_PingIn(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Event dispatch
      // ----------------------------------------------------------------------

      //! Dispatch an event
      //!
      void dispatchEvents(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::LogSeverity severity, /*!< The severity*/
          Fw::LogBuffer& args /*!< The serialized arguments*/
      );

      //! Clear event history
      //!
      void clearEvents(void);

      //! The total number of events seen
      //!
      U32 eventsSize;

#if FW_ENABLE_TEXT_LOGGING

    protected:

      // ----------------------------------------------------------------------
      // Text events
      // ----------------------------------------------------------------------

      //! Handle a text event
      //!
      virtual void textLogIn(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::TextLogSeverity severity, /*!< The severity*/
          const Fw::TextLogString& text /*!< The event string*/
      );

      //! A history entry for the text log
      //!
      typedef struct {
        U32 id;
        Fw::Time timeTag;
        Fw::TextLogSeverity severity;
        Fw::TextLogString text;
      } TextLogEntry;

      //! The history of text log events
      //!
      History<TextLogEntry> *textLogHistory;

      //! Print a text log history entry
      //!
      static void printTextLogHistoryEntry(
          const TextLogEntry& e,
          FILE* file
      );

      //! Print the text log history
      //!
      void printTextLogHistory(FILE *const file);

#endif

    protected:

      // ----------------------------------------------------------------------
      // Event: TILT_LIMIT_REACHED
      // ----------------------------------------------------------------------

      //! Handle event TILT_LIMIT_REACHED
      //!
      virtual void logIn_ACTIVITY_HI_TILT_LIMIT_REACHED(
          F32 pitch, /*!< current pitch*/
          F32 roll, /*!< current roll*/
          F32 yaw /*!< current yaw*/
      );

      //! A history entry for event TILT_LIMIT_REACHED
      //!
      typedef struct {
        F32 pitch;
        F32 roll;
        F32 yaw;
      } EventEntry_TILT_LIMIT_REACHED;

      //! The history of TILT_LIMIT_REACHED events
      //!
      History<EventEntry_TILT_LIMIT_REACHED> 
        *eventHistory_TILT_LIMIT_REACHED;

    protected:

      // ----------------------------------------------------------------------
      // Event: TILT_RATE_LIMIT_REACHED
      // ----------------------------------------------------------------------

      //! Handle event TILT_RATE_LIMIT_REACHED
      //!
      virtual void logIn_ACTIVITY_HI_TILT_RATE_LIMIT_REACHED(
          F32 pitch, /*!< current angular velocity about the x axis*/
          F32 roll, /*!< current angular velocity about the y axis*/
          F32 yaw /*!< current angular velocity about the z axis*/
      );

      //! A history entry for event TILT_RATE_LIMIT_REACHED
      //!
      typedef struct {
        F32 pitch;
        F32 roll;
        F32 yaw;
      } EventEntry_TILT_RATE_LIMIT_REACHED;

      //! The history of TILT_RATE_LIMIT_REACHED events
      //!
      History<EventEntry_TILT_RATE_LIMIT_REACHED> 
        *eventHistory_TILT_RATE_LIMIT_REACHED;

    protected:

      // ----------------------------------------------------------------------
      // Event: ACCEL_INIT_ERROR
      // ----------------------------------------------------------------------

      //! Handle event ACCEL_INIT_ERROR
      //!
      virtual void logIn_ACTIVITY_HI_ACCEL_INIT_ERROR(
          void
      );

      //! Size of history for event ACCEL_INIT_ERROR
      //!
      U32 eventsSize_ACCEL_INIT_ERROR;

    protected:

      // ----------------------------------------------------------------------
      // Event: GYRO_INIT_ERROR
      // ----------------------------------------------------------------------

      //! Handle event GYRO_INIT_ERROR
      //!
      virtual void logIn_ACTIVITY_HI_GYRO_INIT_ERROR(
          void
      );

      //! Size of history for event GYRO_INIT_ERROR
      //!
      U32 eventsSize_GYRO_INIT_ERROR;

    protected:

      // ----------------------------------------------------------------------
      // Event: INVALID_SYSTEM_BUFFER
      // ----------------------------------------------------------------------

      //! Handle event INVALID_SYSTEM_BUFFER
      //!
      virtual void logIn_ACTIVITY_LO_INVALID_SYSTEM_BUFFER(
          int32 signalbyte, /*!< byte that signals which operation to do*/
          int32 rangebyte /*!< byte that denotes what range to choose*/
      );

      //! A history entry for event INVALID_SYSTEM_BUFFER
      //!
      typedef struct {
        int32 signalbyte;
        int32 rangebyte;
      } EventEntry_INVALID_SYSTEM_BUFFER;

      //! The history of INVALID_SYSTEM_BUFFER events
      //!
      History<EventEntry_INVALID_SYSTEM_BUFFER> 
        *eventHistory_INVALID_SYSTEM_BUFFER;

    protected:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Set the test time for events and telemetry
      //!
      void setTestTime(
          const Fw::Time& timeTag /*!< The time*/
      );

    private:

      // ----------------------------------------------------------------------
      // To ports
      // ----------------------------------------------------------------------

      //! To port connected to BufferIn
      //!
      Drv::OutputDataBufferPort m_to_BufferIn[1];

      //! To port connected to SpiRead
      //!
      Drv::OutputSpiReadWritePort m_to_SpiRead[2];

      //! To port connected to Sched
      //!
      Svc::OutputSchedPort m_to_Sched[1];

      //! To port connected to PingIn
      //!
      Svc::OutputPingPort m_to_PingIn[1];

    private:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      //! From port connected to PingOut
      //!
      Svc::InputPingPort m_from_PingOut[1];

      //! From port connected to BufferOut
      //!
      Drv::InputDataBufferPort m_from_BufferOut[1];

      //! From port connected to Tlm
      //!
      Fw::InputTlmPort m_from_Tlm[1];

      //! From port connected to SpiWrite
      //!
      Drv::InputSpiReadWritePort m_from_SpiWrite[2];

      //! From port connected to CycleOut
      //!
      Svc::InputCyclePort m_from_CycleOut[1];

      //! From port connected to Time
      //!
      Fw::InputTimePort m_from_Time[1];

      //! From port connected to Time
      //!
      Fw::InputTimePort m_from_Time[1];

      //! From port connected to Log
      //!
      Fw::InputLogPort m_from_Log[1];

#if FW_ENABLE_TEXT_LOGGING == 1
      //! From port connected to LogText
      //!
      Fw::InputLogTextPort m_from_LogText[1];
#endif

    private:

      // ----------------------------------------------------------------------
      // Static functions for output ports
      // ----------------------------------------------------------------------

      //! Static function for port from_PingOut
      //!
      static void from_PingOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      );

      //! Static function for port from_BufferOut
      //!
      static void from_BufferOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Drv::DataBuffer &buff /*!< A data buffer*/
      );

      //! Static function for port from_Tlm
      //!
      static void from_Tlm_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwChanIdType id, /*!< Telemetry Channel ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
      );

      //! Static function for port from_SpiWrite
      //!
      static void from_SpiWrite_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &writeBuffer, 
          Fw::Buffer &readBuffer 
      );

      //! Static function for port from_CycleOut
      //!
      static void from_CycleOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::TimerVal &cycleStart /*!< Cycle start timer value*/
      );

      //! Static function for port from_Time
      //!
      static void from_Time_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      );

      //! Static function for port from_Time
      //!
      static void from_Time_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      );

      //! Static function for port from_Log
      //!
      static void from_Log_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::LogSeverity severity, /*!< The severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Static function for port from_LogText
      //!
      static void from_LogText_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TextLogSeverity severity, /*!< The severity argument*/
          Fw::TextLogString &text /*!< Text of log message*/
      );
#endif

    private:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Test time stamp
      //!
      Fw::Time m_testTime;

  };

} // end namespace Drv

#endif
