# Защищенная сборка и проверка exe

Этот документ описывает, что делает защищенная сборка. Полный порядок выпуска версии находится в [update_release_full.md](update_release_full.md).

## Что делает build_secure.ps1

Скрипт:

1. Готовит streaming binaries.
2. Создает временную копию `src`.
3. Генерирует новый `build_key`.
4. Генерирует новый seed обфускации.
5. Выбирает имя exe и иконку из `assets\game_icons`.
6. Шифрует runtime literals под `build_key`.
7. Удаляет лишние dev/tools файлы из release source.
8. Обфусцирует приватные идентификаторы с seed.
9. Собирает onefile exe через Nuitka.
10. Проверяет dist на запрещенные plaintext markers.
11. Создает рядом готовый zip `<build_key>-<exe name>.zip`.
12. Записывает build metadata в `config\sonar_build_keys.json`.

## Нейтральный публичный домен

Не используйте домен со словами `keygen`, `license`, `admin`, `ui`, а также `nip.io`. Такой домен раскрывает IP и назначение сервиса.

Нормальная схема:

```text
updates.<ваш-домен>      публичный URL для приложения, release metadata и скачивания
license-admin.<ваш-домен> закрытый админский UI, лучше за VPN/basic auth/IP allowlist
```

Для пользовательского релиза передавайте публичный домен в сборку:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -LicenseServerUrl "https://m-sonar-addr.ru"
```

Без этого параметра используется dev-placeholder:

```text
https://updates.example.invalid
```

Он нужен только для разработки и не подходит для пользовательских exe.

Вместо параметра можно задать переменную окружения перед сборкой:

```powershell
$env:SONAR_LICENSE_SERVER_URL = "https://m-sonar-addr.ru"
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
```

Подробно про все переменные окружения: [environment_variables.md](environment_variables.md).

## Runtime encryption

Адреса API, публичные IP endpoints, Telegram API, process names и memory markers не хранятся в исходном виде в release source.

Они попадают в `sonar/security/literals.py` уже зашифрованными и расшифровываются только в момент использования.

Для локального запуска через `.py` используется стабильный dev key. Для exe используется build key конкретной сборки.

## Обфускация

Обфускация использует seed из сборки.

Каждая обычная сборка получает новый seed, поэтому приватные имена функций и переменных отличаются между билдами.

Для повторения конкретного билда используйте:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -BuildKey "<build_key>" -ObfuscationSeed "<seed>" -LicenseServerUrl "https://m-sonar-addr.ru"
```

Seed берется из:

```text
P:\projects\Majestic\Sonar\config\sonar_build_keys.json
```

## Что не должно попадать в exe

`audit_release_secrets.py` проверяет, что в release artifact нет открытых строк вроде:

- старого публичного `sonar-keygen`/`nip.io` домена;
- IP сервера;
- Telegram API URL;
- URL загрузки ffmpeg/cloudflared;
- memory-search markers;
- process names `gta5.exe` и `majestic-webengine.exe`.

Если audit падает, exe не отдавать пользователям.

Ручной запуск:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\audit_release_secrets.py --target ".\dist\<app_version>\<имя exe>"
```

## Как проверить build key

Из exe:

```powershell
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<имя exe>\<имя exe>.exe"
```

Из zip:

```powershell
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<имя exe>\<build_key>-<имя exe>.zip"
```

Если рядом есть `config\sonar_build_keys.json`, утилита также покажет seed, app name и exe name.

## Минимальный чек перед публикацией

Перед загрузкой build archive на сервер проверьте:

- `python scripts\run_tests.py` проходит;
- `build_secure.ps1` запущен с правильным `-LicenseServerUrl`;
- `build_secure.ps1` завершился без ошибок;
- audit release secrets прошел;
- рядом с exe создан zip;
- имя zip начинается с 64-символьного build key;
- exe внутри zip открывается и запускается;
- `extract_build_key_from_exe.py` находит build key;
- build key есть в `config\sonar_build_keys.json`.
