# Sonar

Sonar - desktop-приложение для автоматизации рыбалки в Majestic RP.

## Возможности

- Автоматизация этапов рыбалки, хранения улова, питания и обработки мусора.
- OCR и OpenCV-распознавание игровых экранов.
- Извлечение истории чата из памяти GTA5.exe и majestic-webengine.exe для разработки и диагностики.
- Статистика сессии с пользовательскими ценами продажи.
- Telegram-бот с меню, уведомлениями, скриншотом, запуском/остановкой и командами выключения.
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

## Runtime-файлы

В режиме исходников приложение пишет настройки и логи в корень проекта:

- `config`
- `logs`

В собранной portable-версии рядом с exe создается только `config`. Реестр не используется. Файловые логи в release-сборке по умолчанию отключены, а `*.runtime` рядом с exe не создается.

## Чат из памяти

Инструменты ниже нужны для разработки и диагностики. Они читают память запущенной игры или заранее сохраненный дамп и пишут результат в `P:\projects\Majestic\Sonar\logs\chat_memory`.

Снять историю чата из текущей запущенной игры:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python -m sonar.tools.dump_chat_history --process auto --progress 0 --print-records 120 --fragment-limit 0
```

Собирать историю непрерывно:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python -m sonar.tools.dump_chat_history --process auto --watch --watch-interval 5 --progress 0 --print-records 120 --fragment-limit 0
```

`--process auto` сам выбирает несколько источников чата: `GTA5.exe` и подходящие `majestic-webengine.exe` renderer-процессы. Если нужно ограничиться CEF-процессами, добавь `--cef-only`. Для ручной проверки конкретного процесса можно передать `--process pid:<PID>`.

Создать полный дамп памяти для повторного анализа без запущенной игры:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python -m sonar.tools.dump_process_memory --process GTA5.exe,majestic-webengine.exe --out-dir P:\projects\Majestic\Sonar\logs\chat_memory
```

Прочитать историю из сохраненного дампа:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python -m sonar.tools.dump_chat_history --memory-dump P:\projects\Majestic\Sonar\logs\chat_memory\process_memory_dump_YYYYMMDD_HHMMSS --process auto --progress 0 --print-records 120 --fragment-limit 0
```

Вывод содержит `chat_state`, `chat_input_active`, `active_tab`, `tabs`, `messageId`, `stableId`, `order`, `orderSource`, `playerName`, `playerId`, `staticId`, `phoneNumber`, `color`, `formatting`, `owner`, `process` и `pid` там, где эти данные удается найти в памяти. Без реального `id` или memory `messageId` одинаковый текст не считается тем же сообщением; порядок тогда берется из позиции в памяти. `fragments` - это сырой отладочный fallback без метаданных; для рабочего чтения истории держи `--fragment-limit 0`.

## Сборка exe

Требования:

- Windows x64.
- Python 3.12.
- Microsoft C++ Build Tools.
- Установленные зависимости проекта: `python -m pip install -e .[build]`.

Команда сборки:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1
```

Результат:

- `dist\<случайное имя из assets\game_icons>.exe`
- `dist\config`

Что делает сборка:

- копирует только `src`, без тестов и fixture-скриншотов;
- выбирает случайную PNG-иконку из `assets\game_icons`;
- делает из имени PNG имя exe, имя процесса и заголовок окна приложения;
- делает из PNG иконку exe и иконку приложения;
- добавляет в onefile-пакет случайную соль размером от 0.1 МБ до 50 МБ;
- собирает один exe через Nuitka без Cython;
- включает только ресурсы из `src\sonar\resources`, нужные приложению;
- отключает консольное окно.

Для повторной сборки без обновления build-зависимостей:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
```

## Лицензирование

Клиент проверяет лицензию при запуске и при истечении срока действия. До валидной лицензии доступна только вкладка `Лицензия`. Адрес сервера не хранится в `license_settings.json` и восстанавливается приложением в runtime.

Для обновлений приложение читает из metadata лицензии:

- `latest_version`
- `update_message`

`update_message` поддерживает переносы строк, кириллицу и emoji.

## Проверки

Перед полным прогоном тестов установи проект с test-зависимостями. Это важно для UI-тестов: `PySide6` должен быть установлен в окружение, иначе проверка интерфейса не будет полноценной.

```powershell
python -m pip install -e ".[test]"
python scripts/run_tests.py
python -m sonar --smoke-test
```

На Windows можно запускать тем же способом через готовый скрипт:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\test.ps1
```

`python -m pytest -q` можно использовать для локальной быстрой проверки, но основной командой считается `python scripts/run_tests.py`: он изолирует зависающие OCR/OpenCV/UI-кейсы и не пропускает UI-тесты из-за отсутствия `PySide6`.
