add_library(SonarFishingEpisode STATIC
    src/episode_validation.cpp
    src/fishing_episode.cpp
)
add_library(Sonar::FishingEpisode ALIAS SonarFishingEpisode)
target_compile_features(SonarFishingEpisode PUBLIC cxx_std_20)
target_include_directories(SonarFishingEpisode
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingEpisode
    PUBLIC
        Sonar::FishingMemoryObservation
        Sonar::FishingReelingControl
        Sonar::FishingStageDetection
)
target_compile_options(SonarFishingEpisode
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingEpisodeTests
    tests/fishing_episode_test.cpp
)
target_compile_features(SonarFishingEpisodeTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingEpisodeTests
    PRIVATE Sonar::FishingEpisode
)
target_compile_definitions(SonarFishingEpisodeTests
    PRIVATE
        SONAR_FISHING_EPISODE_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/fishing_episode/e13-v1.tsv"
)
target_compile_options(SonarFishingEpisodeTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.fishing_episode
    COMMAND SonarFishingEpisodeTests
)

add_executable(SonarFishingEpisodeBenchmark
    tests/fishing_episode_benchmark.cpp
)
target_compile_features(SonarFishingEpisodeBenchmark PRIVATE cxx_std_20)
target_link_libraries(SonarFishingEpisodeBenchmark
    PRIVATE Sonar::FishingEpisode
)
target_compile_options(SonarFishingEpisodeBenchmark
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)
