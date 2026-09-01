if(NOT DEFINED PACKAGE_ROOT OR NOT IS_DIRECTORY "${PACKAGE_ROOT}")
    message(FATAL_ERROR "installed Common inventory package is missing")
endif()
if(NOT DEFINED SOURCE_ROOT OR NOT IS_DIRECTORY "${SOURCE_ROOT}")
    message(FATAL_ERROR "Fishing source root is missing")
endif()
if(NOT DEFINED RUNTIME_PACKAGE_ROOT OR
   NOT IS_DIRECTORY "${RUNTIME_PACKAGE_ROOT}")
    message(FATAL_ERROR "installed Common runtime-module package is missing")
endif()
if(NOT DEFINED CATALOG_PACKAGE_ROOT OR
   NOT IS_DIRECTORY "${CATALOG_PACKAGE_ROOT}")
    message(FATAL_ERROR "installed Common Majestic catalog package is missing")
endif()

set(manifest "${PACKAGE_ROOT}/SHA256SUMS.txt")
if(NOT EXISTS "${manifest}")
    message(FATAL_ERROR "installed Common inventory manifest is missing")
endif()
file(SHA256 "${manifest}" actual_manifest_hash)
string(TOUPPER "${actual_manifest_hash}" actual_manifest_hash)
if(NOT actual_manifest_hash STREQUAL
   "E79A579A3CAA29E91FC8EA4A4DCDFDDE98FA4D03FACBF5BC8B6AB0C76440A4FE")
    message(FATAL_ERROR "installed Common inventory manifest hash drifted")
endif()

set(runtime_manifest "${RUNTIME_PACKAGE_ROOT}/SHA256SUMS.txt")
if(NOT EXISTS "${runtime_manifest}")
    message(FATAL_ERROR "installed Common runtime-module manifest is missing")
endif()
file(SHA256 "${runtime_manifest}" actual_runtime_manifest_hash)
string(TOUPPER "${actual_runtime_manifest_hash}" actual_runtime_manifest_hash)
if(NOT actual_runtime_manifest_hash STREQUAL
   "6E902CF03A7F19F4451D6F5F03CFAD6AA2B2928FEB9C56C5B873CD6EC1ADA845")
    message(FATAL_ERROR "installed Common runtime-module manifest hash drifted")
endif()

set(runtime_config
    "${RUNTIME_PACKAGE_ROOT}/lib/cmake/SonarMajesticRuntimeModule/SonarMajesticRuntimeModuleConfig.cmake")
set(runtime_targets
    "${RUNTIME_PACKAGE_ROOT}/lib/cmake/SonarMajesticRuntimeModule/SonarMajesticRuntimeModuleTargets.cmake")
set(inventory_config
    "${PACKAGE_ROOT}/lib/cmake/SonarMajesticCefInventory/SonarMajesticCefInventoryConfig.cmake")
set(inventory_targets
    "${PACKAGE_ROOT}/lib/cmake/SonarMajesticCefInventory/SonarMajesticCefInventoryTargets.cmake")
foreach(required_file IN ITEMS
        "${runtime_config}"
        "${runtime_targets}"
        "${inventory_config}"
        "${inventory_targets}")
    if(NOT EXISTS "${required_file}")
        message(FATAL_ERROR "installed Common package metadata is missing: ${required_file}")
    endif()
endforeach()
file(READ "${runtime_config}" runtime_config_text)
file(READ "${runtime_targets}" runtime_targets_text)
file(READ "${inventory_config}" inventory_config_text)
file(READ "${inventory_targets}" inventory_targets_text)
foreach(required IN ITEMS
        "find_dependency(SonarPlatformWindows 0.1.12 EXACT CONFIG)"
        "SonarMajesticRuntimeModuleTargets.cmake")
    string(FIND "${runtime_config_text}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR
            "Common runtime-module package dependency contract is missing: ${required}")
    endif()
