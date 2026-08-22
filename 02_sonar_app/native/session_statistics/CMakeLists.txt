set(SONAR_SESSION_STATISTICS_FISH_CATALOG
    "${CMAKE_CURRENT_SOURCE_DIR}/../../contracts/fishing/fish-catalog.json"
)
set(SONAR_SESSION_STATISTICS_GENERATED_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/generated"
)
set(SONAR_SESSION_STATISTICS_GENERATED_PRICES
    "${SONAR_SESSION_STATISTICS_GENERATED_DIRECTORY}/default_prices.generated.cpp"
)
if(NOT EXISTS "${SONAR_SESSION_STATISTICS_FISH_CATALOG}")
    message(FATAL_ERROR
        "Missing canonical fish catalog: ${SONAR_SESSION_STATISTICS_FISH_CATALOG}")
endif()
set_property(
    DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
    "${SONAR_SESSION_STATISTICS_FISH_CATALOG}"
)
execute_process(
    COMMAND
        "${CMAKE_COMMAND}"
        "-DINPUT=${SONAR_SESSION_STATISTICS_FISH_CATALOG}"
        "-DOUTPUT=${SONAR_SESSION_STATISTICS_GENERATED_PRICES}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/generate_default_prices.cmake"
    RESULT_VARIABLE SONAR_SESSION_STATISTICS_GENERATE_RESULT
)
if(NOT SONAR_SESSION_STATISTICS_GENERATE_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to generate the native default price catalog")
endif()

add_library(SonarFishingSessionStatistics STATIC
    src/session_statistics.cpp
    "${SONAR_SESSION_STATISTICS_GENERATED_PRICES}"
)
add_library(Sonar::FishingSessionStatistics ALIAS SonarFishingSessionStatistics)

target_compile_features(SonarFishingSessionStatistics PUBLIC cxx_std_20)
target_include_directories(SonarFishingSessionStatistics
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_options(SonarFishingSessionStatistics
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

add_executable(SonarFishingSessionStatisticsTests
    tests/session_statistics_golden_test.cpp
)
target_compile_features(SonarFishingSessionStatisticsTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingSessionStatisticsTests
    PRIVATE
        Sonar::FishingSessionStatistics
)
target_compile_options(SonarFishingSessionStatisticsTests
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

set(SONAR_SESSION_STATISTICS_CORPUS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../tests/fixtures/session_statistics/legacy_oracle.tsv"
)
if(NOT EXISTS "${SONAR_SESSION_STATISTICS_CORPUS}")
    message(FATAL_ERROR
        "Missing session-statistics golden corpus: ${SONAR_SESSION_STATISTICS_CORPUS}")
endif()

add_test(
    NAME sonar_fishing.session_statistics.golden
    COMMAND SonarFishingSessionStatisticsTests "${SONAR_SESSION_STATISTICS_CORPUS}"
)
