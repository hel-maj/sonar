param(
    [switch]$SkipInstall,
    [int]$Count = 1,
    [string]$BuildKey = "",
    [string]$ObfuscationSeed = "",
    [string]$LicenseServerUrl = "",
    [string]$LicenseAccountId = "",
    [string]$StartupBlockUrl = "",
    [string]$StartupBlockPublicKey = "",
    [string]$IconName = "",
    [switch]$NoLto
)

$ErrorActionPreference = "Stop"
[Console]::OutputEncoding = [System.Text.UTF8Encoding]::new()
$OutputEncoding = [System.Text.UTF8Encoding]::new()
$env:PYTHONUTF8 = "1"
$env:PYTHONIOENCODING = "utf-8"

if ($Count -lt 1) {
    throw "Count must be greater than zero"
}
if ($IconName -and $Count -ne 1) {
    throw "IconName can only be used with Count 1"
}

$Root = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
$BuildParent = Join-Path $Root "build"
$DistRoot = Join-Path $Root "dist"
$IconAssets = Join-Path $Root "assets\game_icons"
$BuildMapPath = Join-Path (Join-Path (Split-Path $Root -Parent) "config") "sonar_build_keys.json"
$PythonExe = $null
$PythonArgs = @()
$LtoMode = if ($NoLto) { "no" } else { "yes" }
$OnefileTempDirSpec = "{PROGRAM_BASE}.rt/onefile_{PID}_{TIME}"
$PayloadDataDir = ".payload"
$ReleaseJunkExtensions = @(".md", ".markdown", ".rst", ".txt", ".log", ".pdb", ".map")

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

function Read-Utf8Text {
    param([string]$Path)
    return Get-Content -LiteralPath $Path -Raw -Encoding UTF8
}

function Write-Utf8Text {
    param(
        [string]$Path,
        [string]$Value
    )
    Set-Content -LiteralPath $Path -Value $Value -Encoding UTF8
}

function Update-BuildKeyMap {
    param(
        [object]$Branding,
        [string]$AppVersion,
        [string]$ExeName,
        [string]$DistPath,
        [string]$ArchiveName,
        [string]$ArchivePath
    )

    if (-not $Branding.build_key) {
        return
    }
    $MapDir = Split-Path $BuildMapPath -Parent
    New-Item -ItemType Directory -Path $MapDir -Force | Out-Null
    $BuildKeys = @{}
    if (Test-Path $BuildMapPath) {
        try {
            $Existing = Read-Utf8Text $BuildMapPath | ConvertFrom-Json
            if ($Existing.build_keys) {
                foreach ($Property in $Existing.build_keys.PSObject.Properties) {
                    $BuildKeys[$Property.Name] = $Property.Value
                }
            }
        } catch {
            $BuildKeys = @{}
        }
    }
    $BuildKeys[[string]$Branding.build_key] = [ordered]@{
        obfuscation_seed = [string]$Branding.obfuscation_seed
        build_hash = [string]$Branding.build_hash
        app_name = [string]$Branding.app_name
        app_version = $AppVersion
        exe_name = $ExeName
        dist_path = $DistPath
        archive_name = $ArchiveName
        archive_path = $ArchivePath
        icon_png = [string]$Branding.icon_png
        created_at = (Get-Date).ToUniversalTime().ToString("o")
    }
    Write-Utf8Text -Path $BuildMapPath -Value ([ordered]@{ build_keys = $BuildKeys } | ConvertTo-Json -Depth 8)
}

function New-BuildArchive {
    param(
        [object]$Branding,
        [string]$ExePath,
        [string]$ExeName,
        [string]$OutputDir
    )

    $ArchiveStem = [System.IO.Path]::GetFileNameWithoutExtension($ExeName)
    $ArchiveName = "{0}-{1}.zip" -f ([string]$Branding.build_key), $ArchiveStem
    $ArchivePath = Join-Path $OutputDir $ArchiveName
    if (Test-Path $ArchivePath) {
        Remove-Item -LiteralPath $ArchivePath -Force
    }

    Add-Type -AssemblyName System.IO.Compression | Out-Null
    Add-Type -AssemblyName System.IO.Compression.FileSystem | Out-Null
    $Archive = [System.IO.Compression.ZipFile]::Open($ArchivePath, [System.IO.Compression.ZipArchiveMode]::Create)
    try {
        [System.IO.Compression.ZipFileExtensions]::CreateEntryFromFile(
            $Archive,
            $ExePath,
            $ExeName,
            [System.IO.Compression.CompressionLevel]::NoCompression
        ) | Out-Null
    } finally {
        $Archive.Dispose()
    }

    return [PSCustomObject]@{
        Name = $ArchiveName
        Path = $ArchivePath
    }
}

function Remove-ReleaseJunkFiles {
    param([string]$Path)

    if (-not (Test-Path $Path)) {
        return
    }
    Get-ChildItem -LiteralPath $Path -Recurse -File |
        Where-Object { $ReleaseJunkExtensions -contains $_.Extension.ToLowerInvariant() } |
        Remove-Item -Force
}

