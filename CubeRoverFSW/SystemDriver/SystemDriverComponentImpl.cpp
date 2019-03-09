// ====================================================================== 
// \title  SystemDriverImpl.cpp
// \author erynqian
// \brief  cpp file for SystemDriver component implementation class
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


#include <CubeRoverFSW/SystemDriver/SystemDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction 
  // ----------------------------------------------------------------------

  SystemDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    SystemDriverComponentImpl(
        const char *const compName
    ) :
      SystemDriverComponentBase(compName)
#else
    SystemDriverImpl(void)
#endif
  {

  }

  void SystemDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    ) 
  {
    SystemDriverComponentBase::init(queueDepth, instance);
  }

  SystemDriverComponentImpl ::
    ~SystemDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void SystemDriverComponentImpl ::
    BufferIn_handler(
        const NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    // TODO
  }

  void SystemDriverComponentImpl ::
    Sched_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
  }

  void SystemDriverComponentImpl ::
    PingIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    // TODO
  }

} // end namespace Drv
