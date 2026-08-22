add_library(SonarFishingInventoryStore STATIC
    src/inventory_store_episode.cpp
)
add_library(Sonar::FishingInventoryStore ALIAS SonarFishingInventoryStore)

target_compile_features(SonarFishingInventoryStore PUBLIC cxx_std_20)
target_include_directories(SonarFishingInventoryStore
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingInventoryStore
    PUBLIC Sonar::FishingStageDetection
)
target_compile_options(SonarFishingInventoryStore
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingInventoryStoreTests
    tests/inventory_store_episode_test.cpp
)
target_compile_features(SonarFishingInventoryStoreTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingInventoryStoreTests
    PRIVATE Sonar::FishingInventoryStore
)
target_compile_definitions(SonarFishingInventoryStoreTests
    PRIVATE
        SONAR_FISHING_INVENTORY_STORE_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/inventory_store/episode-v1.tsv"
)
target_compile_options(SonarFishingInventoryStoreTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.inventory_store
    COMMAND SonarFishingInventoryStoreTests
)

add_executable(SonarFishingInventoryStoreBenchmark
    tests/inventory_store_benchmark.cpp
)
target_compile_features(SonarFishingInventoryStoreBenchmark PRIVATE cxx_std_20)
target_link_libraries(SonarFishingInventoryStoreBenchmark
    PRIVATE Sonar::FishingInventoryStore
)
target_compile_options(SonarFishingInventoryStoreBenchmark
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
