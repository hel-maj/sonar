# Offline wheelhouse for Python 3.12

Эта схема нужна, чтобы тесты Sonar ставили PySide6 и остальные зависимости без интернета.

## Структура

```text
02_sonar_app/
  .venv/
  requirements-offline-py312.txt
  requirements-test.txt
  wheelhouse/
    windows-py312/
    linux-py312/
  scripts/
    download_wheelhouse.ps1
    download_wheelhouse.sh
    install_venv_offline.ps1
    install_venv_offline.sh
    test.ps1
    test.sh
```

`.venv/` не коммитится. `wheelhouse/**/*.whl` коммитится через Git LFS.

## Один раз включить Git LFS

```bash
git lfs install
git lfs pull
```

## Скачать wheelhouse для Windows

Запускать из `02_sonar_app` на Windows с Python 3.12:

```powershell
.\scripts\download_wheelhouse.ps1
```

Файлы появятся в:

```text
wheelhouse/windows-py312/
```

## Скачать wheelhouse для Linux

Запускать из `02_sonar_app` на Linux с Python 3.12:

```bash
chmod +x scripts/download_wheelhouse.sh
./scripts/download_wheelhouse.sh
```

Файлы появятся в:

```text
wheelhouse/linux-py312/
```

## Закоммитить wheelhouse

```bash
git add .gitattributes 02_sonar_app/requirements-offline-py312.txt 02_sonar_app/requirements-test.txt 02_sonar_app/wheelhouse 02_sonar_app/scripts 02_sonar_app/docs/offline_wheelhouse_py312.md
git commit -m "Add offline Python 3.12 wheelhouse workflow"
```

## Установить зависимости без интернета на Windows

```powershell
.\scripts\install_venv_offline.ps1
```

Скрипт создаст `.venv` через `py -3.12` и установит проект с test-зависимостями из `wheelhouse/windows-py312`.

## Установить зависимости без интернета на Linux

```bash
chmod +x scripts/install_venv_offline.sh
./scripts/install_venv_offline.sh
```

Скрипт создаст `.venv` через `python3.12` и установит проект с test-зависимостями из `wheelhouse/linux-py312`.

## Запустить тесты

Windows:

```powershell
.\scripts\test.ps1
```

Linux:

```bash
chmod +x scripts/test.sh
./scripts/test.sh
```

Эти test-скрипты всегда используют локальный `.venv`, а не глобальный Python.

## Важно

- Windows wheels не подходят для Linux.
- Linux wheels не подходят для Windows.
- Wheels для Python 3.12 не обязаны подходить для Python 3.11 или 3.13.
- Если меняется Python или версия PySide6, wheelhouse надо перескачать.
