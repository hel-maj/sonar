if(NOT DEFINED SOURCE OR NOT EXISTS "${SOURCE}")
    message(FATAL_ERROR "Target resolver source is required")
endif()

file(READ "${SOURCE}" CONTENT)

foreach(FORBIDDEN IN ITEMS
        "#include <Windows.h>"
        "EnumWindows"
        "GetWindowThreadProcessId"
        "IsWindowVisible"
        "collect_window")
    string(FIND "${CONTENT}" "${FORBIDDEN}" POSITION)
    if(NOT POSITION EQUAL -1)
        message(FATAL_ERROR
            "Fishing target resolver duplicates Common window observation: ${FORBIDDEN}")
    endif()
endforeach()

foreach(REQUIRED IN ITEMS
        "readonly_process::find_process_ids"
        "unique_top_level_client_observer")
    string(FIND "${CONTENT}" "${REQUIRED}" POSITION)
    if(POSITION EQUAL -1)
        message(FATAL_ERROR
            "Fishing target resolver does not consume required Common primitive: ${REQUIRED}")
    endif()
endforeach()
