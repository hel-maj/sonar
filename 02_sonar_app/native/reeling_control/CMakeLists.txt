add_library(SonarFishingReelingControl STATIC
    src/reeling_control.cpp
)
add_library(Sonar::FishingReelingControl ALIAS SonarFishingReelingControl)

target_compile_features(SonarFishingReelingControl PUBLIC cxx_std_20)
target_include_directories(SonarFishingReelingControl
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_options(SonarFishingReelingControl
    PRIVATE /permissive- /utf-8 /W4 /WX
)

add_executable(SonarFishingReelingControlTests
    tests/reeling_control_test.cpp
)
target_compile_features(SonarFishingReelingControlTests PRIVATE cxx_std_20)
target_link_libraries(
    SonarFishingReelingControlTests
    PRIVATE Sonar::FishingReelingControl
)
target_compile_options(SonarFishingReelingControlTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.reeling_control
    COMMAND SonarFishingReelingControlTests
)

add_executable(SonarFishingReelingControlBenchmark
    tests/reeling_control_benchmark.cpp
)
target_compile_features(SonarFishingReelingControlBenchmark PRIVATE cxx_std_20)
target_link_libraries(
    SonarFishingReelingControlBenchmark
    PRIVATE Sonar::FishingReelingControl
)
target_compile_options(SonarFishingReelingControlBenchmark
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
