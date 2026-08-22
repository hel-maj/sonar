[CmdletBinding()]
param(
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$CommonNativePackage = $env:SONAR_COMMON_NATIVE_PACKAGE,
    [string]$CommonNativeWindowsPackage = $env:SONAR_COMMON_NATIVE_WINDOWS_PACKAGE,
    [string]$CommonNativeLicensingPackage = $env:SONAR_COMMON_NATIVE_LICENSING_PACKAGE,
    [string]$ProtocExecutable = $env:SONAR_PROTOC_EXECUTABLE,
    [string]$CMakeExecutable = $env:SONAR_CMAKE_EXECUTABLE,
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release"
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$noPythonGate = Join-Path $PSScriptRoot "test_no_python_runtime.ps1"
& $noPythonGate -ProductRoot $productRoot
$nativeSource = Join-Path $productRoot "native"
$nativeBuild = Join-Path $productRoot "build\native\windows-msvc-v143-ipc"
$packageCache = Join-Path $productRoot "build\nuget\managed-packages-deterministic-v2"
$testProject = Join-Path $productRoot "tests\dotnet\Sonar.Fishing.Ipc.IntegrationTests\Sonar.Fishing.Ipc.IntegrationTests.csproj"
$expectedProtocHash = "C77B7F5125113306ECDE9B328E72466E5CA805A3974DBF10B9DF91A35781E89C"
$expectedCommunityToolkitHash = "8CB4B5BE8E95F9F1EC26CF341D84FBEE8244E88102EBC7C88242E960E0E35805"
$expectedNativeManifestHash = "695B6BFAD82A3052A5021BA55F9F833D81672DA755BF98626CC66CFB3DACAE0C"
$expectedNativeWindowsManifestHash = "052F20CF47881FEDB75E25128BB48970798BF22B726DBD71482AFC282907BBAE"
$expectedNativeLicensingManifestHash = "E777E623A2974E07CF4338670C3A41DF13BCDB8990F447987BB1BC0FF21834AC"

function Resolve-Directory([string]$requested, [string]$fallback, [string]$description) {
    if ([string]::IsNullOrWhiteSpace($requested)) {
        $requested = $fallback
    }
    if (-not [IO.Path]::IsPathRooted($requested)) {
        $requested = Join-Path $productRoot $requested
    }
    if (-not (Test-Path -LiteralPath $requested -PathType Container)) {
        throw "$description does not exist: $requested"
    }
    return (Resolve-Path -LiteralPath $requested).Path
}

function Resolve-Executable([string]$requested, [string]$fallback, [string]$description) {
    if ([string]::IsNullOrWhiteSpace($requested)) {
        $requested = $fallback
    }
    if (-not [string]::IsNullOrWhiteSpace($requested) -and
        -not [IO.Path]::IsPathRooted($requested)) {
        $command = Get-Command $requested -ErrorAction SilentlyContinue
        if ($null -ne $command) {
            $requested = $command.Source
        }
        else {
            $requested = Join-Path $productRoot $requested
        }
    }
    if ([string]::IsNullOrWhiteSpace($requested) -or
        -not (Test-Path -LiteralPath $requested -PathType Leaf)) {
        throw "$description does not exist: $requested"
    }
    return (Resolve-Path -LiteralPath $requested).Path
}

function Invoke-Checked([string]$executable, [string[]]$arguments) {
    & $executable @arguments
    if ($LASTEXITCODE -ne 0) {
        throw "$executable failed with exit code ${LASTEXITCODE}"
    }
}

$resolvedFeed = Resolve-Directory `
    $CommonFeed `
    (Join-Path $productRoot "..\..\.artifacts\sonar-feed") `
    "Sonar Common feed"
$resolvedNativePackage = Resolve-Directory `
    $CommonNativePackage `
    (Join-Path $productRoot "..\..\.artifacts\sonar-native\0.1.1") `
    "Installed Sonar Platform IPC native package"
$nativeManifest = Join-Path $resolvedNativePackage "SHA256SUMS.txt"
if (-not (Test-Path -LiteralPath $nativeManifest -PathType Leaf)) {
    throw "Pinned native Common manifest is missing: $nativeManifest"
}
$actualNativeManifestHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $nativeManifest).Hash
if ($actualNativeManifestHash -ne $expectedNativeManifestHash) {
    throw "Pinned native Common manifest hash mismatch: $actualNativeManifestHash"
}
$resolvedNativeWindowsPackage = Resolve-Directory `
    $CommonNativeWindowsPackage `
    (Join-Path $productRoot "..\..\.artifacts\sonar-native-windows\0.1.1") `
    "Installed Sonar Platform Windows native package"
$nativeWindowsManifest = Join-Path $resolvedNativeWindowsPackage "SHA256SUMS.txt"
if (-not (Test-Path -LiteralPath $nativeWindowsManifest -PathType Leaf)) {
    throw "Pinned native Windows Common manifest is missing: $nativeWindowsManifest"
}
$actualNativeWindowsManifestHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $nativeWindowsManifest).Hash
if ($actualNativeWindowsManifestHash -ne $expectedNativeWindowsManifestHash) {
    throw "Pinned native Windows Common manifest hash mismatch: $actualNativeWindowsManifestHash"
}
$resolvedNativeLicensingPackage = Resolve-Directory `
    $CommonNativeLicensingPackage `
    (Join-Path $productRoot "..\..\.artifacts\sonar-native-licensing\0.1.2") `
    "Installed Sonar Platform Licensing native package"
