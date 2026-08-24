[CmdletBinding()]
param(
    [string]$BundleDirectory = ""
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

[void](Read-FishingBundleManifest $productRoot $BundleDirectory)
Assert-FishingDesktopRuntime

$hostPath = Join-Path $BundleDirectory "Sonar.exe"
$startInfo = [Diagnostics.ProcessStartInfo]::new()
$startInfo.FileName = $hostPath
$startInfo.WorkingDirectory = $BundleDirectory
$startInfo.UseShellExecute = $true
$process = [Diagnostics.Process]::Start($startInfo)
if ($null -eq $process) {
    throw "release_host_start_failed"
}

try {
    Start-Sleep -Milliseconds 750
    $process.Refresh()
    if ($process.HasExited) {
        throw "release_host_exited_during_startup: $($process.ExitCode)"
    }
    Write-Output "PASS Fishing normal product process started: pid=$($process.Id)"
}
finally {
    $process.Dispose()
}
