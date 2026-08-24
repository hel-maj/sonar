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

[void](Assert-FishingDeveloperFullAccessLaunchAdmission `
    $productRoot $BundleDirectory)
Write-Output "PASS Fishing developer-full-access launch admission: $BundleDirectory"
