execute_process(
    COMMAND "${TOOL}"
    RESULT_VARIABLE EXIT_CODE
    OUTPUT_VARIABLE STDOUT
    ERROR_VARIABLE STDERR
)
if(NOT EXIT_CODE EQUAL 64)
    message(FATAL_ERROR
        "Compatibility probe without explicit authority returned ${EXIT_CODE}")
endif()
if(NOT STDOUT STREQUAL "")
    message(FATAL_ERROR
        "Compatibility probe emitted result data without explicit authority")
endif()
