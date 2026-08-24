[CmdletBinding()]
param(
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$ProtocExecutable = $env:SONAR_PROTOC_EXECUTABLE,
    [string]$RenderUiDirectory = "",
    [switch]$DeveloperFullAccess,
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release"
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$noPythonGate = Join-Path $PSScriptRoot "test_no_python_runtime.ps1"
& $noPythonGate -ProductRoot $productRoot -RunSelfTest
$testProject = Join-Path $productRoot "tests\dotnet\Sonar.Fishing.Host.Tests\Sonar.Fishing.Host.Tests.csproj"
$packageCache = Join-Path $productRoot "build\nuget\managed-packages-deterministic-v2"
$expectedProtocHash = "C77B7F5125113306ECDE9B328E72466E5CA805A3974DBF10B9DF91A35781E89C"
$expectedCommunityToolkitHash = "8CB4B5BE8E95F9F1EC26CF341D84FBEE8244E88102EBC7C88242E960E0E35805"
$expectedPackages = @{
    "Sonar.Platform.Ipc.Contracts.0.1.1.nupkg" = "33137FEBA79D2C7DD980E44189B73CB108231BCC443A2674853A2820466CFBD2"
    "Sonar.Platform.Ipc.NamedPipes.0.1.1.nupkg" = "0CF50FDAFFF00608F0B5742C39A15B3AB24CF79329DA8B07A01404E9F7A45214"
    "Sonar.Platform.Processes.0.1.0.nupkg" = "03DEE12DCB7F2C30A21921A9198CA5388D93A682B8CCE69658CAD0E1996AE5EB"
    "Sonar.Licensing.Verification.0.1.3.nupkg" = "CA1DAC5C5220872F15130C863AB5D12E85709AC19D4972AFC7193C8223FA7518"
    "Sonar.UI.Wpf.0.2.19.nupkg" = "37BE4E2FB5C38B400640D3EB5CF91DC54BB8052C09D9C50BD67DBFE40F3AEB33"
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
$developerProperty = "-p:SonarFishingDeveloperFullAccess=$($DeveloperFullAccess.IsPresent.ToString().ToLowerInvariant())"
Invoke-Dotnet @("restore", $testProject, "--nologo", $commonFeedProperty, $protocProperty, $packageCacheProperty, $developerProperty)
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
Invoke-Dotnet @("build", $testProject, "--configuration", $Configuration, "--no-restore", "--nologo", $commonFeedProperty, $protocProperty, $packageCacheProperty, $developerProperty)
Invoke-Dotnet @(
    "run",
    "--project", $testProject,
    "--configuration", $Configuration,
    "--no-build",
    "--no-restore",
    $commonFeedProperty,
    $protocProperty,
    $packageCacheProperty,
    $developerProperty
)
if (-not [string]::IsNullOrWhiteSpace($RenderUiDirectory)) {
    if (-not [IO.Path]::IsPathRooted($RenderUiDirectory)) {
        $RenderUiDirectory = Join-Path $productRoot $RenderUiDirectory
    }
    $RenderUiDirectory = [IO.Path]::GetFullPath($RenderUiDirectory)
    Invoke-Dotnet @(
        "run",
        "--project", $testProject,
        "--configuration", $Configuration,
        "--no-build",
        "--no-restore",
        $commonFeedProperty,
        $protocProperty,
        $packageCacheProperty,
        $developerProperty,
        "--",
        "--render-ui", $RenderUiDirectory
    )
}
