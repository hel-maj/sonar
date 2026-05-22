# Sonar Code Index

Дата актуализации: 2026-05-22

Этот файл — ручной кодовый индекс репозитория Sonar. Это не системный GitHub Code Search Index: такой индекс GitHub строит сам и его нельзя закоммитить как файл. Здесь хранится постоянная карта проекта, чтобы быстрее понимать, куда лезть при правках.

## 1. Назначение проекта

Sonar — desktop-приложение для автоматизации рыбалки в Majestic RP.

Основные зоны:

- автоматизация рыбалки;
- распознавание экранов через OpenCV/OCR;
- чтение памяти GTA5.exe и majestic-webengine.exe для диагностики чата;
- статистика сессии;
- Telegram-бот;
- локальный web-стрим через FFmpeg/HLS/cloudflared;
- лицензирование через Keygen CE;
- portable exe-сборка через Nuitka.

## 2. Корень приложения

```text
02_sonar_app/
├─ src/sonar/              # основной Python-код приложения
├─ scripts/                # сборка, подготовка release-кода, streaming binaries, branding
├─ assets/game_icons/      # PNG-иконки для рандомизации имени/иконки exe
├─ config/                 # runtime-конфиги в dev/source режиме
├─ logs/                   # runtime-логи в dev/source режиме
├─ build/                  # временные файлы сборки
├─ dist/                   # результат сборки exe
├─ pyproject.toml          # зависимости, entrypoint, package-data
└─ README.md               # запуск, сборка, диагностика, лицензирование
```

## 3. Запуск и entrypoint

### `pyproject.toml`

Ключевое:

```toml
[project.scripts]
sonar = "sonar.app:main"
```

Основные зависимости:

- numpy;
- opencv-python;
- Pillow;
- psutil;
- requests;
- pywin32;
- PySide6;
- pyautogui;
- pytesseract.

Build-зависимости:

- Nuitka;
- ordered-set;
- zstandard.

### `src/sonar/__main__.py`

Точка запуска для `python -m sonar`. Обычно просто прокидывает управление в `sonar.app:main`.

### `src/sonar/app.py`

Главный runtime-вход приложения.

Отвечает за:

- настройку логирования;
- обработку `--debug`;
- включение `SONAR_DEBUG_CAPTURE` и `SONAR_DEBUG_MODE`;
- включение faulthandler, если логи разрешены;
- импорт UI, streaming и Telegram;
- применение gate для WIP-режима чата;
- запуск `sonar.ui.main_window.run_ui()`.

Важная логика:

```text
python -m sonar --debug
```

Включает debug/WIP-режим, если приложение не собрано в exe.

## 4. Runtime-пути

### `src/sonar/paths.py`

Центральный файл путей.

Ключевые значения:

```text
IS_FROZEN
PACKAGE_DIR
PROJECT_DIR
APP_DIR
RESOURCE_DIR
FISHING_RESOURCE_DIR
CONFIG_DIR
LOG_DIR
LOGS_ENABLED
```

Логика:

- в source/dev режиме `APP_DIR = PROJECT_DIR`;
- в frozen/exe режиме `APP_DIR = папка рядом с exe`;
- `CONFIG_DIR = APP_DIR / "config"`;
- `LOG_DIR = APP_DIR / "logs"`;
- в release/exe файловые логи выключены, если нет `SONAR_ENABLE_RELEASE_LOGS=1`.

Это первое место для проверки багов вида “в Python работает, в exe нет”.

## 5. UI

### `src/sonar/ui/main_window.py`

Главный UI-файл PySide6.

Ключевые классы:

```text
LogBridge
LicenseBridge
TelegramSettingsBridge
DigitsOnlyDelegate
MainWindow
```

`MainWindow` связывает между собой:

- `ConfigManager`;
- `LicenseManager`;
- `FishingSessionStats`;
- `FishingBot`;
- `MajesticChatController`;
- `StreamingService`;
- Telegram callbacks;
- QTimer-обновления статуса, статистики, стрима и лицензии.

### Вкладки

Метод `_build_ui()` создаёт:

```text
Лицензия
Рыбалка
Настройки
Статистика
Стрим
Telegram
```

