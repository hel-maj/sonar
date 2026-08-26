[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string]$CommonContractRoot,

    [Parameter(Mandatory = $true)]
    [string]$InventoryContractRoot,

    [Parameter(Mandatory = $true)]
    [string]$OutputDirectory,

    [string]$ProtocExecutable = $env:SONAR_PROTOC_EXECUTABLE
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$productContractRoot = Join-Path $productRoot "contracts"
$productSchema = Join-Path $productContractRoot "ipc\v1\sonar_fishing.proto"
$expectedProtocHash = "C77B7F5125113306ECDE9B328E72466E5CA805A3974DBF10B9DF91A35781E89C"

function Get-Sha256([string]$path) {
    $stream = [IO.File]::OpenRead($path)
    try {
        $hasher = [Security.Cryptography.SHA256]::Create()
        try {
            return [BitConverter]::ToString($hasher.ComputeHash($stream)).Replace("-", "")
        }
        finally {
            $hasher.Dispose()
        }
    }
    finally {
        $stream.Dispose()
    }
}

function Resolve-Protoc([string]$requestedPath) {
    if ([string]::IsNullOrWhiteSpace($requestedPath)) {
        $requestedPath = Join-Path $productRoot "..\..\.artifacts\sonar-tools\protoc\35.1\bin\protoc.exe"
    }
    $candidate = $requestedPath
    if (-not [IO.Path]::IsPathRooted($candidate)) {
        $candidate = Join-Path $productRoot $candidate
    }
    if (-not (Test-Path -LiteralPath $candidate -PathType Leaf)) {
        throw "Pinned protoc 35.1 executable does not exist: $candidate"
    }
    $version = & $candidate --version
    if ($LASTEXITCODE -ne 0 -or $version -ne "libprotoc 35.1") {
        throw "Expected protoc 35.1, received: $version"
    }
    $actualHash = Get-Sha256 $candidate
    if ($actualHash -ne $expectedProtocHash) {
        throw "Pinned protoc 35.1 hash mismatch: $actualHash"
    }
    return (Resolve-Path -LiteralPath $candidate).Path
}

$resolvedProtoc = Resolve-Protoc $ProtocExecutable
$resolvedCommonContractRoot = $CommonContractRoot
if (-not [IO.Path]::IsPathRooted($resolvedCommonContractRoot)) {
    $resolvedCommonContractRoot = Join-Path $productRoot $resolvedCommonContractRoot
}
if (-not (Test-Path -LiteralPath $resolvedCommonContractRoot -PathType Container)) {
    throw "Canonical Common contract root does not exist: $resolvedCommonContractRoot"
}
$resolvedCommonContractRoot = (Resolve-Path -LiteralPath $resolvedCommonContractRoot).Path
$commonSchema = Join-Path $resolvedCommonContractRoot "ipc\v1\sonar_platform.proto"
if (-not (Test-Path -LiteralPath $commonSchema -PathType Leaf)) {
    throw "Common package does not expose canonical ipc/v1/sonar_platform.proto: $commonSchema"
}

$resolvedInventoryContractRoot = $InventoryContractRoot
if (-not [IO.Path]::IsPathRooted($resolvedInventoryContractRoot)) {
    $resolvedInventoryContractRoot = Join-Path $productRoot $resolvedInventoryContractRoot
}
if (-not (Test-Path -LiteralPath $resolvedInventoryContractRoot -PathType Container)) {
    throw "Canonical Common inventory contract root does not exist: $resolvedInventoryContractRoot"
}
$resolvedInventoryContractRoot =
    (Resolve-Path -LiteralPath $resolvedInventoryContractRoot).Path
$inventorySchema = Join-Path $resolvedInventoryContractRoot "inventory\v1\sonar_inventory.proto"
if (-not (Test-Path -LiteralPath $inventorySchema -PathType Leaf)) {
    throw "Common package does not expose canonical inventory/v1/sonar_inventory.proto: $inventorySchema"
}

[IO.Directory]::CreateDirectory($OutputDirectory) | Out-Null

& $resolvedProtoc `
    "--proto_path=$productContractRoot" `
    "--proto_path=$resolvedCommonContractRoot" `
    "--proto_path=$resolvedInventoryContractRoot" `
    "--csharp_out=$OutputDirectory" `
    $productSchema
if ($LASTEXITCODE -ne 0) {
    throw "Fishing managed protobuf contract generation failed."
}

$schemaHash = (Get-Sha256 $productSchema).ToLowerInvariant()
$identitySource = @"
namespace Sonar.Fishing.Ipc.Contracts;

public static class FishingSchemaIdentity
{
    public const string Sha256 = "$schemaHash";
}
"@
[IO.File]::WriteAllText(
    (Join-Path $OutputDirectory "FishingSchemaIdentity.g.cs"),
    $identitySource,
    [Text.UTF8Encoding]::new($false))
