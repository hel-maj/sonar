[CmdletBinding()]
param(
    [switch]$NoBuild,
    [ValidateRange(5, 10)]
    [int]$ReturnToGameDelaySeconds = 5,
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release"
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$buildRoot = Join-Path $productRoot "build\native\windows-msvc-v143-ipc"
$tool = Join-Path $buildRoot `
    "live_observation_preflight\$Configuration\Sonar.Fishing.LiveObservationPreflight.exe"

if (-not $NoBuild) {
    & (Join-Path $PSScriptRoot "test_ipc.ps1") -Configuration $Configuration
    if ($LASTEXITCODE -ne 0) {
        throw "live_readonly_offline_gate_failed:$LASTEXITCODE"
    }
}
if (-not (Test-Path -LiteralPath $tool -PathType Leaf)) {
    throw "live_readonly_tool_missing:$tool"
}

. (Join-Path $PSScriptRoot "release_common.ps1")
$dumpbin = Resolve-FishingDumpbin
$imports = & $dumpbin /nologo /imports $tool 2>&1 | Out-String
if ($LASTEXITCODE -ne 0) {
    throw "live_readonly_import_scan_failed"
}
foreach ($symbol in @("SendInput", "keybd_event", "mouse_event", "SetCursorPos")) {
    if ($imports -match "(?im)^\s*$([regex]::Escape($symbol))\s*$") {
        throw "live_readonly_mutation_import_detected:$symbol"
    }
}
$dependencies = & $dumpbin /nologo /dependents $tool 2>&1 | Out-String
if ($LASTEXITCODE -ne 0) {
    throw "live_readonly_dependency_scan_failed"
}
foreach ($library in @("WS2_32.dll", "WINHTTP.dll", "WININET.dll", "URLMON.dll")) {
    if ($dependencies -match "(?im)^\s*$([regex]::Escape($library))\s*$") {
        throw "live_readonly_network_dependency_detected:$library"
    }
}

Write-Host (
    "Read-only preflight готов. Вернитесь в окно GTA и оставьте его на переднем плане. " +
    "Инструмент выполнит один снимок окна и один bounded memory-read; ввода не будет."
)
for ($remaining = $ReturnToGameDelaySeconds; $remaining -gt 0; $remaining--) {
    Write-Host "Запуск через $remaining..."
    Start-Sleep -Seconds 1
}

& $tool "--confirmed-live-read-only"
$toolExitCode = $LASTEXITCODE
if ($toolExitCode -notin @(0, 2)) {
    throw "live_readonly_tool_failed:$toolExitCode"
}
exit $toolExitCode