Доступ к рабочим вкладкам закрыт через `_apply_license_gate()`. Без активной лицензии остаётся только вкладка `Лицензия`.

### Лицензия в UI

Основные методы:

```text
activate_license()
_start_saved_license_check()
_run_license_check()
_handle_license_result()
_has_active_license()
_schedule_next_license_refresh()
_current_license_key()
_apply_license_gate()
_refresh_license_ui()
_license_tick()
_refresh_update_block()
```

Смысл:

- проверка лицензии идёт в отдельном thread;
- результат приходит через Qt signal;
- если лицензия неактивна, бот и стрим останавливаются;
- лицензия периодически перепроверяется;
- `latest_version` и `update_message` показываются в UI как блок обновления.

### Стрим в UI

Метод `_build_stream_tab()` создаёт:

- статус;
- область стрима;
- качество;
- автостоп;
- ссылку;
- выбор качества `480p / 720p / 1080p`;
- чекбокс увеличения чата;
- чекбокс 10fps;
- кнопки запуска/остановки стрима;
- кнопку режима чата.

Метод `_refresh_stream_tab()` управляет состоянием кнопок:

```text
stream_start_button enabled если stream не active и status не starting/preparing
stream_stop_button enabled если active или status in {starting, preparing, error}
stream_chat_mode_button зависит от active/chat_active/chat_mode_enabled
```

При багаx “статус preparing висит всегда” или “Остановить стрим активна после запуска exe” смотреть именно связку:

```text
MainWindow._refresh_stream_tab()
StreamingService.snapshot()
StreamingService.__init__()
StreamingService._prepare_binaries_worker()
scripts/prepare_release_sources.py
src/sonar/paths.py
```

## 6. Конфиги

### `src/sonar/config/models.py`

Dataclass-модели настроек:

```text
FishingSettings
TelegramSettings
LicenseSettings
SonarSettings
```

`FishingSettings`:

- auto_meal;
- auto_change_bait;
- store_in_backpack;
- store_in_trunk;
- overweight_action;
- fish_without_leader;
- leader_depleted_action;
- fish_without_net;
- net_depleted_action;
- equipment_depleted_action;
- fish_settings;
- hotkey;
- inventory_hotkey;
- use_item_hotkey;
- discard_key;
- chat_hotkey;
- stream_snapshot_mode;
- start_stop_sound_enabled;
- garbage_settings;
- custom_fish_prices.

`TelegramSettings`:

- enabled;
- bot_token;
- admin_ids;
- notify_catch;
- notify_start_stop;
- notify_meal;
- notify_inventory_full;
- notify_focus_lost.

`LicenseSettings`:

- license_key;
- license_id;
- last_validated_at;
- expires_at;
- role.

### `src/sonar/config/manager.py`

Читает и пишет:

```text
config/fishing_settings.json
config/telegram_settings.json
config/license_settings.json
```

Метод `load()` не просто читает файлы, а нормализует значения через модели и сохраняет их обратно.

## 7. Лицензирование

### `src/sonar/license/manager.py`

Класс:

```text
LicenseManager
```

Отвечает за:

- cached status;
- проверку сохранённой лицензии;
- validate key;
- сохранение license key/id/expires/role;
- работу с Keygen-клиентом;
- machine fingerprint.

### `src/sonar/license/client.py`

Класс:

```text
KeygenLicenseClient
```

Основные операции:

```text
validate_and_activate()
validate_key()
activate_machine()
update_machine_details()
```

Keygen endpoints:

```text
/licenses/actions/validate-key
/machines
/machines/{fingerprint}
```

Machine metadata:

```text
build_hash
app_name
windows_user
local_ip
public_ip
```

License role читается из metadata:

```text
role
sonar_role
sonarRole
user_role
userRole
admin
is_admin
isAdmin
```

### `src/sonar/license/hwid.py`

Отвечает за отпечаток машины.

### `src/sonar/license/secrets.py`

Хранит/расшифровывает данные сервера лицензий. Не светить значения в документации, логах и ответах.

## 8. Рыболовный бот

### `src/sonar/fishing/bot.py`

Главный оркестратор автоматизации.

Класс:

```text
FishingBot
```

Создаёт и связывает:

