module XBee {

    # XBee Radio Integration
    instance comMgr: XBee.XBeeManager base id XBee.BASE_ID + 0x1000 \
        queue size Components.QUEUE_SIZE \
        stack size Components.STACK_SIZE \
        priority 140


    topology Subtopology {
        instance bufferManager

        connections XBee {
            # Buffer allocations
            comDriver.allocate      -> bufferManager.bufferGetCallee
            comDriver.deallocate    -> bufferManager.bufferSendIn
        }
    }
}
