[CmdletBinding()]
param(
    [string]$OutputDirectory = "build\ui-gallery",
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$ProtocExecutable = $env:SONAR_PROTOC_EXECUTABLE,
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release"
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$testScript = Join-Path $PSScriptRoot "test_dotnet.ps1"
& $testScript `
    -CommonFeed $CommonFeed `
    -ProtocExecutable $ProtocExecutable `
    -Configuration $Configuration `
    -RenderUiDirectory $OutputDirectory
