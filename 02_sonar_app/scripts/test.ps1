[CmdletBinding()]
param()

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$nativeTest = Join-Path $PSScriptRoot "test_native.ps1"
& $nativeTest
