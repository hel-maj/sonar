Set-StrictMode -Version Latest

function Assert-FishingCommonRuntimeModulePackage(
    [Parameter(Mandatory = $true)]
    [string]$PackageRoot
) {
    if (-not (Test-Path -LiteralPath $PackageRoot -PathType Container)) {
        throw "common_runtime_module_package_missing: $PackageRoot"
    }
    $resolvedRoot = (Resolve-Path -LiteralPath $PackageRoot).Path
    $manifest = Join-Path $resolvedRoot "SHA256SUMS.txt"
    if (-not (Test-Path -LiteralPath $manifest -PathType Leaf)) {
        throw "common_runtime_module_manifest_missing: $manifest"
    }
    $expectedManifestHash =
        "6E902CF03A7F19F4451D6F5F03CFAD6AA2B2928FEB9C56C5B873CD6EC1ADA845"
    if ((Get-FileHash -Algorithm SHA256 -LiteralPath $manifest).Hash -cne
        $expectedManifestHash) {
        throw "common_runtime_module_manifest_hash_mismatch"
    }

    $listed = [Collections.Generic.HashSet[string]]::new(
        [StringComparer]::OrdinalIgnoreCase)
    foreach ($line in Get-Content -LiteralPath $manifest) {
        if ($line -notmatch '^([0-9A-F]{64})  (.+)$') {
            throw "common_runtime_module_manifest_line_invalid"
        }
        $relative = $Matches[2].Replace('/', [IO.Path]::DirectorySeparatorChar)
        if ([IO.Path]::IsPathRooted($relative) -or
            $relative.Split([IO.Path]::DirectorySeparatorChar) -contains '..') {
            throw "common_runtime_module_manifest_path_invalid"
        }
        $payload = Join-Path $resolvedRoot $relative
        if (-not (Test-Path -LiteralPath $payload -PathType Leaf)) {
            throw "common_runtime_module_payload_missing: $relative"
        }
        if ((Get-FileHash -Algorithm SHA256 -LiteralPath $payload).Hash -cne
            $Matches[1]) {
            throw "common_runtime_module_payload_hash_mismatch: $relative"
        }
        if (-not $listed.Add($relative)) {
            throw "common_runtime_module_manifest_path_duplicate: $relative"
        }
    }

    $payloads = @(Get-ChildItem -LiteralPath $resolvedRoot -File -Recurse -Force |
        Where-Object { $_.FullName -cne $manifest })
    if ($payloads.Count -ne $listed.Count) {
        throw "common_runtime_module_package_payload_set_mismatch"
    }
    $rootPrefix = $resolvedRoot.TrimEnd(
        [IO.Path]::DirectorySeparatorChar) + [IO.Path]::DirectorySeparatorChar
    foreach ($payload in $payloads) {
        if (-not $payload.FullName.StartsWith(
            $rootPrefix, [StringComparison]::OrdinalIgnoreCase)) {
            throw "common_runtime_module_payload_path_escaped"
        }
        $relative = $payload.FullName.Substring($rootPrefix.Length)
        if (-not $listed.Contains($relative)) {
            throw "common_runtime_module_unlisted_payload: $relative"
        }
    }
    return $resolvedRoot
}
