add_library(SonarFishingMemoryObservation STATIC
    src/build_profile_registry.cpp
    src/chat_decoder.cpp
    src/inventory_capture_plan_resolver.cpp
    src/memory_capture_plan_resolver.cpp
    src/memory_observer.cpp
    src/player_status_decoder.cpp
    src/reeling_inventory_decoders.cpp
    src/windows_memory_connector.cpp
)
add_library(Sonar::FishingMemoryObservation ALIAS SonarFishingMemoryObservation)
target_compile_features(SonarFishingMemoryObservation PUBLIC cxx_std_20)
target_include_directories(SonarFishingMemoryObservation
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingMemoryObservation
    PUBLIC
        Sonar::PlatformWindowsProcess
        Sonar::PlatformInventoryState
    PRIVATE bcrypt
)
target_compile_options(SonarFishingMemoryObservation
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingMemoryObservationTests
    tests/memory_observation_test.cpp
)
target_compile_features(SonarFishingMemoryObservationTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingMemoryObservationTests
    PRIVATE Sonar::FishingMemoryObservation
)
target_compile_definitions(SonarFishingMemoryObservationTests
    PRIVATE
        SONAR_FISHING_MEMORY_OBSERVATION_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/memory_observation/e11-v1.tsv"
        SONAR_FISHING_MEMORY_BUILD_PROFILE_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/memory_observation/build-profiles-v1.tsv"
        SONAR_FISHING_MEMORY_BUILD_PROFILE_SHA256="A49D7CE5FE04EB3E5B24DCC717A5AF160E315D0C9449DA725B1578A643F9EB8C"
)
target_compile_options(SonarFishingMemoryObservationTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.memory_observation
    COMMAND SonarFishingMemoryObservationTests
)

add_executable(SonarFishingMemoryObservationBenchmark
    tests/memory_observation_benchmark.cpp
)
target_compile_features(SonarFishingMemoryObservationBenchmark PRIVATE cxx_std_20)
target_link_libraries(SonarFishingMemoryObservationBenchmark
    PRIVATE Sonar::FishingMemoryObservation
)
target_compile_options(SonarFishingMemoryObservationBenchmark
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
