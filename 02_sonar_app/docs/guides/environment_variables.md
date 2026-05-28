# Переменные окружения для домена и релиза

Главное правило: домен для проверки лицензии попадает в exe во время сборки. Если exe уже собран, переменная окружения на компьютере пользователя не поменяет адрес сервера лицензий внутри этого exe.

Текущий боевой домен:

```text
https://m-sonar-addr.ru
```

## Быстрый вариант без переменных

Для релизной сборки проще передавать домен параметром команды:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -Count 1 -LicenseServerUrl "https://m-sonar-addr.ru" -NoLto
```

`-NoLto` нужен, если Nuitka/MinGW падает на этапе линковки с internal compiler error.

Для загрузки zip на сервер параметр `--host` уже не обязателен, потому что дефолт в скрипте сейчас `m-sonar-addr.ru`:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\upload_build_archives.py
```

## Куда вставлять переменные в PowerShell

Если хочется задавать значения через переменные окружения, вставляйте их в тот же PowerShell перед командой сборки или загрузки:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
$env:SONAR_LICENSE_SERVER_URL = "https://m-sonar-addr.ru"
$env:SONAR_UPLOAD_HOST = "m-sonar-addr.ru"

powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -Count 1 -NoLto
python scripts\upload_build_archives.py
```

Такая запись действует только в текущем окне PowerShell. Закрыли окно - переменные пропали.

## Можно ли просто создать `.env`

Да. Сейчас `.env` читают:

- запуск из исходников `python -m sonar`;
- `scripts\build_secure.ps1` через `prepare_build_branding.py`;
- `scripts\upload_build_archives.py`.

Создайте файл:

```text
P:\projects\Majestic\Sonar\02_sonar_app\.env
```

Минимальное содержимое:

```dotenv
SONAR_LICENSE_SERVER_URL=https://m-sonar-addr.ru
SONAR_UPLOAD_HOST=m-sonar-addr.ru
```

После этого можно запускать так:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python -m sonar --debug --keep-debug-capture
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -Count 1 -NoLto
python scripts\upload_build_archives.py
```

Файл `.env` игнорируется git. Шаблон лежит рядом:

```text
P:\projects\Majestic\Sonar\02_sonar_app\.env.example
```

Приоритет такой:

1. Параметры команды, например `-LicenseServerUrl`, важнее всего для сборки.
2. Настоящие переменные окружения Windows, например `$env:SONAR_LICENSE_SERVER_URL`, важнее `.env`.
3. `.env` используется, если переменная не задана в окружении.
4. Если ничего не задано, используются дефолты скриптов.

Скрипты ищут `.env` в двух местах:

```text
P:\projects\Majestic\Sonar\.env
P:\projects\Majestic\Sonar\02_sonar_app\.env
```

Если есть оба файла, значения из `02_sonar_app\.env` перекрывают значения из корневого `.env`.

Для нестандартного пути можно задать:

```powershell
$env:SONAR_DOTENV_PATH = "C:\path\to\sonar.env"
```

## Постоянные переменные Windows

Постоянно задавать обычно стоит только `SONAR_UPLOAD_HOST`. Для `SONAR_LICENSE_SERVER_URL` безопаснее использовать параметр `-LicenseServerUrl` в релизной команде, чтобы адрес был явно виден в истории сборки.

```powershell
[Environment]::SetEnvironmentVariable("SONAR_UPLOAD_HOST", "m-sonar-addr.ru", "User")
```

После этого откройте новое окно PowerShell.

Если все же нужно постоянно задать license URL:

```powershell
[Environment]::SetEnvironmentVariable("SONAR_LICENSE_SERVER_URL", "https://m-sonar-addr.ru", "User")
```

Удалить постоянную переменную:

```powershell
[Environment]::SetEnvironmentVariable("SONAR_LICENSE_SERVER_URL", $null, "User")
[Environment]::SetEnvironmentVariable("SONAR_UPLOAD_HOST", $null, "User")
```

Удалить переменную только из текущего окна:

```powershell
Remove-Item Env:\SONAR_LICENSE_SERVER_URL -ErrorAction SilentlyContinue
Remove-Item Env:\SONAR_UPLOAD_HOST -ErrorAction SilentlyContinue
```

## Список переменных

| Переменная | Где задавать | Для чего нужна | Текущее значение |
| --- | --- | --- | --- |
| `SONAR_LICENSE_SERVER_URL` | На локальном ПК перед сборкой | Вшивается в exe как сервер проверки лицензии и release metadata | `https://m-sonar-addr.ru` |
| `SONAR_LICENSE_ACCOUNT_ID` | На локальном ПК перед сборкой | Необязательный account id для account-scoped Keygen routes | Пусто |
| `SONAR_UPLOAD_HOST` | На локальном ПК перед upload-скриптом | SSH/SCP host для загрузки готовых zip | `m-sonar-addr.ru` |
| `SONAR_RELEASE_METADATA_URL` | Только для отладки runtime | Заставляет приложение читать release metadata из отдельного URL вместо `<license_server_url>/sonar-release.json` | Обычно не задавать |
| `SONAR_DOTENV_PATH` | На локальном ПК перед сборкой/upload | Нестандартный путь к `.env` | Обычно не задавать |

## Что куда не писать

`config\license_settings.json` не предназначен для домена сервера. Там хранится лицензия пользователя и кеш результата проверки.

`/opt/sonar-keygen/.env` на сервере не используется локальной сборкой. Там лежит серверная переменная Keygen:

```text
KEYGEN_HOST=m-sonar-addr.ru
```

Если когда-нибудь поменяете `KEYGEN_HOST` на сервере, после этого надо пересоздать или перезапустить контейнеры `sonar-keygen-web` и `sonar-keygen-worker`.

`sonar-release.json` тоже не переменная окружения. Это публичный JSON на сервере:

```text
/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/sonar-release.json
```

В нем задается ссылка, которую пользователь видит в карточке обновления:

```json
{
  "download_link": "https://m-sonar-addr.ru/download"
}
```
