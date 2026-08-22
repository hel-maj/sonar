add_library(SonarFishingRuntimeSettings STATIC
    src/runtime_settings.cpp
)
add_library(Sonar::FishingRuntimeSettings ALIAS SonarFishingRuntimeSettings)

target_compile_features(SonarFishingRuntimeSettings PUBLIC cxx_std_20)
target_include_directories(SonarFishingRuntimeSettings
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_options(SonarFishingRuntimeSettings
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

add_executable(SonarFishingRuntimeSettingsTests
    tests/runtime_settings_test.cpp
)
target_compile_features(SonarFishingRuntimeSettingsTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingRuntimeSettingsTests
    PRIVATE
        Sonar::FishingRuntimeSettings
)
target_compile_options(SonarFishingRuntimeSettingsTests
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

add_test(
    NAME sonar_fishing.runtime_settings
    COMMAND SonarFishingRuntimeSettingsTests
)
