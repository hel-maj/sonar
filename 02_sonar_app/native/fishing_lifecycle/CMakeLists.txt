add_library(SonarFishingLifecycle STATIC
    src/fishing_lifecycle.cpp
)
add_library(Sonar::FishingLifecycle ALIAS SonarFishingLifecycle)

target_compile_features(SonarFishingLifecycle PUBLIC cxx_std_20)
target_include_directories(SonarFishingLifecycle
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_options(SonarFishingLifecycle
    PRIVATE /permissive- /utf-8 /W4 /WX
)

add_executable(SonarFishingLifecycleTests
    tests/fishing_lifecycle_test.cpp
)
target_compile_features(SonarFishingLifecycleTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingLifecycleTests PRIVATE Sonar::FishingLifecycle)
target_compile_options(SonarFishingLifecycleTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.lifecycle
    COMMAND SonarFishingLifecycleTests
)
