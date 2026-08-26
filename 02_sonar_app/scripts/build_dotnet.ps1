[CmdletBinding()]
param(
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$ProtocExecutable = $env:SONAR_PROTOC_EXECUTABLE,
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release"
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$hostProject = Join-Path $productRoot "src\dotnet\Sonar.Fishing.Host\Sonar.Fishing.Host.csproj"
$packageCache = Join-Path $productRoot "build\nuget\managed-packages-deterministic-v2"
$expectedProtocHash = "C77B7F5125113306ECDE9B328E72466E5CA805A3974DBF10B9DF91A35781E89C"
$expectedCommunityToolkitHash = "8CB4B5BE8E95F9F1EC26CF341D84FBEE8244E88102EBC7C88242E960E0E35805"
$expectedPackages = @{
    "Sonar.Inventory.Ipc.Contracts.0.1.0.nupkg" = "C5A771A49D5E9B67E366E3A82AD0066E528B65536BA6B1293EBC0854DE9E3172"
    "Sonar.Platform.Ipc.Contracts.0.1.1.nupkg" = "33137FEBA79D2C7DD980E44189B73CB108231BCC443A2674853A2820466CFBD2"
    "Sonar.Platform.Ipc.NamedPipes.0.1.1.nupkg" = "0CF50FDAFFF00608F0B5742C39A15B3AB24CF79329DA8B07A01404E9F7A45214"
    "Sonar.Platform.Processes.0.1.0.nupkg" = "03DEE12DCB7F2C30A21921A9198CA5388D93A682B8CCE69658CAD0E1996AE5EB"
    "Sonar.UI.Wpf.0.2.22.nupkg" = "A2B33A8D7E6F7F4803F8A5D4F703CF091D8D4A18B51F4147413A8D90837BA6A8"
    "emoji.wpf.0.3.4.nupkg" = "A9C0570F97961E3DC2B2BA9E41EB7B28808733D194742D837653478EECE7D191"
    "stfu.0.1.1.nupkg" = "BDD1BAEEEC5FF16B74D0354B88393D002A6E8ECBB19793AB900B9151CE686B3A"
    "jeremyansel.hlsl.targets.1.0.13.nupkg" = "4F4CC76E9EFD35F605042FB6D8BD64EF1203F2174DED65217779BB049CFB22E8"
}

function Resolve-CommonFeed([string]$requestedFeed) {
    if ([string]::IsNullOrWhiteSpace($requestedFeed)) {
        $requestedFeed = Join-Path $productRoot "..\..\.artifacts\sonar-feed"
    }

    $feedUri = $null
    if ([Uri]::TryCreate($requestedFeed, [UriKind]::Absolute, [ref]$feedUri) -and
        $feedUri.Scheme -in @("http", "https")) {
        return $requestedFeed
    }

    $candidate = $requestedFeed
    if (-not [IO.Path]::IsPathRooted($candidate)) {
        $candidate = Join-Path $productRoot $candidate
    }
    if (-not (Test-Path -LiteralPath $candidate -PathType Container)) {
        throw "Sonar Common feed directory does not exist: $candidate"
    }
    return (Resolve-Path -LiteralPath $candidate).Path
}

function Invoke-Dotnet([string[]]$arguments) {
    & dotnet @arguments
    if ($LASTEXITCODE -ne 0) {
        throw "dotnet command failed with exit code ${LASTEXITCODE}"
    }
}

$resolvedFeed = Resolve-CommonFeed $CommonFeed
if (Test-Path -LiteralPath $resolvedFeed -PathType Container) {
    foreach ($package in $expectedPackages.GetEnumerator()) {
        $packagePath = Join-Path $resolvedFeed $package.Key
        if (-not (Test-Path -LiteralPath $packagePath -PathType Leaf)) {
            throw "Pinned Common package is missing: $packagePath"
        }
        $actualHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $packagePath).Hash
        if ($actualHash -ne $package.Value) {
            throw "Pinned Common package hash mismatch for $($package.Key): $actualHash"
        }
    }
}

if ([string]::IsNullOrWhiteSpace($ProtocExecutable)) {
    $ProtocExecutable = Join-Path $productRoot "..\..\.artifacts\sonar-tools\protoc\35.1\bin\protoc.exe"
}
if (-not [IO.Path]::IsPathRooted($ProtocExecutable)) {
    $ProtocExecutable = Join-Path $productRoot $ProtocExecutable
}
if (-not (Test-Path -LiteralPath $ProtocExecutable -PathType Leaf)) {
    throw "Pinned protoc 35.1 executable does not exist: $ProtocExecutable"
}
$ProtocExecutable = (Resolve-Path -LiteralPath $ProtocExecutable).Path
$protocVersion = & $ProtocExecutable --version
if ($LASTEXITCODE -ne 0 -or $protocVersion -ne "libprotoc 35.1") {
    throw "Expected protoc 35.1, received: $protocVersion"
}
$actualProtocHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $ProtocExecutable).Hash
if ($actualProtocHash -ne $expectedProtocHash) {
    throw "Pinned protoc 35.1 hash mismatch: $actualProtocHash"
}

$commonFeedProperty = "-p:CommonFeed=$resolvedFeed"
$protocProperty = "-p:SonarProtocExecutable=$ProtocExecutable"
$packageCacheProperty = "-p:RestorePackagesPath=$packageCache"
Invoke-Dotnet @(
    "restore", $hostProject, "--nologo", $commonFeedProperty, $protocProperty, $packageCacheProperty
)

foreach ($package in $expectedPackages.GetEnumerator()) {
    $match = [regex]::Match($package.Key, "^(?<id>.+)\.(?<version>\d+\.\d+\.\d+)\.nupkg$")
    if (-not $match.Success) {
        throw "Invalid pinned package filename: $($package.Key)"
    }
    $packageId = $match.Groups["id"].Value.ToLowerInvariant()
    $packageVersion = $match.Groups["version"].Value
    $consumedPackage = Join-Path $packageCache "$packageId\$packageVersion\$packageId.$packageVersion.nupkg"
    if (-not (Test-Path -LiteralPath $consumedPackage -PathType Leaf)) {
        throw "Restored exact Common package is missing: $consumedPackage"
    }
    $consumedHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $consumedPackage).Hash
    if ($consumedHash -ne $package.Value) {
        throw "Restored Common package hash mismatch for $($package.Key): $consumedHash"
    }
}

$communityToolkitPackage = Join-Path $packageCache "communitytoolkit.mvvm\8.4.2\communitytoolkit.mvvm.8.4.2.nupkg"
if (-not (Test-Path -LiteralPath $communityToolkitPackage -PathType Leaf)) {
    throw "Pinned CommunityToolkit.Mvvm package is missing: $communityToolkitPackage"
}
$communityToolkitHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $communityToolkitPackage).Hash
if ($communityToolkitHash -ne $expectedCommunityToolkitHash) {
    throw "Pinned CommunityToolkit.Mvvm package hash mismatch: $communityToolkitHash"
}

Invoke-Dotnet @(
    "build", $hostProject,
    "--configuration", $Configuration,
    "--no-restore",
    "--nologo",
    $commonFeedProperty,
    $protocProperty,
    $packageCacheProperty
)
