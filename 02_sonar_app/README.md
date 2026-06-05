# Sonar

Sonar - desktop-приложение для автоматизации рыбалки в Majestic RP.

## Возможности

- Автоматизация рыбалки, хранения улова, питания и обработки мусора.
- OCR и OpenCV-распознавание игровых экранов.
- Чтение памяти процессов для диагностики чата, инвентаря, статуса игрока и вываживания.
- Статистика сессии с пользовательскими ценами продажи.
- Telegram-бот с меню, уведомлениями, скриншотами и управлением.
- Локальный web-стрим через FFmpeg/HLS/cloudflared.
- Проверка лицензии через Keygen CE.
- Feature gates по license/policy metadata.
- Защищенная portable exe-сборка через Nuitka с runtime encryption, обфускацией и build archives.

## Быстрый старт из исходников

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python -m pip install -e .[test]
python -m sonar
```

Smoke test без ручного закрытия окна:

```powershell
python -m sonar --smoke-test
```

Полный прогон тестов:

```powershell
python scripts\run_tests.py
```

## Release build

Один защищенный билд:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
```

Много билдов для случайной выдачи:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall --count 20 -LicenseServerUrl "https://m-sonar-addr.ru"
```

`m-sonar-addr.ru` - текущий нейтральный публичный домен релиза. Не используйте публично `nip.io`, `keygen`, `license`, `admin` или `ui` в названии домена.

Переменные окружения и `.env` для сборки и загрузки описаны в [docs/guides/environment_variables.md](docs/guides/environment_variables.md). Полный список публичных URL: [docs/guides/available_urls.md](docs/guides/available_urls.md).

После сборки создаются:

```text
dist\<app_version>\<exe name>\<exe name>.exe
dist\<app_version>\<exe name>\<build_key>-<exe name>.zip
```

Локальная карта воспроизводимости:

```text
P:\projects\Majestic\Sonar\config\sonar_build_keys.json
```

В ней хранится `build_key`, `obfuscation_seed`, имя exe, путь к exe и путь к archive.

## Загрузка build archives на сервер

Если на ПК настроен SSH key и команда `ssh root@m-sonar-addr.ru` входит без пароля, можно загрузить готовые zip из `dist/<APP_VERSION>` в `builds/<APP_VERSION>`:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\upload_build_archives.py --host m-sonar-addr.ru
```

Вместо постоянного `--host` можно один раз задать переменную `SONAR_UPLOAD_HOST`.

Проверка без загрузки:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --dry-run
```

Если пересобираете ту же версию и хотите заменить ее набор архивов:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --replace-version
```

Если вход по паролю, а не по SSH key:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --allow-password
```

Если ключ лежит не в стандартном месте:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --key "$env:USERPROFILE\.ssh\id_ed25519"
```

Если архивы лежат не в `dist`:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --source "C:\path\to\archives"
```

Папка на сервере для конкретной версии:

```text
/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds/<app_version>
```

Публичная ссылка для пользователей:

```text
https://m-sonar-addr.ru/download
```

Прямая ссылка на случайный архив:

```text
https://m-sonar-addr.ru/api/random-build.zip
```

Сервер выбирает случайный zip только из latest version folder внутри `builds`. Старые version-папки не отдаются через публичные URL.

Статус пула архивов:

```text
https://m-sonar-addr.ru/random-build-health
```

## Извлечение build key

Из exe:

```powershell
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<name>\<name>.exe"
```

Из zip:

```powershell
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<name>\<build_key>-<name>.zip"
```

JSON-вывод:

```powershell
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<name>\<name>.exe" --json
```

## Лицензии и обновления

Приложение читает metadata из трех уровней:

```text
sonar-release.json < Keygen policy metadata < Keygen license metadata
```

Для массовых обновлений не надо менять сотни лицензий. Используйте:

- `sonar-release.json`, если версия и ссылка общие для всех;
- policy metadata, если группе нужен свой текст, версия или набор features;
- license metadata только для персональных исключений.

Главные поля metadata:

```json
{
  "license_group": "premium",
  "allow_features": ["telegram"],
  "deny_features": ["stream"],
  "latest_version": "1.2.3",
  "update_message": "🚀 Новая версия\nИсправлены ошибки",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

## Документация

Все рабочие гайды лежат в [docs/guides](docs/guides).

Начинать с полного гайда:

```text
docs/guides/update_release_full.md
```

Полезные файлы:

- [docs/guides/update_release_full.md](docs/guides/update_release_full.md)
- [docs/guides/random_build_downloads.md](docs/guides/random_build_downloads.md)
- [docs/guides/delete_old_build_versions.md](docs/guides/delete_old_build_versions.md)
- [docs/guides/keygen_license_features.md](docs/guides/keygen_license_features.md)
- [docs/guides/release_build_security.md](docs/guides/release_build_security.md)
- [CODE_INDEX.md](CODE_INDEX.md)
- [docs/guides/manual_reeling_capture.md](docs/guides/manual_reeling_capture.md)

## Основные скрипты

- `scripts/run_tests.py` - полный тестовый прогон.
- `scripts/build_secure.ps1` - защищенная Nuitka-сборка exe и zip archive.
- `scripts/upload_build_archives.py` - загрузка готовых zip на сервер через `ssh/scp`.
- `scripts/extract_build_key_from_exe.py` - извлечение build key из exe или zip.
- `scripts/random_build_download_server.py` - сервер случайной выдачи готовых zip из `builds`.
- `scripts/audit_release_secrets.py` - проверка release artifact на plaintext markers.
- `scripts/obfuscate_release_sources.py` - seed-based обфускация release source copy.

## Проверки перед публикацией

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\run_tests.py
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<name>\<build_key>-<name>.zip"
python scripts\upload_build_archives.py --host m-sonar-addr.ru --dry-run
```

Если все ок, загрузить:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru
```
