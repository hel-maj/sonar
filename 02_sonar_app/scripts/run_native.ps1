[CmdletBinding()]
param(
    [switch]$NoBuild
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
if (-not $NoBuild) {
    & (Join-Path $PSScriptRoot "build_native.ps1")
}

$engine = Join-Path $productRoot "build\native\windows-msvc-v143-ipc\engine_ipc\Release\SonarFishingOfflineEngine.exe"
if (-not (Test-Path -LiteralPath $engine -PathType Leaf)) {
    throw "Offline Fishing Engine is missing: $engine"
}

& (Join-Path $PSScriptRoot "run_dotnet.ps1") -OfflineEngine $engine -NoBuild
