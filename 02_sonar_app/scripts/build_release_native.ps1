[CmdletBinding()]
param(
    [string]$Version = "",
    [string]$OutputDirectory = "",
    [switch]$DevelopmentUnsigned,
    [switch]$DeveloperFullAccess,
    [switch]$SkipOfflineTests,
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$CommonNativePackage = $env:SONAR_COMMON_NATIVE_PACKAGE,
    [string]$CommonNativeWindowsPackage = $env:SONAR_COMMON_NATIVE_WINDOWS_PACKAGE,
    [string]$CommonNativeLicensingPackage = $env:SONAR_COMMON_NATIVE_LICENSING_PACKAGE,
    [string]$ProtocExecutable = $env:SONAR_PROTOC_EXECUTABLE,
    [string]$CMakeExecutable = $env:SONAR_CMAKE_EXECUTABLE,
    [string]$SignToolPath = $env:SONAR_FISHING_SIGNTOOL,
    [string]$SigningCertificateThumbprint = $env:SONAR_FISHING_SIGNING_CERT_THUMBPRINT,
    [string]$TimestampUrl = $env:SONAR_FISHING_TIMESTAMP_URL
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

. (Join-Path $PSScriptRoot "release_common.ps1")

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$releaseMode = if ($DeveloperFullAccess) {
    "developer-full-access-unsigned"
}
elseif ($DevelopmentUnsigned) {
    "development-unsigned"
}
else {
    "production-signed"
}
if ($DeveloperFullAccess -and -not $DevelopmentUnsigned) {
    throw "developer_full_access_requires_unsigned_build"
}
if ([string]::IsNullOrWhiteSpace($Version)) {
    if ($DevelopmentUnsigned) {
        $Version = "0.0.0-dev"
    }
    else {
        throw "release_version_required"
    }
}
$Version = Get-FishingCanonicalVersion $Version
if ($SkipOfflineTests -and -not $DevelopmentUnsigned) {
    throw "release_tests_cannot_be_skipped_in_production"
}
if ([string]::IsNullOrWhiteSpace($OutputDirectory)) {
    $OutputDirectory = if ($DeveloperFullAccess) {
        Join-Path $productRoot "build\developer-full-access\bundle"
    }
    else {
        Join-Path $productRoot "build\release\bundle"
    }
}
elseif (-not [IO.Path]::IsPathRooted($OutputDirectory)) {
    $OutputDirectory = Join-Path $productRoot $OutputDirectory
}
$OutputDirectory = Assert-FishingSafeBuildPath `
    $productRoot $OutputDirectory "release bundle"

function Resolve-RequiredDirectory(
    [string]$Requested,
    [string]$Fallback,
    [string]$Description) {
    $candidate = if ([string]::IsNullOrWhiteSpace($Requested)) {
        $Fallback
    }
    else {
        $Requested
    }
    if (-not [IO.Path]::IsPathRooted($candidate)) {
        $candidate = Join-Path $productRoot $candidate
    }
    if (-not (Test-Path -LiteralPath $candidate -PathType Container)) {
        throw "release_dependency_missing: $Description"
    }
    return (Resolve-Path -LiteralPath $candidate).Path
}

function Resolve-RequiredExecutable(
    [string]$Requested,
    [string[]]$Fallbacks,
    [string]$Description) {
    $candidates = [Collections.Generic.List[string]]::new()
    if (-not [string]::IsNullOrWhiteSpace($Requested)) {
        $command = Get-Command $Requested -ErrorAction SilentlyContinue
        $candidates.Add($(if ($null -eq $command) { $Requested } else { $command.Source }))
    }
    foreach ($fallback in $Fallbacks) {
        if (-not [string]::IsNullOrWhiteSpace($fallback)) {
            $candidates.Add($fallback)
        }
    }
    foreach ($candidate in $candidates) {
        $path = if ([IO.Path]::IsPathRooted($candidate)) {
            $candidate
        }
        else {
            Join-Path $productRoot $candidate
        }
        if (Test-Path -LiteralPath $path -PathType Leaf) {
            return (Resolve-Path -LiteralPath $path).Path
        }
    }
    throw "release_dependency_missing: $Description"
}

function Invoke-Checked([string]$Executable, [string[]]$Arguments) {
    & $Executable @Arguments 2>&1 | ForEach-Object { Write-Host $_ }
    $exitCode = $LASTEXITCODE
    if ($exitCode -ne 0) {
        throw "release_command_failed: $([IO.Path]::GetFileName($Executable)) exit=$exitCode"
    }
}

function Assert-ProductionAuthority {
    $authorityPath = Join-Path $productRoot "docs\migration\runtime-authority.json"
    if (-not (Test-Path -LiteralPath $authorityPath -PathType Leaf)) {
        throw "native_authority_ledger_missing"
    }
    $authority = Get-Content -Raw -LiteralPath $authorityPath | ConvertFrom-Json
    if (-not $authority.offline_ipc_slice.signed_entitlement.production_rsa_public_key_embedded) {
        throw "native_entitlement_trust_root_missing"
    }
    if (-not $authority.offline_ipc_slice.production_cutover -or
        -not $authority.wpf_migration_host.production_cutover) {
        throw "native_cutover_incomplete"
    }
}

function Add-LocalPackage([string]$Source, [string]$Destination) {
    $target = Join-Path $Destination ([IO.Path]::GetFileName($Source))
    if (Test-Path -LiteralPath $target -PathType Leaf) {
        if ((Get-FishingSha256 $Source) -cne (Get-FishingSha256 $target)) {
            throw "release_local_feed_collision: $([IO.Path]::GetFileName($Source))"
        }
        return
    }
    Copy-Item -LiteralPath $Source -Destination $target
}

function Publish-FishingHost(
    [string]$BuildRoot,
    [string]$LocalFeed,
    [string]$ResolvedProtoc) {
    $hostProject = Join-Path $productRoot `
        "src\dotnet\Sonar.Fishing.Host\Sonar.Fishing.Host.csproj"
    $publishDirectory = Join-Path $BuildRoot "host-publish"
    $packageDirectory = Join-Path $BuildRoot "packages"
    $artifactsDirectory = Join-Path $BuildRoot "managed-artifacts"
    New-Item -ItemType Directory -Path $publishDirectory -Force | Out-Null
    New-Item -ItemType Directory -Path $packageDirectory -Force | Out-Null
    $arguments = @(
        "publish", $hostProject,
        "--configuration", "Release",
        "--runtime", "win-x64",
        "--self-contained", "false",
        "--artifacts-path", $artifactsDirectory,
        "--output", $publishDirectory,
        "--nologo",
        "-p:SonarFishingReleaseBundle=true",
        "-p:UseArtifactsOutput=true",
        "-p:Version=$Version",
        "-p:InformationalVersion=$Version",
        "-p:ContinuousIntegrationBuild=true",
        "-p:Deterministic=true",
        "-p:DebugSymbols=false",
        "-p:DebugType=None",
        "-p:EnableSingleFileAnalyzer=false",
        "-p:DisableTransitiveFrameworkReferenceDownloads=true",
        "-p:EnableRuntimePackDownload=false",
        "-p:PathMap=$productRoot=/_/src%2C$BuildRoot=/_/out",
        "-p:CommonFeed=$LocalFeed",
        "-p:RestoreSources=$LocalFeed",
        "-p:RestoreAdditionalProjectSources=$LocalFeed",
        "-p:RestorePackagesPath=$packageDirectory",
        "-p:NuGetAudit=false",
        "-p:SonarProtocExecutable=$ResolvedProtoc"
    )
    if ($DeveloperFullAccess) {
        $arguments += "-p:SonarFishingDeveloperFullAccess=true"
    }
    Invoke-Checked "dotnet" $arguments
    $publishedFiles = @(Get-ChildItem -LiteralPath $publishDirectory -File -Force)
    if ($publishedFiles.Count -ne 1 -or
        $publishedFiles[0].Name -cne "Sonar.Fishing.Host.exe") {
        $names = $publishedFiles.Name -join ","
        throw "release_host_single_file_contract_failed: $names"
    }
    return $publishedFiles[0].FullName
}

