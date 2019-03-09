// ====================================================================== 
// \title  CameraDriverImpl.cpp
// \author erynqian
// \brief  cpp file for CameraDriver component implementation class
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


#include <CubeRoverFSW/CameraDriver/CameraDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction 
  // ----------------------------------------------------------------------

  CameraDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    CameraDriverComponentImpl(
        const char *const compName
    ) :
      CameraDriverComponentBase(compName)
#else
    CameraDriverImpl(void)
#endif
  {

  }

  void CameraDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    ) 
  {
    CameraDriverComponentBase::init(queueDepth, instance);
  }

  CameraDriverComponentImpl ::
    ~CameraDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void CameraDriverComponentImpl ::
    BufferIn_handler(
        const NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    // TODO
  }

  void CameraDriverComponentImpl ::
    Sched_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
  }

  void CameraDriverComponentImpl ::
    PingIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    // TODO
  }

} // end namespace Drv
