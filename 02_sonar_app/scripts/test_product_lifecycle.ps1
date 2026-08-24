[CmdletBinding()]
param(
    [string]$BundleDirectory = "",
    [switch]$DevelopmentUnsigned,
    [ValidateSet(30, 60, 120)]
    [int]$DurationSeconds = 30
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

[void](Read-FishingBundleManifest $productRoot $BundleDirectory $expectedMode)
Assert-FishingDesktopRuntime
$sourceHasState = Test-Path `
    -LiteralPath (Join-Path $BundleDirectory "config\state.dat") `
    -PathType Leaf
$sourceHasLogs = @(Get-ChildItem `
    -LiteralPath (Join-Path $BundleDirectory "logs") `
    -File `
    -ErrorAction SilentlyContinue).Count -gt 0
$sourceLifecycleStage = if ($sourceHasState -or $sourceHasLogs) {
    "Installed"
}
else {
    "Package"
}
& (Join-Path $PSScriptRoot "test_no_python_runtime.ps1") `
    -ProductRoot $productRoot `
    -BundleDirectory $BundleDirectory `
    -BundleLifecycleStage $sourceLifecycleStage

$smokeRoot = Reset-FishingBuildDirectory `
    $productRoot `
    (Join-Path $productRoot "build\normal-lifecycle\current") `
    "normal lifecycle workspace"
foreach ($entry in Get-ChildItem -LiteralPath $BundleDirectory -Force) {
    Copy-Item -LiteralPath $entry.FullName -Destination $smokeRoot -Recurse
}

# A clean state proves the ordinary no-argument composition without borrowing
# a saved entitlement or user setting from another installed copy.
$copiedConfig = Join-Path $smokeRoot "config"
if (Test-Path -LiteralPath $copiedConfig) {
    Remove-Item -LiteralPath $copiedConfig -Recurse -Force
}

$hostPath = Join-Path $smokeRoot "Sonar.exe"
$hostProcess = $null
$engineProcessId = 0
try {
    $startInfo = [Diagnostics.ProcessStartInfo]::new()
    $startInfo.FileName = $hostPath
    $startInfo.WorkingDirectory = $smokeRoot
    $startInfo.UseShellExecute = $false
    $startInfo.CreateNoWindow = $true
    $startInfo.WindowStyle = [Diagnostics.ProcessWindowStyle]::Hidden
    # Intentionally no arguments: this is the real product composition.
    $hostProcess = [Diagnostics.Process]::Start($startInfo)
    if ($null -eq $hostProcess) {
        throw "release_host_start_failed"
    }

    $readinessDeadline = [DateTimeOffset]::UtcNow.AddSeconds(30)
    while ([DateTimeOffset]::UtcNow -lt $readinessDeadline) {
        $hostProcess.Refresh()
        if ($hostProcess.HasExited) {
            throw "release_host_exited_during_startup: $($hostProcess.ExitCode)"
        }
        $engine = Get-CimInstance Win32_Process `
            -Filter "Name = 'Sonar.Engine.exe'" `
            -ErrorAction SilentlyContinue |
            Where-Object { $_.ParentProcessId -eq $hostProcess.Id } |
            Select-Object -First 1
        if ($null -ne $engine -and $hostProcess.MainWindowHandle -ne [IntPtr]::Zero) {
            $engineProcessId = [int]$engine.ProcessId
            break
        }
        Start-Sleep -Milliseconds 100
    }
    if ($engineProcessId -eq 0) {
        throw "release_normal_composition_not_ready"
    }

    # Exercise the production supervisor with an actual unexpected child exit.
    # No automation command is sent: only the isolated bundle's exact child
    # process is terminated and the Host must replace it with a new generation.
    $retiredEngineProcessId = $engineProcessId
    Stop-Process -Id $retiredEngineProcessId -Force
    # Retirement and replacement each have their own bounded 10-second IPC
    # budget; leave room for the two-second supervisor heartbeat as well.
    $replacementDeadline = [DateTimeOffset]::UtcNow.AddSeconds(30)
    $engineProcessId = 0
    while ([DateTimeOffset]::UtcNow -lt $replacementDeadline) {
        $hostProcess.Refresh()
        if ($hostProcess.HasExited) {
            throw "release_host_exited_during_engine_recovery: $($hostProcess.ExitCode)"
        }
        $replacement = Get-CimInstance Win32_Process `
            -Filter "Name = 'Sonar.Engine.exe'" `
            -ErrorAction SilentlyContinue |
            Where-Object {
                $_.ParentProcessId -eq $hostProcess.Id -and
                $_.ProcessId -ne $retiredEngineProcessId
            } |
            Select-Object -First 1
        if ($null -ne $replacement) {
            $engineProcessId = [int]$replacement.ProcessId
            break
        }
        Start-Sleep -Milliseconds 100
    }
    if ($engineProcessId -eq 0) {
        throw "release_engine_recovery_timeout"
    }
    & (Join-Path $PSScriptRoot "test_no_python_runtime.ps1") `
        -ProductRoot $productRoot `
        -BundleDirectory $smokeRoot `
        -BundleLifecycleStage CrashRecovery

    $sustainDeadline = [DateTimeOffset]::UtcNow.AddSeconds($DurationSeconds)
    while ([DateTimeOffset]::UtcNow -lt $sustainDeadline) {
        Start-Sleep -Milliseconds 250
        $hostProcess.Refresh()
        if ($hostProcess.HasExited) {
            throw "release_host_exited_during_sustain: $($hostProcess.ExitCode)"
        }
        if ($null -eq (Get-Process -Id $engineProcessId -ErrorAction SilentlyContinue)) {
            throw "release_engine_exited_during_sustain"
        }
    }

    if (-not $hostProcess.CloseMainWindow()) {
        throw "release_host_normal_close_unavailable"
    }
    if (-not $hostProcess.WaitForExit(15000)) {
        throw "release_host_normal_exit_timeout"
    }
    if ($hostProcess.ExitCode -ne 0) {
        throw "release_host_normal_exit_failed: $($hostProcess.ExitCode)"
    }
    if ($null -ne (Get-Process -Id $engineProcessId -ErrorAction SilentlyContinue)) {
        throw "release_engine_survived_normal_host_exit"
    }

    $statePath = Join-Path $smokeRoot "config\state.dat"
    if (-not (Test-Path -LiteralPath $statePath -PathType Leaf) -or
        (Get-Item -LiteralPath $statePath).Length -le 0) {
        throw "release_persistent_state_missing_after_first_run"
    }
    & (Join-Path $PSScriptRoot "test_no_python_runtime.ps1") `
        -ProductRoot $productRoot `
        -BundleDirectory $smokeRoot `
        -BundleLifecycleStage NormalExit

    # Restart the exact same installed copy without clearing config. Successful
    # readiness proves that the production state written by run one is accepted
    # and retained by run two; no fixture state is injected.
    $hostProcess.Dispose()
    $hostProcess = $null
    $engineProcessId = 0
    $restartInfo = [Diagnostics.ProcessStartInfo]::new()
    $restartInfo.FileName = $hostPath
    $restartInfo.WorkingDirectory = $smokeRoot
    $restartInfo.UseShellExecute = $false
    $restartInfo.CreateNoWindow = $true
    $restartInfo.WindowStyle = [Diagnostics.ProcessWindowStyle]::Hidden
    # Intentionally no arguments: persistent production restart.
    $hostProcess = [Diagnostics.Process]::Start($restartInfo)
    if ($null -eq $hostProcess) {
        throw "release_host_restart_failed"
    }
    $restartDeadline = [DateTimeOffset]::UtcNow.AddSeconds(30)
    while ([DateTimeOffset]::UtcNow -lt $restartDeadline) {
        $hostProcess.Refresh()
        if ($hostProcess.HasExited) {
            throw "release_host_exited_during_restart: $($hostProcess.ExitCode)"
        }
        $restartEngine = Get-CimInstance Win32_Process `
            -Filter "Name = 'Sonar.Engine.exe'" `
            -ErrorAction SilentlyContinue |
            Where-Object { $_.ParentProcessId -eq $hostProcess.Id } |
            Select-Object -First 1
        if ($null -ne $restartEngine -and
            $hostProcess.MainWindowHandle -ne [IntPtr]::Zero) {
            $engineProcessId = [int]$restartEngine.ProcessId
            break
        }
        Start-Sleep -Milliseconds 100
    }
    if ($engineProcessId -eq 0) {
        throw "release_persistent_restart_not_ready"
    }
    Start-Sleep -Seconds 5
    $hostProcess.Refresh()
    if ($hostProcess.HasExited -or
        $null -eq (Get-Process -Id $engineProcessId -ErrorAction SilentlyContinue)) {
        throw "release_persistent_restart_unstable"
    }
    if (-not $hostProcess.CloseMainWindow() -or
        -not $hostProcess.WaitForExit(15000) -or
        $hostProcess.ExitCode -ne 0) {
        throw "release_persistent_restart_normal_exit_failed"
    }
    if ($null -ne (Get-Process -Id $engineProcessId -ErrorAction SilentlyContinue)) {
        throw "release_engine_survived_persistent_restart_exit"
    }
    if (-not (Test-Path -LiteralPath $statePath -PathType Leaf) -or
        (Get-Item -LiteralPath $statePath).Length -le 0) {
        throw "release_persistent_state_lost_after_restart"
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
    if ($engineProcessId -ne 0) {
        Stop-Process -Id $engineProcessId -Force -ErrorAction SilentlyContinue
    }
}

& (Join-Path $PSScriptRoot "test_no_python_runtime.ps1") `
    -ProductRoot $productRoot `
    -BundleDirectory $smokeRoot `
    -BundleLifecycleStage NormalExit
[void](Read-FishingBundleManifest $productRoot $smokeRoot $expectedMode)
Write-Output "PASS Fishing no-argument product lifecycle sustained for $DurationSeconds seconds"
