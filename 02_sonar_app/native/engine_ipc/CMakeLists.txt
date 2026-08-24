set(SONAR_FISHING_PRODUCT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../..")
set(SONAR_FISHING_CONTRACT_ROOT "${SONAR_FISHING_PRODUCT_ROOT}/contracts")
set(SONAR_FISHING_SCHEMA
    "${SONAR_FISHING_CONTRACT_ROOT}/ipc/v1/sonar_fishing.proto")
set(SONAR_PLATFORM_SCHEMA_ROOT
    "${SONAR_COMMON_NATIVE_PACKAGE}/share/sonar-platform-ipc/contracts")
set(SONAR_PLATFORM_SCHEMA
    "${SONAR_PLATFORM_SCHEMA_ROOT}/ipc/v1/sonar_platform.proto")
set(SONAR_FISHING_GENERATED_ROOT "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(SONAR_FISHING_GENERATED_HEADER
    "${SONAR_FISHING_GENERATED_ROOT}/ipc/v1/sonar_fishing.pb.h")
set(SONAR_FISHING_GENERATED_SOURCE
    "${SONAR_FISHING_GENERATED_ROOT}/ipc/v1/sonar_fishing.pb.cc")

foreach(required_file IN ITEMS "${SONAR_FISHING_SCHEMA}" "${SONAR_PLATFORM_SCHEMA}")
    if(NOT EXISTS "${required_file}")
        message(FATAL_ERROR "Missing IPC schema: ${required_file}")
    endif()
endforeach()

file(SHA256 "${SONAR_FISHING_SCHEMA}" SONAR_FISHING_SCHEMA_SHA256)

add_custom_command(
    OUTPUT
        "${SONAR_FISHING_GENERATED_HEADER}"
        "${SONAR_FISHING_GENERATED_SOURCE}"
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${SONAR_FISHING_GENERATED_ROOT}"
    COMMAND "${SONAR_PROTOC_EXECUTABLE}"
        "--proto_path=${SONAR_FISHING_CONTRACT_ROOT}"
        "--proto_path=${SONAR_PLATFORM_SCHEMA_ROOT}"
        "--cpp_out=${SONAR_FISHING_GENERATED_ROOT}"
        "${SONAR_FISHING_SCHEMA}"
    DEPENDS "${SONAR_FISHING_SCHEMA}" "${SONAR_PLATFORM_SCHEMA}"
    VERBATIM
)

add_library(SonarFishingIpcContracts STATIC
    "${SONAR_FISHING_GENERATED_SOURCE}"
)
add_library(Sonar::FishingIpcContracts ALIAS SonarFishingIpcContracts)
target_compile_features(SonarFishingIpcContracts PUBLIC cxx_std_20)
target_include_directories(SonarFishingIpcContracts
    PUBLIC "${SONAR_FISHING_GENERATED_ROOT}"
)
target_link_libraries(SonarFishingIpcContracts
    PUBLIC Sonar::PlatformIpcContracts
)
target_compile_options(SonarFishingIpcContracts PRIVATE /permissive- /utf-8)
set_source_files_properties(
    "${SONAR_FISHING_GENERATED_SOURCE}"
    PROPERTIES COMPILE_OPTIONS "/W0;/WX-"
)

add_library(SonarFishingEventDelivery STATIC
    src/event_delivery.cpp
)
add_library(Sonar::FishingEventDelivery ALIAS SonarFishingEventDelivery)
target_compile_features(SonarFishingEventDelivery PUBLIC cxx_std_20)
target_include_directories(SonarFishingEventDelivery
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingEventDelivery
    PUBLIC Sonar::PlatformIpcTransport
)
target_compile_options(SonarFishingEventDelivery
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_library(SonarFishingSessionControl STATIC
    src/engine_mode.cpp
    src/session_lifecycle.cpp
)
add_library(Sonar::FishingSessionControl ALIAS SonarFishingSessionControl)
target_compile_features(SonarFishingSessionControl PUBLIC cxx_std_20)
target_include_directories(SonarFishingSessionControl
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingSessionControl
    PUBLIC Sonar::PlatformIpcContracts
)
target_compile_options(SonarFishingSessionControl
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_library(SonarFishingProductionComposition STATIC
    src/production_composition.cpp
    src/production_session_loop.cpp
)
add_library(
    Sonar::FishingProductionComposition
    ALIAS SonarFishingProductionComposition
)
target_compile_features(SonarFishingProductionComposition PUBLIC cxx_std_20)
target_include_directories(SonarFishingProductionComposition
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingProductionComposition
    PUBLIC
        Sonar::FishingAutomationAdapters
        Sonar::FishingStageDetection
        Sonar::FishingMemoryObservation
        Sonar::FishingEpisode
        Sonar::FishingInventoryStore
        Sonar::FishingMaintenanceEpisode
        Sonar::FishingCatchObservation
        Sonar::FishingCatchDisposition
        Sonar::FishingSessionStatistics
)
target_compile_options(SonarFishingProductionComposition
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

set(SONAR_FISHING_ENGINE_RUNTIME_SOURCES
    src/main.cpp
    src/diagnostic_commands.cpp
    src/engine_bootstrap.cpp
    src/engine_protocol.cpp
    src/engine_runtime.cpp
    src/entitlement_commands.cpp
    src/session_commands.cpp
    src/settings_commands.cpp
)

if(SONAR_FISHING_BUILD_OFFLINE_IPC)
    add_executable(SonarFishingOfflineEngine
        ${SONAR_FISHING_ENGINE_RUNTIME_SOURCES}
    )
    target_compile_features(SonarFishingOfflineEngine PRIVATE cxx_std_20)
    target_link_libraries(SonarFishingOfflineEngine
        PRIVATE
            Sonar::FishingCatchQuality
            Sonar::FishingCatchDisposition
            Sonar::FishingSessionStatistics
            Sonar::FishingRuntimeSettings
            Sonar::FishingEntitlement
            Sonar::FishingIpcContracts
            Sonar::FishingEventDelivery
            Sonar::FishingSessionControl
            Sonar::FishingProductionComposition
            Sonar::PlatformIpcTransport
    )
    target_compile_definitions(SonarFishingOfflineEngine
        PRIVATE
            SONAR_FISHING_SCHEMA_SHA256="${SONAR_FISHING_SCHEMA_SHA256}"
            SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS=1
    )
    target_compile_options(SonarFishingOfflineEngine
        PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
    )
endif()

add_executable(SonarFishingEngine
    ${SONAR_FISHING_ENGINE_RUNTIME_SOURCES}
)
set_target_properties(SonarFishingEngine PROPERTIES OUTPUT_NAME "Sonar.Engine")
target_compile_features(SonarFishingEngine PRIVATE cxx_std_20)
target_link_libraries(SonarFishingEngine
    PRIVATE
        Sonar::FishingCatchQuality
        Sonar::FishingCatchDisposition
        Sonar::FishingSessionStatistics
        Sonar::FishingRuntimeSettings
        Sonar::FishingEntitlement
        Sonar::FishingIpcContracts
        Sonar::FishingEventDelivery
        Sonar::FishingSessionControl
        Sonar::FishingProductionComposition
        Sonar::PlatformIpcTransport
)
target_compile_definitions(SonarFishingEngine
    PRIVATE
        SONAR_FISHING_SCHEMA_SHA256="${SONAR_FISHING_SCHEMA_SHA256}"
        SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS=0
)
target_compile_options(SonarFishingEngine
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingIpcContractsTests
    tests/contracts_golden_test.cpp
)

add_executable(SonarFishingEventDeliveryTests
    tests/event_delivery_test.cpp
)
target_compile_features(SonarFishingEventDeliveryTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingEventDeliveryTests
    PRIVATE Sonar::FishingEventDelivery
)
target_compile_options(SonarFishingEventDeliveryTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingSessionControlTests
    tests/session_lifecycle_test.cpp
)
target_compile_features(SonarFishingSessionControlTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingSessionControlTests
    PRIVATE Sonar::FishingSessionControl
)
target_compile_options(SonarFishingSessionControlTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingProductionCompositionTests
    tests/production_composition_test.cpp
)
target_compile_features(SonarFishingProductionCompositionTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingProductionCompositionTests
    PRIVATE Sonar::FishingProductionComposition
)
target_compile_options(SonarFishingProductionCompositionTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
target_compile_features(SonarFishingIpcContractsTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingIpcContractsTests
    PRIVATE Sonar::FishingIpcContracts
)
target_compile_definitions(SonarFishingIpcContractsTests
    PRIVATE
        SONAR_FISHING_IPC_FIXTURE_ROOT="${SONAR_FISHING_PRODUCT_ROOT}/tests/fixtures/ipc/v1"
)
target_compile_options(SonarFishingIpcContractsTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.ipc.contract_golden
    COMMAND SonarFishingIpcContractsTests
)
add_test(
    NAME sonar_fishing.ipc.event_delivery
    COMMAND SonarFishingEventDeliveryTests
)
add_test(
    NAME sonar_fishing.ipc.session_control
    COMMAND SonarFishingSessionControlTests
)
add_test(
    NAME sonar_fishing.ipc.production_composition
    COMMAND SonarFishingProductionCompositionTests
)
if(SONAR_FISHING_BUILD_OFFLINE_IPC)
    add_test(
        NAME sonar_fishing.ipc.offline_authority_gate
        COMMAND SonarFishingOfflineEngine
    )
    set_tests_properties(
        sonar_fishing.ipc.offline_authority_gate
        PROPERTIES WILL_FAIL TRUE
    )
endif()
add_test(
    NAME sonar_fishing.ipc.production_identity_gate
    COMMAND "${CMAKE_COMMAND}"
        "-DENGINE_EXECUTABLE=$<TARGET_FILE:SonarFishingEngine>"
        "-DEXPECTED_REASON=production_host_build_id_missing"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/tests/expect_engine_failure.cmake"
)
