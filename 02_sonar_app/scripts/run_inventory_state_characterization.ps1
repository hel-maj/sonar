[CmdletBinding()]
param(
    [switch]$ConfirmedManualInventoryCharacterization,
    [switch]$NoBuild,
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release"
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

if (-not $ConfirmedManualInventoryCharacterization) {
    throw "manual_inventory_characterization_confirmation_required"
}

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$buildRoot = Join-Path $productRoot "build\native\windows-msvc-v143-ipc"
$tool = Join-Path $buildRoot `
    "build_profile_compatibility_probe\$Configuration\Sonar.Fishing.InventoryStateCharacterization.exe"

if (-not $NoBuild) {
    & (Join-Path $PSScriptRoot "test_ipc.ps1") -Configuration $Configuration
    if ($LASTEXITCODE -ne 0) {
        throw "inventory_characterization_offline_gate_failed:$LASTEXITCODE"
    }
}
if (-not (Test-Path -LiteralPath $tool -PathType Leaf)) {
    throw "inventory_characterization_tool_missing"
}

. (Join-Path $PSScriptRoot "release_common.ps1")
$dumpbin = Resolve-FishingDumpbin
$imports = & $dumpbin /nologo /imports $tool 2>&1 | Out-String
if ($LASTEXITCODE -ne 0) {
    throw "inventory_characterization_import_scan_failed"
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
        "GetWindowDC")) {
    if ($imports -match "(?im)^\s*$([regex]::Escape($symbol))\s*$") {
        throw "inventory_characterization_forbidden_import:$symbol"
    }
}
$dependencies = & $dumpbin /nologo /dependents $tool 2>&1 | Out-String
if ($LASTEXITCODE -ne 0) {
    throw "inventory_characterization_dependency_scan_failed"
}
foreach ($library in @("WS2_32.dll", "WINHTTP.dll", "WININET.dll", "URLMON.dll")) {
    if ($dependencies -match "(?im)^\s*$([regex]::Escape($library))\s*$") {
        throw "inventory_characterization_network_dependency_detected:$library"
    }
}

$evidenceDirectory = Join-Path $productRoot "build\live-evidence"
New-Item -ItemType Directory -Path $evidenceDirectory -Force | Out-Null
$stamp = Get-Date -Format "yyyyMMdd-HHmmss"
$receipt = Join-Path $evidenceDirectory "fishing-inventory-characterization-$stamp.json"

Write-Host "Инструмент не переключает окно и не нажимает TAB."
Write-Host "В каждом запросе вручную установите указанное состояние инвентаря, дождитесь конца анимации и нажмите Enter в этой консоли."
Write-Host "Потребуются discovery CLOSED/OPEN и два validation-цикла CLOSED/OPEN."

& $tool "--confirmed-manual-inventory-characterization" "--output" $receipt
$toolExitCode = $LASTEXITCODE
if ($toolExitCode -notin @(0, 2)) {
    throw "inventory_characterization_tool_failed:$toolExitCode"
}
if (-not (Test-Path -LiteralPath $receipt -PathType Leaf)) {
    throw "inventory_characterization_receipt_missing"
}
Write-Host "Сохранено: $receipt"
exit $toolExitCode
