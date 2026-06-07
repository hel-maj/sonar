param(
    [string]$TargetDir,
    [string]$SDeletePath,
    [string]$ExecutablePath
)

if (-not (Test-Path $TargetDir)) { exit 0 }

Write-Host "[SECURE WIPE] Targeted secure deletion started"

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

# Только файлы и папки, которые приложение создаёт само
Secure-Delete-Path $ExecutablePath
Secure-Delete-Path (Join-Path $TargetDir "config")
Secure-Delete-Path (Join-Path $TargetDir "logs")
Secure-Delete-Path (Join-Path $TargetDir "debug_capture")
Secure-Delete-Path (Join-Path $TargetDir ".runtime")

# Лёгкая очистка свободного места (меньше шума)
$Drive = $TargetDir.Substring(0,2)
& $SDeletePath -accepteula -p 1 -z -q $Drive 2>$null

# Только prefetch этой программы
$AppName = [System.IO.Path]::GetFileNameWithoutExtension($ExecutablePath)
if ($AppName) {
    Get-ChildItem -Path "$env:SystemRoot\Prefetch" -Filter "$AppName*.pf" -ErrorAction SilentlyContinue |
        Remove-Item -Force -ErrorAction SilentlyContinue
}

Write-Host "[SECURE WIPE] Completed"
