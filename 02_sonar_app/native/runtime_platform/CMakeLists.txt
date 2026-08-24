add_library(SonarFishingRuntimePlatform STATIC
    src/automation_lease.cpp
    src/platform_capture.cpp
    src/platform_input.cpp
    src/target_resolver.cpp
)
add_library(Sonar::FishingRuntimePlatform ALIAS SonarFishingRuntimePlatform)
target_compile_features(SonarFishingRuntimePlatform PUBLIC cxx_std_20)
target_include_directories(SonarFishingRuntimePlatform
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingRuntimePlatform
    PUBLIC
        Sonar::PlatformWindowsProcess
        Sonar::PlatformWindowsWindow
    PRIVATE
        user32
        gdi32
)
target_compile_options(SonarFishingRuntimePlatform
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingRuntimePlatformTests
    tests/runtime_platform_test.cpp
)
target_compile_features(SonarFishingRuntimePlatformTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingRuntimePlatformTests
    PRIVATE Sonar::FishingRuntimePlatform
)
target_compile_options(SonarFishingRuntimePlatformTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.runtime_platform
    COMMAND SonarFishingRuntimePlatformTests
)

add_test(
    NAME sonar_fishing.runtime_platform_common_window_ownership
    COMMAND "${CMAKE_COMMAND}"
        "-DSOURCE=${CMAKE_CURRENT_SOURCE_DIR}/src/target_resolver.cpp"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/verify_common_window_ownership.cmake"
)
