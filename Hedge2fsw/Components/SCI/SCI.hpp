// ======================================================================
// \title  SCI.hpp
// \author kq9p
// \brief  hpp file for SCI component implementation class
// ======================================================================

#ifndef Components_SCI_HPP
#define Components_SCI_HPP

#include "Hedge2fsw/Components/SCI/SCIComponentAc.hpp"
#include "Fw/Logger/Logger.hpp"
#include <Drv/LinuxGpioDriver/LinuxGpioDriver.hpp>

namespace Components {

class SCI final : public SCIComponentBase {

  struct SciPacket {
    unsigned int sciTimeStamp;
    float sciTemp1;
    float sciTemp2;
    float sciTemp3;
    float sciTemp4;
    float sciPress1;
    float sciPress2;
    float sciPress3;
    float sciPress4;
    float sciHkTemp1;
    float sciHkTemp2;
    float sciHkTemp3;
    float sciHkTemp4;
    float sciHkVolt1;
    float sciHkVolt2;
    float sciHkVolt3;
    float sciHkVolt4;
    float sciHkVolt5;
    float sciHkVolt6;
    float sciHkCurr1;
    float sciHkCurr2;
    float sciHkCurr3;
    float sciHkCurr4;
    float sciHkCurr5;
    float sciHkCurr6;
    float sciHkInaTemp1;
    float sciHkInaTemp2;
    float sciHkInaTemp3;
    float sciHkInaTemp4;
    float sciHkInaTemp5;
    float sciHkInaTemp6;
  } m_sciPacket;

  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct SCI object
    SCI(const char* const compName  //!< The component name
    );

    //! Destroy SCI object
    ~SCI();

  private:

    char m_dataBuffer[sizeof(SciPacket)];
    U32 m_sciCount = 0;
    U32 m_bufferSize = 0;
    F32 m_sps = 0.0;

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for SciRecv
    //!
    //! Port to receive Science data
    void SciRecv_handler(FwIndexType portNum,  //!< The port number
                         Fw::Buffer& buffer,
                         const Drv::ByteStreamStatus& status) override;

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command REPORT_SCICOUNT
    //!
    //! Return the number of science samples collected by the SCI
    void REPORT_SCICOUNT_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                                    U32 cmdSeq,           //!< The command sequence number
                                    U32 param_name) override;

    //! Handler implementation for command REPORT_SPS
    //!
    //! Return the samples per second parameter
    void REPORT_SPS_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                               U32 cmdSeq,           //!< The command sequence number
                               U32 param_name) override;

    //! Handler implementation for command SET_SPS
    //!
    //! Set the samples per second parameter
    void SET_SPS_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                            U32 cmdSeq,           //!< The command sequence number
                            U32 param_name,
                            U32 param_value) override;
};

}  // namespace Components

#endif
