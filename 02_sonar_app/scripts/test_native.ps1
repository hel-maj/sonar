[CmdletBinding()]
param()

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

foreach ($scriptName in @(
    "setup_native.ps1",
    "test_release_plumbing.ps1",
    "test_dotnet.ps1",
    "test_ipc.ps1"
)) {
    $scriptPath = Join-Path $PSScriptRoot $scriptName
    & $scriptPath
}