```text
WindowCapture
WindowActivator
TriggerMonitor
FishRecognition
CatchScreenDetector
GameMenuDetector
InventoryStageDetector
InventoryMemoryDetector
GarbageDisposal
MealSystem
FishStorer
MemoryReelingTracker
TackleDetector
NotificationManager
```

### Старт/стоп

Основные методы:

```text
start()
stop()
_stop_from_brain()
_finish_stop()
_join_brain_thread()
```

`start()` проверяет:

- не запущен ли бот;
- не завис ли старый brain thread;
- активна ли лицензия;
- найдено ли окно `gta5.exe`;
- можно ли очистить debug capture;
- можно ли сфокусировать игру.

После этого запускает `_brain_loop()` в thread.

### Главный цикл

Метод:

```text
_brain_loop()
```

Обрабатывает:

- паузу для режима чата;
- потерю фокуса;
- триггеры стадий;
- меню игры;
- перевес;
- экран улова;
- вываживание;
- смену наживки;
- стадии `start`, `start1`, `start2`, `wait_tension`, `ad`;
- еду/воду;
- аварийные восстановления.

Стадии:

```text
start        -> Выбор снастей
start1       -> Заброс
start2       -> Ожидание поклёвки
wait_tension -> Ожидание поклёвки
ad           -> Вываживание
None         -> Свободно
```

### Режим чата

Методы:

```text
pause_for_chat()
is_paused_for_chat()
prepare_for_chat_mode()
_close_inventory_for_chat()
_dismiss_catch_screen_for_chat()
```

Логика:

- при входе в чат отпускаются клавиши;
- бот ставится на паузу;
- закрывается инвентарь/меню/экран улова;
- персонаж выводится из стадии рыбалки;
- после выхода из чата рыбалка может продолжиться.

## 9. Распознавание и игровые состояния

Важные файлы в `src/sonar/fishing/`:

```text
catch_screen.py          # детект экрана пойманной рыбы
fish_recognition.py      # распознавание рыбы
fish_names.py            # id/display names рыбы
statistics.py            # статистика сессии, форматирование денег/веса/длительности
statistics_export.py     # экспорт CSV
constants.py             # задержки, ROI, базовые константы
trigger_monitor.py       # поиск триггеров стадий по шаблонам
casting_a_fishing_rod.py # контроль заброса
hooking.py               # контроль подсечки/ожидания
memory_reeling.py        # вываживание через память процесса
inventory_stage.py       # детект открытого инвентаря
inventory_memory.py      # чтение/детект инвентаря через память/состояния
store_fish.py            # перекладывание рыбы
meal_system.py           # еда/вода
trash/garbage_disposal.py или garbage_disposal.py # обработка мусора
trade/tackle_detection.py или tackle_detection.py # снасти
```

Точные имена некоторых вспомогательных файлов проверять по дереву проекта перед правкой. Главный вход для их использования — `FishingBot`.

## 10. Вываживание через память

### `src/sonar/fishing/memory_reeling.py`

Класс:

```text
MemoryReelingTracker
```

Работает с памятью `gta5.exe`:

- ищет process/module;
- читает memory regions;
- ищет player/fish pointers;
- использует offsets;
- определяет позицию игрока и рыбы;
- вычисляет направление;
- управляет клавишами через `InputController`.

Это самый хрупкий модуль: обновления клиента/игры могут ломать offsets, паттерны и эвристику.

Смотреть сюда при проблемах:

- бот не вываживает;
- держит не ту клавишу;
- теряет рыбу;
- пишет `target_search`, `position_unreadable`, `memory_unavailable`, `control_error`;
- ломается после обновления Majestic/GTA.

## 11. Захват окна и ввод

### `src/sonar/vision/capture.py`

Класс:

```text
WindowCapture
```

Отвечает за:

- поиск окна по имени процесса;
- получение client rect;
- перевод координат client -> screen;
- скриншот через Win32 `BitBlt`;
- возврат кадра как `numpy.ndarray`.

### `src/sonar/automation/input_controller.py`

Класс:

```text
InputController
```

Отвечает за:

- `SendInput` клавиатуры;
- клики мыши;
- hotkeys;
- отпускание клавиш;
- `dry_run`;
- блокировку ввода через `input_allowed_callback`.

Важно: если игра не в фокусе, ввод может быть запрещён через callback. Это защита от нажатий в чужие окна.