$nativeLicensingManifest = Join-Path $resolvedNativeLicensingPackage "SHA256SUMS.txt"
if (-not (Test-Path -LiteralPath $nativeLicensingManifest -PathType Leaf)) {
    throw "Pinned native Licensing Common manifest is missing: $nativeLicensingManifest"
}
$actualNativeLicensingManifestHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $nativeLicensingManifest).Hash
if ($actualNativeLicensingManifestHash -ne $expectedNativeLicensingManifestHash) {
    throw "Pinned native Licensing Common manifest hash mismatch: $actualNativeLicensingManifestHash"
}
$resolvedProtoc = Resolve-Executable `
    $ProtocExecutable `
    (Join-Path $productRoot "..\..\.artifacts\sonar-tools\protoc\35.1\bin\protoc.exe") `
    "protoc 35.1"
$actualProtocHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $resolvedProtoc).Hash
if ($actualProtocHash -ne $expectedProtocHash) {
    throw "Pinned protoc 35.1 hash mismatch: $actualProtocHash"
}

if ([string]::IsNullOrWhiteSpace($CMakeExecutable)) {
    $cmakeCommand = Get-Command cmake -ErrorAction SilentlyContinue
    if ($null -ne $cmakeCommand) {
        $CMakeExecutable = $cmakeCommand.Source
    }
    else {
        $visualStudioCandidates = @(
            "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
            "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
            "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
            "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
        )
        $CMakeExecutable = $visualStudioCandidates |
            Where-Object { Test-Path -LiteralPath $_ -PathType Leaf } |
            Select-Object -First 1
    }
}
$resolvedCMake = Resolve-Executable $CMakeExecutable "" "CMake executable"
$ctestExecutable = Join-Path (Split-Path -Parent $resolvedCMake) "ctest.exe"
if (-not (Test-Path -LiteralPath $ctestExecutable -PathType Leaf)) {
    throw "CTest executable does not exist next to CMake: $ctestExecutable"
}

$expectedPackages = @{
    "Sonar.Platform.Ipc.Contracts.0.1.1.nupkg" = "33137FEBA79D2C7DD980E44189B73CB108231BCC443A2674853A2820466CFBD2"
    "Sonar.Platform.Ipc.NamedPipes.0.1.1.nupkg" = "0CF50FDAFFF00608F0B5742C39A15B3AB24CF79329DA8B07A01404E9F7A45214"
    "Sonar.Platform.Processes.0.1.0.nupkg" = "03DEE12DCB7F2C30A21921A9198CA5388D93A682B8CCE69658CAD0E1996AE5EB"
    "Sonar.Licensing.Verification.0.1.3.nupkg" = "CA1DAC5C5220872F15130C863AB5D12E85709AC19D4972AFC7193C8223FA7518"
    "Sonar.UI.Wpf.0.2.13.nupkg" = "A2A7BB255E511729E5A2FC1157E72C34D5A19C0EEA03969596B62BFB6FDDD221"
    "emoji.wpf.0.3.4.nupkg" = "A9C0570F97961E3DC2B2BA9E41EB7B28808733D194742D837653478EECE7D191"
    "stfu.0.1.1.nupkg" = "BDD1BAEEEC5FF16B74D0354B88393D002A6E8ECBB19793AB900B9151CE686B3A"
    "jeremyansel.hlsl.targets.1.0.13.nupkg" = "4F4CC76E9EFD35F605042FB6D8BD64EF1203F2174DED65217779BB049CFB22E8"
}
foreach ($package in $expectedPackages.GetEnumerator()) {
    $path = Join-Path $resolvedFeed $package.Key
    if (-not (Test-Path -LiteralPath $path -PathType Leaf)) {
        throw "Pinned Common package is missing: $path"
    }
    $actualHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $path).Hash
    if ($actualHash -ne $package.Value) {
        throw "Pinned Common package hash mismatch for $($package.Key): $actualHash"
    }
}

$chatCorpusManifest = Join-Path $productRoot "tests\fixtures\game_chat\screenshots-v1.tsv"
if (-not (Test-Path -LiteralPath $chatCorpusManifest -PathType Leaf)) {
    throw "Pinned game-chat screenshot manifest is missing: $chatCorpusManifest"
}
$chatCorpusRows = @(Import-Csv -LiteralPath $chatCorpusManifest -Delimiter "`t")
if ($chatCorpusRows.Count -ne 12) {
    throw "Pinned game-chat screenshot corpus must contain exactly 12 rows"
}
$fixtureRoot = [IO.Path]::GetFullPath((Join-Path $productRoot "tests\fixtures"))
foreach ($row in $chatCorpusRows) {
    $fixturePath = [IO.Path]::GetFullPath((Join-Path (Split-Path -Parent $chatCorpusManifest) $row.file))
    if (-not $fixturePath.StartsWith($fixtureRoot, [StringComparison]::OrdinalIgnoreCase)) {
        throw "Game-chat fixture escaped tests/fixtures: $fixturePath"
    }
    if (-not (Test-Path -LiteralPath $fixturePath -PathType Leaf)) {
        throw "Pinned game-chat screenshot is missing: $fixturePath"
    }
    $actualFixtureHash = (Get-FileHash -LiteralPath $fixturePath -Algorithm SHA256).Hash
    if ($actualFixtureHash -ne $row.sha256) {
        throw "Pinned game-chat screenshot hash mismatch for $($row.file): $actualFixtureHash"
    }
    if ((Get-Item -LiteralPath $fixturePath).Length -ne [long]$row.bytes) {
        throw "Pinned game-chat screenshot size mismatch for $($row.file)"
    }
}

