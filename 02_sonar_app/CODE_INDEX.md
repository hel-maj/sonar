# Sonar Code Index

Дата актуализации: 2026-07-18

Это ручной индекс проекта. Он нужен, чтобы быстро понимать, где лежит нужная логика и какие файлы трогать при типовых изменениях.
Индекс является навигацией, а не доказательством текущего поведения. Перед
изменением проверять пути, symbols, consumers и tests через `rg` и исходный код.

## Корень приложения

```text
02_sonar_app/
  src/sonar/              основной код приложения
  scripts/                сборка, релизные проверки, upload/download utilities
  tests/                  unit/integration tests
  docs/guides/            рабочие инструкции
  assets/game_icons/      иконки, из которых выбираются имя exe, process name и app icon
  dist/                   результат локальной сборки, не коммитится
  build/                  временные файлы сборки, не коммитятся
```

## Runtime entrypoints

### `src/sonar/__main__.py`

Entrypoint для `python -m sonar`.

### `src/sonar/app.py`

Главный runtime-вход:

- настройка logging/debug flags;
- обработка `--debug`, `--smoke-test`, `--manual-reeling`;
- запуск PySide UI через `sonar.ui.main_window.run_ui()`.

### `src/sonar/paths.py`

Центральное место для dev/frozen путей:

- `APP_DIR`;
- `CONFIG_DIR`;
- `LOG_DIR`;
- `RESOURCE_DIR`;
- `IS_FROZEN`;
- release logging behavior.

Если в Python работает, а в exe нет, начинать проверку часто стоит отсюда.

## UI

### `src/sonar/ui/main_window.py`

Главное окно PySide6:

- вкладка лицензии;
- вкладка рыбалки;
- настройки;
- статистика;
- стрим;
- Telegram;
- карточка обновления;
- применение feature gates.

Обновления в UI читают:

- `latest_version`;
- `update_message`;
- `download_link`.

`update_message` поддерживает `\n` и emoji. Если `download_link` задан, показывается ссылка скачивания.

### `src/sonar/ui/feature_gate.py`

UI helper для проверки доступности features и блокировки действий.

### `src/sonar/ui/widgets.py`

Переиспользуемые product UI widgets текущего PySide6 приложения. Не добавлять
сюда несвязанные page state, persistence или domain policy.

### `src/sonar/chat_wip_gate.py`

Startup-sensitive gate текущего chat WIP. Проверять вместе с bootstrap,
streaming state и release source stripping.

## License and feature gates

### `src/sonar/license/client.py`

Клиент Keygen:

- validate key;
- machine activation;
- machine details update;
- чтение license metadata;
- чтение policy metadata через `include=policy`;
- чтение глобального `sonar-release.json`;
- сбор итогового `LicenseStatus`.

### `src/sonar/license/manager.py`

Кэширует и сохраняет состояние лицензии:

- license key/id;
- expires;
- group/features;
- denied_features;
- update metadata.

### `src/sonar/license/features.py`

Центральная схема групп и features.

Основные entities:

- `LicenseEntitlements`;
- `GROUP_FEATURES`;
- `entitlements_from_metadata()`;
- `entitlements_from_cached_fields()`.

Если надо добавить новую платную функцию, сначала добавить feature здесь, потом подключить gate в UI/runtime.

### `src/sonar/license/context.py`

Легкий контекст лицензии для проверки доступности функций.

## Runtime security

### `src/sonar/security/runtime.py`

Runtime-дешифровка строк под build key.

Для dev/source режима используется стабильный dev key. Для exe используется `APP_BUILD_KEY`.

### `src/sonar/security/literals.py`

Сгенерированные encrypted literals. В release source сюда попадают зашифрованные значения:

- Keygen URL;
- public IP endpoints;
- Telegram API;
- streaming download URLs;
- process names;
- memory markers.

### `src/sonar/build_metadata.py`

Build metadata:

- `APP_BUILD_KEY`;
- `APP_OBFUSCATION_SEED`;
- `APP_BUILD_HASH`;
- `APP_NAME`.

Файл перезаписывается во временной копии source во время сборки.

## Fishing

### `src/sonar/fishing/bot.py`

Главный state machine рыбалки:

- start/stop lifecycle;
- brain loop;
- стадии рыбалки;
- пауза для chat mode;
- связка OCR, memory trackers, inventory, notifications.

### Важные файлы fishing