function Build-FishingEngine(
    [string]$BuildRoot,
    [string]$ResolvedCMake,
    [string]$ResolvedNativePackage,
    [string]$ResolvedNativeWindowsPackage,
    [string]$ResolvedNativeLicensingPackage,
    [string]$ResolvedProtoc) {
    $nativeSource = Join-Path $productRoot "native"
    $nativeBuild = Join-Path $BuildRoot "native-build"
    $target = "SonarFishingEngine"
    $developerCMakeValue = if ($DeveloperFullAccess) { "ON" } else { "OFF" }
    Invoke-Checked $ResolvedCMake @(
        "-S", $nativeSource,
        "-B", $nativeBuild,
        "-G", "Visual Studio 17 2022",
        "-A", "x64",
        "-T", "v143",
        "-DSONAR_FISHING_BUILD_OFFLINE_IPC=OFF",
        "-DSONAR_FISHING_BUILD_PRODUCTION_ENGINE=ON",
        "-DSONAR_FISHING_BUILD_LIVE_OBSERVATION_PREFLIGHT=OFF",
        "-DSONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE=OFF",
        "-DSONAR_FISHING_DEVELOPER_FULL_ACCESS=$developerCMakeValue",
        "-DSONAR_COMMON_NATIVE_PACKAGE=$ResolvedNativePackage",
        "-DSONAR_COMMON_NATIVE_WINDOWS_PACKAGE=$ResolvedNativeWindowsPackage",
        "-DSONAR_COMMON_NATIVE_LICENSING_PACKAGE=$ResolvedNativeLicensingPackage",
        "-DSONAR_PROTOC_EXECUTABLE=$ResolvedProtoc",
        "-DCMAKE_EXE_LINKER_FLAGS_RELEASE=/INCREMENTAL:NO /OPT:REF /OPT:ICF /Brepro /PDBALTPATH:Sonar.Engine.pdb"
    )
    Invoke-Checked $ResolvedCMake @(
        "--build", $nativeBuild,
        "--config", "Release",
        "--target", $target
    )
    $expectedNames = @("Sonar.Engine.exe", "SonarFishingEngine.exe")
    $matches = @(Get-ChildItem -LiteralPath $nativeBuild -File -Recurse -Force |
        Where-Object { $expectedNames -contains $_.Name })
    if ($matches.Count -ne 1) {
        throw "release_engine_output_invalid: target=$target matches=$($matches.Count)"
    }
    return $matches[0].FullName
}

