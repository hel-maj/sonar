# Bundled Tesseract runtime

Sonar uses this runtime before checking global `PATH` or `C:\Program Files`.
This keeps OCR tests and offline installs independent from a system Tesseract
installation. Language data lives in `../tessdata`.