$stageCorpusManifest = Join-Path $productRoot "tests\fixtures\fishing_stage\screenshots-v1.tsv"
if (-not (Test-Path -LiteralPath $stageCorpusManifest -PathType Leaf)) {
    throw "Pinned fishing-stage screenshot manifest is missing: $stageCorpusManifest"
}
$stageCorpusRows = @(Import-Csv -LiteralPath $stageCorpusManifest -Delimiter "`t")
if ($stageCorpusRows.Count -ne 30) {
    throw "Pinned fishing-stage screenshot corpus must contain exactly 30 rows"
}
foreach ($row in $stageCorpusRows) {
    $fixturePath = [IO.Path]::GetFullPath((Join-Path (Split-Path -Parent $stageCorpusManifest) $row.file))
    if (-not $fixturePath.StartsWith($fixtureRoot, [StringComparison]::OrdinalIgnoreCase)) {
        throw "Fishing-stage fixture escaped tests/fixtures: $fixturePath"
    }
    if (-not (Test-Path -LiteralPath $fixturePath -PathType Leaf)) {
        throw "Pinned fishing-stage screenshot is missing: $fixturePath"
    }
    $actualFixtureHash = (Get-FileHash -LiteralPath $fixturePath -Algorithm SHA256).Hash
    if ($actualFixtureHash -ne $row.sha256) {
        throw "Pinned fishing-stage screenshot hash mismatch for $($row.file): $actualFixtureHash"
    }
    if ((Get-Item -LiteralPath $fixturePath).Length -ne [long]$row.bytes) {
        throw "Pinned fishing-stage screenshot size mismatch for $($row.file)"
    }
}

