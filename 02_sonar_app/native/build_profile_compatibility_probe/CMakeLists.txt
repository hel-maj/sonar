if(NOT SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE)
    return()
endif()

add_library(SonarFishingBuildProfileCompatibilityProbeCore STATIC
    src/build_profile_compatibility_probe.cpp
    src/inventory_state_characterization.cpp
)
add_library(
    Sonar::FishingBuildProfileCompatibilityProbeCore
    ALIAS SonarFishingBuildProfileCompatibilityProbeCore
)
target_compile_features(
    SonarFishingBuildProfileCompatibilityProbeCore PUBLIC cxx_std_20
)
target_include_directories(SonarFishingBuildProfileCompatibilityProbeCore
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_options(SonarFishingBuildProfileCompatibilityProbeCore
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_library(SonarFishingForensicMemoryConnector STATIC
    src/windows_forensic_memory_connector.cpp
)
target_compile_features(
    SonarFishingForensicMemoryConnector PRIVATE cxx_std_20
)
target_include_directories(
    SonarFishingForensicMemoryConnector
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_link_libraries(
    SonarFishingForensicMemoryConnector
    PRIVATE Sonar::FishingMemoryObservation bcrypt
)
target_compile_options(
    SonarFishingForensicMemoryConnector
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingBuildProfileCompatibilityProbeTests
    tests/build_profile_compatibility_probe_test.cpp
)
target_compile_features(
    SonarFishingBuildProfileCompatibilityProbeTests PRIVATE cxx_std_20
)
target_link_libraries(SonarFishingBuildProfileCompatibilityProbeTests
    PRIVATE Sonar::FishingBuildProfileCompatibilityProbeCore
)
target_compile_options(SonarFishingBuildProfileCompatibilityProbeTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
add_test(
    NAME sonar_fishing.build_profile_compatibility_probe
    COMMAND SonarFishingBuildProfileCompatibilityProbeTests
)

add_executable(SonarFishingInventoryStateCharacterizationTests
    tests/inventory_state_characterization_test.cpp
)
target_compile_features(
    SonarFishingInventoryStateCharacterizationTests PRIVATE cxx_std_20
)
target_include_directories(
    SonarFishingInventoryStateCharacterizationTests
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_link_libraries(
    SonarFishingInventoryStateCharacterizationTests
    PRIVATE Sonar::FishingBuildProfileCompatibilityProbeCore
)
target_compile_options(
    SonarFishingInventoryStateCharacterizationTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
add_test(
    NAME sonar_fishing.inventory_state_characterization
    COMMAND SonarFishingInventoryStateCharacterizationTests
)

add_test(
    NAME sonar_fishing.build_profile_compatibility_probe_readonly_boundary
    COMMAND "${CMAKE_COMMAND}"
        "-DSOURCE_ROOT=${CMAKE_CURRENT_SOURCE_DIR}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/verify_readonly_boundary.cmake"
)

add_test(
    NAME sonar_fishing.build_profile_compatibility_probe_shipping_isolation
    COMMAND "${CMAKE_COMMAND}"
        "-DNATIVE_ROOT=${CMAKE_SOURCE_DIR}"
        "-DPRODUCT_ROOT=${CMAKE_SOURCE_DIR}/.."
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/verify_shipping_isolation.cmake"
)

add_executable(SonarFishingBuildProfileCompatibilityProbeTool
    src/main.cpp
    src/candidate_reeling_validator.cpp
    src/windows_compatibility_port.cpp
)
set_target_properties(
    SonarFishingBuildProfileCompatibilityProbeTool PROPERTIES
    OUTPUT_NAME "Sonar.Fishing.BuildProfileCompatibilityProbe"
)
target_compile_features(
    SonarFishingBuildProfileCompatibilityProbeTool PRIVATE cxx_std_20
)
target_include_directories(SonarFishingBuildProfileCompatibilityProbeTool
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/../memory_observation/src"
)
target_link_libraries(SonarFishingBuildProfileCompatibilityProbeTool
    PRIVATE
        Sonar::FishingBuildProfileCompatibilityProbeCore
        SonarFishingForensicMemoryConnector
        Sonar::FishingRuntimePlatform
        Sonar::FishingMemoryObservation
)
target_compile_options(SonarFishingBuildProfileCompatibilityProbeTool
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.build_profile_compatibility_probe_authority_gate
    COMMAND "${CMAKE_COMMAND}"
        "-DTOOL=$<TARGET_FILE:SonarFishingBuildProfileCompatibilityProbeTool>"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/verify_authority_gate.cmake"
)

add_test(
    NAME sonar_fishing.build_profile_compatibility_probe_binary_imports
    COMMAND "${CMAKE_COMMAND}"
        "-DDUMPBIN=${CMAKE_DUMPBIN}"
        "-DTOOL=$<TARGET_FILE:SonarFishingBuildProfileCompatibilityProbeTool>"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/verify_binary_imports.cmake"
)

add_executable(SonarFishingInventoryStateCharacterizationTool
    src/inventory_state_characterization_main.cpp
)
set_target_properties(
    SonarFishingInventoryStateCharacterizationTool PROPERTIES
    OUTPUT_NAME "Sonar.Fishing.InventoryStateCharacterization"
)
target_compile_features(
    SonarFishingInventoryStateCharacterizationTool PRIVATE cxx_std_20
)
target_include_directories(
    SonarFishingInventoryStateCharacterizationTool
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_link_libraries(
    SonarFishingInventoryStateCharacterizationTool
    PRIVATE
        Sonar::FishingBuildProfileCompatibilityProbeCore
        SonarFishingForensicMemoryConnector
        Sonar::FishingMemoryObservation
)
target_compile_options(
    SonarFishingInventoryStateCharacterizationTool
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
add_test(
    NAME sonar_fishing.inventory_state_characterization_authority_gate
    COMMAND "${CMAKE_COMMAND}"
        "-DTOOL=$<TARGET_FILE:SonarFishingInventoryStateCharacterizationTool>"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/verify_authority_gate.cmake"
)
add_test(
    NAME sonar_fishing.inventory_state_characterization_binary_imports
    COMMAND "${CMAKE_COMMAND}"
        "-DDUMPBIN=${CMAKE_DUMPBIN}"
        "-DTOOL=$<TARGET_FILE:SonarFishingInventoryStateCharacterizationTool>"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/verify_binary_imports.cmake"
)

add_executable(SonarFishingBuildProfileCompatibilityValidatorTests
    src/candidate_reeling_validator.cpp
    tests/candidate_reeling_validator_test.cpp
)
target_compile_features(
    SonarFishingBuildProfileCompatibilityValidatorTests PRIVATE cxx_std_20
)
target_include_directories(
    SonarFishingBuildProfileCompatibilityValidatorTests
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/../memory_observation/src"
)
target_link_libraries(SonarFishingBuildProfileCompatibilityValidatorTests
    PRIVATE
        Sonar::FishingBuildProfileCompatibilityProbeCore
        Sonar::FishingMemoryObservation
)
target_compile_options(
    SonarFishingBuildProfileCompatibilityValidatorTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
add_test(
    NAME sonar_fishing.build_profile_compatibility_validator
    COMMAND SonarFishingBuildProfileCompatibilityValidatorTests
)
