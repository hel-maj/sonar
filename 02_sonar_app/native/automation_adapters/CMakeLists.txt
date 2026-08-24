add_library(SonarFishingAutomationAdapters STATIC
    src/embedded_visual_assets.generated.cpp
    src/fishing_adapters.cpp
    src/frame_semantics.cpp
    src/production_mutation.cpp
    src/production_observation.cpp
    src/production_visual_detector.cpp
    src/runtime_policy.cpp
    src/system_terminal_action.cpp
    src/windows_runtime_text_recognizer.cpp
)
add_library(Sonar::FishingAutomationAdapters ALIAS SonarFishingAutomationAdapters)
target_compile_features(SonarFishingAutomationAdapters PUBLIC cxx_std_20)
target_include_directories(SonarFishingAutomationAdapters
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingAutomationAdapters
    PUBLIC
        Sonar::FishingEpisode
        Sonar::FishingCatchObservation
        Sonar::FishingInventoryStore
        Sonar::FishingMaintenanceEpisode
        Sonar::FishingRuntimePlatform
        Sonar::FishingRuntimeSafety
        Sonar::FishingStageDetection
        Sonar::PlatformInventoryState
        advapi32
        windowsapp
)
target_compile_options(SonarFishingAutomationAdapters
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingAutomationAdaptersTests
    tests/automation_adapters_test.cpp
)
add_executable(SonarFishingProductionAdaptersTests
    tests/production_adapters_test.cpp
)
target_compile_features(SonarFishingAutomationAdaptersTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingAutomationAdaptersTests
    PRIVATE
        Sonar::FishingAutomationAdapters
        windowscodecs
        ole32
)
target_compile_definitions(SonarFishingAutomationAdaptersTests
    PRIVATE
        SONAR_FISHING_AUTOMATION_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/automation_adapters/frame-semantics-v1.tsv"
        SONAR_FISHING_BUBBLE_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/automation_adapters/bubbles-v1.tsv"
)
target_compile_options(SonarFishingAutomationAdaptersTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

target_compile_features(SonarFishingProductionAdaptersTests PRIVATE cxx_std_20)
target_include_directories(SonarFishingProductionAdaptersTests
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_link_libraries(SonarFishingProductionAdaptersTests
    PRIVATE
        Sonar::FishingAutomationAdapters
        windowscodecs
        ole32
)
target_compile_definitions(SonarFishingProductionAdaptersTests
    PRIVATE
        SONAR_FISHING_CATCH_PRODUCTION_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/gameplay/catch_marlin_310_20260519113616.jpg"
        SONAR_FISHING_INVENTORY_PRODUCTION_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/gameplay/inventory_474.jpg"
        SONAR_FISHING_INVENTORY_FISH_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/gameplay/inventory_490.jpg"
        SONAR_FISHING_TACKLE_PRODUCTION_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/gameplay/tackle_select_473.jpg"
)
target_compile_options(SonarFishingProductionAdaptersTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.automation_adapters
    COMMAND SonarFishingAutomationAdaptersTests
)
add_test(
    NAME sonar_fishing.production_adapters
    COMMAND SonarFishingProductionAdaptersTests
)
