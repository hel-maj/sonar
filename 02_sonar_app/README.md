# Sonar

Sonar - desktop-приложение для автоматизации рыбалки в Majestic RP.

## Возможности

- Автоматизация этапов рыбалки, хранения улова, питания и обработки мусора.
- OCR и OpenCV-распознавание игровых экранов.
- Чтение памяти `GTA5.exe` и `majestic-webengine.exe` для диагностики чата, инвентаря, статуса игрока и вываживания.
- Статистика сессии с пользовательскими ценами продажи.
- Telegram-бот с меню, уведомлениями, скриншотами, запуском/остановкой и командами выключения.
- Проверка лицензии через Keygen CE с привязкой к отпечатку железа.

## Запуск из исходников

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python -m pip install -e .
python -m sonar
```

Для проверки без ручного закрытия окна:

```powershell
python -m sonar --smoke-test
```

## Параметры запуска

Основные флаги приложения:

- `--debug` - включает `SONAR_DEBUG_CAPTURE=1` и `SONAR_DEBUG_MODE=1`, пишет расширенные отладочные снимки и логи.
- `--smoke-test` - открывает UI и автоматически закрывает окно после короткой проверки.
- `--keep-debug-capture` - не очищает папку `debug_capture` перед новой сессией.
- `--manual-reeling` - временный режим диагностики вываживания. Бот продолжает читать память и решать, какую A/D он бы держал, но не отправляет реальные `key_down/key_up` для A/D. Фактические A/D нажимает игрок.

Пример запуска ручного вываживания:

```powershell
python -m sonar --manual-reeling --debug
```

В режиме `--manual-reeling` JSONL-дампы пишутся в `logs\reeling_manual`. Каждая строка содержит решение бота (`bot_key`, `bot_label`, `move_val`, `action`), фактически зажатые пользователем клавиши (`actual_a`, `actual_d`, `actual_label`), адреса игрока/рыбы, выбранное поле направления, значения direction-полей и периодические base64-снимки памяти игрока и рыбы. Дополнительно режим можно включить переменной окружения `SONAR_REELING_MANUAL_MODE=1`.

## Runtime-файлы

В режиме исходников приложение пишет настройки и логи в корень проекта:

- `config`
- `logs`

В portable-сборке рядом с exe создается `config`. Реестр не используется. Файловые логи в release-сборке по умолчанию отключены, если не включить `SONAR_ENABLE_RELEASE_LOGS=1`.

## Вспомогательные скрипты

Запускаются из корня `02_sonar_app` через `python -m ...` или напрямую для файлов из `scripts`.

### Вываживание и направление рыбы

`python -m sonar.tools.probe_reeling_direction`

Пассивно записывает память, фактические A/D и решение трекера во время ручного вываживания. Используется, чтобы проверить, какое поле памяти соответствует направлению рыбы.

Параметры: `--process`, `--duration`, `--interval`, `--warmup`, `--bytes`, `--max-candidates`, `--out-dir`, `--no-tracker-step`.

`python -m sonar.tools.record_reeling_memory`

Пишет сжатый `.npz` с памятью игрока, кандидатами рыбы и метками ручных A/D для последующего анализа.

Параметры: `--process`, `--duration`, `--interval`, `--bytes`, `--max-candidates`, `--out-dir`.

`python -m sonar.tools.analyze_reeling_memory <snapshot.npz>`

Ищет в записанном `.npz` float-поля, которые коррелируют с ручными A/D.

Параметры: positional `snapshot`, `--top`.

### Память статуса игрока и инвентаря

`python -m sonar.tools.record_player_status_memory`

Делает сфокусированные дампы памяти вокруг изменений еды, воды и HP, используя OCR статуса на экране.

Параметры: `--capture-process`, `--target-process`, `--out-dir`, `--interval`, `--duration`, `--watch-changes`, `--no-initial`, `--max-processes-per-name`, `--chunk-mb`, `--marker-window-kb`, `--numeric-window-kb`, `--max-marker-hits`, `--max-numeric-hits`, `--full-selected-mb`, `--full-selected-region-mb`.

`python -m sonar.tools.probe_inventory_memory`

Ищет байты памяти, коррелирующие с открытым/закрытым инвентарем.

Параметры: `--process`, `--max-total-mb`, `--max-region-mb`, `--top`, `--discovery-cycles`, `--validation-cycles`, `--samples-per-state`, `--sample-interval`, `--candidate-limit`, `--per-region-limit`, `--per-page-limit`, `--profile-per-page-limit`, `--min-accuracy`, `--max-wrong`, `--max-unreadable`.

`python -m sonar.tools.build_inventory_memory_anchors`

Строит signature и pointer-кандидаты для стабильных адресов профиля инвентаря.

Параметры: `--process`, `--profile`, `--report-dir`, `--cluster-gap`, `--signature-before`, `--signature-after`, `--signature-limit`, `--signature-samples`, `--signature-sample-interval`, `--min-exact-run`, `--no-pointer-wildcards`, `--skip-signature-scan`, `--signature-scan-mb`, `--signature-scan-region-mb`, `--signature-match-limit`, `--pointer-max-offset`, `--pointer-heap-mb`, `--pointer-heap-region-mb`, `--pointer-module-mb`, `--pointer-limit`, `--pointer-depth`, `--pointer-frontier-limit`, `--pointer-chain-limit`.

`python -m sonar.tools.validate_inventory_memory_anchors`

Проверяет anchors инвентаря на текущем процессе и при необходимости пишет обновленный профиль.

Параметры: `--process`, `--anchors`, `--report-dir`, `--signature-scan-mb`, `--signature-scan-region-mb`, `--signature-match-limit`, `--base-candidates`, `--min-signature-votes`, `--min-candidate-votes`, `--min-candidate-ratio`, `--min-candidate-confidence`, `--write-profile`.

### Чат и полные дампы памяти

`python -m sonar.tools.find_chat_memory`

Ищет текстовые фрагменты чата в памяти процесса.

Параметры: `--process`, `--query-file`, `--query`, `--encodings`, `--min-fragment-chars`, `--max-fragment-chars`, `--max-fragments`, `--hits`, `--print-hits`, `--print-context-chars`, `--context-bytes`, `--chunk-mb`, `--max-overlap-kb`, `--max-region-mb`, `--max-total-mb`, `--startup-delay`, `--progress`, `--out-dir`, `--watch`, `--watch-interval`.

`python -m sonar.tools.dump_process_memory`

Создает полный дамп выбранных читаемых регионов процессов для повторного анализа без запущенной игры.

Параметры: `--process`, `--pid`, `--out-dir`, `--name`, `--max-region-mb`, `--max-total-mb`, `--chunk-mb`, `--progress`.

`python -m sonar.tools.dump_chat_history`

Извлекает историю чата из живого процесса или из сохраненного дампа.

Параметры: `--process`, `--memory-dump`, `--max-region-mb`, `--max-total-mb`, `--chunk-mb`, `--window-kb`, `--marker-hits`, `--max-chat-processes`, `--auto-max-total-mb`, `--auto-marker-hits`, `--no-process-cache`, `--no-window-cache`, `--window-cache-max-age`, `--window-cache-refresh-hits`, `--window-cache-pad-kb`, `--no-state-window-cache`, `--state-window-cache-max-age`, `--state-window-cache-pad-kb`, `--allow-gta-fallback`, `--cef-only`, `--active-tab-max-total-mb`, `--active-tab-marker-hits`, `--no-active-tab`, `--min-fragment-chars`, `--fragment-limit`, `--print-records`, `--print-chars`, `--progress`, `--anchor-report`, `--address`, `--out-dir`, `--latest-name`, `--no-latest`, `--watch`, `--watch-interval`.

Примеры:

```powershell
python -m sonar.tools.dump_chat_history --process auto --progress 0 --print-records 120 --fragment-limit 0
python -m sonar.tools.dump_chat_history --process auto --watch --watch-interval 5 --progress 0 --print-records 120 --fragment-limit 0
python -m sonar.tools.dump_process_memory --process GTA5.exe,majestic-webengine.exe --out-dir P:\projects\Majestic\Sonar\logs\chat_memory
python -m sonar.tools.dump_chat_history --memory-dump P:\projects\Majestic\Sonar\logs\chat_memory\process_memory_dump_YYYYMMDD_HHMMSS --process auto --progress 0 --print-records 120 --fragment-limit 0
```

`--process auto` в `dump_chat_history` выбирает `GTA5.exe` и подходящие `majestic-webengine.exe` renderer-процессы. Для ограничения только CEF-процессами передай `--cef-only`. Для конкретного процесса можно использовать `--process pid:<PID>`.

### Сборка и проверки

`python scripts\run_tests.py [pytest args...]`

Запускает pytest по файлам с fallback на отдельные тесты. Без аргументов собирает и прогоняет весь набор, с аргументами передает их в pytest.

`powershell -ExecutionPolicy Bypass -File .\scripts\test.ps1`

Windows-обертка для тестов с переменными окружения для headless Qt/OpenCV.

`powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1`

Собирает portable exe через Nuitka.

Параметры: `-SkipInstall`, `-Count`.

`python scripts\prepare_streaming_binaries.py`

Скачивает `ffmpeg.exe` и `cloudflared.exe` в runtime-ресурсы стриминга. Параметров нет.

`python scripts\prepare_build_branding.py`

Готовит случайное имя, иконку и metadata для сборки.

Параметры: `--source-root`, `--icons-dir`, `--metadata-out`, `--history-file`.

`python scripts\prepare_release_sources.py`

Убирает WIP-части из копии исходников перед release-сборкой.

Параметры: `--source-root`.

## Сборка exe

Требования:

- Windows x64.
- Python 3.12.
- Microsoft C++ Build Tools.
- Зависимости проекта: `python -m pip install -e .[build]`.

Команда сборки:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1
```

Для повторной сборки без обновления build-зависимостей:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
```

Результат пишется в `dist`. Сборка копирует только `src`, ресурсы из `src\sonar\resources`, выбирает случайную иконку из `assets\game_icons`, отключает консольное окно и собирает onefile exe через Nuitka.

## Лицензирование

Клиент проверяет лицензию при запуске и при истечении срока действия. До валидной лицензии доступна только вкладка лицензии. Адрес сервера не хранится в `license_settings.json` и восстанавливается приложением в runtime.

Для обновлений приложение читает из metadata лицензии:

- `latest_version`
- `update_message`

`update_message` поддерживает переносы строк и кириллицу.

## Проверки

Перед полным прогоном тестов установи проект с test-зависимостями:

```powershell
python -m pip install -e ".[test]"
python scripts/run_tests.py
python -m sonar --smoke-test
```

На Windows можно запустить готовый скрипт:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\test.ps1
```

`python -m pytest -q` подходит для быстрой локальной проверки, но основной командой считается `python scripts/run_tests.py`: он изолирует зависимые OCR/OpenCV/UI-кейсы и не пропускает UI-тесты из-за отсутствия `PySide6`.
