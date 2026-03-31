#ifndef SUBTOPOLOGY_DEFS_HPP
#define SUBTOPOLOGY_DEFS_HPP

namespace Subtopology {
    struct SubtopologyState {
        /* include any variables that are needed for 
        configuring/starting/tearing down the topology */
    };
    struct TopologyState {
        SubtopologyState Subtopology_state;
    };
}

#endif