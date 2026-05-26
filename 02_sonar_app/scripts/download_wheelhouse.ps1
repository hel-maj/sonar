$ErrorActionPreference = "Stop"

$Root = Resolve-Path (Join-Path $PSScriptRoot "..")
$Wheelhouse = Join-Path $Root "wheelhouse\windows-py312"
$PythonVersion = "3.12"
$Abi = "cp312"

New-Item -ItemType Directory -Force -Path $Wheelhouse | Out-Null

python -m pip download `
  --only-binary=:all: `
  --platform win_amd64 `
  --implementation cp `
  --python-version $PythonVersion `
  --abi $Abi `
  --dest $Wheelhouse `
  -r (Join-Path $Root "requirements-test.txt")

python -m pip download `
  --only-binary=:all: `
  --platform win_amd64 `
  --implementation cp `
  --python-version $PythonVersion `
  --abi $Abi `
  --dest $Wheelhouse `
  ".[test]"

Write-Host "Windows wheelhouse is ready: $Wheelhouse"
