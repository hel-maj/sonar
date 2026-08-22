add_library(SonarFishingRuntimeSafety STATIC
    src/runtime_safety.cpp
)
add_library(Sonar::FishingRuntimeSafety ALIAS SonarFishingRuntimeSafety)
target_compile_features(SonarFishingRuntimeSafety PUBLIC cxx_std_20)
target_compile_options(SonarFishingRuntimeSafety PRIVATE /W4 /WX /permissive-)
target_include_directories(SonarFishingRuntimeSafety PUBLIC include)
target_link_libraries(SonarFishingRuntimeSafety
    PUBLIC
        Sonar::PlatformWindowsProcess
        Sonar::PlatformWindowsWindow
        Sonar::PlatformInputSafety
)

add_executable(SonarFishingRuntimeSafetyTests
    tests/runtime_safety_test.cpp
)
target_compile_features(SonarFishingRuntimeSafetyTests PRIVATE cxx_std_20)
target_compile_options(SonarFishingRuntimeSafetyTests PRIVATE /W4 /WX /permissive-)
target_link_libraries(SonarFishingRuntimeSafetyTests PRIVATE SonarFishingRuntimeSafety)

add_test(
    NAME sonar_fishing.runtime_safety
    COMMAND SonarFishingRuntimeSafetyTests
)
