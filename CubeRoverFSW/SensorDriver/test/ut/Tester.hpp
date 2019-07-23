// ======================================================================
// \title  SensorDriver/test/ut/Tester.hpp
// \author sisyphuslaetus
// \brief  hpp file for SensorDriver test harness implementation class
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

#ifndef TESTER_HPP
#define TESTER_HPP

#include "GTestBase.hpp"
#include "CubeRoverFSW/SensorDriver/SensorDriverComponentImpl.hpp"

namespace Drv {

  class Tester :
    public SensorDriverGTestBase
  {

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

    public:

      //! Construct object Tester
      //!
      Tester(void);

      //! Destroy object Tester
      //!
      ~Tester(void);

    public:

      // ----------------------------------------------------------------------
      // Tests
      // ----------------------------------------------------------------------

      //! To do
      //!
      void testTipOver(void);
      void testTipRate(void);
      void testSignal(void);
      void testRange(void);
      void testAccelInit(void);
      void testGyroInit(void);

    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_PingOut
      //!
      void from_PingOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      );

      //! Handler for from_BufferOut
      //!
      void from_BufferOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Drv::DataBuffer &buff /*!< A data buffer*/
      );

      //! Handler for from_Tlm
      //!
      void from_Tlm_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwChanIdType id, /*!< Telemetry Channel ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
      );

      //! Handler for from_SpiWrite
      //!
      void from_SpiWrite_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &writeBuffer,
          Fw::Buffer &readBuffer
      );

      //! Handler for from_CycleOut
      //!
      void from_CycleOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::TimerVal &cycleStart /*!< Cycle start timer value*/
      );

      //! Handler for from_Time
      //!
      void from_Time_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      );

    private:

      // ----------------------------------------------------------------------
      // Helper methods
      // ----------------------------------------------------------------------

      //! Connect ports
      //!
      void connectPorts(void);

      //! Initialize components
      //!
      void initComponents(void);

    private:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      SensorDriverComponentImpl component;

  };

} // end namespace Drv

#endif