### `src/sonar/automation/window.py`

Отвечает за поиск/активацию окна игры. Смотреть при проблемах фокуса и возврата окна.

## 12. Стриминг

### `src/sonar/streaming/service.py`

Главный класс:

```text
StreamingService
```

Отвечает за:

- подготовку FFmpeg;
- подготовку cloudflared;
- локальный HTTP server;
- HLS-поток;
- public URL через trycloudflare;
- HTML-страницу `/live/`;
- heartbeat зрителей;
- автостоп через 5 минут без зрителей;
- переключение качества;
- режим 10fps;
- увеличение области чата;
- WIP-чат;
- чтение истории чата из памяти.

### Качества

```text
480p  -> 1400k
720p  -> 3200k
1080p -> 5800k
```

### Состояния стрима

Часто встречаются:

```text
offline
starting
preparing
online
error
```

При UI-багах со статусом и кнопками проверять:

```text
StreamingService.__init__()
StreamingService.start_stream()
StreamingService.stop_stream()
StreamingService.snapshot()
StreamingService._snapshot_locked()
StreamingService._prepare_new_runtime_locked()
StreamingService._start_runtime_worker()
StreamingService._stop_runtime_locked()
MainWindow._refresh_stream_tab()
```

### Web UI стрима

В dev/source режиме HTML живёт прямо в переменной:

```text
STREAM_PAGE_HTML
```

Внутри HTML есть React + Video.js.

Это неудобная зона для поддержки: JavaScript лежит внутри Python raw-string. Перед крупными правками лучше подумать о выносе в отдельный frontend-файл или template.

### HTTP endpoints

`StreamRequestHandler`:

```text
GET  /
GET  /live/
GET  /api/stream/status
GET  /api/stream/chat
GET  /assets/chat-icons/<name>.png
GET  /hls/<file>

POST /api/stream/viewer-heartbeat
POST /api/stream/chat-zoom
POST /api/stream/snapshot-mode
POST /api/stream/chat-memory
POST /api/stream/chat-mode
POST /api/stream/chat-select
POST /api/stream/chat-send
POST /api/stream/chat-clear
```

В release-сборке часть chat endpoints должна вырезаться через `scripts/prepare_release_sources.py`.

## 13. Чат

### `src/sonar/streaming/chat.py`

WIP-модуль визуального управления чатом Majestic.

Ключевые структуры:

```text
ChatCommand
ChatTab
ChatDetection
ChatActionResult
MajesticChatDetector
MajesticChatController
```

Поддерживаемые команды-подсказки:

```text
обычный IC
/w
/s
/b
/me
/do
/c
/cb
/g
/gb
/report
```

Детектор ищет:

- активный input чата;
- вкладки чата;
- активную вкладку;
- координаты input rect.

Использует OpenCV: HSV-маски, edge detection, connected components, эвристики размеров.

### `src/sonar/chat_wip_gate.py`

Runtime-gate для WIP-чата.

Чат включён только если:

```text
not sys.frozen
и
--debug или SONAR_DEBUG_MODE=1
```

Если чат выключен:

- кнопка режима чата в UI скрывается;
- HTML стрима патчится скриптом удаления элементов;
- Telegram-хинт про режим чата вырезается;
- методы чата в `StreamingService` заменяются заглушками.

## 14. Чтение истории чата из памяти

Инструменты в `src/sonar/tools/`:

```text
dump_chat_history
find_chat_memory
dump_process_memory
```

Назначение:

- читать историю чата из `GTA5.exe` и `majestic-webengine.exe`;
- сохранять debug-отчёты;
- искать подтверждение отправленных сообщений;
- работать с заранее сохранённым дампом.

Выходная папка:

```text
logs/chat_memory/
```

В `StreamingService` эти инструменты вызываются через subprocess:

```text
python -m sonar.tools.dump_chat_history
python -m sonar.tools.find_chat_memory
```

В release-сборке `sonar.tools` не должен включаться в exe через Nuitka `--nofollow-import-to=sonar.tools`.

## 15. Telegram

### `src/sonar/telegram/notifier.py`

Главный класс:

```text
NotificationManager
```

Отвечает за:

