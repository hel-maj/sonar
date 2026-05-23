from __future__ import annotations

import os

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")
os.environ.setdefault("OMP_THREAD_LIMIT", "1")
os.environ.setdefault("OPENBLAS_NUM_THREADS", "1")
os.environ.setdefault("OPENCV_FOR_THREADS_NUM", "1")

try:
    import cv2
except Exception:
    cv2 = None

if cv2 is not None:
    cv2.setNumThreads(1)
    try:
        cv2.ocl.setUseOpenCL(False)
    except Exception:
        pass
