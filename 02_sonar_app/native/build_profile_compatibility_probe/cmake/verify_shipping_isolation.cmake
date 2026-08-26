file(GLOB_RECURSE SHIPPING_SOURCES
    "${NATIVE_ROOT}/memory_observation/include/*.h"
    "${NATIVE_ROOT}/memory_observation/src/*.cpp"
    "${NATIVE_ROOT}/engine_ipc/include/*.h"
    "${NATIVE_ROOT}/engine_ipc/src/*.cpp"
)
list(APPEND SHIPPING_SOURCES
    "${NATIVE_ROOT}/memory_observation/CMakeLists.txt"
    "${NATIVE_ROOT}/engine_ipc/CMakeLists.txt"
)
foreach(SOURCE IN LISTS SHIPPING_SOURCES)
    file(READ "${SOURCE}" CONTENT)
    foreach(FORBIDDEN
            "BuildProfileCompatibilityProbe"
            "compatibility_candidate"
            "candidate_sha256"
            "candidate_profile_schema_version"
            "nonshipping-build-profile-candidate-v1")
        string(FIND "${CONTENT}" "${FORBIDDEN}" POSITION)
        if(NOT POSITION EQUAL -1)
            message(FATAL_ERROR
                "Shipping source references diagnostic candidate capability '${FORBIDDEN}': ${SOURCE}")
        endif()
    endforeach()
endforeach()

file(READ "${NATIVE_ROOT}/memory_observation/src/memory_capture_plan_resolver.cpp"
    RESOLVER_CONTENT)
string(FIND "${RESOLVER_CONTENT}"
    "embedded_memory_build_profiles()" EMBEDDED_REGISTRY_POSITION)
string(FIND "${RESOLVER_CONTENT}"
    "select_memory_build_profile(" SELECTOR_POSITION)
foreach(REQUIRED_TRUSTED_RUNTIME_CONTRACT
        "process_admission::trusted_publisher_runtime"
        "resolve_trusted_reeling_binding"
        "authority_fingerprint")
    string(FIND "${RESOLVER_CONTENT}"
        "${REQUIRED_TRUSTED_RUNTIME_CONTRACT}" TRUSTED_RUNTIME_POSITION)
    if(TRUSTED_RUNTIME_POSITION EQUAL -1)
        message(FATAL_ERROR
            "Shipping memory resolver lost trusted runtime contract: ${REQUIRED_TRUSTED_RUNTIME_CONTRACT}")
    endif()
endforeach()
if(EMBEDDED_REGISTRY_POSITION EQUAL -1)
    message(FATAL_ERROR "Shipping memory resolver lost semantic layout registry ownership")
endif()
if(SELECTOR_POSITION EQUAL -1)
    message(FATAL_ERROR "Shipping memory resolver lost forensic exact-profile branch")
endif()

file(READ "${NATIVE_ROOT}/CMakeLists.txt" ROOT_CMAKE)
string(REGEX MATCH
    "option\\([ \t\r\n]*SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE[^)]*OFF[ \t\r\n]*\\)"
    OPTION_BLOCK "${ROOT_CMAKE}")
if(OPTION_BLOCK STREQUAL "")
    message(FATAL_ERROR "Compatibility probe option is not default OFF")
endif()

file(READ "${PRODUCT_ROOT}/scripts/build_release_native.ps1" RELEASE_SCRIPT)
string(FIND "${RELEASE_SCRIPT}"
    "-DSONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE=OFF"
    RELEASE_OFF_POSITION)
if(RELEASE_OFF_POSITION EQUAL -1)
    message(FATAL_ERROR "Release build does not explicitly disable compatibility probe")
endif()

file(READ "${PRODUCT_ROOT}/scripts/package_native.ps1" PACKAGE_SCRIPT)
string(FIND "${PACKAGE_SCRIPT}"
    "Sonar.Fishing.BuildProfileCompatibilityProbe" PACKAGE_POSITION)
if(NOT PACKAGE_POSITION EQUAL -1)
    message(FATAL_ERROR "Release package script references diagnostic probe executable")
endif()

file(READ "${PRODUCT_ROOT}/scripts/run_build_profile_compatibility_probe.ps1"
    WRAPPER_SCRIPT)
foreach(REQUIRED
        "ValidateRange(5, 10)"
        "build_profile_compatibility_import_scan_failed"
        "build_profile_compatibility_network_dependency_detected"
        "--confirmed-live-build-profile-compatibility")
    string(FIND "${WRAPPER_SCRIPT}" "${REQUIRED}" REQUIRED_POSITION)
    if(REQUIRED_POSITION EQUAL -1)
        message(FATAL_ERROR "Compatibility wrapper lost required gate: ${REQUIRED}")
    endif()
endforeach()
foreach(FORBIDDEN "Start-Process" "Invoke-WebRequest" "Invoke-RestMethod")
    string(FIND "${WRAPPER_SCRIPT}" "${FORBIDDEN}" FORBIDDEN_POSITION)
    if(NOT FORBIDDEN_POSITION EQUAL -1)
        message(FATAL_ERROR "Compatibility wrapper contains forbidden operation: ${FORBIDDEN}")
    endif()
endforeach()

file(READ "${PRODUCT_ROOT}/scripts/run_inventory_state_characterization.ps1"
    INVENTORY_WRAPPER_SCRIPT)
foreach(REQUIRED
        "ConfirmedManualInventoryCharacterization"
        "inventory_characterization_import_scan_failed"
        "inventory_characterization_network_dependency_detected"
        "--confirmed-manual-inventory-characterization")
    string(FIND "${INVENTORY_WRAPPER_SCRIPT}" "${REQUIRED}" REQUIRED_POSITION)
    if(REQUIRED_POSITION EQUAL -1)
        message(FATAL_ERROR
            "Inventory characterization wrapper lost required gate: ${REQUIRED}")
    endif()
endforeach()
foreach(FORBIDDEN "Start-Process" "Invoke-WebRequest" "Invoke-RestMethod")
    string(FIND "${INVENTORY_WRAPPER_SCRIPT}" "${FORBIDDEN}" FORBIDDEN_POSITION)
    if(NOT FORBIDDEN_POSITION EQUAL -1)
        message(FATAL_ERROR
            "Inventory characterization wrapper contains forbidden operation: ${FORBIDDEN}")
    endif()
endforeach()

file(READ "${PRODUCT_ROOT}/product-commands.json" PRODUCT_COMMANDS)
foreach(REQUIRED
        "fishing-build-profile-compatibility-probe"
        "run_build_profile_compatibility_probe.ps1")
    string(FIND "${PRODUCT_COMMANDS}" "${REQUIRED}" COMMAND_POSITION)
    if(COMMAND_POSITION EQUAL -1)
        message(FATAL_ERROR "Product command lost compatibility probe contract: ${REQUIRED}")
    endif()
endforeach()
string(FIND "${PRODUCT_COMMANDS}"
    "ConfirmedLiveBuildProfileCompatibility" REDUNDANT_CONFIRMATION_POSITION)
if(NOT REDUNDANT_CONFIRMATION_POSITION EQUAL -1)
    message(FATAL_ERROR
        "Product command exposes a redundant read-only confirmation toggle")
endif()
