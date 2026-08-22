[CmdletBinding()]
param(
    [string]$ProductRoot,
    [string]$BundleDirectory,
    [ValidateSet("Package", "Installed")]
    [string]$BundleLifecycleStage = "Package",
    [switch]$RunSelfTest
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

if ([string]::IsNullOrWhiteSpace($ProductRoot)) {
    $ProductRoot = Join-Path $PSScriptRoot ".."
}
if (-not [IO.Path]::IsPathRooted($ProductRoot)) {
    $ProductRoot = Join-Path $PSScriptRoot $ProductRoot
}
if (-not (Test-Path -LiteralPath $ProductRoot -PathType Container)) {
    throw "Fishing product root does not exist: $ProductRoot"
}
$ProductRoot = (Resolve-Path -LiteralPath $ProductRoot).Path

$forbiddenExtensions = @(
    ".py", ".pyw", ".pyc", ".pyo", ".pyd", ".whl", ".spec"
)
$forbiddenExactPaths = @(
    "pyproject.toml",
    "requirements-offline-py312.txt",
    "requirements-test.txt",
    "scripts/build_secure.ps1",
    "scripts/download_wheelhouse.ps1",
    "scripts/download_wheelhouse.sh",
    "scripts/install_venv_offline.ps1",
    "scripts/install_venv_offline.sh",
    "scripts/record_manual_reeling.ps1",
    "scripts/test.sh"
)
$forbiddenPathPrefixes = @(
    "src/sonar/",
    "src/sonar.egg-info/",
    "wheelhouse/"
)
$forbiddenCompositionPattern = [regex]::new(
    '(?i)(pyside6|nuitka|legacyenginefacade|python-legacy-engine-facade|--legacy-engine|src[\\/]sonar|pyproject\.toml|requirements-offline-py312|requirements-test\.txt|(?:python(?:3(?:\.\d+)?)?(?:\.exe)?|py(?:\.exe)?)\s+(?:-|/|scripts[\\/]|[^\s"'']+\.py\b)|\bpip(?:3)?\s+install\b|find_package\s*\(\s*python)',
    [Text.RegularExpressions.RegexOptions]::CultureInvariant
)
$compositionTextExtensions = @(
    ".cs", ".csproj", ".cpp", ".cc", ".cxx", ".h", ".hpp", ".xaml",
    ".props", ".targets", ".ps1", ".cmd", ".bat", ".json", ".proto",
    ".cmake", ".txt"
)

function Convert-ToRepositoryPath([string]$path) {
    return $path.Replace("\", "/").TrimStart([char[]]@(".", "/"))
}

function Test-ForbiddenOwnedPath([string]$relativePath) {
    $normalized = Convert-ToRepositoryPath $relativePath
    $extension = [IO.Path]::GetExtension($normalized).ToLowerInvariant()
    if ($forbiddenExtensions -contains $extension) {
        return $true
    }
    if ($forbiddenExactPaths -contains $normalized) {
        return $true
    }
    foreach ($prefix in $forbiddenPathPrefixes) {
        if ($normalized.StartsWith($prefix, [StringComparison]::OrdinalIgnoreCase)) {
            return $true
        }
    }
    return $false
}

function Get-OwnedRepositoryFiles {
    $git = Get-Command git -ErrorAction SilentlyContinue
    if ($null -eq $git) {
        throw "git is required for the repository-wide source ownership scan"
    }
    $relativePaths = @(& $git.Source -c core.quotepath=false -C $ProductRoot `
        ls-files --cached --others --exclude-standard)
    if ($LASTEXITCODE -ne 0) {
        throw "git source ownership inventory failed"
    }

    $files = [Collections.Generic.List[object]]::new()
    foreach ($relativePath in $relativePaths) {
        if ([string]::IsNullOrWhiteSpace($relativePath)) {
            continue
        }
        $normalized = Convert-ToRepositoryPath $relativePath
        $absolutePath = Join-Path $ProductRoot $normalized
        if (Test-Path -LiteralPath $absolutePath -PathType Leaf) {
            $files.Add([pscustomobject]@{
                RelativePath = $normalized
                FullName = [IO.Path]::GetFullPath($absolutePath)
            })
        }
    }
    return $files
}

function Test-CompositionFile([object]$file) {
    if ($file.RelativePath -eq "scripts/test_no_python_runtime.ps1") {
        return $false
    }
    if ($file.RelativePath -eq "product-commands.json") {
        return $true
    }
    return $file.RelativePath.StartsWith("src/", [StringComparison]::OrdinalIgnoreCase) -or
        $file.RelativePath.StartsWith("native/", [StringComparison]::OrdinalIgnoreCase) -or
        $file.RelativePath.StartsWith("contracts/", [StringComparison]::OrdinalIgnoreCase) -or
        $file.RelativePath.StartsWith("scripts/", [StringComparison]::OrdinalIgnoreCase) -or
        $file.RelativePath.StartsWith("tests/dotnet/", [StringComparison]::OrdinalIgnoreCase)
}

if ($RunSelfTest) {
    foreach ($badPath in @(
        "src/sonar/app.py",
        "tests/oracle.py",
        "wheelhouse/runtime.whl",
        "scripts/build_secure.ps1",
        "pyproject.toml"
    )) {
        if (-not (Test-ForbiddenOwnedPath $badPath)) {
            throw "No-Python ownership self-test accepted forbidden path: $badPath"
        }
    }
    foreach ($safePath in @(
        "src/dotnet/Sonar.Fishing.Host/App.xaml.cs",
        "native/catch_quality/src/catch_quality.cpp",
        "tests/fixtures/catch_quality/legacy_oracle.tsv"
    )) {
        if (Test-ForbiddenOwnedPath $safePath) {
            throw "No-Python ownership self-test rejected target path: $safePath"
        }
    }
    foreach ($badText in @(
        "py -3.12 -m pip install -e .",
        "find_package(Python REQUIRED)",
        "src\sonar\app.py",
        "python-legacy-engine-facade",
        "--enable-plugin=pyside6"
    )) {
        if (-not $forbiddenCompositionPattern.IsMatch($badText)) {
            throw "No-Python ownership self-test accepted forbidden composition: $badText"
        }
    }
    if ($forbiddenCompositionPattern.IsMatch("Preserves frozen Python/C++ parity semantics.")) {
        throw "No-Python ownership self-test rejected historical parity prose"
    }
    Write-Output "PASS no-Python ownership detector self-test"
}

$ownedFiles = @(Get-OwnedRepositoryFiles)
$forbiddenFiles = @($ownedFiles | Where-Object {
    Test-ForbiddenOwnedPath $_.RelativePath
})
if ($forbiddenFiles.Count -ne 0) {
    $paths = $forbiddenFiles.RelativePath -join [Environment]::NewLine
    throw "Python-era product files are forbidden:`n$paths"
}

$compositionMarkers = [Collections.Generic.List[string]]::new()
foreach ($file in $ownedFiles) {
    if (-not (Test-CompositionFile $file)) {
        continue
    }
    $extension = [IO.Path]::GetExtension($file.RelativePath).ToLowerInvariant()
    if ($compositionTextExtensions -notcontains $extension -and
        [IO.Path]::GetFileName($file.RelativePath) -ne "CMakeLists.txt") {
        continue
    }
    foreach ($match in Select-String -LiteralPath $file.FullName -Pattern $forbiddenCompositionPattern) {
        $compositionMarkers.Add("$($file.RelativePath):$($match.LineNumber):$($match.Line.Trim())")
    }
}
if ($compositionMarkers.Count -ne 0) {
    throw "Python-era product composition markers are forbidden:`n$($compositionMarkers -join [Environment]::NewLine)"
}

if ([string]::IsNullOrWhiteSpace($BundleDirectory)) {
    Write-Output "PASS repository-owned Fishing source, tests and entrypoints contain no Python-era product files or composition"
    return
}
if (-not [IO.Path]::IsPathRooted($BundleDirectory)) {
    $BundleDirectory = Join-Path $ProductRoot $BundleDirectory
}
if (-not (Test-Path -LiteralPath $BundleDirectory -PathType Container)) {
    throw "Bundle directory does not exist: $BundleDirectory"
}
$BundleDirectory = (Resolve-Path -LiteralPath $BundleDirectory).Path

$allowedRootFiles = @("Sonar.exe", "Sonar.Engine.exe", "bundle-manifest.json")
$allowedRootDirectories = @("config", "logs")
$rootEntries = @(Get-ChildItem -LiteralPath $BundleDirectory -Force)
foreach ($entry in $rootEntries) {
    if (($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0) {
        throw "Bundle reparse points are forbidden: $($entry.FullName)"
    }
    if ($entry.PSIsContainer) {
        if ($allowedRootDirectories -notcontains $entry.Name) {
            throw "Bundle directory is outside the allowlist: $($entry.FullName)"
        }
    }
    elseif ($allowedRootFiles -notcontains $entry.Name) {
        throw "Bundle file is outside the allowlist: $($entry.FullName)"
    }
}
$actualRootFiles = @($rootEntries | Where-Object { -not $_.PSIsContainer } |
    ForEach-Object Name | Sort-Object)
$actualRootDirectories = @($rootEntries | Where-Object { $_.PSIsContainer } |
    ForEach-Object Name | Sort-Object)
if (($actualRootFiles -join "`n") -cne (($allowedRootFiles | Sort-Object) -join "`n") -or
    ($actualRootDirectories -join "`n") -cne
        (($allowedRootDirectories | Sort-Object) -join "`n")) {
    throw "Bundle root must contain the exact release allowlist"
}

$configDirectory = Join-Path $BundleDirectory "config"
if (-not (Test-Path -LiteralPath $configDirectory -PathType Container)) {
    throw "Bundle config directory is missing"
}
$configEntries = @(Get-ChildItem -LiteralPath $configDirectory -Force)
if ($BundleLifecycleStage -eq "Package") {
    if ($configEntries.Count -ne 0) {
        throw "Package bundle config must be empty before CurrentUser state creation"
    }
}
elseif ($configEntries.Count -ne 1 -or $configEntries[0].PSIsContainer -or
    $configEntries[0].Name -cne "state.dat" -or
    ($configEntries[0].Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0) {
    throw "Installed bundle config allowlist requires exactly config/state.dat"
}
$logsDirectory = Join-Path $BundleDirectory "logs"
if (-not (Test-Path -LiteralPath $logsDirectory -PathType Container)) {
    throw "Bundle logs directory is missing"
}
$logEntries = @(Get-ChildItem -LiteralPath $logsDirectory -Force)
foreach ($entry in $logEntries) {
    if ($entry.PSIsContainer -or
        ($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0 -or
        $entry.Extension -cne ".log") {
        throw "Bundle logs allowlist accepts only direct *.log files"
    }
}
if ($BundleLifecycleStage -eq "Package" -and $logEntries.Count -ne 0) {
    throw "Package bundle logs directory must be empty"
}

$bundleFiles = @(Get-ChildItem -LiteralPath $BundleDirectory -File -Recurse -Force)
foreach ($file in $bundleFiles) {
    if ($forbiddenExtensions -contains $file.Extension.ToLowerInvariant() -or
        $file.Name -match '(?i)(^|[._-])(python|pyside|nuitka)([._-]|$)') {
        throw "Python runtime artifact is forbidden in bundle: $($file.FullName)"
    }
}

$binaryMarkerPattern = '(?i)(python(?:3(?:\.\d+)?)?(?:\.exe|\.dll)?|pyside6|nuitka|--legacy-engine|legacyenginefacade)'
foreach ($executableName in @("Sonar.exe", "Sonar.Engine.exe")) {
    $executable = Join-Path $BundleDirectory $executableName
    if (-not (Test-Path -LiteralPath $executable -PathType Leaf)) {
        throw "Required bundle executable is missing: $executable"
    }
    $bytes = [IO.File]::ReadAllBytes($executable)
    $strings = [Text.Encoding]::GetEncoding(28591).GetString($bytes)
    if ($strings -match $binaryMarkerPattern) {
        throw "Python/legacy marker '$($Matches[0])' is embedded in $executableName"
    }
}

$dumpbin = Get-Command dumpbin.exe -ErrorAction SilentlyContinue
if ($null -eq $dumpbin) {
    $dumpbin = Get-ChildItem -LiteralPath "C:\Program Files (x86)\Microsoft Visual Studio\2022" `
        -Filter dumpbin.exe -File -Recurse -ErrorAction SilentlyContinue |
        Select-Object -First 1
}
if ($null -eq $dumpbin) {
    throw "dumpbin.exe is required for the native dependency scan"
}
$dumpbinPath = if ($dumpbin -is [Management.Automation.CommandInfo]) {
    $dumpbin.Source
}
else {
    $dumpbin.FullName
}
foreach ($executableName in @("Sonar.exe", "Sonar.Engine.exe")) {
    $executable = Join-Path $BundleDirectory $executableName
    $dependencies = & $dumpbinPath /nologo /dependents $executable 2>&1 | Out-String
    if ($LASTEXITCODE -ne 0) {
        throw "dumpbin dependency scan failed for $executableName"
    }
    if ($dependencies -match '(?i)(python|pyside|nuitka)') {
        throw "Python dependency is imported by ${executableName}: $($Matches[0])"
    }
}

Write-Output "PASS final Fishing source, $BundleLifecycleStage bundle allowlist, binary markers and dependency imports contain no Python runtime"
