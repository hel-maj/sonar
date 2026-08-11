# Offline wheelhouse для Python 3.12

Эта схема нужна, чтобы ставить зависимости Sonar без интернета.

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

`.venv` не коммитится. Wheels хранятся в `wheelhouse`.

## Скачать wheelhouse на Windows

```powershell
cd P:\projects\neiro\Sonar Fishing\02_sonar_app
.\scripts\download_wheelhouse.ps1
```

Файлы появятся в:

```text
wheelhouse/windows-py312/
```

## Скачать wheelhouse на Linux

```bash
cd 02_sonar_app
chmod +x scripts/download_wheelhouse.sh
./scripts/download_wheelhouse.sh
```

Файлы появятся в:

```text
wheelhouse/linux-py312/
```

## Установить зависимости без интернета на Windows

```powershell
cd P:\projects\neiro\Sonar Fishing\02_sonar_app
.\scripts\install_venv_offline.ps1
```

Скрипт создаст `.venv` через `py -3.12` и установит проект с test-зависимостями из `wheelhouse/windows-py312`.

## Установить зависимости без интернета на Linux

```bash
cd 02_sonar_app
chmod +x scripts/install_venv_offline.sh
./scripts/install_venv_offline.sh
```

Скрипт создаст `.venv` через `python3.12` и установит проект с test-зависимостями из `wheelhouse/linux-py312`.

## Запустить тесты через локальный venv

Windows:

```powershell
.\scripts\test.ps1
```

Linux:

```bash
chmod +x scripts/test.sh
./scripts/test.sh
```

## Важно

- Windows wheels не подходят для Linux.
- Linux wheels не подходят для Windows.
- Wheels для Python 3.12 не обязаны подходить для Python 3.11 или 3.13.
- Если меняется Python или версия PySide6, wheelhouse надо перескачать.
