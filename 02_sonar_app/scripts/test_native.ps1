[CmdletBinding()]
param(
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$CommonNativeWindowsPackage =
        $env:SONAR_COMMON_NATIVE_WINDOWS_PACKAGE,
    [string]$CommonMajesticCatalogPackage =
        $env:SONAR_COMMON_MAJESTIC_CATALOG_PACKAGE,
    [string]$CommonMajesticRuntimeModulePackage =
        $env:SONAR_COMMON_MAJESTIC_RUNTIME_MODULE_PACKAGE,
    [string]$CommonMajesticCefInventoryPackage =
        $env:SONAR_COMMON_MAJESTIC_CEF_INVENTORY_PACKAGE
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

foreach ($scriptName in @(
    "setup_native.ps1",
    "test_release_plumbing.ps1",
    "test_dotnet.ps1",
    "test_ipc.ps1"
)) {
    $scriptPath = Join-Path $PSScriptRoot $scriptName
    if ($scriptName -in @("setup_native.ps1", "test_ipc.ps1")) {
        & $scriptPath `
            -CommonFeed $CommonFeed `
            -CommonNativeWindowsPackage $CommonNativeWindowsPackage `
            -CommonMajesticCatalogPackage $CommonMajesticCatalogPackage `
            -CommonMajesticRuntimeModulePackage $CommonMajesticRuntimeModulePackage `
            -CommonMajesticCefInventoryPackage $CommonMajesticCefInventoryPackage
    }
    elseif ($scriptName -eq "test_dotnet.ps1") {
        & $scriptPath -CommonFeed $CommonFeed
    }
    else {
        & $scriptPath
    }
}
