if(NOT EXISTS "${TOOL}")
    message(FATAL_ERROR "live_preflight_tool_missing:${TOOL}")
endif()
execute_process(
    COMMAND "${TOOL}"
    RESULT_VARIABLE RESULT
    OUTPUT_VARIABLE OUTPUT
    ERROR_VARIABLE ERROR_OUTPUT
    TIMEOUT 5
)
if(NOT RESULT EQUAL 64)
    message(FATAL_ERROR
        "live_preflight_authority_gate_failed:exit=${RESULT};out=${OUTPUT};err=${ERROR_OUTPUT}")
endif()
if(NOT OUTPUT STREQUAL "")
    message(FATAL_ERROR "live_preflight_unconfirmed_stdout_not_empty")
endif()