$stageAssetRoot = Join-Path $nativeSource "fishing_stage_detection\assets"
$stageAssetManifest = Join-Path $stageAssetRoot "manifest-v1.tsv"
if (-not (Test-Path -LiteralPath $stageAssetManifest -PathType Leaf)) {
    throw "Pinned embedded fishing-stage asset manifest is missing: $stageAssetManifest"
}
$stageAssetRows = @(Import-Csv -LiteralPath $stageAssetManifest -Delimiter "`t")
if ($stageAssetRows.Count -ne 10) {
    throw "Pinned embedded fishing-stage asset manifest must contain exactly 10 rows"
}
foreach ($row in $stageAssetRows) {
    $assetPath = [IO.Path]::GetFullPath((Join-Path $stageAssetRoot $row.embedded_file))
    if (-not $assetPath.StartsWith($stageAssetRoot, [StringComparison]::OrdinalIgnoreCase)) {
        throw "Fishing-stage asset escaped native asset root: $assetPath"
    }
    if (-not (Test-Path -LiteralPath $assetPath -PathType Leaf)) {
        throw "Pinned embedded fishing-stage asset is missing: $assetPath"
    }
    $actualAssetHash = (Get-FileHash -LiteralPath $assetPath -Algorithm SHA256).Hash
    if ($actualAssetHash -ne $row.embedded_sha256) {
        throw "Pinned embedded fishing-stage asset hash mismatch for $($row.embedded_file): $actualAssetHash"
    }
    if ((Get-Item -LiteralPath $assetPath).Length -ne [long]$row.bytes) {
        throw "Pinned embedded fishing-stage asset size mismatch for $($row.embedded_file)"
    }
}

$inventoryStoreFixture = Join-Path $productRoot "tests\fixtures\inventory_store\episode-v1.tsv"
if (-not (Test-Path -LiteralPath $inventoryStoreFixture -PathType Leaf)) {
    throw "Pinned inventory-store episode fixture is missing: $inventoryStoreFixture"
}
$expectedInventoryStoreFixtureHash = "FE747957DC7CEE960CB13BFC25D4D4725A9491F7D33A6E98C4A132688088E062"
$actualInventoryStoreFixtureHash =
    (Get-FileHash -LiteralPath $inventoryStoreFixture -Algorithm SHA256).Hash
if ($actualInventoryStoreFixtureHash -ne $expectedInventoryStoreFixtureHash) {
    throw "Pinned inventory-store episode fixture hash mismatch: $actualInventoryStoreFixtureHash"
}
$inventoryStoreFixtureRows = @(Import-Csv -LiteralPath $inventoryStoreFixture -Delimiter "`t")
if ($inventoryStoreFixtureRows.Count -ne 26) {
    throw "Pinned inventory-store episode fixture must contain exactly 26 rows"
}

$memoryObservationFixture = Join-Path $productRoot "tests\fixtures\memory_observation\e11-v1.tsv"
if (-not (Test-Path -LiteralPath $memoryObservationFixture -PathType Leaf)) {
    throw "Pinned memory-observation fixture is missing: $memoryObservationFixture"
}
$expectedMemoryObservationFixtureHash = "ACB3FA6C1D9E7983344E53906E748DB9C7EED67E07695013A7D77166FF6DE8DD"
$actualMemoryObservationFixtureHash =
    (Get-FileHash -LiteralPath $memoryObservationFixture -Algorithm SHA256).Hash
if ($actualMemoryObservationFixtureHash -ne $expectedMemoryObservationFixtureHash) {
    throw "Pinned memory-observation fixture hash mismatch: $actualMemoryObservationFixtureHash"
}
$memoryObservationRows = @(
    Get-Content -LiteralPath $memoryObservationFixture |
        Where-Object { $_ -and -not $_.StartsWith("#", [StringComparison]::Ordinal) }
)
if ($memoryObservationRows.Count -ne 5) {
    throw "Pinned memory-observation fixture must contain exactly 5 rows"
}
$memoryObservationKinds = @(
    $memoryObservationRows |
        ForEach-Object { ($_ -split "`t", 2)[0] } |
        Sort-Object -Unique
)
if (($memoryObservationKinds -join ",") -ne "chat,inventory,player_status,reeling") {
    throw "Pinned memory-observation fixture domain union is invalid"
}

$fishingEpisodeFixture = Join-Path $productRoot "tests\fixtures\fishing_episode\e13-v1.tsv"
if (-not (Test-Path -LiteralPath $fishingEpisodeFixture -PathType Leaf)) {
    throw "Pinned fishing-episode fixture is missing: $fishingEpisodeFixture"
}
$expectedFishingEpisodeFixtureHash = "F4111DB2536409CCB9C9DAF79228AA9C624BF588A7C97A79F9BFC962523CAF49"
$actualFishingEpisodeFixtureHash =
    (Get-FileHash -LiteralPath $fishingEpisodeFixture -Algorithm SHA256).Hash
