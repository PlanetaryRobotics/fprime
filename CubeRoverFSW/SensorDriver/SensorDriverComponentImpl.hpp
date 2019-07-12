// ====================================================================== 
// \title  SensorDriverImpl.hpp
// \author sisyphuslaetus
// \brief  hpp file for SensorDriver component implementation class
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

#ifndef SensorDriver_HPP
#define SensorDriver_HPP

#include "CubeRoverFSW/SensorDriver/SensorDriverComponentAc.hpp"

namespace Drv {

  class SensorDriverComponentImpl :
    public SensorDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object SensorDriver
      //!
      SensorDriverComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object SensorDriver
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object SensorDriver
      //!
      ~SensorDriverComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for BufferIn
      //!
      void BufferIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Drv::DataBuffer &buff /*!< A data buffer*/
      );

      //! Handler implementation for SpiRead
      //!
      void SpiRead_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &writeBuffer,
          Fw::Buffer &readBuffer
      );

      //! Handler implementation for Sched
      //!
      void Sched_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

      //! Handler implementation for PingIn
      //!
      void PingIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      );


    };

} // end namespace Drv

#endif
