param(
    [string]$TargetDir,
    [string]$SDeletePath
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

# Secure delete файлов
Get-ChildItem -Path $TargetDir -Recurse -File -ErrorAction SilentlyContinue | ForEach-Object {
    Secure-Delete-File $_
}

# Удаление папки
Remove-Item -Path $TargetDir -Recurse -Force -ErrorAction SilentlyContinue

# Лёгкая очистка свободного места (меньше шума)
$Drive = $TargetDir.Substring(0,2)
& $SDeletePath -accepteula -p 1 -z -q $Drive 2>$null

# Только prefetch этой программы
$AppName = Split-Path $TargetDir -Leaf
Get-ChildItem "$env:SystemRoot\Prefetch\*$AppName*.pf" -ErrorAction SilentlyContinue |
    Remove-Item -Force -ErrorAction SilentlyContinue

Write-Host "[SECURE WIPE] Completed"