if ($actualFishingEpisodeFixtureHash -ne $expectedFishingEpisodeFixtureHash) {
    throw "Pinned fishing-episode fixture hash mismatch: $actualFishingEpisodeFixtureHash"
}
$fishingEpisodeRows = @(Import-Csv -LiteralPath $fishingEpisodeFixture -Delimiter "`t")
if ($fishingEpisodeRows.Count -ne 19) {
    throw "Pinned fishing-episode fixture must contain exactly 19 rows"
}
$fishingEpisodeCases = @($fishingEpisodeRows.case_id | Sort-Object -Unique)
$expectedFishingEpisodeCases = @(
    "cast_timeout",
    "catch_after_hook",
    "full_episode",
    "hook_not_confirmed",
    "reeling_stage_lost",
    "resume_reeling_manual"
)
if (($fishingEpisodeCases -join ",") -ne ($expectedFishingEpisodeCases -join ",")) {
    throw "Pinned fishing-episode fixture case union is invalid"
}

$maintenanceEpisodeFixture = Join-Path $productRoot "tests\fixtures\maintenance_episode\episode-v1.tsv"
if (-not (Test-Path -LiteralPath $maintenanceEpisodeFixture -PathType Leaf)) {
    throw "Pinned maintenance-episode fixture is missing: $maintenanceEpisodeFixture"
}
$expectedMaintenanceEpisodeFixtureHash = "F4ED4238EEDB677620C4AFEABCAAEEA62F61EA97F33775567643269376BF7BBA"
$actualMaintenanceEpisodeFixtureHash =
    (Get-FileHash -LiteralPath $maintenanceEpisodeFixture -Algorithm SHA256).Hash
if ($actualMaintenanceEpisodeFixtureHash -ne $expectedMaintenanceEpisodeFixtureHash) {
    throw "Pinned maintenance-episode fixture hash mismatch: $actualMaintenanceEpisodeFixtureHash"
}
$maintenanceEpisodeRows = @(Import-Csv -LiteralPath $maintenanceEpisodeFixture -Delimiter "`t")
if ($maintenanceEpisodeRows.Count -ne 27) {
    throw "Pinned maintenance-episode fixture must contain exactly 27 rows"
}
$maintenanceEpisodeKinds = @($maintenanceEpisodeRows.kind | Sort-Object -Unique)
if (($maintenanceEpisodeKinds -join ",") -ne "bait,garbage,meal,tackle") {
    throw "Pinned maintenance-episode fixture domain union is invalid"
}
$maintenanceEpisodeCases = @($maintenanceEpisodeRows.case_id | Sort-Object -Unique)
if ($maintenanceEpisodeCases.Count -ne 5) {
    throw "Pinned maintenance-episode fixture must contain exactly 5 cases"
}

Invoke-Checked $resolvedCMake @(
    "-S", $nativeSource,
    "-B", $nativeBuild,
    "-G", "Visual Studio 17 2022",
    "-A", "x64",
    "-T", "v143",
    "-DSONAR_FISHING_BUILD_OFFLINE_IPC=ON",
    "-DSONAR_COMMON_NATIVE_PACKAGE=$resolvedNativePackage",
    "-DSONAR_COMMON_NATIVE_WINDOWS_PACKAGE=$resolvedNativeWindowsPackage",
    "-DSONAR_COMMON_NATIVE_LICENSING_PACKAGE=$resolvedNativeLicensingPackage",
    "-DSONAR_PROTOC_EXECUTABLE=$resolvedProtoc"
)
Invoke-Checked $resolvedCMake @(
    "--build", $nativeBuild,
    "--config", $Configuration,
    "--target",
    "SonarFishingCatchQualityTests",
    "SonarFishingCatchDispositionTests",
    "SonarFishingSessionStatisticsTests",
    "SonarFishingFishIdentityTests",
    "SonarFishingCatchObservationTests",
    "SonarFishingRuntimeSettingsTests",
    "SonarFishingLifecycleTests",
    "SonarFishingReelingControlTests",
    "SonarFishingReelingControlBenchmark",
    "SonarFishingMealRecoveryTests",
    "SonarFishingMealRecoveryBenchmark",
    "SonarFishingGarbageDisposalTests",
    "SonarFishingEquipmentRecoveryTests",
    "SonarFishingRuntimePlatformTests",
    "SonarFishingRuntimeSafetyTests",
    "SonarFishingEntitlementTests",
    "SonarFishingGameChatTests",
    "SonarFishingGameChatBoundaryTests",
    "SonarFishingGameChatPlatformMutationTests",
    "SonarFishingGameChatVisualDetectorTests",
    "SonarFishingStageDetectionTests",
    "SonarFishingInventoryStoreTests",
    "SonarFishingInventoryStoreBenchmark",
    "SonarFishingMemoryObservationTests",
    "SonarFishingMemoryObservationBenchmark",
    "SonarFishingEpisodeTests",
    "SonarFishingEpisodeBenchmark",
    "SonarFishingMaintenanceEpisodeTests",
    "SonarFishingMaintenanceEpisodeBenchmark",
    "SonarFishingAutomationAdaptersTests",
    "SonarFishingProductionAdaptersTests",
    "SonarFishingIpcContractsTests",
    "SonarFishingEventDeliveryTests",
    "SonarFishingSessionControlTests",
    "SonarFishingProductionCompositionTests",
    "SonarFishingEngine",
    "SonarFishingOfflineEngine"
)
Invoke-Checked $ctestExecutable @(
    "--test-dir", $nativeBuild,
    "-C", $Configuration,
    "--output-on-failure"
)

