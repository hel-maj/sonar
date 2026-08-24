if(NOT EXISTS "${ENGINE}")
    message(FATAL_ERROR "Shipping Engine is missing: ${ENGINE}")
endif()
file(STRINGS "${ENGINE}" ENGINE_STRINGS)
foreach(FORBIDDEN
        "Sonar.Fishing.BuildProfileCompatibilityProbe"
        "nonshipping-build-profile-candidate-v1"
        "candidate_sha256"
        "pattern_scan_incomplete")
    list(FILTER ENGINE_STRINGS INCLUDE REGEX "${FORBIDDEN}")
    if(ENGINE_STRINGS)
        message(FATAL_ERROR "Shipping Engine contains diagnostic marker: ${FORBIDDEN}")
    endif()
    file(STRINGS "${ENGINE}" ENGINE_STRINGS)
endforeach()
