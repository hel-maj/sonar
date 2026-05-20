# Sonar

Sonar - desktop-приложение для автоматизации рыбалки в Majestic RP.

## Возможности

- Автоматизация этапов рыбалки, хранения улова, питания и обработки мусора.
- OCR и OpenCV-распознавание игровых экранов.
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

```powershell
python -m pytest -q
python -m sonar --smoke-test
```
