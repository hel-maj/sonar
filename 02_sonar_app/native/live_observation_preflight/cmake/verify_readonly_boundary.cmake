set(SOURCES
    "${SOURCE_ROOT}/include/sonar/fishing/live_observation_preflight/live_observation_preflight.h"
    "${SOURCE_ROOT}/src/live_observation_preflight.cpp"
    "${SOURCE_ROOT}/src/windows_observation_port.h"
    "${SOURCE_ROOT}/src/windows_observation_port.cpp"
    "${SOURCE_ROOT}/src/main.cpp"
)
set(FORBIDDEN_PATTERNS
    "platform_input"
    "automation_lease"
    "mutation_sink"
    "SendInput"
    "keybd_event"
    "mouse_event"
    "SetCursorPos"
    "SetForegroundWindow"
    "OpenClipboard"
)
foreach(SOURCE IN LISTS SOURCES)
    if(NOT EXISTS "${SOURCE}")
        message(FATAL_ERROR "live_preflight_source_missing:${SOURCE}")
    endif()
    file(READ "${SOURCE}" CONTENT)
    foreach(PATTERN IN LISTS FORBIDDEN_PATTERNS)
        string(FIND "${CONTENT}" "${PATTERN}" OFFSET)
        if(NOT OFFSET EQUAL -1)
            message(FATAL_ERROR
                "live_preflight_mutation_boundary_violation:${SOURCE}:${PATTERN}")
        endif()
    endforeach()
endforeach()
