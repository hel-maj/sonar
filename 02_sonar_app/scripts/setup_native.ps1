[CmdletBinding()]
param(
    [string]$CommonFeed = $env:SONAR_COMMON_FEED,
    [string]$CommonMajesticCatalogPackage =
        $env:SONAR_COMMON_MAJESTIC_CATALOG_PACKAGE,
    [string]$CommonMajesticCefInventoryPackage =
        $env:SONAR_COMMON_MAJESTIC_CEF_INVENTORY_PACKAGE
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
. (Join-Path $PSScriptRoot "common_inventory_package.ps1")

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$requiredFiles = @(
    "src\dotnet\Sonar.Fishing.Host\Sonar.Fishing.Host.csproj",
    "native\CMakeLists.txt",
    "contracts\ipc\v1\sonar_fishing.proto",
    "scripts\test_dotnet.ps1",
    "scripts\test_ipc.ps1",
    "scripts\test_no_python_runtime.ps1",
    "scripts\release_common.ps1",
    "scripts\build_release_native.ps1",
    "scripts\build_developer_full_access.ps1",
    "scripts\verify_developer_full_access.ps1",
    "scripts\admit_developer_full_access_launch.ps1",
    "scripts\run_developer_full_access.ps1",
    "scripts\smoke_release_native.ps1",
    "scripts\test_release_plumbing.ps1"
    "scripts\common_inventory_package.ps1"
)
foreach ($relativePath in $requiredFiles) {
    $path = Join-Path $productRoot $relativePath
    if (-not (Test-Path -LiteralPath $path -PathType Leaf)) {
        throw "Required native Fishing path is missing: $path"
    }
}

$dotnet = Get-Command dotnet -ErrorAction SilentlyContinue
if ($null -eq $dotnet) {
    throw ".NET SDK is not available"
}
$sdkVersion = & $dotnet.Source --version
if ($LASTEXITCODE -ne 0 -or -not $sdkVersion.StartsWith("10.")) {
    throw ".NET 10 SDK is required; received: $sdkVersion"
}

$cmakeCommand = Get-Command cmake -ErrorAction SilentlyContinue
$cmakeFromPath = if ($null -eq $cmakeCommand) { $null } else { $cmakeCommand.Source }
$cmakeCandidates = @(
    $cmakeFromPath,
    "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
    "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
    "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
    "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
) | Where-Object { -not [string]::IsNullOrWhiteSpace($_) }
if (-not ($cmakeCandidates | Where-Object { Test-Path -LiteralPath $_ -PathType Leaf } | Select-Object -First 1)) {
    throw "CMake from Visual Studio 2022 is not available"
}

$commonFeed = if ([string]::IsNullOrWhiteSpace($CommonFeed)) {
    Join-Path $productRoot "..\..\.artifacts\sonar-feed"
}
elseif ([IO.Path]::IsPathRooted($CommonFeed)) {
    $CommonFeed
}
else {
    Join-Path $productRoot $CommonFeed
}
if (-not (Test-Path -LiteralPath $commonFeed -PathType Container)) {
    throw "Pinned dependency feed is missing: $commonFeed"
}
$commonFeed = (Resolve-Path -LiteralPath $commonFeed).Path
$nativePackage = Join-Path $productRoot "..\..\.artifacts\sonar-native\0.1.1"
$nativeWindowsPackage = Join-Path $productRoot "..\..\.artifacts\sonar-native-windows\0.1.9"
$nativeLicensingPackage = Join-Path $productRoot "..\..\.artifacts\sonar-native-licensing\0.1.2"
$majesticCatalogPackage = if (
    [string]::IsNullOrWhiteSpace($CommonMajesticCatalogPackage)) {
    Join-Path $productRoot "..\..\.artifacts\sonar-majestic-catalog\1.0.0"
}
elseif ([IO.Path]::IsPathRooted($CommonMajesticCatalogPackage)) {
    $CommonMajesticCatalogPackage
}
else {
    Join-Path $productRoot $CommonMajesticCatalogPackage
}
$majesticCatalogPackage = (Resolve-Path -LiteralPath `
    $majesticCatalogPackage -ErrorAction Stop).Path
$majesticCefInventoryPackage = if (
    [string]::IsNullOrWhiteSpace($CommonMajesticCefInventoryPackage)) {
    Join-Path $productRoot "..\..\.artifacts\sonar-majestic-cef-inventory\0.1.18"
}
elseif ([IO.Path]::IsPathRooted($CommonMajesticCefInventoryPackage)) {
    $CommonMajesticCefInventoryPackage
}
else {
    Join-Path $productRoot $CommonMajesticCefInventoryPackage
}
$majesticCefInventoryPackage = Assert-FishingCommonInventoryPackage `
    $majesticCefInventoryPackage
$expected = @{
    (Join-Path $commonFeed "Sonar.Inventory.Ipc.Contracts.0.1.0.nupkg") = "C5A771A49D5E9B67E366E3A82AD0066E528B65536BA6B1293EBC0854DE9E3172"
    (Join-Path $commonFeed "Sonar.UI.Wpf.0.2.21.nupkg") = "BCF274F21A2BBBB0BC21799D489881AF086929AEA26547EEF4E816590D2D2675"
    (Join-Path $commonFeed "emoji.wpf.0.3.4.nupkg") = "A9C0570F97961E3DC2B2BA9E41EB7B28808733D194742D837653478EECE7D191"
    (Join-Path $commonFeed "stfu.0.1.1.nupkg") = "BDD1BAEEEC5FF16B74D0354B88393D002A6E8ECBB19793AB900B9151CE686B3A"
    (Join-Path $commonFeed "jeremyansel.hlsl.targets.1.0.13.nupkg") = "4F4CC76E9EFD35F605042FB6D8BD64EF1203F2174DED65217779BB049CFB22E8"
    (Join-Path $commonFeed "Sonar.Licensing.Verification.0.1.3.nupkg") = "CA1DAC5C5220872F15130C863AB5D12E85709AC19D4972AFC7193C8223FA7518"
    (Join-Path $nativePackage "SHA256SUMS.txt") = "695B6BFAD82A3052A5021BA55F9F833D81672DA755BF98626CC66CFB3DACAE0C"
    (Join-Path $nativeWindowsPackage "SHA256SUMS.txt") = "504C26A0B084EDA6EE0C71FD6CCA6B773F85FC0FFC8A2460EE3FA19B55C00C86"
    (Join-Path $nativeLicensingPackage "SHA256SUMS.txt") = "E777E623A2974E07CF4338670C3A41DF13BCDB8990F447987BB1BC0FF21834AC"
    (Join-Path $majesticCatalogPackage "SHA256SUMS.txt") = "EAF7FAD575747B773C0E5DB82D8E923343C35642FF24A8E4640B2D7B4040EBDB"
}
foreach ($pair in $expected.GetEnumerator()) {
    if (-not (Test-Path -LiteralPath $pair.Key -PathType Leaf)) {
        throw "Pinned dependency is missing: $($pair.Key)"
    }
    $actual = (Get-FileHash -Algorithm SHA256 -LiteralPath $pair.Key).Hash
    if ($actual -ne $pair.Value) {
        throw "Pinned dependency hash mismatch: $($pair.Key)"
    }
}

Write-Host "PASS Fishing native toolchain and immutable dependency pins"
