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
$expectedNativeWindowsManifestHash = "EE61031CBC06550FD478892EFECD250FD4786790C5687F260B2D40B85B5C9446"
$expectedNativeLicensingManifestHash = "E777E623A2974E07CF4338670C3A41DF13BCDB8990F447987BB1BC0FF21834AC"
$requiredNativeTargets = @(
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
    "SonarFishingLiveObservationPreflightTests",
    "SonarFishingLiveObservationPreflightTool",
    "SonarFishingBuildProfileCompatibilityProbeTests",
    "SonarFishingBuildProfileCompatibilityProbeTool",
    "SonarFishingBuildProfileCompatibilityValidatorTests",
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
$expectedCTestNames = @(
    "sonar_fishing.build_profile_compatibility_probe_shipping_binary_exclusion",
    "sonar_fishing.catch_quality.golden",
    "sonar_fishing.catch_disposition.golden",
    "sonar_fishing.session_statistics.golden",
    "sonar_fishing.fish_identity.golden",
    "sonar_fishing.catch_observation.golden",
    "sonar_fishing.runtime_settings",
    "sonar_fishing.lifecycle",
    "sonar_fishing.reeling_control",
    "sonar_fishing.meal_recovery",
    "sonar_fishing.garbage_disposal.golden",
    "sonar_fishing.equipment_recovery",
    "sonar_fishing.runtime_platform",
    "sonar_fishing.runtime_safety",
    "sonar_fishing.entitlement",
    "sonar_fishing.game_chat",
    "sonar_fishing.game_chat_boundary",
    "sonar_fishing.game_chat_platform_mutation",
    "sonar_fishing.game_chat_visual_detector",
    "sonar_fishing.stage_detection",
    "sonar_fishing.inventory_store",
    "sonar_fishing.memory_observation",
    "sonar_fishing.live_observation_preflight",
    "sonar_fishing.live_observation_preflight_readonly_boundary",
    "sonar_fishing.live_observation_preflight_authority_gate",
    "sonar_fishing.build_profile_compatibility_probe",
    "sonar_fishing.build_profile_compatibility_probe_readonly_boundary",
    "sonar_fishing.build_profile_compatibility_probe_shipping_isolation",
    "sonar_fishing.build_profile_compatibility_probe_authority_gate",
    "sonar_fishing.build_profile_compatibility_probe_binary_imports",
    "sonar_fishing.build_profile_compatibility_validator",
    "sonar_fishing.fishing_episode",
    "sonar_fishing.maintenance_episode",
    "sonar_fishing.automation_adapters",
    "sonar_fishing.production_adapters",
    "sonar_fishing.ipc.contract_golden",
    "sonar_fishing.ipc.event_delivery",
    "sonar_fishing.ipc.session_control",
    "sonar_fishing.ipc.production_composition",
    "sonar_fishing.ipc.offline_authority_gate",
    "sonar_fishing.ipc.production_identity_gate"
)

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

function Assert-GeneratedSolutionTargets(
    [string]$buildRoot,
    [string[]]$requiredTargets,
    [string[]]$forbiddenAllBuildTargets = @()
) {
    $solutions = @(Get-ChildItem -LiteralPath $buildRoot -Filter "*.sln" -File)
    if ($solutions.Count -ne 1) {
        throw "Expected exactly one generated Visual Studio solution in ${buildRoot}; found $($solutions.Count)"
    }

    $fullBuildRoot = [IO.Path]::GetFullPath($buildRoot).TrimEnd('\', '/')
    $buildRootPrefix = $fullBuildRoot + [IO.Path]::DirectorySeparatorChar
    $projectRecords = @(
        foreach ($line in Get-Content -LiteralPath $solutions[0].FullName) {
            $match = [regex]::Match(
                $line,
                '^Project\("\{[0-9A-Fa-f-]+\}"\)\s*=\s*"(?<name>[^"]+)",\s*"(?<path>[^"]+)"'
            )
            if ($match.Success) {
                $rawProjectPath = $match.Groups["path"].Value
                $projectPath = if ([IO.Path]::IsPathRooted($rawProjectPath)) {
                    $rawProjectPath
                }
                else {
                    Join-Path $buildRoot $rawProjectPath
                }
                [pscustomobject]@{
                    Name = $match.Groups["name"].Value
                    ProjectPath = [IO.Path]::GetFullPath($projectPath)
                }
            }
        }
    )
    $projectNames = @($projectRecords | ForEach-Object { $_.Name })
    $duplicateRequiredTargets = @(
        $requiredTargets |
            Group-Object |
            Where-Object Count -gt 1 |
            ForEach-Object { $_.Name }
    )
    $duplicateProjectNames = @(
        $projectNames |
            Group-Object |
            Where-Object Count -gt 1 |
            ForEach-Object { $_.Name }
    )
    if ($duplicateRequiredTargets.Count -ne 0 -or
        $duplicateProjectNames.Count -ne 0) {
        throw ("Generated solution target manifest contains duplicates; required: [{0}]; generated: [{1}]" -f `
            ($duplicateRequiredTargets -join ', '),
            ($duplicateProjectNames -join ', '))
    }
    $missingTargets = @($requiredTargets | Where-Object {
        $projectNames -cnotcontains $_
    })
    if ($missingTargets.Count -ne 0) {
        throw "Generated solution is missing required native targets: $($missingTargets -join ', ')"
    }
    foreach ($target in $requiredTargets) {
        $projectPath = @($projectRecords | Where-Object {
            $_.Name -ceq $target
        })[0].ProjectPath
        if (-not $projectPath.StartsWith(
            $buildRootPrefix,
            [StringComparison]::OrdinalIgnoreCase
        ) -or [IO.Path]::GetExtension($projectPath) -cne ".vcxproj") {
            throw "Required native target maps outside the generated build graph: $target -> $projectPath"
        }
    }

    $allBuildProjectPath = Join-Path $buildRoot "ALL_BUILD.vcxproj"
    if (-not (Test-Path -LiteralPath $allBuildProjectPath -PathType Leaf)) {
        throw "Generated ALL_BUILD project is missing: $allBuildProjectPath"
    }
    [xml]$allBuildProject = Get-Content -LiteralPath $allBuildProjectPath -Raw
    $namespace = [Xml.XmlNamespaceManager]::new($allBuildProject.NameTable)
    $namespace.AddNamespace(
        "msbuild",
        $allBuildProject.DocumentElement.NamespaceURI
    )
    $allBuildReferences = @(
        foreach ($reference in $allBuildProject.SelectNodes(
            "//msbuild:ProjectReference",
            $namespace
        )) {
            $nameNode = $reference.SelectSingleNode(
                "msbuild:Name",
                $namespace
            )
            $rawProjectPath = $reference.GetAttribute("Include")
            if ($null -eq $nameNode -or
                [string]::IsNullOrWhiteSpace($rawProjectPath)) {
                throw "Generated ALL_BUILD contains an invalid ProjectReference."
            }
            $projectPath = if ([IO.Path]::IsPathRooted($rawProjectPath)) {
                $rawProjectPath
            }
            else {
                Join-Path $buildRoot $rawProjectPath
            }
            [pscustomobject]@{
                Name = $nameNode.InnerText
                ProjectPath = [IO.Path]::GetFullPath($projectPath)
            }
        }
    )
    $allBuildTargetNames = @($allBuildReferences | ForEach-Object { $_.Name })
    $duplicateAllBuildTargets = @(
        $allBuildTargetNames |
            Group-Object |
            Where-Object Count -gt 1 |
            ForEach-Object { $_.Name }
    )
    if ($duplicateAllBuildTargets.Count -ne 0) {
        throw "Generated ALL_BUILD target manifest contains duplicates: $($duplicateAllBuildTargets -join ', ')"
    }
    $duplicateAllBuildPaths = @(
        $allBuildReferences |
            Group-Object ProjectPath |
            Where-Object Count -gt 1 |
            ForEach-Object { $_.Name }
    )
    if ($duplicateAllBuildPaths.Count -ne 0) {
        throw "Generated ALL_BUILD references projects more than once: $($duplicateAllBuildPaths -join ', ')"
    }
    $missingAllBuildTargets = @($requiredTargets | Where-Object {
        $allBuildTargetNames -cnotcontains $_
    })
    if ($missingAllBuildTargets.Count -ne 0) {
        throw "Required native targets are not members of ALL_BUILD: $($missingAllBuildTargets -join ', ')"
    }
    foreach ($target in $requiredTargets) {
        $solutionProjectPath = @($projectRecords | Where-Object {
            $_.Name -ceq $target
        })[0].ProjectPath
        $allBuildProjectReference = @($allBuildReferences | Where-Object {
            $_.Name -ceq $target
        })[0].ProjectPath
        if (-not $solutionProjectPath.Equals(
            $allBuildProjectReference,
            [StringComparison]::OrdinalIgnoreCase
        )) {
            throw "ALL_BUILD target reference does not match the generated solution mapping: $target"
        }
    }
    $forbiddenAllBuildMembers = @($forbiddenAllBuildTargets | Where-Object {
        $allBuildTargetNames -ccontains $_
    })
    if ($forbiddenAllBuildMembers.Count -ne 0) {
        throw "Forbidden live targets entered ALL_BUILD: $($forbiddenAllBuildMembers -join ', ')"
    }
}

function Assert-GeneratedCTestManifest(
    [string]$ctest,
    [string]$buildRoot,
    [string]$configuration,
    [string[]]$expectedNames
) {
    $manifestOutput = @(& $ctest --test-dir $buildRoot -C $configuration -N 2>&1)
    $manifestExitCode = $LASTEXITCODE
    foreach ($line in $manifestOutput) {
        Write-Host ([string]$line)
    }
    if ($manifestExitCode -ne 0) {
        throw "CTest manifest discovery failed with exit code ${manifestExitCode}"
    }

    $actualNames = @(
        foreach ($line in $manifestOutput) {
            $match = [regex]::Match(
                [string]$line,
                '^\s*Test\s+#\s*\d+:\s*(?<name>\S(?:.*\S)?)\s*$'
            )
            if ($match.Success) {
                $match.Groups["name"].Value
            }
        }
    )
    $reportedTotals = @(
        foreach ($line in $manifestOutput) {
            $match = [regex]::Match(
                [string]$line,
                '^\s*Total Tests:\s*(?<count>\d+)\s*$'
            )
            if ($match.Success) {
                [int]$match.Groups["count"].Value
            }
        }
    )
    if ($reportedTotals.Count -ne 1 -or
        $reportedTotals[0] -ne $actualNames.Count) {
        throw "CTest manifest count could not be parsed consistently."
    }
    $duplicateExpectedNames = @(
        $expectedNames |
            Group-Object |
            Where-Object Count -gt 1 |
            ForEach-Object { $_.Name }
    )
    $duplicateActualNames = @(
        $actualNames |
            Group-Object |
            Where-Object Count -gt 1 |
            ForEach-Object { $_.Name }
    )
    if ($duplicateExpectedNames.Count -ne 0 -or
        $duplicateActualNames.Count -ne 0) {
        throw ("Generated CTest manifest contains duplicates; required: [{0}]; generated: [{1}]" -f `
            ($duplicateExpectedNames -join ', '),
            ($duplicateActualNames -join ', '))
    }
    $missingNames = @($expectedNames | Where-Object {
        $actualNames -cnotcontains $_
    })
    if ($missingNames.Count -ne 0) {
        throw ("Generated CTest manifest is missing required tests. Required {0}, found {1}; missing: [{2}]" -f `
            $expectedNames.Count,
            $actualNames.Count,
            ($missingNames -join ', '))
    }
    Write-Host ("PASS generated CTest manifest: {0} discovered, {1} required" -f `
        $actualNames.Count,
        $expectedNames.Count)
}

function Get-ValidatedGeneratedExecutablePath(
    [string]$buildRoot,
    [string]$candidatePath
) {
    $fullBuildRoot = [IO.Path]::GetFullPath($buildRoot).TrimEnd('\', '/')
    $fullCandidate = [IO.Path]::GetFullPath($candidatePath)
    $requiredPrefix = $fullBuildRoot + [IO.Path]::DirectorySeparatorChar
    if (-not $fullCandidate.StartsWith(
        $requiredPrefix,
        [StringComparison]::OrdinalIgnoreCase
    ) -or [IO.Path]::GetExtension($fullCandidate) -cne ".exe") {
        throw "Generated executable escaped the validated native build root: $fullCandidate"
    }
    return $fullCandidate
}

function Remove-ExpectedGeneratedExecutables(
    [string]$buildRoot,
    [string[]]$paths
) {
    $buildRootItem = Get-Item -LiteralPath $buildRoot -ErrorAction Stop
    if (-not $buildRootItem.PSIsContainer -or
        ($buildRootItem.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
        throw "Native build root is not a validated ordinary directory: $buildRoot"
    }
    foreach ($path in $paths) {
        $validatedPath = Get-ValidatedGeneratedExecutablePath $buildRoot $path
        if (Test-Path -LiteralPath $validatedPath) {
            if (-not (Test-Path -LiteralPath $validatedPath -PathType Leaf)) {
                throw "Expected generated executable path is not a file: $validatedPath"
            }
            Remove-Item -LiteralPath $validatedPath -Force
        }
    }
}

function Assert-ExpectedGeneratedExecutables(
    [string]$buildRoot,
    [string[]]$paths
) {
    foreach ($path in $paths) {
        $validatedPath = Get-ValidatedGeneratedExecutablePath $buildRoot $path
        if (-not (Test-Path -LiteralPath $validatedPath -PathType Leaf)) {
            throw "ALL_BUILD did not recreate required generated executable: $validatedPath"
        }
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
    (Join-Path $productRoot "..\..\.artifacts\sonar-native-windows\0.1.6") `
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
    "Sonar.UI.Wpf.0.2.18.nupkg" = "737CB6EAC3FDB7A25D20D0B74626F6912092848C2697A8E200A9570CFDF955F6"
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
$expectedInventoryStoreFixtureHash = "CE748E406FC4CD65FAA5B136BBAD7A8E0BE1B592F2953F1754451955614DF92D"
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
$expectedMaintenanceEpisodeFixtureHash = "11A96DCC27B652E33143A8BDB031B01FC85D450890A524C4D59060709AEBB472"
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
    "-DSONAR_FISHING_BUILD_LIVE_OBSERVATION_PREFLIGHT=ON",
    "-DSONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE=ON",
    "-DSONAR_COMMON_NATIVE_PACKAGE=$resolvedNativePackage",
    "-DSONAR_COMMON_NATIVE_WINDOWS_PACKAGE=$resolvedNativeWindowsPackage",
    "-DSONAR_COMMON_NATIVE_LICENSING_PACKAGE=$resolvedNativeLicensingPackage",
    "-DSONAR_PROTOC_EXECUTABLE=$resolvedProtoc"
)
Assert-GeneratedSolutionTargets $nativeBuild $requiredNativeTargets
Assert-GeneratedCTestManifest `
    $ctestExecutable $nativeBuild $Configuration $expectedCTestNames

$reelingBenchmark = Join-Path $nativeBuild `
    "reeling_control\$Configuration\SonarFishingReelingControlBenchmark.exe"
$mealRecoveryBenchmark = Join-Path $nativeBuild `
    "meal_recovery\$Configuration\SonarFishingMealRecoveryBenchmark.exe"
$inventoryStoreBenchmark = Join-Path $nativeBuild `
    "inventory_store\$Configuration\SonarFishingInventoryStoreBenchmark.exe"
$memoryObservationBenchmark = Join-Path $nativeBuild `
    "memory_observation\$Configuration\SonarFishingMemoryObservationBenchmark.exe"
$fishingEpisodeBenchmark = Join-Path $nativeBuild `
    "fishing_episode\$Configuration\SonarFishingEpisodeBenchmark.exe"
$maintenanceEpisodeBenchmark = Join-Path $nativeBuild `
    "maintenance_episode\$Configuration\SonarFishingMaintenanceEpisodeBenchmark.exe"
$engineExecutable = Join-Path $nativeBuild `
    "engine_ipc\$Configuration\SonarFishingOfflineEngine.exe"
$productionEngineExecutable = Join-Path $nativeBuild `
    "engine_ipc\$Configuration\Sonar.Engine.exe"
$manuallyExecutedNativeArtifacts = @(
    $reelingBenchmark,
    $mealRecoveryBenchmark,
    $inventoryStoreBenchmark,
    $memoryObservationBenchmark,
    $fishingEpisodeBenchmark,
    $maintenanceEpisodeBenchmark,
    $engineExecutable,
    $productionEngineExecutable
)
Remove-ExpectedGeneratedExecutables `
    $nativeBuild $manuallyExecutedNativeArtifacts

$buildJobs = [Math]::Max(
    1,
    [Math]::Min(4, [Environment]::ProcessorCount)
)
Invoke-Checked $resolvedCMake @(
    "--build", $nativeBuild,
    "--config", $Configuration,
    "--parallel", $buildJobs
)
Assert-ExpectedGeneratedExecutables `
    $nativeBuild $manuallyExecutedNativeArtifacts
Invoke-Checked $ctestExecutable @(
    "--test-dir", $nativeBuild,
    "-C", $Configuration,
    "--parallel", $buildJobs,
    "--output-on-failure"
)

Invoke-Checked $reelingBenchmark @()
Invoke-Checked $mealRecoveryBenchmark @()
Invoke-Checked $inventoryStoreBenchmark @()
Invoke-Checked $memoryObservationBenchmark @()
Invoke-Checked $fishingEpisodeBenchmark @()
Invoke-Checked $maintenanceEpisodeBenchmark @()

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
