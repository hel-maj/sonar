if(DUMPBIN STREQUAL "" OR NOT EXISTS "${DUMPBIN}")
    file(GLOB DUMPBIN_CANDIDATES
        "C:/Program Files/Microsoft Visual Studio/2022/*/VC/Tools/MSVC/*/bin/Hostx64/x64/dumpbin.exe"
        "C:/Program Files (x86)/Microsoft Visual Studio/2022/*/VC/Tools/MSVC/*/bin/Hostx64/x64/dumpbin.exe"
    )
    list(SORT DUMPBIN_CANDIDATES COMPARE NATURAL ORDER DESCENDING)
    list(LENGTH DUMPBIN_CANDIDATES DUMPBIN_COUNT)
    if(DUMPBIN_COUNT EQUAL 0)
        message(FATAL_ERROR "dumpbin.exe was not found")
    endif()
    list(GET DUMPBIN_CANDIDATES 0 DUMPBIN)
endif()

execute_process(
    COMMAND "${DUMPBIN}" /nologo /imports "${TOOL}"
    RESULT_VARIABLE IMPORT_RESULT
    OUTPUT_VARIABLE IMPORTS
    ERROR_VARIABLE IMPORT_ERROR
)
if(NOT IMPORT_RESULT EQUAL 0)
    message(FATAL_ERROR "dumpbin /imports failed: ${IMPORT_ERROR}")
endif()
foreach(FORBIDDEN
        "SendInput"
        "keybd_event"
        "mouse_event"
        "SetCursorPos"
        "WriteProcessMemory"
        "VirtualProtectEx"
        "VirtualAllocEx"
        "CreateRemoteThread"
        "SetForegroundWindow"
        "SendMessageA"
        "SendMessageW"
        "PostMessageA"
        "PostMessageW"
        "BitBlt"
        "PrintWindow"
        "GetDC"
        "GetWindowDC"
        "SetLayeredWindowAttributes"
        "UpdateLayeredWindow")
    string(REGEX MATCH "(^|[\r\n])[ \t]*${FORBIDDEN}[ \t]*([\r\n]|$)"
        FOUND "${IMPORTS}")
    if(NOT FOUND STREQUAL "")
        message(FATAL_ERROR "Diagnostic probe imports forbidden API: ${FORBIDDEN}")
    endif()
endforeach()

execute_process(
    COMMAND "${DUMPBIN}" /nologo /dependents "${TOOL}"
    RESULT_VARIABLE DEPENDENCY_RESULT
    OUTPUT_VARIABLE DEPENDENCIES
    ERROR_VARIABLE DEPENDENCY_ERROR
)
if(NOT DEPENDENCY_RESULT EQUAL 0)
    message(FATAL_ERROR "dumpbin /dependents failed: ${DEPENDENCY_ERROR}")
endif()
foreach(FORBIDDEN "WS2_32.dll" "WINHTTP.dll" "WININET.dll" "URLMON.dll")
    string(TOUPPER "${DEPENDENCIES}" UPPER_DEPENDENCIES)
    string(TOUPPER "${FORBIDDEN}" UPPER_FORBIDDEN)
    string(FIND "${UPPER_DEPENDENCIES}" "${UPPER_FORBIDDEN}" FOUND_AT)
    if(NOT FOUND_AT EQUAL -1)
        message(FATAL_ERROR "Diagnostic probe links forbidden network library: ${FORBIDDEN}")
    endif()
endforeach()
