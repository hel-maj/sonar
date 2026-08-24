file(GLOB_RECURSE PROBE_SOURCES
    "${SOURCE_ROOT}/src/*.cpp"
    "${SOURCE_ROOT}/src/*.h"
    "${SOURCE_ROOT}/include/*.h"
)
foreach(SOURCE IN LISTS PROBE_SOURCES)
    file(READ "${SOURCE}" CONTENT)
    foreach(FORBIDDEN
            "SendInput"
            "keybd_event"
            "mouse_event"
            "SetCursorPos"
            "WriteProcessMemory"
            "PROCESS_VM_WRITE"
            "PROCESS_VM_OPERATION"
            "VirtualProtectEx"
            "VirtualAllocEx"
            "CreateRemoteThread"
            "SetForegroundWindow"
            "SendMessage"
            "PostMessage"
            "platform_input"
            "automation_lease"
            "mutation_sink"
            "platform_capture"
            "fishing_stage_detector"
            "overlay")
        string(FIND "${CONTENT}" "${FORBIDDEN}" POSITION)
        if(NOT POSITION EQUAL -1)
            message(FATAL_ERROR
                "Compatibility probe source contains forbidden capability '${FORBIDDEN}': ${SOURCE}")
        endif()
    endforeach()
endforeach()
