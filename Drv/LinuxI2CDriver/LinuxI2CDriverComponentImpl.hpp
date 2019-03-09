// ====================================================================== 
// \title  LinuxI2CDriverImpl.hpp
// \author erynqian
// \brief  hpp file for LinuxI2CDriver component implementation class
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

#ifndef LinuxI2CDriver_HPP
#define LinuxI2CDriver_HPP

#include "Drv/LinuxI2CDriver/LinuxI2CDriverComponentAc.hpp"

namespace Drv {

  class LinuxI2CDriverComponentImpl :
    public LinuxI2CDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object LinuxI2CDriver
      //!
      LinuxI2CDriverComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object LinuxI2CDriver
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object LinuxI2CDriver
      //!
      ~LinuxI2CDriverComponentImpl(void);


    };

} // end namespace Drv

#endif
