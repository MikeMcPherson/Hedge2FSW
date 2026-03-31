module Components {
    @ Manager component to receive and process data from Science PCB
    active component SCI {

        @ Return the number of science samples collected by the SCI
        async command REPORT_SCICOUNT(param_name: U32)
        @ Return the samples per second parameter
        async command REPORT_SPS(param_name: U32)
        @ Set the samples per second parameter
        async command SET_SPS(param_name: U32, param_value: U32)

        @ Number of bytes in buffer received from the SCI PCB
        telemetry sciBufferSize: U32
        @ SCI sample count
        telemetry sciCount: U64
        @ SCI science data timestamp
        telemetry sciTimeStamp: U32
        @ SCI science data temperatures
        telemetry sciTemp1: F32
        telemetry sciTemp2: F32
        telemetry sciTemp3: F32
        telemetry sciTemp4: F32
        @ SCI science data pressures
        telemetry sciPress1: F32
        telemetry sciPress2: F32
        telemetry sciPress3: F32
        telemetry sciPress4: F32
        @ SCI housekeeping temperatures
        telemetry sciHkTemp1: F32
        telemetry sciHkTemp2: F32
        telemetry sciHkTemp3: F32
        telemetry sciHkTemp4: F32
        @ SCI housekeeping voltages
        telemetry sciHkVolt1: F32
        telemetry sciHkVolt2: F32
        telemetry sciHkVolt3: F32
        telemetry sciHkVolt4: F32
        telemetry sciHkVolt5: F32
        telemetry sciHkVolt6: F32
        @ SCI housekeeping currents
        telemetry sciHkCurr1: F32
        telemetry sciHkCurr2: F32
        telemetry sciHkCurr3: F32
        telemetry sciHkCurr4: F32
        telemetry sciHkCurr5: F32
        telemetry sciHkCurr6: F32
        @ SCI housekeeping INA temperatures
        telemetry sciHkInaTemp1: F32
        telemetry sciHkInaTemp2: F32
        telemetry sciHkInaTemp3: F32
        telemetry sciHkInaTemp4: F32
        telemetry sciHkInaTemp5: F32
        telemetry sciHkInaTemp6: F32

        @ Samples per second changed
        event SpsChanged(SAMPLES_PER_SECOND: U32) severity activity high id 0 format "Samples per second changed to {}"

        @ Samples per second parameter
        param SAMPLES_PER_SECOND: F32

        @ Port to receive Science data
        async input port SciRecv: Drv.ByteStreamData
        @ Port to return buffers for deallocation
        output port deallocate: Fw.BufferSend
        @ Port to set the RS-485 DE/RE pin
        output port gpioSet: Drv.GpioWrite

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Enables command handling
        import Fw.Command

        @ Enables event handling
        import Fw.Event

        @ Enables telemetry channels handling
        import Fw.Channel

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}