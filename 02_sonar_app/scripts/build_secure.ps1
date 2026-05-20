param(
    [switch]$SkipInstall,
    [int]$Count = 1
)

$ErrorActionPreference = "Stop"

if ($Count -lt 1) {
    throw "Count must be greater than zero"
}

$Root = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
$BuildParent = Join-Path $Root "build"
$DistRoot = Join-Path $Root "dist"
$IconAssets = Join-Path $Root "assets\game_icons"

if (-not $SkipInstall) {
    python -m pip install --upgrade nuitka ordered-set zstandard
    if ($LASTEXITCODE -ne 0) { throw "Failed to install build dependencies" }
}

python (Join-Path $Root "scripts\prepare_streaming_binaries.py")
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

    python (Join-Path $Root "scripts\prepare_build_branding.py") `
        --source-root "$SecureSrc" `
        --icons-dir "$IconAssets" `
        --metadata-out "$BrandingInfoPath"
    if ($LASTEXITCODE -ne 0) { throw "Build branding failed" }

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
    python -m nuitka `
        --mode=onefile `
        --assume-yes-for-downloads `
        --enable-plugin=pyqt6 `
        --windows-uac-admin `
        --windows-console-mode=disable `
        --windows-icon-from-ico="$IconPath" `
        --product-name="$AppName" `
        --file-description="$AppName" `
        --product-version="$WindowsVersion" `
        --file-version="$WindowsVersion" `
        --include-package=sonar `
        --include-package=requests `
        --include-data-dir="$ResourcesPath=sonar/resources" `
        --include-data-files="$SecureWipePath=sonar/secure_wipe.ps1" `
        --include-data-files="$SDeletePath=sonar/sdelete.exe" `
        --nofollow-import-to=pytest `
        --nofollow-import-to=tests `
        --nofollow-import-to=sonar.tools `
        --output-filename="$OutputExeName" `
        --output-dir="$AppDist" `
        "$EntryPoint"
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
