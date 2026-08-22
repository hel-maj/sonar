add_library(SonarFishingCatchDisposition STATIC
    src/catch_disposition.cpp
)
add_library(Sonar::FishingCatchDisposition ALIAS SonarFishingCatchDisposition)

target_compile_features(SonarFishingCatchDisposition PUBLIC cxx_std_20)
target_include_directories(SonarFishingCatchDisposition
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_options(SonarFishingCatchDisposition
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

add_executable(SonarFishingCatchDispositionTests
    tests/catch_disposition_golden_test.cpp
)
target_compile_features(SonarFishingCatchDispositionTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingCatchDispositionTests
    PRIVATE
        Sonar::FishingCatchDisposition
)
target_compile_options(SonarFishingCatchDispositionTests
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

set(SONAR_CATCH_DISPOSITION_CORPUS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../tests/fixtures/catch_disposition/legacy_oracle.tsv"
)
if(NOT EXISTS "${SONAR_CATCH_DISPOSITION_CORPUS}")
    message(FATAL_ERROR
        "Missing catch-disposition golden corpus: ${SONAR_CATCH_DISPOSITION_CORPUS}")
endif()

add_test(
    NAME sonar_fishing.catch_disposition.golden
    COMMAND SonarFishingCatchDispositionTests "${SONAR_CATCH_DISPOSITION_CORPUS}"
)
