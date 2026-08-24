if(NOT DEFINED PACKAGE_ROOT OR NOT IS_DIRECTORY "${PACKAGE_ROOT}")
    message(FATAL_ERROR "installed Common inventory package is missing")
endif()
if(NOT DEFINED SOURCE_ROOT OR NOT IS_DIRECTORY "${SOURCE_ROOT}")
    message(FATAL_ERROR "Fishing source root is missing")
endif()

set(manifest "${PACKAGE_ROOT}/SHA256SUMS.txt")
if(NOT EXISTS "${manifest}")
    message(FATAL_ERROR "installed Common inventory manifest is missing")
endif()
file(SHA256 "${manifest}" actual_manifest_hash)
string(TOUPPER "${actual_manifest_hash}" actual_manifest_hash)
if(NOT actual_manifest_hash STREQUAL
   "B44CD61110B4B4E152DE52245021CD4C12233E2886EE1FDF323942F27C2352F8")
    message(FATAL_ERROR "installed Common inventory manifest hash drifted")
endif()

file(READ "${SOURCE_ROOT}/CMakeLists.txt" root_cmake)
foreach(required IN ITEMS
        "SonarMajesticCefInventory 0.1.0 EXACT CONFIG REQUIRED"
        "SONAR_COMMON_MAJESTIC_CEF_INVENTORY_PACKAGE")
    string(FIND "${root_cmake}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR "Fishing exact package pin is missing: ${required}")
    endif()
endforeach()

file(READ "${SOURCE_ROOT}/automation_adapters/src/common_inventory_open.cpp" adapter)
file(READ "${SOURCE_ROOT}/automation_adapters/CMakeLists.txt" adapter_cmake)
string(FIND "${adapter_cmake}" "Sonar::MajesticCefInventory" target_index)
if(target_index EQUAL -1)
    message(FATAL_ERROR "Fishing adapter does not link the installed Common facade")
endif()
foreach(forbidden IN ITEMS
        "Windows.h" "ReadProcessMemory" "VirtualQueryEx" "WinVerifyTrust"
        "v8-internal" "renderer_source.hpp" "client_identity.hpp")
    string(FIND "${adapter}" "${forbidden}" index)
    if(NOT index EQUAL -1)
        message(FATAL_ERROR "Fishing copied a Common-owned implementation boundary: ${forbidden}")
    endif()
endforeach()
foreach(required IN ITEMS
        "sonar/majestic/cef_inventory/inventory_open.hpp"
        "create_win32_inventory_open_acquisition"
        "reason_name")
    string(FIND "${adapter}" "${required}" index)
    if(index EQUAL -1)
        message(FATAL_ERROR "Fishing Common facade use is missing: ${required}")
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
