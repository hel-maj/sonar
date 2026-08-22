add_library(SonarFishingGarbageDisposal STATIC
    src/garbage_disposal.cpp)
add_library(Sonar::FishingGarbageDisposal ALIAS SonarFishingGarbageDisposal)

target_include_directories(SonarFishingGarbageDisposal
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_compile_features(SonarFishingGarbageDisposal PUBLIC cxx_std_20)
target_compile_options(SonarFishingGarbageDisposal
    PRIVATE /permissive- /utf-8 /W4 /WX)

add_executable(SonarFishingGarbageDisposalTests
    tests/garbage_disposal_golden_test.cpp)

target_link_libraries(SonarFishingGarbageDisposalTests
    PRIVATE Sonar::FishingGarbageDisposal)

target_compile_features(SonarFishingGarbageDisposalTests PRIVATE cxx_std_20)
target_compile_options(SonarFishingGarbageDisposalTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc)

set(SONAR_GARBAGE_DISPOSAL_CORPUS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../tests/fixtures/garbage_disposal/legacy_oracle.tsv")
if(NOT EXISTS "${SONAR_GARBAGE_DISPOSAL_CORPUS}")
    message(FATAL_ERROR
        "Missing garbage-disposal golden corpus: ${SONAR_GARBAGE_DISPOSAL_CORPUS}")
endif()

add_test(
    NAME sonar_fishing.garbage_disposal.golden
    COMMAND SonarFishingGarbageDisposalTests "${SONAR_GARBAGE_DISPOSAL_CORPUS}")