function Remove-ReleaseForbiddenNames {
    param([string]$Path)

    if (-not (Test-Path $Path)) {
        return
    }
    Get-ChildItem -LiteralPath $Path -Recurse -File |
        Where-Object { $_.Name -like "*sonar*" } |
        Remove-Item -Force
    Get-ChildItem -LiteralPath $Path -Recurse -Directory |
        Where-Object { $_.Name -like "*sonar*" } |
        Sort-Object FullName -Descending |
        Remove-Item -Recurse -Force
}

function Copy-ReleaseLogo {
    param([string]$ResourcesPath)

    $SourceLogo = Join-Path $ResourcesPath "sonar_logo.png"
    $ReleaseLogo = Join-Path $ResourcesPath "logo.png"
    if (Test-Path $SourceLogo) {
        Copy-Item -LiteralPath $SourceLogo -Destination $ReleaseLogo -Force
    }
}

Write-Host "Using Python: $PythonInfo"

if (-not $SkipInstall) {
    Invoke-Python @("-m", "pip", "install", "--upgrade", "-e", "${Root}[build]")
    if ($LASTEXITCODE -ne 0) { throw "Failed to install project build dependencies" }
}

Invoke-Python @((Join-Path $Root "scripts\prepare_streaming_binaries.py"))
if ($LASTEXITCODE -ne 0) { throw "Failed to prepare streaming binaries" }

$BuildNamePlanPath = Join-Path ([System.IO.Path]::GetTempPath()) ("build_name_plan_{0}.json" -f ([guid]::NewGuid().ToString("N")))
$BuildNamePlanArgs = @(
    (Join-Path $Root "scripts\prepare_build_branding.py"),
    "--source-root", (Join-Path $Root "src"),
    "--icons-dir", "$IconAssets",
    "--metadata-out", $BuildNamePlanPath,
    "--plan-count", "$Count",
    "--plan-out", "$BuildNamePlanPath",
    "--existing-builds-dir", "$DistRoot"
)
if ($ObfuscationSeed) {
    $BuildNamePlanArgs += @("--seed", "$ObfuscationSeed")
}
if ($IconName) {
    $BuildNamePlanArgs += @("--icon-name", "$IconName")
}
Invoke-Python $BuildNamePlanArgs
if ($LASTEXITCODE -ne 0) { throw "Build name planning failed" }
$BuildNamePlanRaw = Read-Utf8Text $BuildNamePlanPath | ConvertFrom-Json
$BuildNamePlan = [System.Collections.Generic.List[object]]::new()
foreach ($PlanItem in $BuildNamePlanRaw) {
    [void]$BuildNamePlan.Add($PlanItem)
}
if ($BuildNamePlan.Count -lt $Count) {
    throw "Build name plan contains $($BuildNamePlan.Count) entries, expected $Count"
}

if (Test-Path $BuildParent) {
    Remove-Item -LiteralPath $BuildParent -Recurse -Force
}
if (Test-Path $DistRoot) {
    Remove-Item -LiteralPath $DistRoot -Recurse -Force
}
New-Item -ItemType Directory -Path $DistRoot | Out-Null