endforeach()
foreach(required IN ITEMS
        "Sonar::MajesticRuntimeModule"
        "Sonar::PlatformWindowsProcess"
        "Sonar::PlatformWindowsTrustedModule")
    string(FIND "${runtime_targets_text}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR
            "Common runtime-module target contract is missing: ${required}")
    endif()
endforeach()
string(FIND "${runtime_targets_text}" "MajesticCefInventory" runtime_cef_index)
if(NOT runtime_cef_index EQUAL -1)
    message(FATAL_ERROR
        "Common runtime-module package gained a reverse CEF dependency")
endif()
foreach(required IN ITEMS
        "find_dependency(SonarPlatformWindows 0.1.12 EXACT CONFIG)"
        "find_dependency(SonarMajesticRuntimeModule 0.1.3 EXACT CONFIG)"
        "find_dependency(SonarMajesticCatalog 1.1.0 EXACT CONFIG)")
    string(FIND "${inventory_config_text}" "${required}"
        inventory_dependency_index)
    if(inventory_dependency_index EQUAL -1)
        message(FATAL_ERROR
            "Common inventory package lost an exact dependency: ${required}")
    endif()
endforeach()
string(FIND "${inventory_targets_text}"
    "Sonar::MajesticRuntimeModule"
    inventory_runtime_target_index)
if(inventory_runtime_target_index EQUAL -1)
    message(FATAL_ERROR
        "Common inventory targets lost their shared runtime-module owner")
endif()

set(catalog_manifest "${CATALOG_PACKAGE_ROOT}/SHA256SUMS.txt")
if(NOT EXISTS "${catalog_manifest}")
    message(FATAL_ERROR "installed Common Majestic catalog manifest is missing")
endif()
file(SHA256 "${catalog_manifest}" actual_catalog_manifest_hash)
string(TOUPPER "${actual_catalog_manifest_hash}" actual_catalog_manifest_hash)
if(NOT actual_catalog_manifest_hash STREQUAL
   "DEA15129044D2B820F6F4AE6307EB5B810166486654AFD8ABCA2E037FE5829B1")
    message(FATAL_ERROR "installed Common Majestic catalog manifest hash drifted")
endif()

