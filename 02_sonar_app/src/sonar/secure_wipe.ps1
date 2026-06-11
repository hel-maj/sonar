param(
    [string]$TargetDir,
    [string]$SDeletePath,
    [string]$ExecutablePath
)

if (-not (Test-Path $TargetDir)) { exit 0 }

Write-Host "[SECURE WIPE] Targeted secure deletion started"

$AppName = [System.IO.Path]::GetFileNameWithoutExtension($ExecutablePath)

function Stop-Target-Processes {
    param([string]$Path)
    $Needle = $Path.TrimEnd("\").ToLowerInvariant()
    $Prefix = "$Needle\"
    Get-CimInstance Win32_Process -ErrorAction SilentlyContinue | ForEach-Object {
        if ($_.ProcessId -ne $PID) {
            $ExePath = if ($_.ExecutablePath) { $_.ExecutablePath.ToLowerInvariant() } else { "" }
            $CommandLine = if ($_.CommandLine) { $_.CommandLine.ToLowerInvariant() } else { "" }
            if ($ExePath.StartsWith($Prefix) -or $CommandLine.Contains($Needle)) {
                Stop-Process -Id $_.ProcessId -Force -ErrorAction SilentlyContinue
            }
        }
    }
    Start-Sleep -Milliseconds 500
}

function Secure-Delete-File {
    param($File)
    try {
        & $SDeletePath -accepteula -p 4 -q -s $File.FullName 2>$null
        Remove-Item $File.FullName -Force -ErrorAction SilentlyContinue
    } catch { }
}

function Secure-Delete-Path {
    param([string]$Path)
    if (-not (Test-Path $Path)) { return }
    try {
        $Item = Get-Item -LiteralPath $Path -Force -ErrorAction SilentlyContinue
        if ($null -eq $Item) { return }
        if ($Item.PSIsContainer) {
            Get-ChildItem -LiteralPath $Item.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | ForEach-Object {
                Secure-Delete-File $_
            }
            Remove-Item -LiteralPath $Item.FullName -Recurse -Force -ErrorAction SilentlyContinue
        } else {
            Secure-Delete-File $Item
        }
    } catch { }
}

Stop-Target-Processes $TargetDir
Secure-Delete-Path $TargetDir
Stop-Target-Processes $TargetDir
if (Test-Path $TargetDir) {
    Remove-Item -LiteralPath $TargetDir -Recurse -Force -ErrorAction SilentlyContinue
}

# Только prefetch этой программы
if ($AppName) {
    Get-ChildItem -Path "$env:SystemRoot\Prefetch" -Filter "$AppName*.pf" -ErrorAction SilentlyContinue |
        Remove-Item -Force -ErrorAction SilentlyContinue
}

Write-Host "[SECURE WIPE] Completed"
