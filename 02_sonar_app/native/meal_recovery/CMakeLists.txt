add_library(SonarFishingMealRecovery STATIC
    src/meal_recovery.cpp
)
add_library(Sonar::FishingMealRecovery ALIAS SonarFishingMealRecovery)

target_compile_features(SonarFishingMealRecovery PUBLIC cxx_std_20)
target_include_directories(SonarFishingMealRecovery
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_options(SonarFishingMealRecovery
    PRIVATE /permissive- /utf-8 /W4 /WX
)

add_executable(SonarFishingMealRecoveryTests
    tests/meal_recovery_test.cpp
)
target_compile_features(SonarFishingMealRecoveryTests PRIVATE cxx_std_20)
target_link_libraries(
    SonarFishingMealRecoveryTests
    PRIVATE Sonar::FishingMealRecovery
)
target_compile_options(SonarFishingMealRecoveryTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.meal_recovery
    COMMAND SonarFishingMealRecoveryTests
)

add_executable(SonarFishingMealRecoveryBenchmark
    tests/meal_recovery_benchmark.cpp
)
target_compile_features(SonarFishingMealRecoveryBenchmark PRIVATE cxx_std_20)
target_link_libraries(
    SonarFishingMealRecoveryBenchmark
    PRIVATE Sonar::FishingMealRecovery
)
target_compile_options(SonarFishingMealRecoveryBenchmark
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
