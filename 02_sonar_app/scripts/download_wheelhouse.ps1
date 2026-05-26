$ErrorActionPreference = "Stop"

$Root = Resolve-Path (Join-Path $PSScriptRoot "..")
$Wheelhouse = Join-Path $Root "wheelhouse\windows-py312"
$Requirements = Join-Path $Root "requirements-offline-py312.txt"

New-Item -ItemType Directory -Force -Path $Wheelhouse | Out-Null

py -3.12 -m pip wheel `
  --wheel-dir $Wheelhouse `
  -r $Requirements

Write-Host "Windows wheelhouse is ready: $Wheelhouse"
