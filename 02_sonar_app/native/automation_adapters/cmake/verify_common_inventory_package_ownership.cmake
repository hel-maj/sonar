if(NOT DEFINED PACKAGE_ROOT OR NOT IS_DIRECTORY "${PACKAGE_ROOT}")
    message(FATAL_ERROR "installed Common inventory package is missing")
endif()
if(NOT DEFINED SOURCE_ROOT OR NOT IS_DIRECTORY "${SOURCE_ROOT}")
    message(FATAL_ERROR "Fishing source root is missing")
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
   "1426967DC010CCDA80749DF15B6C3ADE8C3318A7FE63A21E6378FD69F787A612")
    message(FATAL_ERROR "installed Common inventory manifest hash drifted")
endif()

set(catalog_manifest "${CATALOG_PACKAGE_ROOT}/SHA256SUMS.txt")
if(NOT EXISTS "${catalog_manifest}")
    message(FATAL_ERROR "installed Common Majestic catalog manifest is missing")
endif()
file(SHA256 "${catalog_manifest}" actual_catalog_manifest_hash)
string(TOUPPER "${actual_catalog_manifest_hash}" actual_catalog_manifest_hash)
if(NOT actual_catalog_manifest_hash STREQUAL
   "EAF7FAD575747B773C0E5DB82D8E923343C35642FF24A8E4640B2D7B4040EBDB")
    message(FATAL_ERROR "installed Common Majestic catalog manifest hash drifted")
endif()

file(READ "${SOURCE_ROOT}/CMakeLists.txt" root_cmake)
foreach(required IN ITEMS
        "SonarMajesticCefInventory 0.1.19 EXACT CONFIG REQUIRED"
        "SonarMajesticCatalog 1.0.0 EXACT CONFIG REQUIRED"
        "SONAR_COMMON_MAJESTIC_CATALOG_PACKAGE"
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
        ".image_sha256 = {}"
        ".admission = process_admission::trusted_publisher_runtime")
    string(FIND "${production_memory_connector}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR
            "Shipping memory connector lost version-independent trusted admission: ${required}")
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
foreach(forbidden IN ITEMS
        "exact_image_sha256"
        "embedded_memory_build_profiles"
        "SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE")
    string(FIND "${production_memory_connector}" "${forbidden}" connector_index)
    if(NOT connector_index EQUAL -1)
        message(FATAL_ERROR
            "Shipping memory connector selected the forensic SHA seam: ${forbidden}")
    endif()
endforeach()
if(NOT root_cmake MATCHES
   "option\\([\r\n ]*SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE[^\\)]*[\r\n ]OFF[\r\n ]*\\)")
    message(FATAL_ERROR
        "Forensic build-profile compatibility probe is not default-OFF")
endif()

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
