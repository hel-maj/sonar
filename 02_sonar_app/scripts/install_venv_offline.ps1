$ErrorActionPreference = "Stop"

$Root = Resolve-Path (Join-Path $PSScriptRoot "..")
$Venv = Join-Path $Root ".venv"
$Python = Join-Path $Venv "Scripts\python.exe"
$Wheelhouse = Join-Path $Root "wheelhouse\windows-py312"

if (-not (Test-Path $Python)) {
  py -3.12 -m venv $Venv
}

Push-Location $Root
try {
  & $Python -m pip install --no-index --find-links=$Wheelhouse "setuptools>=69" "wheel>=0.43"
  & $Python -m pip install --no-index --find-links=$Wheelhouse --no-build-isolation -e ".[test]"
} finally {
  Pop-Location
}

Write-Host "Offline venv is ready: $Venv"
