add_library(SonarFishingCatchObservation STATIC
    src/catch_observation.cpp
)
add_library(Sonar::FishingCatchObservation ALIAS SonarFishingCatchObservation)

target_compile_features(SonarFishingCatchObservation PUBLIC cxx_std_20)
target_include_directories(SonarFishingCatchObservation
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(SonarFishingCatchObservation
    PUBLIC
        Sonar::FishingCatchQuality
        Sonar::FishingFishIdentity
)
target_compile_options(SonarFishingCatchObservation
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

add_executable(SonarFishingCatchObservationTests
    tests/catch_observation_golden_test.cpp
)
target_compile_features(SonarFishingCatchObservationTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingCatchObservationTests
    PRIVATE
        Sonar::FishingCatchObservation
)
target_compile_options(SonarFishingCatchObservationTests
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

set(SONAR_CATCH_OBSERVATION_CORPUS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../tests/fixtures/catch_observation/legacy_oracle.tsv"
)
if(NOT EXISTS "${SONAR_CATCH_OBSERVATION_CORPUS}")
    message(FATAL_ERROR
        "Missing catch-observation golden corpus: ${SONAR_CATCH_OBSERVATION_CORPUS}")
endif()

add_test(
    NAME sonar_fishing.catch_observation.golden
    COMMAND SonarFishingCatchObservationTests "${SONAR_CATCH_OBSERVATION_CORPUS}"
)
