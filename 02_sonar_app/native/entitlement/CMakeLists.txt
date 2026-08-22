add_library(SonarFishingEntitlement STATIC
    src/entitlement.cpp
    src/keygen_entitlement.cpp
    src/json_document.cpp
    src/windows_machine_fingerprint.cpp
)
add_library(Sonar::FishingEntitlement ALIAS SonarFishingEntitlement)
target_compile_features(SonarFishingEntitlement PUBLIC cxx_std_20)
target_include_directories(SonarFishingEntitlement
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_link_libraries(SonarFishingEntitlement
    PUBLIC Sonar::LicensingVerification
    PRIVATE bcrypt advapi32
)
target_compile_options(SonarFishingEntitlement
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_executable(SonarFishingEntitlementTests
    tests/entitlement_test.cpp
)
target_compile_features(SonarFishingEntitlementTests PRIVATE cxx_std_20)
target_link_libraries(SonarFishingEntitlementTests
    PRIVATE Sonar::FishingEntitlement
)
target_compile_definitions(SonarFishingEntitlementTests
    PRIVATE SONAR_FISHING_ENTITLEMENT_FIXTURE_ROOT="${CMAKE_SOURCE_DIR}/../tests/fixtures/licensing"
)
target_compile_options(SonarFishingEntitlementTests
    PRIVATE /permissive- /utf-8 /W4 /WX /EHsc
)

add_test(
    NAME sonar_fishing.entitlement
    COMMAND SonarFishingEntitlementTests
)
