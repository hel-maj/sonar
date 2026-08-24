cmake_minimum_required(VERSION 3.25)

project(SonarFishingNative LANGUAGES CXX)

if(NOT MSVC)
    message(FATAL_ERROR "Sonar Fishing native code requires MSVC")
endif()

if(NOT MSVC_TOOLSET_VERSION STREQUAL "143")
    message(FATAL_ERROR "Sonar Fishing native code requires the MSVC v143 toolset")
endif()

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

option(
    SONAR_FISHING_BUILD_OFFLINE_IPC
    "Build the inert product IPC diagnostic executable and tests"
    OFF
)
option(
    SONAR_FISHING_BUILD_PRODUCTION_ENGINE
    "Build the shipping Sonar.Engine.exe IPC composition"
    OFF
)
option(
    SONAR_FISHING_BUILD_LIVE_OBSERVATION_PREFLIGHT
    "Build the non-shipping one-shot read-only GTA observation preflight"
    OFF
)
option(
    SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE
    "Build the non-shipping one-shot GTA build-profile compatibility probe"
    OFF
)

enable_testing()

if(NOT DEFINED SONAR_COMMON_NATIVE_WINDOWS_PACKAGE OR
   NOT IS_DIRECTORY "${SONAR_COMMON_NATIVE_WINDOWS_PACKAGE}")
    message(FATAL_ERROR
        "SONAR_COMMON_NATIVE_WINDOWS_PACKAGE must point to installed Sonar Platform Windows 0.1.6")
endif()
find_package(
    SonarPlatformWindows 0.1.6 EXACT CONFIG REQUIRED
    PATHS "${SONAR_COMMON_NATIVE_WINDOWS_PACKAGE}/lib/cmake/SonarPlatformWindows"
    NO_DEFAULT_PATH
)

if(NOT DEFINED SONAR_COMMON_NATIVE_LICENSING_PACKAGE OR
   NOT IS_DIRECTORY "${SONAR_COMMON_NATIVE_LICENSING_PACKAGE}")
    message(FATAL_ERROR
        "SONAR_COMMON_NATIVE_LICENSING_PACKAGE must point to installed Sonar Platform Licensing 0.1.2")
endif()
find_package(
    SonarPlatformLicensing 0.1.2 EXACT CONFIG REQUIRED
    PATHS "${SONAR_COMMON_NATIVE_LICENSING_PACKAGE}/lib/cmake/SonarPlatformLicensing"
    NO_DEFAULT_PATH
)

add_subdirectory(catch_quality)
add_subdirectory(catch_disposition)
add_subdirectory(session_statistics)
add_subdirectory(fish_identity)
add_subdirectory(catch_observation)
add_subdirectory(runtime_settings)
add_subdirectory(fishing_lifecycle)
add_subdirectory(reeling_control)
add_subdirectory(meal_recovery)
add_subdirectory(garbage_disposal)
add_subdirectory(equipment_recovery)
add_subdirectory(runtime_platform)
add_subdirectory(runtime_safety)
add_subdirectory(entitlement)
add_subdirectory(game_chat)
add_subdirectory(fishing_stage_detection)
add_subdirectory(inventory_store)
add_subdirectory(memory_observation)
add_subdirectory(live_observation_preflight)
add_subdirectory(build_profile_compatibility_probe)
add_subdirectory(fishing_episode)
add_subdirectory(maintenance_episode)
add_subdirectory(automation_adapters)

if(SONAR_FISHING_BUILD_OFFLINE_IPC OR SONAR_FISHING_BUILD_PRODUCTION_ENGINE)
    if(NOT DEFINED SONAR_COMMON_NATIVE_PACKAGE OR
       NOT IS_DIRECTORY "${SONAR_COMMON_NATIVE_PACKAGE}")
        message(FATAL_ERROR
            "SONAR_COMMON_NATIVE_PACKAGE must point to installed Sonar Platform IPC 0.1.1")
    endif()
    if(NOT DEFINED SONAR_PROTOC_EXECUTABLE OR
       NOT EXISTS "${SONAR_PROTOC_EXECUTABLE}")
        message(FATAL_ERROR "SONAR_PROTOC_EXECUTABLE must point to protoc 35.1")
    endif()

    # The immutable prefix also owns Protobuf's exact Abseil/utf8_range
    # dependency closure. Keep resolution inside that installed package.
    list(PREPEND CMAKE_PREFIX_PATH "${SONAR_COMMON_NATIVE_PACKAGE}")

    execute_process(
        COMMAND "${SONAR_PROTOC_EXECUTABLE}" --version
        OUTPUT_VARIABLE SONAR_PROTOC_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
        RESULT_VARIABLE SONAR_PROTOC_RESULT
    )
    if(NOT SONAR_PROTOC_RESULT EQUAL 0 OR
       NOT SONAR_PROTOC_VERSION STREQUAL "libprotoc 35.1")
        message(FATAL_ERROR
            "Fishing IPC requires exact protoc 35.1, received '${SONAR_PROTOC_VERSION}'")
    endif()

    find_package(
        SonarPlatformIpc 0.1.1 EXACT CONFIG REQUIRED
        PATHS "${SONAR_COMMON_NATIVE_PACKAGE}/lib/cmake/SonarPlatformIpc"
        NO_DEFAULT_PATH
    )
    add_subdirectory(engine_ipc)
endif()

if(SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE AND
   TARGET SonarFishingEngine)
    add_test(
        NAME sonar_fishing.build_profile_compatibility_probe_shipping_binary_exclusion
        COMMAND "${CMAKE_COMMAND}"
            "-DENGINE=$<TARGET_FILE:SonarFishingEngine>"
            -P "${CMAKE_CURRENT_SOURCE_DIR}/build_profile_compatibility_probe/cmake/verify_shipping_binary_exclusion.cmake"
    )
endif()
