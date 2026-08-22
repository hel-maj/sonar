add_library(SonarFishingEquipmentRecovery STATIC
    src/equipment_recovery.cpp
)
add_library(Sonar::FishingEquipmentRecovery ALIAS SonarFishingEquipmentRecovery)

target_compile_features(SonarFishingEquipmentRecovery PUBLIC cxx_std_20)
target_include_directories(SonarFishingEquipmentRecovery
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(SonarFishingEquipmentRecovery
    PUBLIC Sonar::FishingRuntimeSettings
)
target_compile_options(SonarFishingEquipmentRecovery
    PRIVATE /permissive- /utf-8 /W4 /WX
)

add_executable(SonarFishingEquipmentRecoveryTests
    tests/equipment_recovery_test.cpp
)
target_compile_features(SonarFishingEquipmentRecoveryTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingEquipmentRecoveryTests
    PRIVATE Sonar::FishingEquipmentRecovery
)
target_compile_options(SonarFishingEquipmentRecoveryTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.equipment_recovery
    COMMAND SonarFishingEquipmentRecoveryTests
)
