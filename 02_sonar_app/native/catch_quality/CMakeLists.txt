add_library(SonarFishingCatchQuality STATIC
    src/catch_quality.cpp
)
add_library(Sonar::FishingCatchQuality ALIAS SonarFishingCatchQuality)

target_compile_features(SonarFishingCatchQuality PUBLIC cxx_std_20)
target_include_directories(SonarFishingCatchQuality
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_options(SonarFishingCatchQuality
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

add_executable(SonarFishingCatchQualityTests
    tests/catch_quality_golden_test.cpp
)
target_compile_features(SonarFishingCatchQualityTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingCatchQualityTests
    PRIVATE
        Sonar::FishingCatchQuality
)
target_compile_options(SonarFishingCatchQualityTests
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

set(SONAR_CATCH_QUALITY_CORPUS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../tests/fixtures/catch_quality/legacy_oracle.tsv"
)
if(NOT EXISTS "${SONAR_CATCH_QUALITY_CORPUS}")
    message(FATAL_ERROR "Missing catch-quality golden corpus: ${SONAR_CATCH_QUALITY_CORPUS}")
endif()

add_test(
    NAME sonar_fishing.catch_quality.golden
    COMMAND SonarFishingCatchQualityTests "${SONAR_CATCH_QUALITY_CORPUS}"
)
