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
    "build_profile_compatibility_probe\$Configuration\Sonar.Fishing.BuildProfileCompatibilityProbe.exe"

if (-not $NoBuild) {
    & (Join-Path $PSScriptRoot "test_ipc.ps1") -Configuration $Configuration
    if ($LASTEXITCODE -ne 0) {
        throw "build_profile_compatibility_offline_gate_failed:$LASTEXITCODE"
    }
}
if (-not (Test-Path -LiteralPath $tool -PathType Leaf)) {
    throw "build_profile_compatibility_tool_missing"
}

. (Join-Path $PSScriptRoot "release_common.ps1")
$dumpbin = Resolve-FishingDumpbin
$imports = & $dumpbin /nologo /imports $tool 2>&1 | Out-String
if ($LASTEXITCODE -ne 0) {
    throw "build_profile_compatibility_import_scan_failed"
}
foreach ($symbol in @(
        "SendInput",
        "keybd_event",
        "mouse_event",
        "SetCursorPos",
        "WriteProcessMemory",
        "VirtualProtectEx",
        "VirtualAllocEx",
        "CreateRemoteThread",
        "SetForegroundWindow",
        "SendMessageA",
        "SendMessageW",
        "PostMessageA",
        "PostMessageW",
        "BitBlt",
        "PrintWindow",
        "GetDC",
        "GetWindowDC",
        "SetLayeredWindowAttributes",
        "UpdateLayeredWindow")) {
    if ($imports -match "(?im)^\s*$([regex]::Escape($symbol))\s*$") {
        throw "build_profile_compatibility_forbidden_import:$symbol"
    }
}
$dependencies = & $dumpbin /nologo /dependents $tool 2>&1 | Out-String
if ($LASTEXITCODE -ne 0) {
    throw "build_profile_compatibility_dependency_scan_failed"
}
foreach ($library in @("WS2_32.dll", "WINHTTP.dll", "WININET.dll", "URLMON.dll")) {
    if ($dependencies -match "(?im)^\s*$([regex]::Escape($library))\s*$") {
        throw "build_profile_compatibility_network_dependency_detected:$library"
    }
}

Write-Host (
    "Одноразовая read-only проверка готова. Вернитесь в GTA к активному " +
    "вытягиванию рыбы и оставьте окно на переднем плане. Ввода, кадра, " +
    "оверлея, сети и повторной попытки не будет."
)
for ($remaining = $ReturnToGameDelaySeconds; $remaining -gt 0; $remaining--) {
    Write-Host "Запуск через $remaining..."
    Start-Sleep -Seconds 1
}

& $tool "--confirmed-live-build-profile-compatibility"
$toolExitCode = $LASTEXITCODE
if ($toolExitCode -notin @(0, 2)) {
    throw "build_profile_compatibility_tool_failed:$toolExitCode"
}
exit $toolExitCode
