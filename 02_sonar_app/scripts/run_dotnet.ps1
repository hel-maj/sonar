[CmdletBinding(DefaultParameterSetName = "Demo")]
param(
    [Parameter(Mandatory, ParameterSetName = "Demo")]
    [switch]$Demo,
    [Parameter(Mandatory, ParameterSetName = "OfflineEngine")]
    [string]$OfflineEngine,
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$ProtocExecutable = $env:SONAR_PROTOC_EXECUTABLE,
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release",
    [switch]$NoBuild
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$hostProject = Join-Path $productRoot "src\dotnet\Sonar.Fishing.Host\Sonar.Fishing.Host.csproj"
$packageCache = Join-Path $productRoot "build\nuget\managed-packages-deterministic-v2"

if (-not $NoBuild) {
    $buildArguments = @(
        "-NoProfile",
        "-ExecutionPolicy", "Bypass",
        "-File", (Join-Path $PSScriptRoot "build_dotnet.ps1"),
        "-Configuration", $Configuration
    )
    if (-not [string]::IsNullOrWhiteSpace($CommonFeed)) {
        $buildArguments += @("-CommonFeed", $CommonFeed)
    }
    if (-not [string]::IsNullOrWhiteSpace($ProtocExecutable)) {
        $buildArguments += @("-ProtocExecutable", $ProtocExecutable)
    }
    & powershell @buildArguments
    if ($LASTEXITCODE -ne 0) {
        throw "WPF Host build failed with exit code ${LASTEXITCODE}"
    }
}

if ([string]::IsNullOrWhiteSpace($CommonFeed)) {
    $CommonFeed = Join-Path $productRoot "..\..\.artifacts\sonar-feed"
}
if (-not [Uri]::IsWellFormedUriString($CommonFeed, [UriKind]::Absolute)) {
    if (-not [IO.Path]::IsPathRooted($CommonFeed)) {
        $CommonFeed = Join-Path $productRoot $CommonFeed
    }
    $CommonFeed = (Resolve-Path -LiteralPath $CommonFeed).Path
}
if ([string]::IsNullOrWhiteSpace($ProtocExecutable)) {
    $ProtocExecutable = Join-Path $productRoot "..\..\.artifacts\sonar-tools\protoc\35.1\bin\protoc.exe"
}
if (-not [IO.Path]::IsPathRooted($ProtocExecutable)) {
    $ProtocExecutable = Join-Path $productRoot $ProtocExecutable
}
$ProtocExecutable = (Resolve-Path -LiteralPath $ProtocExecutable).Path

$applicationArguments = @("--demo")
if ($PSCmdlet.ParameterSetName -eq "OfflineEngine") {
    if (-not [IO.Path]::IsPathRooted($OfflineEngine)) {
        $OfflineEngine = Join-Path $productRoot $OfflineEngine
    }
    if (-not (Test-Path -LiteralPath $OfflineEngine -PathType Leaf)) {
        throw "Offline Fishing Engine does not exist: $OfflineEngine"
    }
    $OfflineEngine = (Resolve-Path -LiteralPath $OfflineEngine).Path
    $applicationArguments = @("--offline-engine", $OfflineEngine)
}

& dotnet run `
    --project $hostProject `
    --configuration $Configuration `
    --no-build `
    --no-restore `
    --nologo `
    "-p:CommonFeed=$CommonFeed" `
    "-p:SonarProtocExecutable=$ProtocExecutable" `
    "-p:RestorePackagesPath=$packageCache" `
    -- `
    @applicationArguments
if ($LASTEXITCODE -ne 0) {
    throw "WPF Host exited with code ${LASTEXITCODE}"
}
