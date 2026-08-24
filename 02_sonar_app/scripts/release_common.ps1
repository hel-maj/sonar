Set-StrictMode -Version Latest

$script:FishingReleaseModes = @(
    "development-unsigned",
    "production-signed"
)

function Get-FishingCanonicalVersion([string]$Version) {
    if ([string]::IsNullOrWhiteSpace($Version) -or
        $Version -notmatch '^(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)(?:-[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*)?$') {
        throw "release_version_invalid: $Version"
    }
    return $Version
}

function Get-FishingCanonicalPath([string]$Path) {
    if ([string]::IsNullOrWhiteSpace($Path)) {
        throw "release_path_missing"
    }
    return [IO.Path]::GetFullPath($Path)
}

function Assert-FishingSafeBuildPath(
    [string]$ProductRoot,
    [string]$Path,
    [string]$Purpose = "release output") {
    $separators = [char[]]@(
        [IO.Path]::DirectorySeparatorChar,
        [IO.Path]::AltDirectorySeparatorChar)
    $root = (Get-FishingCanonicalPath $ProductRoot).TrimEnd($separators)
    $buildRoot = (Get-FishingCanonicalPath (Join-Path $root "build")).TrimEnd($separators)
    $candidate = (Get-FishingCanonicalPath $Path).TrimEnd($separators)
    $prefix = $buildRoot + [IO.Path]::DirectorySeparatorChar
    if (-not $candidate.StartsWith($prefix, [StringComparison]::OrdinalIgnoreCase) -or
        $candidate.Equals($buildRoot, [StringComparison]::OrdinalIgnoreCase)) {
        throw "release_path_outside_build_root: $Purpose"
    }

    $current = $candidate
    while ($true) {
        if (Test-Path -LiteralPath $current) {
            $item = Get-Item -LiteralPath $current -Force
            if (($item.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0) {
                throw "release_path_reparse_point: $Purpose"
            }
            if (-not $item.PSIsContainer) {
                throw "release_path_not_directory: $Purpose"
            }
        }
        if ($current.Equals($buildRoot, [StringComparison]::OrdinalIgnoreCase)) {
            break
        }
        $parent = Split-Path -Parent $current
        if ([string]::IsNullOrWhiteSpace($parent) -or
            $parent.Equals($current, [StringComparison]::OrdinalIgnoreCase) -or
            (-not $parent.Equals($buildRoot, [StringComparison]::OrdinalIgnoreCase) -and
             -not $parent.StartsWith($prefix, [StringComparison]::OrdinalIgnoreCase))) {
            throw "release_path_outside_build_root: $Purpose"
        }
        $current = $parent
    }
    return $candidate
}

function Reset-FishingBuildDirectory(
    [string]$ProductRoot,
    [string]$Path,
    [string]$Purpose = "release output") {
    $candidate = Assert-FishingSafeBuildPath $ProductRoot $Path $Purpose
    if (Test-Path -LiteralPath $candidate) {
        Remove-Item -LiteralPath $candidate -Recurse -Force
    }
    New-Item -ItemType Directory -Path $candidate -Force | Out-Null
    return $candidate
}

function Get-FishingSha256([string]$Path) {
    if (-not (Test-Path -LiteralPath $Path -PathType Leaf)) {
        throw "release_file_missing: $Path"
    }
    return (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToUpperInvariant()
}

function Get-FishingSourceIdentity([string]$ProductRoot) {
    $commitLines = @(& git -C $ProductRoot rev-parse HEAD 2>$null)
    $commitExitCode = $LASTEXITCODE
    $commit = $commitLines | Select-Object -First 1
    if ($commitExitCode -ne 0 -or $commit -notmatch '^[0-9a-fA-F]{40}$') {
        throw "release_git_commit_unavailable"
    }
    $changes = @(& git -C $ProductRoot status --short -- . 2>$null)
    $statusExitCode = $LASTEXITCODE
    if ($statusExitCode -ne 0) {
        throw "release_git_status_unavailable"
    }
    return [pscustomobject][ordered]@{
        commitSha = $commit.ToLowerInvariant()
        dirty = [bool]($changes.Count -ne 0)
    }
}

function New-FishingBundleManifestData(
    [string]$ProductRoot,
    [string]$BundleDirectory,
    [string]$Version,
    [string]$ReleaseMode,
    [string]$UnsignedHostSha256,
    [string]$UnsignedEngineSha256,
    [string]$SecondHostSha256,
    [string]$SecondEngineSha256,
    [bool]$DeterminismVerified,
    [string]$HostSignatureStatus,
    [string]$EngineSignatureStatus) {
    $Version = Get-FishingCanonicalVersion $Version
    if ($script:FishingReleaseModes -notcontains $ReleaseMode) {
        throw "release_mode_invalid: $ReleaseMode"
    }
    $bundle = Get-FishingCanonicalPath $BundleDirectory
    $hostPath = Join-Path $bundle "Sonar.exe"
    $enginePath = Join-Path $bundle "Sonar.Engine.exe"
    $schemaPath = Join-Path $ProductRoot "contracts\ipc\v1\sonar_fishing.proto"
    $hostHash = Get-FishingSha256 $hostPath
    $engineHash = Get-FishingSha256 $enginePath
    $schemaHash = Get-FishingSha256 $schemaPath
    foreach ($hash in @(
        $UnsignedHostSha256,
        $UnsignedEngineSha256,
        $SecondHostSha256,
        $SecondEngineSha256)) {
        if ($hash -notmatch '^[0-9A-Fa-f]{64}$') {
            throw "release_determinism_hash_invalid"
        }
    }
    $source = Get-FishingSourceIdentity $ProductRoot
    return [pscustomobject][ordered]@{
        schemaVersion = 1
        product = "fishing"
        releaseMode = $ReleaseMode
        version = $Version
        source = [pscustomobject][ordered]@{
            commitSha = $source.commitSha
            dirty = $source.dirty
        }
        ipc = [pscustomobject][ordered]@{
            schema = "ipc/v1/sonar_fishing.proto"
            schemaSha256 = $schemaHash
        }
        host = [pscustomobject][ordered]@{
            path = "Sonar.exe"
            sha256 = $hostHash
            unsignedSha256 = $UnsignedHostSha256.ToUpperInvariant()
            buildId = "fishing-host-$($UnsignedHostSha256.Substring(0, 16).ToLowerInvariant())"
        }
        engine = [pscustomobject][ordered]@{
            path = "Sonar.Engine.exe"
            sha256 = $engineHash
            unsignedSha256 = $UnsignedEngineSha256.ToUpperInvariant()
            buildId = "fishing-engine-$($UnsignedEngineSha256.Substring(0, 16).ToLowerInvariant())"
        }
        requiredRuntime = [pscustomobject][ordered]@{
            family = "Microsoft.WindowsDesktop.App"
            majorVersion = 10
            architecture = "x64"
            deployment = "framework-dependent-single-file"
        }
        determinism = [pscustomobject][ordered]@{
            verified = $DeterminismVerified
            secondHostSha256 = $SecondHostSha256.ToUpperInvariant()
            secondEngineSha256 = $SecondEngineSha256.ToUpperInvariant()
        }
        authenticode = [pscustomobject][ordered]@{
            required = [bool]($ReleaseMode -eq "production-signed")
            hostStatus = $HostSignatureStatus
            engineStatus = $EngineSignatureStatus
        }
    }
}

function ConvertTo-FishingCanonicalManifestJson([object]$Manifest) {
    return ($Manifest | ConvertTo-Json -Depth 8 -Compress)
}

function Write-FishingBundleManifest(
    [string]$Path,
    [object]$Manifest) {
    $json = ConvertTo-FishingCanonicalManifestJson $Manifest
    [IO.File]::WriteAllText(
        (Get-FishingCanonicalPath $Path),
        $json + "`n",
        [Text.UTF8Encoding]::new($false))
}

function Assert-FishingPropertyOrder(
    [object]$Value,
    [string[]]$Expected,
    [string]$Context) {
    if ($null -eq $Value) {
        throw "release_manifest_${Context}_missing"
    }
    $actual = @($Value.PSObject.Properties.Name)
    if (($actual -join "`n") -cne ($Expected -join "`n")) {
        throw "release_manifest_${Context}_properties_invalid"
    }
}

function Assert-FishingHash([string]$Value, [string]$Context) {
    if ($Value -cnotmatch '^[0-9A-F]{64}$') {
        throw "release_manifest_${Context}_hash_invalid"
    }
}

function Read-FishingBundleManifest(
    [string]$ProductRoot,
    [string]$BundleDirectory,
    [string]$ExpectedReleaseMode = "") {
    $bundle = Get-FishingCanonicalPath $BundleDirectory
    $path = Join-Path $bundle "bundle-manifest.json"
    if (-not (Test-Path -LiteralPath $path -PathType Leaf)) {
        throw "release_manifest_missing"
    }
    $raw = [IO.File]::ReadAllText($path, [Text.UTF8Encoding]::new($false))
    try {
        $manifest = $raw | ConvertFrom-Json
    }
    catch {
        throw "release_manifest_json_invalid"
    }

    Assert-FishingPropertyOrder $manifest @(
        "schemaVersion", "product", "releaseMode", "version", "source", "ipc",
        "host", "engine", "requiredRuntime", "determinism", "authenticode"
    ) "root"
    Assert-FishingPropertyOrder $manifest.source @("commitSha", "dirty") "source"
    Assert-FishingPropertyOrder $manifest.ipc @("schema", "schemaSha256") "ipc"
    Assert-FishingPropertyOrder $manifest.host @(
        "path", "sha256", "unsignedSha256", "buildId"
    ) "host"
    Assert-FishingPropertyOrder $manifest.engine @(
        "path", "sha256", "unsignedSha256", "buildId"
    ) "engine"
    Assert-FishingPropertyOrder $manifest.requiredRuntime @(
        "family", "majorVersion", "architecture", "deployment"
    ) "runtime"
    Assert-FishingPropertyOrder $manifest.determinism @(
        "verified", "secondHostSha256", "secondEngineSha256"
    ) "determinism"
    Assert-FishingPropertyOrder $manifest.authenticode @(
        "required", "hostStatus", "engineStatus"
    ) "authenticode"

    $canonical = ConvertTo-FishingCanonicalManifestJson $manifest
    if ($raw -cne ($canonical + "`n")) {
        throw "release_manifest_not_canonical"
    }
    if ($manifest.schemaVersion -ne 1 -or $manifest.product -cne "fishing" -or
        $script:FishingReleaseModes -notcontains $manifest.releaseMode) {
        throw "release_manifest_identity_invalid"
    }
    [void](Get-FishingCanonicalVersion ([string]$manifest.version))
    if (-not [string]::IsNullOrWhiteSpace($ExpectedReleaseMode) -and
        $manifest.releaseMode -cne $ExpectedReleaseMode) {
        throw "release_manifest_mode_mismatch"
    }
    if ($manifest.source.commitSha -cnotmatch '^[0-9a-f]{40}$' -or
        $manifest.source.dirty -isnot [bool]) {
        throw "release_manifest_source_invalid"
    }
    if ($manifest.ipc.schema -cne "ipc/v1/sonar_fishing.proto") {
        throw "release_manifest_schema_path_invalid"
    }
    Assert-FishingHash ([string]$manifest.ipc.schemaSha256) "schema"
    Assert-FishingHash ([string]$manifest.host.sha256) "host"
    Assert-FishingHash ([string]$manifest.host.unsignedSha256) "host_unsigned"
    Assert-FishingHash ([string]$manifest.engine.sha256) "engine"
    Assert-FishingHash ([string]$manifest.engine.unsignedSha256) "engine_unsigned"
    Assert-FishingHash ([string]$manifest.determinism.secondHostSha256) "host_second"
    Assert-FishingHash ([string]$manifest.determinism.secondEngineSha256) "engine_second"

    if ($manifest.host.path -cne "Sonar.exe" -or
        $manifest.engine.path -cne "Sonar.Engine.exe" -or
        $manifest.host.buildId -cne
            "fishing-host-$($manifest.host.unsignedSha256.Substring(0, 16).ToLowerInvariant())" -or
        $manifest.engine.buildId -cne
            "fishing-engine-$($manifest.engine.unsignedSha256.Substring(0, 16).ToLowerInvariant())") {
        throw "release_manifest_pair_identity_invalid"
    }
    if ($manifest.requiredRuntime.family -cne "Microsoft.WindowsDesktop.App" -or
        $manifest.requiredRuntime.majorVersion -ne 10 -or
        $manifest.requiredRuntime.architecture -cne "x64" -or
        $manifest.requiredRuntime.deployment -cne "framework-dependent-single-file") {
        throw "release_manifest_runtime_invalid"
    }
    if ($manifest.determinism.verified -isnot [bool] -or
        $manifest.authenticode.required -isnot [bool] -or
        $manifest.authenticode.required -ne
            ($manifest.releaseMode -eq "production-signed")) {
        throw "release_manifest_policy_invalid"
    }
    if ($manifest.determinism.verified -and
        ($manifest.host.unsignedSha256 -cne $manifest.determinism.secondHostSha256 -or
         $manifest.engine.unsignedSha256 -cne $manifest.determinism.secondEngineSha256)) {
        throw "release_manifest_determinism_invalid"
    }
    if ($manifest.releaseMode -eq "production-signed" -and
        ($manifest.authenticode.hostStatus -cne "Valid" -or
         $manifest.authenticode.engineStatus -cne "Valid" -or
         -not $manifest.determinism.verified)) {
        throw "release_manifest_production_policy_invalid"
    }

    $hostPath = Join-Path $bundle "Sonar.exe"
    $enginePath = Join-Path $bundle "Sonar.Engine.exe"
    if ((Get-FishingSha256 $hostPath) -cne $manifest.host.sha256 -or
        (Get-FishingSha256 $enginePath) -cne $manifest.engine.sha256 -or
        (Get-FishingSha256 (Join-Path $ProductRoot "contracts\ipc\v1\sonar_fishing.proto")) -cne
            $manifest.ipc.schemaSha256) {
        throw "release_manifest_content_hash_mismatch"
    }
    return $manifest
}

function Assert-FishingDesktopRuntime {
    $runtimes = @(& dotnet --list-runtimes)
    if ($LASTEXITCODE -ne 0 -or
        -not ($runtimes | Where-Object { $_ -match '^Microsoft\.WindowsDesktop\.App 10\.' })) {
        throw "release_windows_desktop_runtime_10_missing"
    }
}

function Get-FishingAuthenticodeStatus([string]$Path) {
    $signature = Get-AuthenticodeSignature -LiteralPath $Path
    return [string]$signature.Status
}

function Assert-FishingHighConfidenceSecretScan([string]$BundleDirectory) {
    $privateKeyPattern = '(?i)-----BEGIN (?:RSA |EC |OPENSSH )?PRIVATE KEY-----'
    $telegramTokenPattern = '(?<![A-Za-z0-9_-])[0-9]{5,}:[A-Za-z0-9_-]{24,}(?![A-Za-z0-9_-])'
    foreach ($file in Get-ChildItem -LiteralPath $BundleDirectory -File -Recurse -Force) {
        $bytes = [IO.File]::ReadAllBytes($file.FullName)
        $text = [Text.Encoding]::GetEncoding(28591).GetString($bytes)
        if ($text -match $privateKeyPattern -or $text -match $telegramTokenPattern) {
            throw "release_secret_marker_detected: $($file.Name)"
        }
    }
}

function Resolve-FishingDumpbin {
    $command = Get-Command dumpbin.exe -ErrorAction SilentlyContinue
    if ($null -ne $command) {
        return $command.Source
    }
    $candidate = Get-ChildItem -LiteralPath `
        "C:\Program Files (x86)\Microsoft Visual Studio\2022" `
        -Filter dumpbin.exe -File -Recurse -ErrorAction SilentlyContinue |
        Where-Object { $_.FullName -match '\\Hostx64\\x64\\dumpbin\.exe$' } |
        Select-Object -First 1
    if ($null -eq $candidate) {
        throw "release_dumpbin_missing"
    }
    return $candidate.FullName
}

function Assert-FishingSystemDependencyClosure([string]$BundleDirectory) {
    $dumpbin = Resolve-FishingDumpbin
    $systemDirectory = Join-Path $env:SystemRoot "System32"
    foreach ($name in @("Sonar.exe", "Sonar.Engine.exe")) {
        $path = Join-Path $BundleDirectory $name
        $output = & $dumpbin /nologo /dependents $path 2>&1 | Out-String
        if ($LASTEXITCODE -ne 0) {
            throw "release_dependency_scan_failed: $name"
        }
        $dependencies = @([regex]::Matches(
            $output,
            '(?im)^\s+([A-Za-z0-9_.-]+\.dll)\s*$') |
            ForEach-Object { $_.Groups[1].Value } |
            Sort-Object -Unique)
        foreach ($dependency in $dependencies) {
            if ($dependency -match '^(?i)(api-ms-win-|ext-ms-)' -or
                (Test-Path -LiteralPath (Join-Path $systemDirectory $dependency) -PathType Leaf)) {
                continue
            }
            throw "release_non_system_dependency: $name -> $dependency"
        }
    }
}

function Get-FishingDirectoryFingerprint([string]$Path) {
    if (-not (Test-Path -LiteralPath $Path -PathType Container)) {
        return "<absent>"
    }
    $root = Get-FishingCanonicalPath $Path
    $rootPrefix = $root.TrimEnd("\") + "\"
    $entries = Get-ChildItem -LiteralPath $root -Force -Recurse -ErrorAction Stop |
        ForEach-Object {
            $fullName = [IO.Path]::GetFullPath($_.FullName)
            if (-not $fullName.StartsWith($rootPrefix, [StringComparison]::OrdinalIgnoreCase)) {
                throw "release_fingerprint_path_escape: $fullName"
            }
            $relative = $fullName.Substring($rootPrefix.Length).Replace("\", "/")
            if ($_.PSIsContainer) {
                "D|$relative|$([int]$_.Attributes)"
            }
            else {
                "F|$relative|$($_.Length)|$($_.LastWriteTimeUtc.Ticks)|$([int]$_.Attributes)"
            }
        } |
        Sort-Object
    return ($entries -join "`n")
}