file(READ "${SOURCE_ROOT}/CMakeLists.txt" root_cmake)
foreach(required IN ITEMS
        "SonarPlatformWindows 0.1.12 EXACT CONFIG REQUIRED"
        "SonarMajesticRuntimeModule 0.1.3 EXACT CONFIG REQUIRED"
        "SonarMajesticCefInventory 0.1.33 EXACT CONFIG REQUIRED"
        "SonarMajesticCatalog 1.1.0 EXACT CONFIG REQUIRED"
        "SONAR_COMMON_MAJESTIC_CATALOG_PACKAGE"
        "SONAR_COMMON_MAJESTIC_RUNTIME_MODULE_PACKAGE"
        "SONAR_COMMON_MAJESTIC_CEF_INVENTORY_PACKAGE")
    string(FIND "${root_cmake}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR "Fishing exact package pin is missing: ${required}")
    endif()
endforeach()

file(READ
    "${SOURCE_ROOT}/engine_ipc/src/production_inventory_sampler.cpp"
    production_inventory_sampler)
file(READ
    "${SOURCE_ROOT}/engine_ipc/src/production_composition.cpp"
    production_composition)
file(READ
    "${SOURCE_ROOT}/memory_observation/src/windows_memory_connector.cpp"
    production_memory_connector)
foreach(required IN ITEMS
        "sonar/majestic/cef_inventory/content/win32_provider.hpp"
        "create_win32_trusted_publisher_inventory_content_provider")
    string(FIND "${production_inventory_sampler}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR
            "Shipping inventory sampler lost the Common trusted-publisher content factory: ${required}")
    endif()
endforeach()
foreach(required IN ITEMS
        "sonar/majestic/runtime_module/runtime_module.hpp"
        "sonar::majestic::runtime_module"
        "win32_runtime_module_role::gta5"
        "win32_runtime_module_role::majestic_webengine"
        "open_win32_trusted_runtime_module_lease"
        ".image_sha256 = {}"
        ".admission = process_admission::trusted_publisher_runtime")
    string(FIND "${production_memory_connector}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR
            "Shipping memory connector lost the Common role-owned admission facade: ${required}")
    endif()
endforeach()
file(READ "${SOURCE_ROOT}/memory_observation/CMakeLists.txt"
    memory_observation_cmake)
string(FIND "${memory_observation_cmake}"
    "Sonar::MajesticRuntimeModule"
    direct_runtime_target_index)
if(direct_runtime_target_index EQUAL -1)
    message(FATAL_ERROR
        "Fishing memory connector lost its direct Common runtime-module link")
endif()
string(FIND "${memory_observation_cmake}"
    "Sonar::MajesticCefInventory"
    memory_cef_target_index)
if(NOT memory_cef_target_index EQUAL -1)
    message(FATAL_ERROR
        "Fishing memory connector still depends on the monolithic CEF facade")
endif()
string(REGEX MATCHALL
    "(^|[^A-Za-z0-9_])open_win32_trusted_runtime_module_lease[ \t\r\n]*\\("
    common_runtime_module_open_calls
    "${production_memory_connector}")
list(LENGTH common_runtime_module_open_calls common_runtime_module_open_count)
if(NOT common_runtime_module_open_count EQUAL 1)
    message(FATAL_ERROR
        "Shipping memory connector must have exactly one Common role+PID admission call")
endif()
string(REGEX MATCH
    "(^|[^A-Za-z0-9_])open_trusted_module_lease[ \t\r\n]*\\("
    raw_trusted_module_open_call
    "${production_memory_connector}")
if(raw_trusted_module_open_call)
    message(FATAL_ERROR
        "Shipping memory connector bypassed the Common role-owned admission facade")
endif()
foreach(forbidden IN ITEMS
        "565932392989B3616F2968E1B1D6F974561B1F32"
        "B03C125E345303D797A951DA1BC76B960C21FF57"
        "GTA5.exe"
        "majestic-webengine.exe"
        "accepted_publisher_thumbprints"
        "publisher_thumbprint"
        "trusted_module_policy"
        "readonly_process::open"
        "expected_gta_module_size"
        "expected_loaded_image_size"
        "expected_module_size"
        "expected_file_size"
        "expected_file_sha256"
        "expected_pe_timestamp"
        "expected_file_version"
        "expected_product_version"
        "file_version"
        "product_version"
        "exact_image_sha256"
        "exact_profile"
        "known_build"
        "embedded_memory_build_profiles"
        "SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE")
    string(FIND "${production_memory_connector}" "${forbidden}" index)
    if(NOT index EQUAL -1)
        message(FATAL_ERROR
            "Shipping memory connector retained caller-owned admission policy: ${forbidden}")
    endif()
endforeach()
foreach(forbidden IN ITEMS
        "ExactForensicCefV8"
        "exact_profile"
        "nonshipping_profile_approval"
        "majestic_client_1_20_7_candidate"
        "policy.profile"
        "expected_gta_module_size"
        "expected_loaded_image_size"
        "expected_module_size"
        "expected_file_size"
        "expected_file_sha256"
        "expected_pe_timestamp"
        "file_version"
        "product_version"
        "file_sha256"
        "first_non_string"
        "one_byte_string_type"
        "sequential_string_tag"
        "cons_string_tag"
        "thin_string_tag"
        "exact_image_sha256"
        "embedded_memory_build_profiles"
        "CefV8"
        "instance_type")
    string(FIND "${production_inventory_sampler}" "${forbidden}" sampler_index)
    string(FIND "${production_composition}" "${forbidden}" composition_index)
    if(NOT sampler_index EQUAL -1 OR NOT composition_index EQUAL -1)
        message(FATAL_ERROR
            "Shipping inventory composition retained build-specific CEF admission: ${forbidden}")
    endif()
endforeach()
if(NOT root_cmake MATCHES
   "option\\([\r\n ]*SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE[^\\)]*[\r\n ]OFF[\r\n ]*\\)")
    message(FATAL_ERROR
        "Forensic build-profile compatibility probe is not default-OFF")
endif()
file(READ
    "${SOURCE_ROOT}/build_profile_compatibility_probe/CMakeLists.txt"
    forensic_probe_cmake)
foreach(required IN ITEMS
        "if(NOT SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE)"
        "return()")
    string(FIND "${forensic_probe_cmake}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR
            "Forensic SHA seam lost its explicit non-shipping guard: ${required}")
    endif()
endforeach()

file(READ "${SOURCE_ROOT}/automation_adapters/src/common_inventory_open.cpp" adapter)
file(READ "${SOURCE_ROOT}/automation_adapters/include/sonar/fishing/automation_adapters/common_inventory_open.h" adapter_header)
file(READ "${SOURCE_ROOT}/automation_adapters/CMakeLists.txt" adapter_cmake)
string(FIND "${adapter_cmake}" "Sonar::MajesticCefInventory" target_index)
if(target_index EQUAL -1)
    message(FATAL_ERROR "Fishing adapter does not link the installed Common facade")
endif()
foreach(forbidden IN ITEMS
        "Windows.h" "ReadProcessMemory" "VirtualQueryEx" "WinVerifyTrust"
        "v8-internal" "renderer_source.hpp" "client_identity.hpp"
        "SONAR_FISHING_DEVELOPER_FULL_ACCESS"
        "create_win32_inventory_open_acquisition"
        "nonshipping_profile_approval"
        "majestic_client_1_20_7_candidate"
        "policy.profile"
        "expected_gta_module_size"
        "expected_loaded_image_size"
        "file_version"
        "product_version"
        "file_sha256")
    string(FIND "${adapter}" "${forbidden}" index)
    if(NOT index EQUAL -1)
        message(FATAL_ERROR "Fishing copied a Common-owned implementation boundary: ${forbidden}")
    endif()
endforeach()

string(FIND "${adapter_cmake}" "SONAR_FISHING_DEVELOPER_FULL_ACCESS" local_mode_index)
if(NOT local_mode_index EQUAL -1)
    message(FATAL_ERROR
        "Fishing inventory adapter composition still varies by Local Access mode")
endif()
foreach(required IN ITEMS
        "sonar/majestic/cef_inventory/inventory_open.hpp"
        "create_win32_trusted_publisher_inventory_open_acquisition"
        "policy.allow_closed_open_state_bootstrap = true"
        "policy, true"
        "reason_name")
    string(FIND "${adapter}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR "Fishing Common facade use is missing: ${required}")
    endif()
endforeach()

foreach(forbidden IN ITEMS
        "SONAR_FISHING_DEVELOPER_FULL_ACCESS"
        "candidate_profile"
        "1.20.7")
    string(FIND "${adapter_header}" "${forbidden}" index)
    if(NOT index EQUAL -1)
        message(FATAL_ERROR "Fishing runtime header retained exact-profile admission: ${forbidden}")
    endif()
endforeach()

file(READ "${SOURCE_ROOT}/automation_adapters/src/fishing_adapters.cpp" routing)
foreach(forbidden IN ITEMS "resolve_inventory(" "resolve_runtime_observation(")
    string(FIND "${routing}" "${forbidden}" index)
    if(NOT index EQUAL -1)
        message(FATAL_ERROR "legacy Fishing inventory binding remains production authority")
    endif()
endforeach()
string(FIND "${routing}" "capture_reeling_with_bounded_retry" reeling_index)
string(FIND "${routing}" "inventory_open_->capture" inventory_index)
if(reeling_index EQUAL -1 OR inventory_index EQUAL -1)
    message(FATAL_ERROR "coarse production routing is incomplete")
endif()
