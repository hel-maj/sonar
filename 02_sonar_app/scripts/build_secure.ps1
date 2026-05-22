param(
    [switch]$SkipInstall,
    [int]$Count = 1
)

$ErrorActionPreference = "Stop"
[Console]::OutputEncoding = [System.Text.UTF8Encoding]::new()
$OutputEncoding = [System.Text.UTF8Encoding]::new()

if ($Count -lt 1) {
    throw "Count must be greater than zero"
}

$Root = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
$BuildParent = Join-Path $Root "build"
$DistRoot = Join-Path $Root "dist"
$IconAssets = Join-Path $Root "assets\game_icons"
$PythonExe = $null
$PythonArgs = @()

function Test-Python312 {
    param(
        [string]$Exe,
        [string[]]$PrefixArgs = @()
    )

    $Version = & $Exe @PrefixArgs -c "import sys; print(sys.executable + ' ' + sys.version.split()[0]); raise SystemExit(0 if sys.version_info[:2] == (3, 12) else 1)" 2>$null
    if ($LASTEXITCODE -eq 0) {
        return $Version
    }
    return $null
}

$PyLauncher = Get-Command py -ErrorAction SilentlyContinue
if ($PyLauncher) {
    $PythonInfo = Test-Python312 $PyLauncher.Source @("-3.12")
    if ($PythonInfo) {
        $PythonExe = $PyLauncher.Source
        $PythonArgs = @("-3.12")
    }
}

if (-not $PythonExe) {
    $Python312Path = "C:\Python312\python.exe"
    if (Test-Path $Python312Path) {
        $PythonInfo = Test-Python312 $Python312Path
        if ($PythonInfo) {
            $PythonExe = $Python312Path
            $PythonArgs = @()
        }
    }
}

if (-not $PythonExe) {
    $Python = Get-Command python -ErrorAction SilentlyContinue
    if ($Python) {
        $PythonInfo = Test-Python312 $Python.Source
        if ($PythonInfo) {
            $PythonExe = $Python.Source
            $PythonArgs = @()
        }
    }
}

if (-not $PythonExe) {
    throw "Python 3.12 is required for secure build"
}

function Invoke-Python {
    param([string[]]$Arguments)
    & $PythonExe @PythonArgs @Arguments
}

Write-Host "Using Python: $PythonInfo"

if (-not $SkipInstall) {
    Invoke-Python @("-m", "pip", "install", "--upgrade", "-e", "${Root}[build]")
    if ($LASTEXITCODE -ne 0) { throw "Failed to install project build dependencies" }
}

Invoke-Python @((Join-Path $Root "scripts\prepare_streaming_binaries.py"))
if ($LASTEXITCODE -ne 0) { throw "Failed to prepare streaming binaries" }

if (Test-Path $BuildParent) {
    Remove-Item -LiteralPath $BuildParent -Recurse -Force
}
if (Test-Path $DistRoot) {
    Remove-Item -LiteralPath $DistRoot -Recurse -Force
}
New-Item -ItemType Directory -Path $DistRoot | Out-Null

for ($BuildIndex = 1; $BuildIndex -le $Count; $BuildIndex++) {
    $BuildRoot = Join-Path $BuildParent ("secure_{0}" -f $BuildIndex)
    $SecureSrc = Join-Path $BuildRoot "src"
    $EntryPoint = Join-Path $SecureSrc "sonar\__main__.py"
    $BrandingInfoPath = Join-Path $BuildRoot "branding.json"

    New-Item -ItemType Directory -Path $BuildRoot -Force | Out-Null
    Copy-Item -LiteralPath (Join-Path $Root "src") -Destination $BuildRoot -Recurse

    Invoke-Python @(
        (Join-Path $Root "scripts\prepare_build_branding.py"),
        "--source-root", "$SecureSrc",
        "--icons-dir", "$IconAssets",
        "--metadata-out", "$BrandingInfoPath"
    )
    if ($LASTEXITCODE -ne 0) { throw "Build branding failed" }

    Invoke-Python @(
        (Join-Path $Root "scripts\prepare_release_sources.py"),
        "--source-root", "$SecureSrc"
    )
    if ($LASTEXITCODE -ne 0) { throw "Release source preparation failed" }

    $Branding = Get-Content -LiteralPath $BrandingInfoPath -Raw | ConvertFrom-Json
    $AppName = [string]$Branding.app_name
    $OutputExeName = [string]$Branding.exe_name
    $OutputStem = [System.IO.Path]::GetFileNameWithoutExtension($OutputExeName)
    $AppDist = Join-Path $DistRoot $OutputStem
    if (Test-Path $AppDist) {
        $OutputStem = "{0}_{1}" -f $OutputStem, ([string]$Branding.build_hash).Substring(0, 8)
        $OutputExeName = "{0}.exe" -f $OutputStem
        $AppDist = Join-Path $DistRoot $OutputStem
    }
    New-Item -ItemType Directory -Path $AppDist -Force | Out-Null

    $VersionContent = Get-Content -LiteralPath (Join-Path $SecureSrc "sonar\version.py") -Raw
    if ($VersionContent -match 'APP_VERSION\s*=\s*"([0-9]+(?:\.[0-9]+){0,3})"') {
        $AppVersion = $Matches[1]
    } else {
        $AppVersion = "0.1.0"
    }
    $VersionParts = @($AppVersion.Split("."))
    while ($VersionParts.Count -lt 4) {
        $VersionParts += "0"
    }
    $WindowsVersion = ($VersionParts[0..3] -join ".")

    $env:PYTHONPATH = $SecureSrc
    $IconPath = Join-Path $SecureSrc "sonar\resources\app.ico"
    $ResourcesPath = Join-Path $SecureSrc "sonar\resources"
    $SecureWipePath = Join-Path $SecureSrc "sonar\secure_wipe.ps1"
    $SDeletePath = Join-Path $SecureSrc "sonar\sdelete.exe"

    Write-Host "Building ${BuildIndex}/${Count}: $OutputExeName"
    Invoke-Python @(
        "-m", "nuitka",
        "--mode=onefile",
        "--assume-yes-for-downloads",
        "--enable-plugin=pyside6",
        "--windows-uac-admin",
        "--windows-console-mode=disable",
        "--windows-icon-from-ico=$IconPath",
        "--product-name=$AppName",
        "--file-description=$AppName",
        "--product-version=$WindowsVersion",
        "--file-version=$WindowsVersion",
        "--include-package=sonar",
        "--include-package=requests",
        "--include-data-dir=$ResourcesPath=sonar/resources",
        "--include-data-files=$SecureWipePath=sonar/secure_wipe.ps1",
        "--include-data-files=$SDeletePath=sonar/sdelete.exe",
        "--nofollow-import-to=pytest",
        "--nofollow-import-to=tests",
        "--nofollow-import-to=sonar.tools",
        "--output-filename=$OutputExeName",
        "--output-dir=$AppDist",
        "$EntryPoint"
    )
    if ($LASTEXITCODE -ne 0) { throw "Nuitka build failed" }

    Get-ChildItem -LiteralPath $AppDist -Directory -Filter "__main__.*" | Remove-Item -Recurse -Force
    New-Item -ItemType Directory -Path (Join-Path $AppDist "config") -Force | Out-Null
    Write-Host "Build complete: $(Join-Path $AppDist $OutputExeName)"
    Write-Host "Build hash: $($Branding.build_hash)"
    Write-Host "Icon source: $($Branding.icon_png)"
    Write-Host "Salt bytes: $($Branding.salt_bytes)"
}

if (Test-Path $BuildParent) {
    Remove-Item -LiteralPath $BuildParent -Recurse -Force
}
