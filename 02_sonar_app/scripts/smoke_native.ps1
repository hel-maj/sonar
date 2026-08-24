[CmdletBinding()]
param(
    [string]$BundleDirectory = "",
    [switch]$DevelopmentUnsigned,
    [switch]$StaticOnly,
    [ValidateRange(2, 10)]
    [int]$Cycles = 3
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
if ([string]::IsNullOrWhiteSpace($BundleDirectory)) {
    $BundleDirectory = Join-Path $productRoot "build\release\bundle"
}
elseif (-not [IO.Path]::IsPathRooted($BundleDirectory)) {
    $BundleDirectory = Join-Path $productRoot $BundleDirectory
}

$noPythonGate = Join-Path $PSScriptRoot "test_no_python_runtime.ps1"
& $noPythonGate -ProductRoot $productRoot
if (-not $DevelopmentUnsigned) {
    $authorityPath = Join-Path $productRoot "docs\migration\runtime-authority.json"
    $authority = Get-Content -LiteralPath $authorityPath -Raw | ConvertFrom-Json
    if (-not $authority.offline_ipc_slice.signed_entitlement.production_rsa_public_key_embedded) {
        throw "native_entitlement_trust_root_missing: production smoke remains blocked"
    }
    if (-not $authority.offline_ipc_slice.production_cutover -or
        -not $authority.wpf_migration_host.production_cutover) {
        throw "native_cutover_incomplete: production smoke remains blocked"
    }
}

& $noPythonGate `
    -ProductRoot $productRoot `
    -BundleDirectory $BundleDirectory `
    -BundleLifecycleStage Package

$implementation = Join-Path $PSScriptRoot "smoke_release_native.ps1"
if (-not (Test-Path -LiteralPath $implementation -PathType Leaf)) {
    throw "native_release_smoke_missing: $implementation"
}
$arguments = @{
    BundleDirectory = $BundleDirectory
    Cycles = $Cycles
}
if ($DevelopmentUnsigned) {
    $arguments.DevelopmentUnsigned = $true
}
if ($StaticOnly) {
    $arguments.StaticOnly = $true
}
& $implementation @arguments
