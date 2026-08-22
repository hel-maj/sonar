add_library(SonarFishingMaintenanceEpisode STATIC
    src/equipment_operation.cpp
    src/garbage_operation.cpp
    src/maintenance_episode.cpp
    src/meal_operation.cpp
)
add_library(Sonar::FishingMaintenanceEpisode ALIAS SonarFishingMaintenanceEpisode)
target_compile_features(SonarFishingMaintenanceEpisode PUBLIC cxx_std_20)
target_include_directories(SonarFishingMaintenanceEpisode
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingMaintenanceEpisode
    PUBLIC
        Sonar::FishingEquipmentRecovery
        Sonar::FishingInventoryStore
        Sonar::FishingMemoryObservation
        Sonar::FishingRuntimeSettings
    PRIVATE
        Sonar::FishingGarbageDisposal
        Sonar::FishingMealRecovery
)
target_compile_options(SonarFishingMaintenanceEpisode
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingMaintenanceEpisodeTests
    tests/maintenance_episode_test.cpp
)
target_compile_features(SonarFishingMaintenanceEpisodeTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingMaintenanceEpisodeTests
    PRIVATE Sonar::FishingMaintenanceEpisode
)
target_compile_definitions(SonarFishingMaintenanceEpisodeTests
    PRIVATE
        SONAR_FISHING_MAINTENANCE_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/maintenance_episode/episode-v1.tsv"
)
target_compile_options(SonarFishingMaintenanceEpisodeTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.maintenance_episode
    COMMAND SonarFishingMaintenanceEpisodeTests
)

add_executable(SonarFishingMaintenanceEpisodeBenchmark
    tests/maintenance_episode_benchmark.cpp
)
target_compile_features(SonarFishingMaintenanceEpisodeBenchmark PRIVATE cxx_std_20)
target_link_libraries(SonarFishingMaintenanceEpisodeBenchmark
    PRIVATE Sonar::FishingMaintenanceEpisode
)
target_compile_options(SonarFishingMaintenanceEpisodeBenchmark
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
