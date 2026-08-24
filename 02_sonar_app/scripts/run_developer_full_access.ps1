[CmdletBinding()]
param(
    [string]$BundleDirectory = "",
    [switch]$Wait,
    [switch]$VerifyOnly
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
if ([string]::IsNullOrWhiteSpace($BundleDirectory)) {
    $BundleDirectory = Join-Path $productRoot "build\developer-full-access\bundle"
}
elseif (-not [IO.Path]::IsPathRooted($BundleDirectory)) {
    $BundleDirectory = Join-Path $productRoot $BundleDirectory
}

& (Join-Path $PSScriptRoot "admit_developer_full_access_launch.ps1") `
    -BundleDirectory $BundleDirectory
$BundleDirectory = (Resolve-Path -LiteralPath $BundleDirectory).Path
$startInfo = [Diagnostics.ProcessStartInfo]::new()
$startInfo.FileName = Join-Path $BundleDirectory "Sonar.exe"
$startInfo.WorkingDirectory = $BundleDirectory
$startInfo.UseShellExecute = $false
$startInfo.Arguments = "--developer-full-access"
if ($VerifyOnly) {
    Write-Output "PASS Fishing developer-full-access launch contract: $BundleDirectory"
    return
}
$process = [Diagnostics.Process]::Start($startInfo)
if ($null -eq $process) {
    throw "developer_host_start_failed"
}

Start-Sleep -Milliseconds 750
$process.Refresh()
if ($process.HasExited) {
    $exitCode = $process.ExitCode
    $process.Dispose()
    throw "developer_host_exited_during_startup: $exitCode"
}
Write-Output "PASS Fishing developer-full-access Host started: pid=$($process.Id)"
if ($Wait) {
    $process.WaitForExit()
    $exitCode = $process.ExitCode
    $process.Dispose()
    exit $exitCode
}
$process.Dispose()
