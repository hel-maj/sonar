if(NOT DEFINED ENGINE_EXECUTABLE OR NOT EXISTS "${ENGINE_EXECUTABLE}")
    message(FATAL_ERROR "Engine executable is missing: ${ENGINE_EXECUTABLE}")
endif()
if(NOT DEFINED EXPECTED_REASON OR EXPECTED_REASON STREQUAL "")
    message(FATAL_ERROR "EXPECTED_REASON is required")
endif()

unset(ENV{SONAR_FISHING_OFFLINE_GATE})
unset(ENV{SONAR_FISHING_HOST_BUILD_ID})
unset(ENV{SONAR_FISHING_ENGINE_BUILD_ID})
unset(ENV{SONAR_FISHING_BUNDLE_MANIFEST_HASH})
if(NOT DEFINED ENGINE_MODE OR ENGINE_MODE STREQUAL "")
    set(ENGINE_MODE "production")
endif()
set(ENV{SONAR_FISHING_ENGINE_MODE} "${ENGINE_MODE}")

execute_process(
    COMMAND "${ENGINE_EXECUTABLE}"
    RESULT_VARIABLE engine_result
    OUTPUT_VARIABLE engine_output
    ERROR_VARIABLE engine_error
)
if(engine_result EQUAL 0)
    message(FATAL_ERROR "Engine unexpectedly accepted incomplete production bootstrap")
endif()
set(combined_output "${engine_output}${engine_error}")
string(FIND "${combined_output}" "${EXPECTED_REASON}" reason_index)
if(reason_index EQUAL -1)
    message(FATAL_ERROR
        "Expected '${EXPECTED_REASON}', received: ${combined_output}")
endif()
