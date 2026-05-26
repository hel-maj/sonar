$ErrorActionPreference = "Stop"

$Root = Resolve-Path (Join-Path $PSScriptRoot "..")
$Wheelhouse = Join-Path $Root "wheelhouse\windows-py312"
$Requirements = Join-Path $Root "requirements-offline-py312.txt"

New-Item -ItemType Directory -Force -Path $Wheelhouse | Out-Null

python -m pip download `
  --only-binary=:all: `
  --platform win_amd64 `
  --implementation cp `
  --python-version 3.12 `
  --abi cp312 `
  --dest $Wheelhouse `
  -r $Requirements

Write-Host "Windows wheelhouse is ready: $Wheelhouse"
