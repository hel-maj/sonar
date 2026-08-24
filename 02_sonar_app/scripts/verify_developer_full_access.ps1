[CmdletBinding()]
param(
    [string]$BundleDirectory = ""
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

. (Join-Path $PSScriptRoot "release_common.ps1")

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
if ([string]::IsNullOrWhiteSpace($BundleDirectory)) {
    $BundleDirectory = Join-Path $productRoot "build\developer-full-access\bundle"
}
elseif (-not [IO.Path]::IsPathRooted($BundleDirectory)) {
    $BundleDirectory = Join-Path $productRoot $BundleDirectory
}
if (-not (Test-Path -LiteralPath $BundleDirectory -PathType Container)) {
    throw "developer_bundle_missing: $BundleDirectory"
}
$BundleDirectory = (Resolve-Path -LiteralPath $BundleDirectory).Path
$manifest = Read-FishingBundleManifest `
    $productRoot `
    $BundleDirectory `
    "developer-full-access-unsigned" `
    -AllowDeveloperFullAccess
if ($manifest.schemaVersion -ne 2 -or
    $manifest.developerFullAccess -ne $true -or
    $manifest.authenticode.required -ne $false) {
    throw "developer_bundle_authority_contract_invalid"
}
if ($manifest.determinism.verified -ne $true) {
    throw "developer_bundle_determinism_unverified"
}

& (Join-Path $PSScriptRoot "test_no_python_runtime.ps1") `
    -ProductRoot $productRoot `
    -BundleDirectory $BundleDirectory `
    -BundleLifecycleStage Package
Assert-FishingDesktopRuntime
Assert-FishingSystemDependencyClosure $BundleDirectory
Assert-FishingHighConfidenceSecretScan $BundleDirectory

Write-Output "PASS Fishing developer-full-access bundle verification: $BundleDirectory"