- `fishing/constants.py` - тайминги, ROI, базовые constants.
- `fishing/fish_recognition.py` - распознавание рыбы.
- `fishing/catch_screen.py` - экран улова.
- `fishing/memory_reeling.py` - вываживание через память.
- `fishing/inventory_memory.py` - состояние инвентаря через память.
- `fishing/player_status.py` - HP/еда/вода.
- `fishing/store_fish.py` - перекладывание рыбы.
- `fishing/meal_system.py` - еда/вода.
- `fishing/garbage_disposal.py` - мусор.
- `fishing/statistics.py` - статистика.
- `fishing/session_history.py` - история сессий.
- `fishing/statistics_export.py` - экспорт статистики.

## Streaming and Telegram

### `src/sonar/streaming/service.py`

Локальный web-stream:

- FFmpeg/HLS;
- cloudflared tunnel;
- HTTP server;
- stream state snapshot;
- подготовка portable binaries;
- feature gate for streaming/chat mode.

### `src/sonar/telegram/notifier.py`

Telegram polling, menu callbacks, уведомления, скриншоты, управление рыбалкой и стримом.

## Config

### `src/sonar/config/models.py`

Dataclass-модели настроек:

- `FishingSettings`;
- `TelegramSettings`;
- `LicenseSettings`;
- `SonarSettings`.

### `src/sonar/config/manager.py`

Читает и пишет runtime config:

```text
config/fishing_settings.json
config/telegram_settings.json
config/license_settings.json
```

## Release scripts

### `scripts/build_secure.ps1`

Главный release build script.

Делает:

- проверяет Python 3.12;
- ставит build dependencies, если нет `-SkipInstall`;
- готовит FFmpeg/cloudflared;
- создает временную копию `src`;
- генерирует build key, seed, имя exe и icon;
- шифрует runtime literals;
- чистит release source;
- обфусцирует приватные identifiers;
- собирает onefile exe через Nuitka;
- запускает audit plaintext markers;
- создает zip рядом с exe: `<build_key>-<exe name>.zip`;
- обновляет `P:\projects\neiro\Sonar Fishing\config\sonar_build_keys.json`.

