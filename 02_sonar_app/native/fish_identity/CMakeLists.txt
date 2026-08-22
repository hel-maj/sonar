set(SONAR_FISH_CATALOG
    "${CMAKE_CURRENT_SOURCE_DIR}/../../contracts/fishing/fish-catalog.json"
)
set(SONAR_FISH_CATALOG_GENERATED_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/generated"
)
set(SONAR_FISH_CATALOG_GENERATED_HEADER
    "${SONAR_FISH_CATALOG_GENERATED_DIRECTORY}/fish_catalog.generated.h"
)
if(NOT EXISTS "${SONAR_FISH_CATALOG}")
    message(FATAL_ERROR "Missing canonical fish catalog: ${SONAR_FISH_CATALOG}")
endif()
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${SONAR_FISH_CATALOG}")
execute_process(
    COMMAND
        "${CMAKE_COMMAND}"
        "-DINPUT=${SONAR_FISH_CATALOG}"
        "-DOUTPUT=${SONAR_FISH_CATALOG_GENERATED_HEADER}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/generate_fish_catalog.cmake"
    RESULT_VARIABLE SONAR_FISH_CATALOG_GENERATE_RESULT
)
if(NOT SONAR_FISH_CATALOG_GENERATE_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to generate the native fish catalog header")
endif()

add_library(SonarFishingFishIdentity STATIC
    src/fish_identity.cpp
    "${SONAR_FISH_CATALOG_GENERATED_HEADER}"
)
add_library(Sonar::FishingFishIdentity ALIAS SonarFishingFishIdentity)

target_compile_features(SonarFishingFishIdentity PUBLIC cxx_std_20)
target_include_directories(SonarFishingFishIdentity
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${SONAR_FISH_CATALOG_GENERATED_DIRECTORY}
)
target_compile_options(SonarFishingFishIdentity
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

add_executable(SonarFishingFishIdentityTests
    tests/fish_identity_golden_test.cpp
)
target_compile_features(SonarFishingFishIdentityTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingFishIdentityTests
    PRIVATE
        Sonar::FishingFishIdentity
)
target_compile_options(SonarFishingFishIdentityTests
    PRIVATE
        /permissive-
        /utf-8
        /W4
        /WX
)

set(SONAR_FISH_IDENTITY_CORPUS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../tests/fixtures/fish_identity/legacy_oracle.tsv"
)
if(NOT EXISTS "${SONAR_FISH_IDENTITY_CORPUS}")
    message(FATAL_ERROR
        "Missing fish-identity golden corpus: ${SONAR_FISH_IDENTITY_CORPUS}")
endif()

add_test(
    NAME sonar_fishing.fish_identity.golden
    COMMAND SonarFishingFishIdentityTests "${SONAR_FISH_IDENTITY_CORPUS}"
)