$reelingBenchmark = Join-Path $nativeBuild "reeling_control\$Configuration\SonarFishingReelingControlBenchmark.exe"
Invoke-Checked $reelingBenchmark @()
$mealRecoveryBenchmark = Join-Path $nativeBuild "meal_recovery\$Configuration\SonarFishingMealRecoveryBenchmark.exe"
Invoke-Checked $mealRecoveryBenchmark @()
$inventoryStoreBenchmark = Join-Path $nativeBuild "inventory_store\$Configuration\SonarFishingInventoryStoreBenchmark.exe"
Invoke-Checked $inventoryStoreBenchmark @()
$memoryObservationBenchmark = Join-Path $nativeBuild "memory_observation\$Configuration\SonarFishingMemoryObservationBenchmark.exe"
Invoke-Checked $memoryObservationBenchmark @()
$fishingEpisodeBenchmark = Join-Path $nativeBuild "fishing_episode\$Configuration\SonarFishingEpisodeBenchmark.exe"
Invoke-Checked $fishingEpisodeBenchmark @()
$maintenanceEpisodeBenchmark = Join-Path $nativeBuild "maintenance_episode\$Configuration\SonarFishingMaintenanceEpisodeBenchmark.exe"
Invoke-Checked $maintenanceEpisodeBenchmark @()

$engineExecutable = Join-Path $nativeBuild "engine_ipc\$Configuration\SonarFishingOfflineEngine.exe"
if (-not (Test-Path -LiteralPath $engineExecutable -PathType Leaf)) {
    throw "Offline Engine executable is missing: $engineExecutable"
}
$productionEngineExecutable = Join-Path $nativeBuild "engine_ipc\$Configuration\Sonar.Engine.exe"
if (-not (Test-Path -LiteralPath $productionEngineExecutable -PathType Leaf)) {
    throw "Production Engine executable is missing: $productionEngineExecutable"
}

$commonFeedProperty = "-p:CommonFeed=$resolvedFeed"
$protocProperty = "-p:SonarProtocExecutable=$resolvedProtoc"
$packageCacheProperty = "-p:RestorePackagesPath=$packageCache"
Invoke-Checked "dotnet" @(
    "restore", $testProject, "--nologo", $commonFeedProperty, $protocProperty, $packageCacheProperty
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
Invoke-Checked "dotnet" @(
    "build", $testProject,
    "--configuration", $Configuration,
    "--no-restore",
    "--nologo",
    $commonFeedProperty,
    $protocProperty,
    $packageCacheProperty
)

$previousEngine = $env:SONAR_FISHING_OFFLINE_ENGINE
$previousProductionEngine = $env:SONAR_FISHING_PRODUCTION_ENGINE
try {
    $env:SONAR_FISHING_OFFLINE_ENGINE = $engineExecutable
    $env:SONAR_FISHING_PRODUCTION_ENGINE = $productionEngineExecutable
    Invoke-Checked "dotnet" @(
        "run",
        "--project", $testProject,
        "--configuration", $Configuration,
        "--no-build",
        "--no-restore",
        $commonFeedProperty,
        $protocProperty,
        $packageCacheProperty
    )
}
finally {
    $env:SONAR_FISHING_OFFLINE_ENGINE = $previousEngine
    $env:SONAR_FISHING_PRODUCTION_ENGINE = $previousProductionEngine
}
