[CmdletBinding()]
param(
    [string]$BundleDirectory = "",
    [switch]$DevelopmentUnsigned,
    [switch]$StaticOnly
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

. (Join-Path $PSScriptRoot "release_common.ps1")

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
if ([string]::IsNullOrWhiteSpace($BundleDirectory)) {
    $BundleDirectory = Join-Path $productRoot "build\release\bundle"
}
elseif (-not [IO.Path]::IsPathRooted($BundleDirectory)) {
    $BundleDirectory = Join-Path $productRoot $BundleDirectory
}
if (-not (Test-Path -LiteralPath $BundleDirectory -PathType Container)) {
    throw "release_bundle_missing: $BundleDirectory"
}
$BundleDirectory = (Resolve-Path -LiteralPath $BundleDirectory).Path
$expectedMode = if ($DevelopmentUnsigned) {
    "development-unsigned"
}
else {
    "production-signed"
}
if ($StaticOnly -and -not $DevelopmentUnsigned) {
    throw "release_static_only_is_development_only"
}

function Assert-ProductionAuthority {
    $authorityPath = Join-Path $productRoot "docs\migration\runtime-authority.json"
    $authority = Get-Content -Raw -LiteralPath $authorityPath | ConvertFrom-Json
    if (-not $authority.offline_ipc_slice.signed_entitlement.production_rsa_public_key_embedded) {
        throw "native_entitlement_trust_root_missing"
    }
    if (-not $authority.offline_ipc_slice.production_cutover -or
        -not $authority.wpf_migration_host.production_cutover) {
        throw "native_cutover_incomplete"
    }
}

function Wait-FishingHostReady(
    [Diagnostics.Process]$HostProcess,
    [string]$ExpectedStatePath,
    [TimeSpan]$Timeout) {
    $deadline = [DateTimeOffset]::UtcNow + $Timeout
    while ([DateTimeOffset]::UtcNow -lt $deadline) {
        $HostProcess.Refresh()
        if ($HostProcess.HasExited) {
            throw "release_host_exited_during_startup: $($HostProcess.ExitCode)"
        }
        if ((Test-Path -LiteralPath $ExpectedStatePath -PathType Leaf) -and
            $HostProcess.MainWindowHandle -ne [IntPtr]::Zero) {
            return
        }
        Start-Sleep -Milliseconds 100
    }
    throw "release_host_startup_timeout"
}

function Invoke-PackagedEngineRecoveryProbe([string]$BundlePath) {
    $runner = Get-ChildItem -LiteralPath (Join-Path $productRoot "build\dotnet\bin") `
        -Filter "Sonar.Fishing.Ipc.IntegrationTests.dll" `
        -File -Recurse -ErrorAction SilentlyContinue |
        Where-Object { $_.FullName -match '\\Release\\' } |
        Sort-Object LastWriteTimeUtc -Descending |
        Select-Object -First 1
    if ($null -eq $runner) {
        throw "release_engine_recovery_probe_missing"
    }
    $previousSelection = $env:SONAR_FISHING_IPC_TEST_SELECTION
    $previousBundle = $env:SONAR_FISHING_PRODUCTION_BUNDLE
    try {
        $env:SONAR_FISHING_IPC_TEST_SELECTION = "packaged-production"
        $env:SONAR_FISHING_PRODUCTION_BUNDLE = $BundlePath
        & dotnet $runner.FullName
        if ($LASTEXITCODE -ne 0) {
            throw "release_engine_recovery_probe_failed: $LASTEXITCODE"
        }
    }
    finally {
        $env:SONAR_FISHING_IPC_TEST_SELECTION = $previousSelection
        $env:SONAR_FISHING_PRODUCTION_BUNDLE = $previousBundle
    }
}

if (-not $DevelopmentUnsigned) {
    Assert-ProductionAuthority
}
Assert-FishingDesktopRuntime
$manifest = Read-FishingBundleManifest `
    $productRoot $BundleDirectory $expectedMode
$noPythonGate = Join-Path $PSScriptRoot "test_no_python_runtime.ps1"
& $noPythonGate `
    -ProductRoot $productRoot `
    -BundleDirectory $BundleDirectory `
    -BundleLifecycleStage Package
Assert-FishingSystemDependencyClosure $BundleDirectory
Assert-FishingHighConfidenceSecretScan $BundleDirectory

if (-not $DevelopmentUnsigned) {
    foreach ($name in @("Sonar.exe", "Sonar.Engine.exe")) {
        $status = Get-FishingAuthenticodeStatus (Join-Path $BundleDirectory $name)
        if ($status -cne "Valid") {
            throw "release_authenticode_invalid: $name status=$status"
        }
    }
}
if ($StaticOnly) {
    Write-Output "PASS Fishing development bundle static smoke: $BundleDirectory"
    return
}

$smokeRoot = Reset-FishingBuildDirectory `
    $productRoot `
    (Join-Path $productRoot "build\release-smoke\current") `
    "release smoke workspace"
foreach ($entry in Get-ChildItem -LiteralPath $BundleDirectory -Force) {
    Copy-Item -LiteralPath $entry.FullName -Destination $smokeRoot -Recurse
}
$hostPath = Get-FishingCanonicalPath (Join-Path $smokeRoot "Sonar.exe")
$enginePath = Get-FishingCanonicalPath (Join-Path $smokeRoot "Sonar.Engine.exe")
$statePath = Join-Path $smokeRoot "config\state.dat"
$tempDotnet = Join-Path $env:TEMP ".net"
$tempBefore = Get-FishingDirectoryFingerprint $tempDotnet

$hostProcess = $null
try {
    $startInfo = [Diagnostics.ProcessStartInfo]::new()
    $startInfo.FileName = $hostPath
    # The packaged Engine intentionally rejects offline diagnostic authority.
    # Start the real Host in its network-inert demo composition, then exercise
    # the actual production pair and crash recovery through the managed probe.
    $startInfo.Arguments = "--demo"
    $startInfo.WorkingDirectory = $smokeRoot
    $startInfo.UseShellExecute = $false
    $startInfo.CreateNoWindow = $true
    $startInfo.WindowStyle = [Diagnostics.ProcessWindowStyle]::Hidden
    $hostProcess = [Diagnostics.Process]::Start($startInfo)
    if ($null -eq $hostProcess) {
        throw "release_host_start_failed"
    }
    Wait-FishingHostReady `
        $hostProcess $statePath ([TimeSpan]::FromSeconds(30))
    if (-not $hostProcess.CloseMainWindow()) {
        throw "release_host_normal_close_unavailable"
    }
    if (-not $hostProcess.WaitForExit(15000)) {
        throw "release_host_normal_exit_timeout"
    }
    if ($hostProcess.ExitCode -ne 0) {
        throw "release_host_normal_exit_failed: $($hostProcess.ExitCode)"
    }
}
finally {
    if ($null -ne $hostProcess) {
        $hostProcess.Refresh()
        if (-not $hostProcess.HasExited) {
            Stop-Process -Id $hostProcess.Id -Force -ErrorAction SilentlyContinue
            $hostProcess.WaitForExit(5000) | Out-Null
        }
        $hostProcess.Dispose()
    }
}

& $noPythonGate `
    -ProductRoot $productRoot `
    -BundleDirectory $smokeRoot `
    -BundleLifecycleStage Installed
[void](Read-FishingBundleManifest $productRoot $smokeRoot $expectedMode)
Assert-FishingSystemDependencyClosure $smokeRoot
Assert-FishingHighConfidenceSecretScan $smokeRoot
Invoke-PackagedEngineRecoveryProbe $smokeRoot

$tempAfter = Get-FishingDirectoryFingerprint $tempDotnet
if ($tempBefore -cne $tempAfter) {
    throw "release_temp_dotnet_residue_detected"
}
if (@(Get-ChildItem -LiteralPath $smokeRoot -Directory -Force |
    Where-Object { $_.Name -match '^\.(?:update|rollback)-' }).Count -ne 0) {
    throw "release_transaction_residue_detected"
}

Write-Output "PASS Fishing $expectedMode packaged Host start/exit and production Engine crash/recovery smoke"