- Telegram polling;
- отправку сообщений;
- отправку фото;
- inline-menu;
- управление ботом;
- управление стримом;
- статистику;
- снасти;
- скриншоты;
- выключение игры/ПК;
- синхронизацию Telegram-настроек.

### Команды

```text
/menu
/notifications
/stats
/tackle
/screen
/shutdown_pc
/shutdown_game
```

### Callback data

```text
menu:main
menu:notifications
menu:stream
menu:stream_quality
toggle:<setting>
stream:quality:<quality>
stream:start_stop
stream:open
stream:switch_area
stream:switch_mode
action:start_stop
action:screen
action:focus_game
action:stats
action:tackle
action:shutdown_pc
action:shutdown_game
```

### Связь с ботом

`FishingBot._configure_notifications()` передаёт в `NotificationManager` callbacks:

```text
start_callback
stop_callback
is_running_callback
stats_callback
stats_rows_callback
has_stats_callback
tackle_callback
tackle_image_callback
tackle_scanned_at_callback
screenshot_callback
focus_game_callback
shutdown_game_callback
shutdown_pc_callback
settings_changed_callback
stream_status_callback
stream_start_callback
stream_stop_callback
stream_set_quality_callback
stream_set_chat_zoom_callback
stream_set_snapshot_mode_callback
```

## 16. Статистика

### `src/sonar/fishing/statistics.py`

Отвечает за:

- накопление статистики сессии;
- строки по рыбам;
- форматирование веса;
- форматирование денег;
- форматирование длительности;
- доход в час;
- custom prices;
- parse базовых цен из markdown.

### `src/sonar/fishing/statistics_export.py`

Отвечает за CSV export.

### Где используется

- UI-вкладка `Статистика` в `main_window.py`;
- Telegram-уведомления в `notifier.py`;
- FishingBot при улове/остановке.

## 17. Release-сборка

### `scripts/build_secure.ps1`

Главный скрипт сборки exe.

Делает:

- требует Python 3.12;
- ставит зависимости `-e .[build]`, если нет `-SkipInstall`;
- готовит streaming binaries;
- очищает `build` и `dist`;
- копирует `src` во временную build-папку;
- запускает branding;
- запускает подготовку release sources;
- собирает onefile через Nuitka;
- включает PySide6 plugin;
- включает UAC admin;
- отключает console window;
- включает resources;
- включает `secure_wipe.ps1` и `sdelete.exe`;
- исключает `pytest`, `tests`, `sonar.tools`;
- создаёт `dist/<random-app-name>/config`.

