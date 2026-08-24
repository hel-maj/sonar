[CmdletBinding()]
param()

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

. (Join-Path $PSScriptRoot "release_common.ps1")

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$testRoot = Reset-FishingBuildDirectory `
    $productRoot `
    (Join-Path $productRoot "build\release-tests\current") `
    "release plumbing tests"
$bundle = Join-Path $testRoot "bundle"
New-Item -ItemType Directory -Path $bundle -Force | Out-Null
New-Item -ItemType Directory -Path (Join-Path $bundle "config") -Force | Out-Null
New-Item -ItemType Directory -Path (Join-Path $bundle "logs") -Force | Out-Null

function Assert-Throws([scriptblock]$Action, [string]$ExpectedReason) {
    try {
        & $Action
    }
    catch {
        if ($_.Exception.Message -notlike "*$ExpectedReason*") {
            throw "release_test_wrong_failure: expected=$ExpectedReason actual=$($_.Exception.Message)"
        }
        return
    }
    throw "release_test_expected_failure_missing: $ExpectedReason"
}

try {
    $currentExecutable = [Diagnostics.Process]::GetCurrentProcess().MainModule.FileName
    Copy-Item -LiteralPath $currentExecutable -Destination (Join-Path $bundle "Sonar.exe")
    Copy-Item -LiteralPath $currentExecutable -Destination (Join-Path $bundle "Sonar.Engine.exe")
    $hostHash = Get-FishingSha256 (Join-Path $bundle "Sonar.exe")
    $engineHash = Get-FishingSha256 (Join-Path $bundle "Sonar.Engine.exe")
    $manifest = New-FishingBundleManifestData `
        $productRoot `
        $bundle `
        "0.0.0-test" `
        "development-unsigned" `
        $hostHash `
        $engineHash `
        $hostHash `
        $engineHash `
        $true `
        "NotRequired" `
        "NotRequired"
    $manifestPath = Join-Path $bundle "bundle-manifest.json"
    Write-FishingBundleManifest $manifestPath $manifest
    $accepted = Read-FishingBundleManifest `
        $productRoot $bundle "development-unsigned"
    if (-not $accepted.determinism.verified) {
        throw "release_test_manifest_determinism_lost"
    }

    & (Join-Path $PSScriptRoot "test_no_python_runtime.ps1") `
        -ProductRoot $productRoot `
        -BundleDirectory $bundle `
        -BundleLifecycleStage Package
    & (Join-Path $PSScriptRoot "smoke_release_native.ps1") `
        -BundleDirectory $bundle `
        -DevelopmentUnsigned `
        -StaticOnly

    $originalManifest = [IO.File]::ReadAllText($manifestPath)
    [IO.File]::WriteAllText($manifestPath, " " + $originalManifest)
    Assert-Throws {
        Read-FishingBundleManifest $productRoot $bundle "development-unsigned"
    } "release_manifest_not_canonical"
    [IO.File]::WriteAllText(
        $manifestPath,
        $originalManifest,
        [Text.UTF8Encoding]::new($false))

    Add-Content -LiteralPath (Join-Path $bundle "Sonar.exe") -Value "tamper"
    Assert-Throws {
        Read-FishingBundleManifest $productRoot $bundle "development-unsigned"
    } "release_manifest_content_hash_mismatch"
    Copy-Item -LiteralPath $currentExecutable `
        -Destination (Join-Path $bundle "Sonar.exe") -Force

    Move-Item -LiteralPath $manifestPath -Destination "$manifestPath.missing"
    Assert-Throws {
        Read-FishingBundleManifest $productRoot $bundle "development-unsigned"
    } "release_manifest_missing"
    Move-Item -LiteralPath "$manifestPath.missing" -Destination $manifestPath

    Set-Content -LiteralPath (Join-Path $bundle "debug.pdb") -Value "forbidden"
    Assert-Throws {
        & (Join-Path $PSScriptRoot "test_no_python_runtime.ps1") `
            -ProductRoot $productRoot `
            -BundleDirectory $bundle `
            -BundleLifecycleStage Package
    } "outside the allowlist"
    Remove-Item -LiteralPath (Join-Path $bundle "debug.pdb") -Force

    Set-Content -LiteralPath (Join-Path $bundle "config\state.dat") -Value "fixture"
    foreach ($lifecycleStage in @(
            "Installed",
            "FirstActivation",
            "NormalExit",
            "CrashRecovery",
            "Updated",
            "InterruptedUpdateRecovery",
            "RemoteRollback")) {
        & (Join-Path $PSScriptRoot "test_no_python_runtime.ps1") `
            -ProductRoot $productRoot `
            -BundleDirectory $bundle `
            -BundleLifecycleStage $lifecycleStage
    }
    Remove-Item -LiteralPath (Join-Path $bundle "config\state.dat") -Force

    Assert-Throws {
        Assert-FishingSafeBuildPath $productRoot (Join-Path $productRoot "dist") "test"
    } "release_path_outside_build_root"

    $hostProject = [xml](Get-Content -Raw -LiteralPath `
        (Join-Path $productRoot "src\dotnet\Sonar.Fishing.Host\Sonar.Fishing.Host.csproj"))
    $releaseGroup = @(@($hostProject.Project.PropertyGroup) |
        Where-Object {
            $_.GetAttribute("Condition") -eq
                "'`$(SonarFishingReleaseBundle)' == 'true'"
        })
    if ($releaseGroup.Count -ne 1 -or
        $releaseGroup.PublishSingleFile -ne "true" -or
        $releaseGroup.SelfContained -ne "false" -or
        $hostProject.Project.PropertyGroup[0].AssemblyName -ne "Sonar.Fishing.Host" -or
        $releaseGroup.IncludeAllContentForSelfExtract -ne "false" -or
        $releaseGroup.DebugType -ne "None" -or
        $releaseGroup.EnableSingleFileAnalyzer -ne "false" -or
        $releaseGroup.DisableTransitiveFrameworkReferenceDownloads -ne "true" -or
        $releaseGroup.EnableRuntimePackDownload -ne "false") {
        throw "release_host_publish_contract_invalid"
    }

    $directoryProps = [xml](Get-Content -Raw -LiteralPath `
        (Join-Path $productRoot "Directory.Build.props"))
    $baseOutputPath = @($directoryProps.Project.PropertyGroup.BaseOutputPath)
    $baseIntermediateOutputPath = @(
        $directoryProps.Project.PropertyGroup.BaseIntermediateOutputPath)
    if ($baseOutputPath.Count -ne 1 -or
        $baseIntermediateOutputPath.Count -ne 1 -or
        $baseOutputPath[0].GetAttribute("Condition") -ne
            "'`$(UseArtifactsOutput)' != 'true'" -or
        $baseIntermediateOutputPath[0].GetAttribute("Condition") -ne
            "'`$(UseArtifactsOutput)' != 'true'") {
        throw "release_managed_artifact_isolation_contract_invalid"
    }

    $releaseBuilderText = Get-Content -Raw -LiteralPath `
        (Join-Path $PSScriptRoot "build_release_native.ps1")
    if (-not $releaseBuilderText.Contains('"--artifacts-path"') -or
        $releaseBuilderText -notmatch 'PathMap=.*%2C\$BuildRoot=/_/out' -or
        $releaseBuilderText -notmatch 'Sonar\.Fishing\.Host\.exe') {
        throw "release_clean_build_contract_invalid"
    }

    $releaseSmokeText = Get-Content -Raw -LiteralPath `
        (Join-Path $PSScriptRoot "smoke_release_native.ps1")
    if ($releaseSmokeText -match '--offline-engine' -or
        $releaseSmokeText -notmatch '\$startInfo\.Arguments = "--demo"' -or
        $releaseSmokeText -notmatch 'SONAR_FISHING_IPC_TEST_SELECTION' -or
        $releaseSmokeText -notmatch 'SONAR_FISHING_PRODUCTION_BUNDLE') {
        throw "release_smoke_authority_contract_invalid"
    }

    $developmentRunnerText = Get-Content -Raw -LiteralPath `
        (Join-Path $PSScriptRoot "run_dotnet.ps1")
    if ($developmentRunnerText -match '(?m)^\s*--nologo\s*`?\s*$') {
        throw "release_development_runner_forwards_nologo_to_host"
    }
    $productRunnerText = Get-Content -Raw -LiteralPath `
        (Join-Path $PSScriptRoot "run_product.ps1")
    if ($productRunnerText -notmatch 'Read-FishingBundleManifest' -or
        $productRunnerText -notmatch 'Assert-FishingDesktopRuntime' -or
        $productRunnerText -match '\.ArgumentList\.Add|\.Arguments\s*=') {
        throw "release_normal_runner_contract_invalid"
    }
    $normalLifecycleText = Get-Content -Raw -LiteralPath `
        (Join-Path $PSScriptRoot "test_product_lifecycle.ps1")
    if ($normalLifecycleText -notmatch 'Intentionally no arguments' -or
        $normalLifecycleText -match '\.ArgumentList\.Add|\.Arguments\s*=' -or
        $normalLifecycleText -notmatch 'release_engine_exited_during_sustain' -or
        $normalLifecycleText -notmatch 'release_engine_recovery_timeout' -or
        $normalLifecycleText -notmatch 'release_persistent_state_lost_after_restart') {
        throw "release_normal_lifecycle_contract_invalid"
    }

    $releaseScripts = @(
        "release_common.ps1",
        "build_release_native.ps1",
        "package_native.ps1",
        "smoke_release_native.ps1",
        "smoke_native.ps1",
        "run_dotnet.ps1",
        "run_product.ps1",
        "test_product_lifecycle.ps1",
        "test_no_python_runtime.ps1",
        "test_release_plumbing.ps1"
    )
    foreach ($scriptName in $releaseScripts) {
        $tokens = $null
        $errors = $null
        [void][Management.Automation.Language.Parser]::ParseFile(
            (Join-Path $PSScriptRoot $scriptName),
            [ref]$tokens,
            [ref]$errors)
        if (@($errors).Count -ne 0) {
            throw "release_script_parse_failed: $scriptName"
        }
    }

    Write-Output "PASS Fishing release manifest, lifecycle allowlist and script contracts"
}
finally {
    $safe = Assert-FishingSafeBuildPath $productRoot $testRoot "release plumbing tests"
    if (Test-Path -LiteralPath $safe) {
        Remove-Item -LiteralPath $safe -Recurse -Force
    }
}
