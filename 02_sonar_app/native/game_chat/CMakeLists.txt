add_library(SonarFishingGameChat STATIC
    src/chat_observation.cpp
    src/chat_image_ops.cpp
    src/chat_runtime.cpp
    src/game_chat.cpp
    src/majestic_chat_frame_detector.cpp
    src/win32_chat_capture.cpp
    src/win32_chat_platform_mutation.cpp
)
add_library(Sonar::FishingGameChat ALIAS SonarFishingGameChat)
target_compile_features(SonarFishingGameChat PUBLIC cxx_std_20)
target_include_directories(SonarFishingGameChat
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(SonarFishingGameChat
    PUBLIC
        SonarFishingRuntimeSafety
        Sonar::FishingRuntimePlatform
)
target_compile_options(SonarFishingGameChat
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingGameChatTests
    tests/game_chat_test.cpp
)
target_compile_features(SonarFishingGameChatTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingGameChatTests
    PRIVATE Sonar::FishingGameChat
)
target_compile_definitions(SonarFishingGameChatTests
    PRIVATE
        SONAR_FISHING_GAME_CHAT_FIXTURE="${CMAKE_SOURCE_DIR}/../tests/fixtures/game_chat/episode-v1.tsv"
)
target_compile_options(SonarFishingGameChatTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.game_chat
    COMMAND SonarFishingGameChatTests
)

add_executable(SonarFishingGameChatBoundaryTests
    tests/chat_boundary_test.cpp
)
target_compile_features(SonarFishingGameChatBoundaryTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingGameChatBoundaryTests
    PRIVATE Sonar::FishingGameChat
)
target_compile_options(SonarFishingGameChatBoundaryTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.game_chat_boundary
    COMMAND SonarFishingGameChatBoundaryTests
)

add_executable(SonarFishingGameChatPlatformMutationTests
    tests/chat_platform_mutation_test.cpp
)
target_compile_features(SonarFishingGameChatPlatformMutationTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingGameChatPlatformMutationTests
    PRIVATE Sonar::FishingGameChat
)
target_compile_options(SonarFishingGameChatPlatformMutationTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.game_chat_platform_mutation
    COMMAND SonarFishingGameChatPlatformMutationTests
)

add_executable(SonarFishingGameChatVisualDetectorTests
    tests/chat_visual_detector_test.cpp
)
target_compile_features(SonarFishingGameChatVisualDetectorTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingGameChatVisualDetectorTests
    PRIVATE Sonar::FishingGameChat windowscodecs ole32 psapi
)
target_compile_definitions(SonarFishingGameChatVisualDetectorTests
    PRIVATE
        SONAR_FISHING_CHAT_SCREENSHOT_MANIFEST="${CMAKE_SOURCE_DIR}/../tests/fixtures/game_chat/screenshots-v1.tsv"
)
target_compile_options(SonarFishingGameChatVisualDetectorTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.game_chat_visual_detector
    COMMAND SonarFishingGameChatVisualDetectorTests
)
