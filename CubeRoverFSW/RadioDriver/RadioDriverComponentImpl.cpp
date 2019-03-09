// ====================================================================== 
// \title  RadioDriverImpl.cpp
// \author erynqian
// \brief  cpp file for RadioDriver component implementation class
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


#include <CubeRoverFSW/RadioDriver/RadioDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction 
  // ----------------------------------------------------------------------

  RadioDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    RadioDriverComponentImpl(
        const char *const compName
    ) :
      RadioDriverComponentBase(compName)
#else
    RadioDriverImpl(void)
#endif
  {

  }

  void RadioDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    ) 
  {
    RadioDriverComponentBase::init(queueDepth, instance);
  }

  RadioDriverComponentImpl ::
    ~RadioDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void RadioDriverComponentImpl ::
    serialRcv_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &serBuffer,
        SerialReadStatus &status
    )
  {
    // TODO
  }

  void RadioDriverComponentImpl ::
    BufferIn_handler(
        const NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    // TODO
  }

  void RadioDriverComponentImpl ::
    Sched_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
  }

  void RadioDriverComponentImpl ::
    PingIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    // TODO
  }

} // end namespace Drv
