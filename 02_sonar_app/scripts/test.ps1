$ErrorActionPreference = "Stop"

$env:QT_QPA_PLATFORM = "offscreen"
$env:OMP_THREAD_LIMIT = "1"
$env:OPENBLAS_NUM_THREADS = "1"
$env:OPENCV_FOR_THREADS_NUM = "1"

python -m pip install -e ".[test]"
python scripts/run_tests.py @args