function Resolve-SignTool([string]$Requested) {
    $fallbacks = @(
        "C:\Program Files (x86)\Windows Kits\10\bin\10.0.26100.0\x64\signtool.exe",
        "C:\Program Files (x86)\Windows Kits\10\bin\x64\signtool.exe"
    )
    return Resolve-RequiredExecutable $Requested $fallbacks "signtool.exe"
}

function Sign-FishingExecutable(
    [string]$ResolvedSignTool,
    [string]$Path) {
    Invoke-Checked $ResolvedSignTool @(
        "sign", "/q", "/fd", "SHA256",
        "/sha1", $SigningCertificateThumbprint,
        "/tr", $TimestampUrl,
        "/td", "SHA256",
        $Path
    )
    $status = Get-FishingAuthenticodeStatus $Path
    if ($status -cne "Valid") {
        throw "release_authenticode_invalid: $([IO.Path]::GetFileName($Path)) status=$status"
    }
    return $status
}

$noPythonGate = Join-Path $PSScriptRoot "test_no_python_runtime.ps1"
& $noPythonGate -ProductRoot $productRoot -RunSelfTest
if (-not $DevelopmentUnsigned) {
    Assert-ProductionAuthority
}

if ($SkipOfflineTests) {
    & (Join-Path $PSScriptRoot "setup_native.ps1") -CommonFeed $CommonFeed
}
else {
    & (Join-Path $PSScriptRoot "test_native.ps1") -CommonFeed $CommonFeed
}

Assert-FishingDesktopRuntime
$resolvedCommonFeed = Resolve-RequiredDirectory `
    $CommonFeed `
    (Join-Path $productRoot "..\..\.artifacts\sonar-feed") `
    "Sonar Common feed"
$resolvedNativePackage = Resolve-RequiredDirectory `
    $CommonNativePackage `
    (Join-Path $productRoot "..\..\.artifacts\sonar-native\0.1.1") `
    "Sonar Platform IPC native package"
$resolvedNativeWindowsPackage = Resolve-RequiredDirectory `
    $CommonNativeWindowsPackage `
    (Join-Path $productRoot "..\..\.artifacts\sonar-native-windows\0.1.6") `
    "Sonar Platform Windows native package"
$resolvedNativeLicensingPackage = Resolve-RequiredDirectory `
    $CommonNativeLicensingPackage `
    (Join-Path $productRoot "..\..\.artifacts\sonar-native-licensing\0.1.2") `
    "Sonar Platform Licensing native package"
$resolvedProtoc = Resolve-RequiredExecutable `
    $ProtocExecutable `
    @((Join-Path $productRoot "..\..\.artifacts\sonar-tools\protoc\35.1\bin\protoc.exe")) `
    "protoc 35.1"
$cmakeFallbacks = @(
    "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
    "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
    "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
    "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
)
$resolvedCMake = Resolve-RequiredExecutable $CMakeExecutable $cmakeFallbacks "CMake"

$workRoot = Reset-FishingBuildDirectory `
    $productRoot `
    (Join-Path $productRoot "build\release-work\current") `
    "release reproducibility workspace"
