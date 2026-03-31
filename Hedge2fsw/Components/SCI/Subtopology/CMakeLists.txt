add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SubtopologyConfig/")

register_fprime_module(
    AUTOCODER_INPUTS
        "${CMAKE_CURRENT_LIST_DIR}/Subtopology.fpp"
    HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/PingEntries.hpp"
    DEPENDS
        SubtopologyConfig
    INTERFACE
)