try {
for ($BuildIndex = 1; $BuildIndex -le $Count; $BuildIndex++) {
    $BuildRoot = Join-Path $BuildParent ("secure_{0}" -f $BuildIndex)
    $SecureSrc = Join-Path $BuildRoot "src"
    $EntryPoint = Join-Path $SecureSrc "sonar\__main__.py"
    $BrandingInfoPath = Join-Path $BuildRoot "branding.json"

    New-Item -ItemType Directory -Path $BuildRoot -Force | Out-Null
    Copy-Item -LiteralPath (Join-Path $Root "src") -Destination $BuildRoot -Recurse

    $BrandingArgs = @(
        (Join-Path $Root "scripts\prepare_build_branding.py"),
        "--source-root", "$SecureSrc",
        "--icons-dir", "$IconAssets",
        "--metadata-out", "$BrandingInfoPath"
    )
    $PlannedBuild = $BuildNamePlan[$BuildIndex - 1]
    $PlannedIconName = [string]$PlannedBuild.icon_name
    if ($PlannedIconName) {
        $BrandingArgs += @("--icon-name", "$PlannedIconName")
    }
    if ($BuildKey) {
        $BrandingArgs += @("--build-key", "$BuildKey")
    }
    if ($ObfuscationSeed) {
        $BrandingArgs += @("--seed", "$ObfuscationSeed")
    }
    if ($LicenseServerUrl) {
        $BrandingArgs += @("--license-server-url", "$LicenseServerUrl")
    }
    if ($LicenseAccountId) {
        $BrandingArgs += @("--license-account-id", "$LicenseAccountId")
    }
    if ($StartupBlockUrl) {
        $BrandingArgs += @("--startup-block-url", "$StartupBlockUrl")
    }
    if ($StartupBlockPublicKey) {
        $BrandingArgs += @("--startup-block-public-key", "$StartupBlockPublicKey")
    }
    Invoke-Python $BrandingArgs
    if ($LASTEXITCODE -ne 0) { throw "Build branding failed" }

    Invoke-Python @(
        (Join-Path $Root "scripts\prepare_release_sources.py"),
        "--source-root", "$SecureSrc"
    )
    if ($LASTEXITCODE -ne 0) { throw "Release source preparation failed" }

    $Branding = Read-Utf8Text $BrandingInfoPath | ConvertFrom-Json
    $ObfuscationInfoPath = Join-Path $BuildRoot "obfuscation.json"
    Invoke-Python @(
        (Join-Path $Root "scripts\obfuscate_release_sources.py"),
        "--source-root", "$SecureSrc",
        "--seed", "$($Branding.obfuscation_seed)",
        "--metadata-out", "$ObfuscationInfoPath"
    )
    if ($LASTEXITCODE -ne 0) { throw "Release source obfuscation failed" }

    $VersionContent = Read-Utf8Text (Join-Path $SecureSrc "sonar\version.py")
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
    $VersionDistRoot = Join-Path $DistRoot $AppVersion

    $AppName = [string]$Branding.app_name
    $OutputExeName = [string]$Branding.exe_name
    $OutputStem = [System.IO.Path]::GetFileNameWithoutExtension($OutputExeName)
    $AppDist = Join-Path $VersionDistRoot $OutputStem
    if (Test-Path $AppDist) {
        $AppDist = Join-Path $VersionDistRoot ("{0}-{1}" -f ([string]$Branding.build_key), $OutputStem)
    }
    New-Item -ItemType Directory -Path $AppDist -Force | Out-Null

    $env:PYTHONPATH = $SecureSrc
    $IconPath = Join-Path $SecureSrc "sonar\resources\app.ico"
    $ResourcesPath = Join-Path $SecureSrc "sonar\resources"
    $SecureWipePath = Join-Path $SecureSrc "sonar\secure_wipe.ps1"
    $SDeletePath = Join-Path $SecureSrc "sonar\sdelete.exe"
    Copy-ReleaseLogo -ResourcesPath $ResourcesPath
    Remove-ReleaseJunkFiles -Path $ResourcesPath
    Remove-ReleaseForbiddenNames -Path $ResourcesPath

    Write-Host "Building ${BuildIndex}/${Count}: $OutputExeName"
    Invoke-Python @(
        "-m", "nuitka",
        "--mode=onefile",
        "--onefile-tempdir-spec=$OnefileTempDirSpec",
        "--assume-yes-for-downloads",
        "--enable-plugin=pyside6",
        "--deployment",
        "--lto=$LtoMode",
        "--python-flag=no_docstrings",
        "--python-flag=no_asserts",
        "--windows-console-mode=disable",
        "--windows-icon-from-ico=$IconPath",
        "--product-name=$AppName",
        "--file-description=$AppName",
        "--product-version=$WindowsVersion",
        "--file-version=$WindowsVersion",
        "--include-package=sonar",
        "--include-package=requests",
        "--include-data-dir=$ResourcesPath=$PayloadDataDir/resources",
        "--include-data-files=$SecureWipePath=$PayloadDataDir/helpers/secure_wipe.ps1",
        "--include-data-files=$SDeletePath=$PayloadDataDir/helpers/sdelete.exe",
        "--nofollow-import-to=pytest",
        "--nofollow-import-to=tests",
        "--nofollow-import-to=sonar.tools",
        "--output-filename=$OutputExeName",
        "--output-dir=$AppDist",
        "$EntryPoint"
    )
    if ($LASTEXITCODE -ne 0) { throw "Nuitka build failed" }

    Get-ChildItem -LiteralPath $AppDist -Directory -Filter "__main__.*" | Remove-Item -Recurse -Force
    Remove-ReleaseJunkFiles -Path $AppDist
    New-Item -ItemType Directory -Path (Join-Path $AppDist "config") -Force | Out-Null
    Invoke-Python @((Join-Path $Root "scripts\audit_release_secrets.py"), "--target", "$AppDist")
    if ($LASTEXITCODE -ne 0) { throw "Release secret audit failed" }
    $ExePath = Join-Path $AppDist $OutputExeName
    $Archive = New-BuildArchive -Branding $Branding -ExePath $ExePath -ExeName $OutputExeName -OutputDir $AppDist
    Update-BuildKeyMap -Branding $Branding -AppVersion $AppVersion -ExeName $OutputExeName -DistPath $ExePath -ArchiveName $Archive.Name -ArchivePath $Archive.Path
    Write-Host "Build complete: $ExePath"
    Write-Host "Build archive: $($Archive.Path)"
    Write-Host "Build version: $AppVersion"
    Write-Host "Build hash: $($Branding.build_hash)"
    Write-Host "Build key: $($Branding.build_key)"
    Write-Host "Obfuscation seed: $($Branding.obfuscation_seed)"
    Write-Host "Build key map: $BuildMapPath"
    Write-Host "Icon source: $($Branding.icon_png)"
    Write-Host "Salt bytes: $($Branding.salt_bytes)"
}
} finally {
    if (Test-Path $BuildNamePlanPath) {
        Remove-Item -LiteralPath $BuildNamePlanPath -Force
    }
}

if (Test-Path $BuildParent) {
    Remove-Item -LiteralPath $BuildParent -Recurse -Force
}