$localFeed = Join-Path $workRoot "local-feed"
New-Item -ItemType Directory -Path $localFeed -Force | Out-Null
foreach ($package in Get-ChildItem -LiteralPath $resolvedCommonFeed -Filter "*.nupkg" -File) {
    Add-LocalPackage $package.FullName $localFeed
}
$packageCache = Join-Path $productRoot "build\nuget\managed-packages-deterministic-v2"
if (-not (Test-Path -LiteralPath $packageCache -PathType Container)) {
    throw "release_managed_package_cache_missing"
}
foreach ($package in Get-ChildItem -LiteralPath $packageCache -Filter "*.nupkg" -File -Recurse) {
    Add-LocalPackage $package.FullName $localFeed
}

$firstBuild = Join-Path $workRoot "build-a"
$secondBuild = Join-Path $workRoot "build-b"
New-Item -ItemType Directory -Path $firstBuild -Force | Out-Null
New-Item -ItemType Directory -Path $secondBuild -Force | Out-Null

$firstHost = Publish-FishingHost $firstBuild $localFeed $resolvedProtoc
$firstEngine = Build-FishingEngine `
    $firstBuild $resolvedCMake $resolvedNativePackage `
    $resolvedNativeWindowsPackage $resolvedNativeLicensingPackage $resolvedProtoc
$secondHost = Publish-FishingHost $secondBuild $localFeed $resolvedProtoc
$secondEngine = Build-FishingEngine `
    $secondBuild $resolvedCMake $resolvedNativePackage `
    $resolvedNativeWindowsPackage $resolvedNativeLicensingPackage $resolvedProtoc

$firstHostHash = Get-FishingSha256 $firstHost
$secondHostHash = Get-FishingSha256 $secondHost
$firstEngineHash = Get-FishingSha256 $firstEngine
$secondEngineHash = Get-FishingSha256 $secondEngine
$determinismVerified = $firstHostHash -ceq $secondHostHash -and
    $firstEngineHash -ceq $secondEngineHash
if (-not $determinismVerified -and
    ($DeveloperFullAccess -or -not $DevelopmentUnsigned)) {
    throw "release_unsigned_inputs_not_deterministic"
}
if (-not $determinismVerified) {
    Write-Warning "Development bundle built, but clean-directory unsigned hashes differ."
}

$bundle = Reset-FishingBuildDirectory $productRoot $OutputDirectory "release bundle"
Copy-Item -LiteralPath $firstHost -Destination (Join-Path $bundle "Sonar.exe")
Copy-Item -LiteralPath $firstEngine -Destination (Join-Path $bundle "Sonar.Engine.exe")
New-Item -ItemType Directory -Path (Join-Path $bundle "config") -Force | Out-Null
New-Item -ItemType Directory -Path (Join-Path $bundle "logs") -Force | Out-Null

$hostSignatureStatus = "NotRequired"
$engineSignatureStatus = "NotRequired"
if (-not $DevelopmentUnsigned) {
    if ($SigningCertificateThumbprint -notmatch '^[0-9A-Fa-f]{40}$') {
        throw "release_signing_certificate_missing"
    }
    $timestampUri = $null
    if (-not [Uri]::TryCreate($TimestampUrl, [UriKind]::Absolute, [ref]$timestampUri) -or
        $timestampUri.Scheme -cne "https" -or
        -not [string]::IsNullOrEmpty($timestampUri.UserInfo)) {
        throw "release_timestamp_url_invalid"
    }
    $resolvedSignTool = Resolve-SignTool $SignToolPath
    $hostSignatureStatus = Sign-FishingExecutable `
        $resolvedSignTool (Join-Path $bundle "Sonar.exe")
    $engineSignatureStatus = Sign-FishingExecutable `
        $resolvedSignTool (Join-Path $bundle "Sonar.Engine.exe")
}

$manifest = New-FishingBundleManifestData `
    $productRoot `
    $bundle `
    $Version `
    $releaseMode `
    $firstHostHash `
    $firstEngineHash `
    $secondHostHash `
    $secondEngineHash `
    $determinismVerified `
    $hostSignatureStatus `
    $engineSignatureStatus `
    $DeveloperFullAccess
Write-FishingBundleManifest (Join-Path $bundle "bundle-manifest.json") $manifest
if ($DeveloperFullAccess) {
    [void](Read-FishingBundleManifest `
        $productRoot $bundle $releaseMode -AllowDeveloperFullAccess)
}
else {
    [void](Read-FishingBundleManifest $productRoot $bundle $releaseMode)
}
& $noPythonGate `
    -ProductRoot $productRoot `
    -BundleDirectory $bundle `
    -BundleLifecycleStage Package
Assert-FishingSystemDependencyClosure $bundle
Assert-FishingHighConfidenceSecretScan $bundle

Write-Output "PASS Fishing $releaseMode bundle: $bundle"
Write-Output "BUNDLE_DIRECTORY=$bundle"
