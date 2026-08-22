set(SONAR_FISHING_STAGE_ASSET_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")
set(SONAR_FISHING_STAGE_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(SONAR_FISHING_STAGE_GENERATED_SOURCE
    "${SONAR_FISHING_STAGE_GENERATED_DIR}/embedded_stage_assets.generated.cpp")

file(MAKE_DIRECTORY "${SONAR_FISHING_STAGE_GENERATED_DIR}")
set(SONAR_FISHING_STAGE_ASSETS
    "${SONAR_FISHING_STAGE_ASSET_DIR}/AD.pgm"
    "${SONAR_FISHING_STAGE_ASSET_DIR}/AD_2k.pgm"
    "${SONAR_FISHING_STAGE_ASSET_DIR}/start_action.pgm"
    "${SONAR_FISHING_STAGE_ASSET_DIR}/start_action_2k.pgm"
    "${SONAR_FISHING_STAGE_ASSET_DIR}/cast_action.pgm"
    "${SONAR_FISHING_STAGE_ASSET_DIR}/cast_action_2k.pgm"
    "${SONAR_FISHING_STAGE_ASSET_DIR}/hook_action.pgm"
    "${SONAR_FISHING_STAGE_ASSET_DIR}/hook_action_2k.pgm"
    "${SONAR_FISHING_STAGE_ASSET_DIR}/wait_tension.pgm"
    "${SONAR_FISHING_STAGE_ASSET_DIR}/wait_tension_2k.pgm"
)
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
    ${SONAR_FISHING_STAGE_ASSETS}
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/generate_stage_assets.cmake"
)
execute_process(
    COMMAND "${CMAKE_COMMAND}"
        "-DOUTPUT_FILE=${SONAR_FISHING_STAGE_GENERATED_SOURCE}"
        "-DSOURCE_ROOT=${SONAR_FISHING_STAGE_ASSET_DIR}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/generate_stage_assets.cmake"
    RESULT_VARIABLE SONAR_FISHING_STAGE_GENERATION_RESULT
)
if(NOT SONAR_FISHING_STAGE_GENERATION_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to embed Fishing stage templates")
endif()

add_library(SonarFishingStageDetection STATIC
    src/bubble_cue_detector.cpp
    src/fishing_stage_detector.cpp
    src/normalized_correlation.cpp
    src/stage_image.cpp
    src/stage_template_catalog.cpp
    "${SONAR_FISHING_STAGE_GENERATED_SOURCE}"
)
add_library(Sonar::FishingStageDetection ALIAS SonarFishingStageDetection)
target_compile_features(SonarFishingStageDetection PUBLIC cxx_std_20)
target_include_directories(SonarFishingStageDetection
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_compile_options(SonarFishingStageDetection
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingStageDetectionTests
    tests/fishing_stage_detector_test.cpp
)
target_compile_features(SonarFishingStageDetectionTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingStageDetectionTests
    PRIVATE Sonar::FishingStageDetection windowscodecs ole32 psapi
)
target_compile_definitions(SonarFishingStageDetectionTests
    PRIVATE
        SONAR_FISHING_STAGE_SCREENSHOT_MANIFEST="${CMAKE_SOURCE_DIR}/../tests/fixtures/fishing_stage/screenshots-v1.tsv"
)
target_compile_options(SonarFishingStageDetectionTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.stage_detection
    COMMAND SonarFishingStageDetectionTests
)
