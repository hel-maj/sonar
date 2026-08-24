[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [ValidateSet("Install", "Update", "Rollback", "Recover", "ImportLicense")]
    [string]$Action,
    [Parameter(Mandatory = $true)]
    [string]$SourceBundle,
    [Parameter(Mandatory = $true)]
    [string]$InstallDirectory,
    [string]$BackupDirectory = "",
    [string]$LegacyLicenseSettingsPath = "",
    [switch]$DevelopmentUnsigned,
    [switch]$DryRun,
    [ValidateRange(5, 120)]
    [int]$WaitTimeoutSeconds = 60
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

. (Join-Path $PSScriptRoot "release_common.ps1")

function ConvertTo-FishingWindowsCommandLineArgument {
    param(
        [Parameter(Mandatory = $true)]
        [AllowEmptyString()]
        [string]$Value
    )

    # ProcessStartInfo.ArgumentList is unavailable in Windows PowerShell 5.1.
    # Quote every token according to CommandLineToArgvW rules so paths with
    # spaces, quotes or trailing backslashes remain one exact argument.
    $builder = [Text.StringBuilder]::new()
    [void]$builder.Append([char]0x22)
    $backslashes = 0
    foreach ($character in $Value.ToCharArray()) {
        if ($character -eq [char]0x5C) {
            $backslashes++
            continue
        }
        if ($character -eq [char]0x22) {
            [void]$builder.Append([char]0x5C, (2 * $backslashes) + 1)
            [void]$builder.Append([char]0x22)
            $backslashes = 0
            continue
        }
        if ($backslashes -gt 0) {
            [void]$builder.Append([char]0x5C, $backslashes)
            $backslashes = 0
        }
        [void]$builder.Append($character)
    }
    if ($backslashes -gt 0) {
        [void]$builder.Append([char]0x5C, 2 * $backslashes)
    }
    [void]$builder.Append([char]0x22)
    return $builder.ToString()
}

if (-not $DevelopmentUnsigned) {
    throw "release_maintenance_production_signed_not_composed"
}

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$source = Get-FishingCanonicalPath $SourceBundle
if (-not (Test-Path -LiteralPath $source -PathType Container)) {
    throw "release_maintenance_source_missing: $source"
}
[void](Read-FishingBundleManifest $productRoot $source "development-unsigned")
$executor = Join-Path $source "Sonar.exe"

$target = Get-FishingCanonicalPath $InstallDirectory
$actionValue = if ($Action -eq "ImportLicense") {
    "import-license"
}
else {
    $Action.ToLowerInvariant()
}
if ($Action -eq "Install") {
    $targetParent = Split-Path -Parent $target
    if ((Test-Path -LiteralPath $target) -or
        -not (Test-Path -LiteralPath $targetParent -PathType Container)) {
        throw "release_maintenance_install_target_invalid: $target"
    }
}
elseif (-not (Test-Path -LiteralPath $target -PathType Container)) {
    throw "release_maintenance_target_missing: $target"
}

$requiresBackup = $Action -in @("Update", "Rollback")
if ($requiresBackup) {
    if ([string]::IsNullOrWhiteSpace($BackupDirectory)) {
        throw "release_maintenance_backup_required"
    }
    $backup = Get-FishingCanonicalPath $BackupDirectory
    $backupParent = Split-Path -Parent $backup
    if ((Test-Path -LiteralPath $backup) -or
        -not (Test-Path -LiteralPath $backupParent -PathType Container)) {
        throw "release_maintenance_backup_invalid: $backup"
    }
}
elseif (-not [string]::IsNullOrWhiteSpace($BackupDirectory)) {
    throw "release_maintenance_backup_unexpected"
}
if ($Action -eq "ImportLicense") {
    if ([string]::IsNullOrWhiteSpace($LegacyLicenseSettingsPath) -or
        -not (Test-Path -LiteralPath $LegacyLicenseSettingsPath -PathType Leaf)) {
        throw "legacy_license_source_required"
    }
    $legacyLicenseSettings = Get-FishingCanonicalPath $LegacyLicenseSettingsPath
}
elseif (-not [string]::IsNullOrWhiteSpace($LegacyLicenseSettingsPath)) {
    throw "legacy_license_source_unexpected"
}

$receiptDirectory = Join-Path $productRoot "build\release-maintenance\receipts"
New-Item -ItemType Directory -Path $receiptDirectory -Force | Out-Null
$receipt = Join-Path $receiptDirectory "receipt-$([Guid]::NewGuid().ToString('N')).json"

$startInfo = [Diagnostics.ProcessStartInfo]::new()
$startInfo.FileName = $executor
$startInfo.WorkingDirectory = $source
$startInfo.UseShellExecute = $false
$startInfo.CreateNoWindow = $true
$startInfo.WindowStyle = [Diagnostics.ProcessWindowStyle]::Hidden
$executorArguments = @(
    "--release-maintenance",
    "--action", $actionValue,
    "--source", $source,
    "--target", $target,
    "--receipt", $receipt,
    "--wait-timeout-seconds", [string]$WaitTimeoutSeconds,
    "--development-unsigned")
if ($requiresBackup) {
    $executorArguments += @("--backup", $backup)
}
if ($Action -eq "ImportLicense") {
    $executorArguments += @("--legacy-license-settings", $legacyLicenseSettings)
}
if ($DryRun) {
    $executorArguments += "--dry-run"
}

if (Test-Path -LiteralPath $target -PathType Container) {
    $expectedExecutables = @(
        (Join-Path $target "Sonar.exe"),
        (Join-Path $target "Sonar.Engine.exe")
    ) | ForEach-Object { [IO.Path]::GetFullPath($_) }
    $running = @(Get-CimInstance Win32_Process `
        -Filter "Name = 'Sonar.exe' OR Name = 'Sonar.Engine.exe'" `
        -ErrorAction Stop |
        Where-Object {
            $_.ExecutablePath -and
            $expectedExecutables -contains
                [IO.Path]::GetFullPath([string]$_.ExecutablePath)
        } |
        Sort-Object ProcessId)
    if ($running.Count -gt 2) {
        throw "release_maintenance_process_set_ambiguous"
    }
    foreach ($process in $running) {
        $executorArguments += @("--wait-pid", [string]$process.ProcessId)
    }
}
$startInfo.Arguments = ($executorArguments |
    ForEach-Object { ConvertTo-FishingWindowsCommandLineArgument ([string]$_) }) -join " "

$process = [Diagnostics.Process]::Start($startInfo)
if ($null -eq $process) {
    throw "release_maintenance_executor_start_failed"
}
try {
    if (-not $process.WaitForExit(($WaitTimeoutSeconds + 30) * 1000)) {
        throw "release_maintenance_executor_timeout"
    }
    if (-not (Test-Path -LiteralPath $receipt -PathType Leaf)) {
        throw "release_maintenance_receipt_missing: exit=$($process.ExitCode)"
    }
    $result = Get-Content -Raw -LiteralPath $receipt | ConvertFrom-Json
    Write-Output ($result | ConvertTo-Json -Compress)
    if ($process.ExitCode -ne 0 -or -not $result.accepted) {
        throw "release_maintenance_rejected: $($result.reason)"
    }
}
finally {
    $process.Dispose()
}

if (-not $DryRun) {
    $stage = switch ($Action) {
        "Install" { "Installed" }
        "Update" { "Updated" }
        "Rollback" { "RemoteRollback" }
        "Recover" { "InterruptedUpdateRecovery" }
        "ImportLicense" { "Installed" }
    }
    & (Join-Path $PSScriptRoot "test_no_python_runtime.ps1") `
        -ProductRoot $productRoot `
        -BundleDirectory $target `
        -BundleLifecycleStage $stage
}
