[CmdletBinding()]
param()

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

foreach ($scriptName in @("setup_native.ps1", "test_ipc.ps1", "build_dotnet.ps1")) {
    $scriptPath = Join-Path $PSScriptRoot $scriptName
    & $scriptPath
}

Write-Host "PASS Fishing WPF Host and inert C++ Engine build"