Команды:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
```

### `scripts/prepare_release_sources.py`

Критичный скрипт для exe.

Делает:

- заменяет `src/sonar/streaming/chat.py` на release stub;
- заменяет `STREAM_PAGE_HTML` на release HTML без WIP-чата;
- удаляет chat endpoints из `StreamRequestHandler`;
- удаляет Telegram-хинт `Режим чата доступен на странице стрима`.

Если WIP-чат случайно попал в exe, проверять этот файл первым.

### `scripts/prepare_build_branding.py`

Готовит branding сборки:

- выбирает PNG-иконку;
- генерирует app name/exe name;
- пишет build metadata;
- готовит app.ico.

### `scripts/prepare_streaming_binaries.py`

Готовит portable FFmpeg/cloudflared для стрима.

## 18. Самоудаление

### `src/sonar/self_uninstall.py`

Отвечает за удаление portable-приложения.

Основные функции:

```text
get_uninstall_availability()
resolve_packaged_executable_path()
schedule_self_uninstall()
create_uninstall_script()
```

Защиты:

- работает только в frozen/exe;
- exe должен лежать внутри target dir;
- нельзя удалить корень диска;
- нельзя удалить папку, похожую на исходники;
- нельзя удалить project dir.

Использует:

```text
secure_wipe.ps1
sdelete.exe
```

## 19. Быстрый индекс “что править”

| Задача | Куда смотреть |
|---|---|
| Запуск приложения | `src/sonar/app.py`, `src/sonar/__main__.py` |
| Пути dev/exe | `src/sonar/paths.py` |
| Главное окно | `src/sonar/ui/main_window.py` |
| Кнопки запуска/остановки бота | `main_window.py`, `fishing/bot.py` |
| Кнопки стрима | `main_window.py`, `streaming/service.py` |
| Статус стрима завис на preparing | `streaming/service.py`, `main_window.py`, `prepare_release_sources.py`, `paths.py` |
| Telegram-меню | `telegram/notifier.py` |
| Telegram-статистика | `telegram/notifier.py`, `fishing/statistics.py` |
| Лицензия | `license/manager.py`, `license/client.py`, `config/models.py` |
| Роли лицензии | `license/client.py`, `streaming/service.py` |
| Настройки | `config/models.py`, `config/manager.py`, `ui/main_window.py` |
| Стадии рыбалки | `fishing/bot.py`, `fishing/trigger_monitor.py`, `fishing/constants.py` |
| Заброс | `fishing/bot.py`, `fishing/casting_a_fishing_rod.py` |
| Вываживание | `fishing/memory_reeling.py`, `fishing/bot.py` |
| Экран улова | `fishing/catch_screen.py`, `fishing/fish_recognition.py` |
| Рыбы и названия | `fishing/fish_names.py` |
| Инвентарь | `fishing/inventory_stage.py`, `fishing/inventory_memory.py`, `fishing/store_fish.py` |
| Еда/вода | `fishing/meal_system.py` |
| Мусор | `fishing/garbage_disposal.py` |
| Снасти | `fishing/tackle_detection.py` |
| Захват окна | `vision/capture.py` |
| Ввод клавиш/мыши | `automation/input_controller.py` |
| Фокус окна | `automation/window.py` |
| Web-стрим | `streaming/service.py` |
| WIP-чат | `streaming/chat.py`, `chat_wip_gate.py` |
| Чтение чата из памяти | `tools/dump_chat_history.py`, `tools/find_chat_memory.py`, `tools/dump_process_memory.py` |
| Сборка exe | `scripts/build_secure.ps1` |
| Удаление WIP из exe | `scripts/prepare_release_sources.py` |
| Branding exe | `scripts/prepare_build_branding.py` |
| Portable FFmpeg/cloudflared | `scripts/prepare_streaming_binaries.py` |
| Самоудаление | `self_uninstall.py`, `secure_wipe.ps1` |

## 20. Зоны риска

### `MainWindow`

Слишком много ответственности:

- UI;
- лицензия;
- bot lifecycle;
- stream lifecycle;
- Telegram sync;
- settings sync;
- timers.

Любые правки в UI могут задеть runtime-состояния.

### `FishingBot`

Главный state machine. Много implicit-состояния и thread/event логики. Перед правками проверять stop/start/pause paths.

### `StreamingService`

Очень широкий класс:

- binaries;
- subprocesses;
- temp dirs;
- HTTP server;
- HLS;
- tunnel;
- chat;
- memory scan.

Самая вероятная зона source/exe багов.

### `NotificationManager`

Много callback_data и UI-состояния Telegram. Легко сломать меню, если поменять callback без обновления обработчика.

### `prepare_release_sources.py`

Меняет исходники во временной build-копии regex/replace-операциями. Любое изменение `STREAM_PAGE_HTML` или endpoint-блоков может сломать release stripping.

## 21. Проверки после правок

Минимум:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python -m pytest -q
python -m sonar --smoke-test
```

Для сборки:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
```

Для проверки source/debug WIP-чата:

```powershell
python -m sonar --debug
```

Для проверки, что WIP-чат не попал в release:

- собрать exe;
- открыть вкладку стрима;
- проверить, что кнопки режима чата нет;
- открыть web-страницу стрима;
- проверить, что кнопки/панели чата нет;
- открыть Telegram-меню стрима;
- проверить, что текста `Режим чата доступен на странице стрима` нет.

## 22. Рекомендации по поддержке индекса

Обновлять этот файл, если:

- добавлен новый крупный модуль;
- изменился entrypoint;
- изменилась сборка exe;
- изменились runtime-пути;
- изменилась схема конфигов;
- изменились Telegram callback_data;
- WIP-функция стала production-функцией;
- появились новые роли лицензий;
- изменились ключевые стадии рыбалки.

Лучше обновлять индекс небольшим коммитом вместе с архитектурной правкой, а не раз в полгода, когда уже нихуя не понятно, кто кого вызывает.