Команды:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -Count 20 -LicenseServerUrl "https://m-sonar-addr.ru"
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -BuildKey "<build_key>" -ObfuscationSeed "<seed>"
```

`-LicenseServerUrl` должен быть нейтральным публичным доменом, например `updates.<ваш-домен>`. Не использовать `nip.io` или домены со словами `keygen`/`license`/`admin`/`ui`.

### `scripts/prepare_build_branding.py`

Генерирует build metadata:

- случайный `build_key`;
- случайный `obfuscation_seed`;
- app/exe name из `assets/game_icons`;
- `app.ico`;
- encrypted literals;
- `build_salt.bin`.

При заданном seed выбор иконки повторяемый.

### `scripts/prepare_release_sources.py`

Чистит временную release source copy перед Nuitka:

- удаляет dev/tools из сборки;
- убирает pycache/pyc;
- подменяет WIP chat logic на release-safe stubs.

### `scripts/obfuscate_release_sources.py`

Seed-based обфускация приватных identifiers во временной копии source.

Не должен трогать stable public config, build metadata и encrypted literals.

### `scripts/audit_release_secrets.py`

Сканирует release artifact на plaintext markers, которые не должны попасть в exe.

### `scripts/extract_build_key_from_exe.py`

Утилита для поддержки пользователей и воспроизводимых сборок.

Примеры:

```powershell
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<name>\<name>.exe" --no-map
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<name>\<build_key>-<name>.zip" --no-map --json
```

Без `--no-map` может вывести seed и build metadata из локальной карты. Не
сохранять такой вывод в transcript, отчёт или чат.

### `scripts/upload_build_archives.py`

Загружает готовые build archives на сервер через системные `ssh/scp`.

Для production передавать точные `--source` и `--version`, чтобы fallback scan
не выбрал старые локальные архивы.

По умолчанию ожидает SSH key или agent, чтобы `ssh root@m-sonar-addr.ru` входил без пароля. Для входа по паролю используйте `--allow-password`; пароль вводится в prompt `ssh/scp`, а не в команду.

Команды:

```powershell
python scripts\upload_build_archives.py --source ".\dist\<version>" --version "<version>" --host m-sonar-addr.ru --dry-run
python scripts\upload_build_archives.py --source ".\dist\<version>" --version "<version>" --host m-sonar-addr.ru
python scripts\upload_build_archives.py --source ".\dist\<version>" --version "<version>" --host m-sonar-addr.ru --replace-version --dry-run
```

Live `--replace-version` выполняет remote `rm -rf` и требует отдельного свежего
подтверждения после проверки backup и rollback source.

Берет только файлы с именем:

```text
<11 or 64 hex build_key>-<exe name>.exe.zip
```

### `scripts/random_build_download_server.py`

Легкий HTTP-сервис для сервера.

В проде запущен в Docker container `sonar-random-build-download` в сети `sonar-keygen`.

Публичные routes через Caddy:

```text
/download
/api/random-build.zip
/random-build-health
```

Сервис не билдит и не пакует exe. Если в `/builds` есть version-папки, он выбирает latest version folder и отдает случайный готовый zip только из нее. Flat `/builds/*.zip` остается legacy fallback.

## Tests

Основной runner:

```powershell
python scripts\run_tests.py
```

Точечные тесты новых release flows:

```powershell
python scripts\run_tests.py tests\test_build_secure.py tests\test_extract_build_key_from_exe.py tests\test_random_build_download_server.py tests\test_upload_build_archives.py
```

Связанные тесты:

- `tests/test_license.py`;
- `tests/test_update_message.py`;
- `tests/test_config.py`;
- `tests/test_streaming_service.py`;
- `tests/test_telegram_notifier.py`.

## Docs

Все рабочие инструкции лежат в `docs/guides`.

- `docs/guides/update_release_full.md` - полный выпуск новой версии.
- `docs/guides/build_secure_parameters.md` - параметры и destructive effects сборки.
- `docs/guides/random_build_downloads.md` - случайная выдача готовых zip.
- `docs/guides/delete_old_build_versions.md` - пошаговое удаление старых version-папок.
- `docs/guides/keygen_license_features.md` - группы, features, Keygen metadata.
- `docs/guides/release_build_security.md` - защита сборки и проверки.
- `docs/guides/offline_wheelhouse_py312.md` - offline dependencies.

## Быстрый индекс "что править"

| Задача | Файлы |
|---|---|
| Добавить новую license feature | `src/sonar/license/features.py`, `src/sonar/ui/main_window.py`, `src/sonar/ui/feature_gate.py` |
| Изменить groups/features | `src/sonar/license/features.py`, docs in `docs/guides/keygen_license_features.md` |
| Изменить update card | `src/sonar/ui/main_window.py`, `tests/test_update_message.py` |
| Изменить Keygen metadata parsing | `src/sonar/license/client.py`, `tests/test_license.py` |
| Изменить runtime encrypted strings | `scripts/prepare_build_branding.py`, `src/sonar/security/runtime.py` |
| Изменить build process | `scripts/build_secure.ps1`, `tests/test_build_secure.py` |
| Изменить upload to server | `scripts/upload_build_archives.py`, `tests/test_upload_build_archives.py` |
| Изменить random download server | `scripts/random_build_download_server.py`, `tests/test_random_build_download_server.py` |
| Проверить plaintext secrets | `scripts/audit_release_secrets.py` |
| Повторить build по user exe | `scripts/extract_build_key_from_exe.py`, `config/sonar_build_keys.json` |
| Рыбалка lifecycle | `src/sonar/fishing/bot.py` |
| Streaming lifecycle | `src/sonar/streaming/service.py`, `src/sonar/ui/main_window.py` |
| Telegram menu | `src/sonar/telegram/notifier.py` |

## Risk zones

- `src/sonar/ui/main_window.py` много связывает: UI, license, bot, stream, Telegram, timers.
- `src/sonar/fishing/bot.py` чувствителен к таймингам и thread lifecycle.
- `src/sonar/streaming/service.py` зависит от subprocesses, temp dirs, HTTP server и packaged binaries.
- `scripts/prepare_release_sources.py` меняет временную копию source перед сборкой. Любое изменение stream/chat HTML или endpoints может сломать stripping.
- `scripts/obfuscate_release_sources.py` не должен переименовывать public/stable names, config schema и runtime metadata.

## Minimal checks after changes

Во время работы запускать только affected checks. Полный offline suite запускать
один раз после завершения кода и документации как final gate.

```powershell
cd P:\projects\neiro\Sonar Fishing\02_sonar_app
python -m compileall -q scripts src\sonar
python scripts\run_tests.py
```

Перед публикацией:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -Count 1 -LicenseServerUrl "https://m-sonar-addr.ru"
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<name>\<build_key>-<name>.zip" --no-map
python scripts\upload_build_archives.py --source ".\dist\<app_version>" --version "<app_version>" --host m-sonar-addr.ru --dry-run
```
