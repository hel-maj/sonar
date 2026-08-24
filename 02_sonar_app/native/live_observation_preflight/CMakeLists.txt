add_library(SonarFishingLiveObservationPreflightCore STATIC
    src/live_observation_preflight.cpp
)
add_library(
    Sonar::FishingLiveObservationPreflightCore
    ALIAS SonarFishingLiveObservationPreflightCore
)
target_compile_features(SonarFishingLiveObservationPreflightCore PUBLIC cxx_std_20)
target_include_directories(SonarFishingLiveObservationPreflightCore
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_options(SonarFishingLiveObservationPreflightCore
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingLiveObservationPreflightTests
    tests/live_observation_preflight_test.cpp
)
target_compile_features(SonarFishingLiveObservationPreflightTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingLiveObservationPreflightTests
    PRIVATE Sonar::FishingLiveObservationPreflightCore
)
target_compile_options(SonarFishingLiveObservationPreflightTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
add_test(
    NAME sonar_fishing.live_observation_preflight
    COMMAND SonarFishingLiveObservationPreflightTests
)

add_test(
    NAME sonar_fishing.live_observation_preflight_readonly_boundary
    COMMAND "${CMAKE_COMMAND}"
        "-DSOURCE_ROOT=${CMAKE_CURRENT_SOURCE_DIR}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/verify_readonly_boundary.cmake"
)

if(SONAR_FISHING_BUILD_LIVE_OBSERVATION_PREFLIGHT)
    add_executable(SonarFishingLiveObservationPreflightTool
        src/main.cpp
        src/windows_observation_port.cpp
    )
    set_target_properties(SonarFishingLiveObservationPreflightTool PROPERTIES
        OUTPUT_NAME "Sonar.Fishing.LiveObservationPreflight"
    )
    target_compile_features(SonarFishingLiveObservationPreflightTool PRIVATE cxx_std_20)
    target_include_directories(SonarFishingLiveObservationPreflightTool
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )
    target_link_libraries(SonarFishingLiveObservationPreflightTool
        PRIVATE
            Sonar::FishingLiveObservationPreflightCore
            Sonar::FishingRuntimePlatform
            Sonar::FishingMemoryObservation
            Sonar::FishingStageDetection
    )
    target_compile_options(SonarFishingLiveObservationPreflightTool
        PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
    )

    add_test(
        NAME sonar_fishing.live_observation_preflight_authority_gate
        COMMAND "${CMAKE_COMMAND}"
            "-DTOOL=$<TARGET_FILE:SonarFishingLiveObservationPreflightTool>"
            -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/verify_authority_gate.cmake"
    )
endif()
