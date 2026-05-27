$ErrorActionPreference = "Stop"

$Root = Resolve-Path (Join-Path $PSScriptRoot "..")
$Venv = Join-Path $Root ".venv"
$Python = Join-Path $Venv "Scripts\python.exe"

$env:QT_QPA_PLATFORM = "offscreen"
$env:OMP_THREAD_LIMIT = "1"
$env:OPENBLAS_NUM_THREADS = "1"
$env:OPENCV_FOR_THREADS_NUM = "1"

if (-not (Test-Path $Python)) {
  py -3.12 -m venv $Venv
}

Push-Location $Root
try {
  & $Python -m pip install -e ".[test]"
  & $Python scripts/run_tests.py @args
} finally {
  Pop-Location
}
