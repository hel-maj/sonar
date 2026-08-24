[CmdletBinding()]
param(
    [string]$Version = "",
    [string]$OutputDirectory = "",
    [switch]$DevelopmentUnsigned,
    [switch]$SkipOfflineTests,
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$SignToolPath = $env:SONAR_FISHING_SIGNTOOL,
    [string]$SigningCertificateThumbprint = $env:SONAR_FISHING_SIGNING_CERT_THUMBPRINT,
    [string]$TimestampUrl = $env:SONAR_FISHING_TIMESTAMP_URL
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
if ([string]::IsNullOrWhiteSpace($OutputDirectory)) {
    $OutputDirectory = Join-Path $productRoot "build\release\bundle"
}
elseif (-not [IO.Path]::IsPathRooted($OutputDirectory)) {
    $OutputDirectory = Join-Path $productRoot $OutputDirectory
}

$noPythonGate = Join-Path $PSScriptRoot "test_no_python_runtime.ps1"
& $noPythonGate -ProductRoot $productRoot -RunSelfTest
if (-not $DevelopmentUnsigned) {
    $authorityPath = Join-Path $productRoot "docs\migration\runtime-authority.json"
    $authority = Get-Content -LiteralPath $authorityPath -Raw | ConvertFrom-Json
    if (-not $authority.offline_ipc_slice.signed_entitlement.production_rsa_public_key_embedded) {
        throw "native_entitlement_trust_root_missing: production package remains blocked"
    }
    if (-not $authority.offline_ipc_slice.production_cutover -or
        -not $authority.wpf_migration_host.production_cutover) {
        throw "native_cutover_incomplete: production package remains blocked"
    }
}

$implementation = Join-Path $PSScriptRoot "build_release_native.ps1"
if (-not (Test-Path -LiteralPath $implementation -PathType Leaf)) {
    throw "native_release_pipeline_missing: $implementation"
}
$arguments = @{
    Version = $Version
    OutputDirectory = $OutputDirectory
    CommonFeed = $CommonFeed
    SignToolPath = $SignToolPath
    SigningCertificateThumbprint = $SigningCertificateThumbprint
    TimestampUrl = $TimestampUrl
}
if ($DevelopmentUnsigned) {
    $arguments.DevelopmentUnsigned = $true
}
if ($SkipOfflineTests) {
    $arguments.SkipOfflineTests = $true
}
& $implementation @arguments

& $noPythonGate `
    -ProductRoot $productRoot `
    -BundleDirectory $OutputDirectory `
    -BundleLifecycleStage Package
