[CmdletBinding()]
param(
    [string]$Version = "1.0.0-local",
    [string]$OutputDirectory = "",
    [switch]$SkipOfflineTests,
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$CommonNativePackage = $env:SONAR_COMMON_NATIVE_PACKAGE,
    [string]$CommonNativeWindowsPackage = $env:SONAR_COMMON_NATIVE_WINDOWS_PACKAGE,
    [string]$CommonNativeLicensingPackage = $env:SONAR_COMMON_NATIVE_LICENSING_PACKAGE,
    [string]$CommonMajesticCefInventoryPackage =
        $env:SONAR_COMMON_MAJESTIC_CEF_INVENTORY_PACKAGE,
    [string]$ProtocExecutable = $env:SONAR_PROTOC_EXECUTABLE,
    [string]$CMakeExecutable = $env:SONAR_CMAKE_EXECUTABLE
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
if ([string]::IsNullOrWhiteSpace($OutputDirectory)) {
    $OutputDirectory = Join-Path $productRoot "build\developer-full-access\bundle"
}

$arguments = @{
    Version = $Version
    OutputDirectory = $OutputDirectory
    DevelopmentUnsigned = $true
    DeveloperFullAccess = $true
    CommonFeed = $CommonFeed
    CommonNativePackage = $CommonNativePackage
    CommonNativeWindowsPackage = $CommonNativeWindowsPackage
    CommonNativeLicensingPackage = $CommonNativeLicensingPackage
    CommonMajesticCefInventoryPackage = $CommonMajesticCefInventoryPackage
    ProtocExecutable = $ProtocExecutable
    CMakeExecutable = $CMakeExecutable
}
if ($SkipOfflineTests) {
    $arguments.SkipOfflineTests = $true
}

& (Join-Path $PSScriptRoot "build_release_native.ps1") @arguments
& (Join-Path $PSScriptRoot "verify_developer_full_access.ps1") `
    -BundleDirectory $OutputDirectory
