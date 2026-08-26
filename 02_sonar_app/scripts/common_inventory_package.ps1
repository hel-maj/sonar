Set-StrictMode -Version Latest

function Assert-FishingCommonInventoryPackage(
    [Parameter(Mandatory = $true)]
    [string]$PackageRoot
) {
    if (-not (Test-Path -LiteralPath $PackageRoot -PathType Container)) {
        throw "common_inventory_package_missing: $PackageRoot"
    }
    $resolvedRoot = (Resolve-Path -LiteralPath $PackageRoot).Path
    $manifest = Join-Path $resolvedRoot "SHA256SUMS.txt"
    if (-not (Test-Path -LiteralPath $manifest -PathType Leaf)) {
        throw "common_inventory_manifest_missing: $manifest"
    }
    $expectedManifestHash =
        "EC109F38E0F0BF1428EA63505B186022CE2116301014E0578AB0886DF7CFCF7D"
    if ((Get-FileHash -Algorithm SHA256 -LiteralPath $manifest).Hash -cne
        $expectedManifestHash) {
        throw "common_inventory_manifest_hash_mismatch"
    }

    $listed = [Collections.Generic.HashSet[string]]::new(
        [StringComparer]::OrdinalIgnoreCase)
    foreach ($line in Get-Content -LiteralPath $manifest) {
        if ($line -notmatch '^([0-9A-F]{64})  (.+)$') {
            throw "common_inventory_manifest_line_invalid"
        }
        $relative = $Matches[2].Replace('/', [IO.Path]::DirectorySeparatorChar)
        if ([IO.Path]::IsPathRooted($relative) -or
            $relative.Split([IO.Path]::DirectorySeparatorChar) -contains '..') {
            throw "common_inventory_manifest_path_invalid"
        }
        $payload = Join-Path $resolvedRoot $relative
        if (-not (Test-Path -LiteralPath $payload -PathType Leaf)) {
            throw "common_inventory_payload_missing: $relative"
        }
        if ((Get-FileHash -Algorithm SHA256 -LiteralPath $payload).Hash -cne
            $Matches[1]) {
            throw "common_inventory_payload_hash_mismatch: $relative"
        }
        if (-not $listed.Add($relative)) {
            throw "common_inventory_manifest_path_duplicate: $relative"
        }
    }

    $payloads = @(Get-ChildItem -LiteralPath $resolvedRoot -File -Recurse -Force |
        Where-Object { $_.FullName -cne $manifest })
    if ($payloads.Count -ne $listed.Count) {
        throw "common_inventory_package_payload_set_mismatch"
    }
    $rootPrefix = $resolvedRoot.TrimEnd(
        [IO.Path]::DirectorySeparatorChar) + [IO.Path]::DirectorySeparatorChar
    foreach ($payload in $payloads) {
        if (-not $payload.FullName.StartsWith(
            $rootPrefix, [StringComparison]::OrdinalIgnoreCase)) {
            throw "common_inventory_payload_path_escaped"
        }
        $relative = $payload.FullName.Substring($rootPrefix.Length)
        if (-not $listed.Contains($relative)) {
            throw "common_inventory_unlisted_payload: $relative"
        }
    }
    return $resolvedRoot
}

function Resolve-FishingCommonInventoryContractRoot(
    [Parameter(Mandatory = $true)]
    [string]$FeedDirectory,

    [Parameter(Mandatory = $true)]
    [string]$ProductRoot
) {
    $resolvedFeed = [IO.Path]::GetFullPath($FeedDirectory)
    $resolvedProductRoot = [IO.Path]::GetFullPath($ProductRoot).TrimEnd('\', '/')
    $buildRoot = [IO.Path]::GetFullPath(
        (Join-Path $resolvedProductRoot 'build')).TrimEnd('\', '/')
    $contractRoot = [IO.Path]::GetFullPath(
        (Join-Path $buildRoot 'common-inventory-contracts\0.1.0'))
    if (-not ($contractRoot + [IO.Path]::DirectorySeparatorChar).StartsWith(
            $buildRoot + [IO.Path]::DirectorySeparatorChar,
            [StringComparison]::OrdinalIgnoreCase)) {
        throw 'common_inventory_contract_staging_scope_invalid'
    }

    $packagePath = Join-Path $resolvedFeed `
        'Sonar.Inventory.Ipc.Contracts.0.1.0.nupkg'
    $expectedPackageHash =
        'C5A771A49D5E9B67E366E3A82AD0066E528B65536BA6B1293EBC0854DE9E3172'
    if (-not (Test-Path -LiteralPath $packagePath -PathType Leaf) -or
        (Get-FileHash -LiteralPath $packagePath -Algorithm SHA256).Hash -cne
            $expectedPackageHash) {
        throw 'common_inventory_contract_package_invalid'
    }

    $schemaPath = Join-Path $contractRoot 'inventory\v1\sonar_inventory.proto'
    $expectedSchemaHash =
        '498E80E0F2D3D58641A8AC249C2658F4BADBC6D80919213FF8574FA935CBE356'
    if (Test-Path -LiteralPath $schemaPath -PathType Leaf) {
        if ((Get-FileHash -LiteralPath $schemaPath -Algorithm SHA256).Hash -cne
            $expectedSchemaHash) {
            throw 'common_inventory_contract_staged_hash_mismatch'
        }
        return $contractRoot
    }

    [IO.Directory]::CreateDirectory((Split-Path -Parent $schemaPath)) | Out-Null
    Add-Type -AssemblyName System.IO.Compression.FileSystem
    $archive = [IO.Compression.ZipFile]::OpenRead($packagePath)
    $temporaryPath = Join-Path (Split-Path -Parent $schemaPath) `
        ('.sonar_inventory.' + [guid]::NewGuid().ToString('N') + '.tmp')
    try {
        $entry = @($archive.Entries | Where-Object FullName -CEQ `
            'contentFiles/any/any/inventory/v1/sonar_inventory.proto')
        if ($entry.Count -ne 1 -or $entry[0].Length -le 0 -or
            $entry[0].Length -gt 131072) {
            throw 'common_inventory_contract_package_entry_invalid'
        }
        $source = $entry[0].Open()
        try {
            $destination = [IO.File]::Open(
                $temporaryPath,
                [IO.FileMode]::CreateNew,
                [IO.FileAccess]::Write,
                [IO.FileShare]::None)
            try {
                $source.CopyTo($destination)
            }
            finally {
                $destination.Dispose()
            }
        }
        finally {
            $source.Dispose()
        }
        if ((Get-FileHash -LiteralPath $temporaryPath -Algorithm SHA256).Hash -cne
            $expectedSchemaHash) {
            throw 'common_inventory_contract_package_schema_hash_mismatch'
        }
        [IO.File]::Move($temporaryPath, $schemaPath)
    }
    finally {
        $archive.Dispose()
        if (Test-Path -LiteralPath $temporaryPath -PathType Leaf) {
            Remove-Item -LiteralPath $temporaryPath -Force
        }
    }
    return $contractRoot
}
