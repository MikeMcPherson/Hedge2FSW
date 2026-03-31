// ======================================================================
// \title  SCI.cpp
// \author kq9p
// \brief  cpp file for SCI component implementation class
// ======================================================================

#include "Hedge2fsw/Components/SCI/SCI.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

SCI ::SCI(const char* const compName) : SCIComponentBase(compName) {
    // this->gpioSet_out(0, Fw::Logic::LOW);
}

SCI ::~SCI() {}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void SCI ::SciRecv_handler(FwIndexType portNum, Fw::Buffer& buffer, const Drv::ByteStreamStatus& status) {
    // Check the receive status
    if(status == Drv::ByteStreamStatus::RECV_NO_DATA)
    {
      // Handle no data case
      Fw::Logger::log("No data received on port %d\n", portNum);
      this->deallocate_out(0, buffer);// Return the buffer to the deallocate port
      return;
    } else if(status != Drv::ByteStreamStatus::OP_OK)
    {
      // Handle error case
      Fw::Logger::log("Receive error on port %d, status: %d\n", portNum, status);
      this->deallocate_out(0, buffer);// Return the buffer to the deallocate port
      return;
    }
    m_bufferSize = buffer.getSize();// How many bytes were received?
    this->tlmWrite_sciBufferSize(m_bufferSize);// Write the buffer size to telemetry
    char* m_data_pointer = reinterpret_cast<char*>(buffer.getData());// Get the data pointer from the buffer
    m_sciCount++;// Increment the science sample count
    this->tlmWrite_sciCount(m_sciCount);// Write the science sample count to telemetry
    // Return the buffer to the deallocate port
    this->deallocate_out(0, buffer);
}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void SCI ::REPORT_SCICOUNT_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, U32 param_name) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void SCI ::REPORT_SPS_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, U32 param_name) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void SCI ::SET_SPS_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, U32 param_name, U32 param_value) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace Components
