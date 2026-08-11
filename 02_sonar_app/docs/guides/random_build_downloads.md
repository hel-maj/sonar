# Случайная выдача готовых build archives

Эта схема используется для скачивания обновления:

```text
пользователь открывает /download -> сервер выбирает latest version folder в builds -> выбирает случайный zip только из этой версии -> браузер скачивает выбранный zip
```

На сервере не запускается сборка и не создается zip на лету. Все архивы должны быть подготовлены заранее локальной сборкой.

## Где лежат архивы на сервере

```text
/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds/<app_version>
```

В `builds` для каждой версии должна быть отдельная папка:

```text
builds/
  0.1.0/
    <build_key>-<exe name>.zip
  0.2.0/
    <build_key>-<exe name>.zip
```

Внутрь version-папки кладутся только готовые build archives:

```text
<build_key>-<exe name>.zip
```

Пример:

```text
bd68400c3c8ad1380fed102e28afd5d6a02451cf58d9fdddb01c4b098164cd4b-Warhammer 40,000 - Darktide.zip
```

Внутри архива лежит exe:

```text
Warhammer 40,000 - Darktide.exe
```

## Как создать такие архивы

Один билд:

```powershell
cd P:\projects\neiro\Sonar Fishing\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
```

Много билдов:

```powershell
cd P:\projects\neiro\Sonar Fishing\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -Count 20 -LicenseServerUrl "https://m-sonar-addr.ru"
```

После сборки в каждой папке `dist\<app_version>\<имя>` будет:

```text
<имя>.exe
<build_key>-<имя>.zip
```

Загружать на сервер надо zip-файлы.

## Как сервер выбирает версию и файл

Сервис сначала ищет в `builds` папки с numeric version name, например `0.1.0` или `1.2.3`.

Если version-папки есть, он выбирает самую новую версию по числам в имени папки и сканирует только ее. Старые папки остаются на диске, но публичные URL их не отдают.

Если version-папок нет, включается legacy fallback: сервис сканирует корень `builds`, чтобы старый сервер не сломался до миграции файлов.

В выбранной version-папке сервис берет только zip, имя которых подходит под шаблон:

```text
11 или 64 hex build key + "-" + имя exe + ".zip"
```

Файлы вроде `test.zip`, `Sonar.zip`, `old-build.zip` игнорируются.

Если в latest version folder валидных архивов нет, `/api/random-build.zip` вернет ошибку `No build .zip archives found`.

## Публичные URL

Страница с loader:

```text
https://m-sonar-addr.ru/download
```

Прямая ссылка на случайный архив из latest version folder:

```text
https://m-sonar-addr.ru/api/random-build.zip
```

Проверка статуса:

```text
https://m-sonar-addr.ru/random-build-health
```

`m-sonar-addr.ru` - текущий домен релиза. Для будущих доменов используйте нейтральное имя без слов `keygen`, `license`, `admin`, `ui` и без `nip.io`.

Эти URL не включают версию в path. Это сделано специально: пользователь всегда получает latest version folder, а `sonar-release.json` хранит только текущий `latest_version` и стабильный `download_link`.

Полный список доступных URL лежит отдельно:

```text
docs/guides/available_urls.md
```

На сервере выдачей занимается Docker-контейнер `sonar-random-build-download` в сети `sonar-keygen`.
Caddy проксирует `/download`, `/api/random-build.zip`, `/api/startup-block` и `/random-build-health` в этот контейнер.

Проверить контейнер на сервере:

```powershell
ssh root@m-sonar-addr.ru "docker ps --filter name=sonar-random-build-download"
ssh root@m-sonar-addr.ru "docker logs --tail 50 sonar-random-build-download"
```

## Что писать в download_link

В `sonar-release.json` или Keygen metadata указывайте:

```json
{
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Так пользователь увидит loader, а потом браузер начнет скачивание.

## Проверка папки builds через SSH

Проверить, что папка существует и в ней есть валидные zip:

```powershell
$BuildsDir = "/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds"
ssh root@m-sonar-addr.ru "mkdir -p '$BuildsDir'"
ssh root@m-sonar-addr.ru "find '$BuildsDir' -mindepth 1 -maxdepth 1 -type d -printf '%f\n' | sort -V"
ssh root@m-sonar-addr.ru "curl -sS https://m-sonar-addr.ru/random-build-health"
```

## Загрузка архивов через SSH key

Если `ssh root@m-sonar-addr.ru` входит без пароля, загрузить все архивы из `dist` можно так:

```powershell
cd P:\projects\neiro\Sonar Fishing\02_sonar_app
python scripts\upload_build_archives.py --source ".\dist\<app_version>" --version "<app_version>" --host m-sonar-addr.ru
```

Для production всегда передавайте точные `--source` и `--version`, чтобы
fallback scan не подобрал старые локальные архивы. Вместо постоянного `--host`
можно задать переменную окружения `SONAR_UPLOAD_HOST`.

Проверить без загрузки:

```powershell
python scripts\upload_build_archives.py --source ".\dist\<app_version>" --version "<app_version>" --host m-sonar-addr.ru --dry-run
```

Если надо заменить набор архивов внутри этой же версии, сначала подготовьте
проверенный backup и rollback source, затем выполните dry-run:

```powershell
python scripts\upload_build_archives.py --source ".\dist\<app_version>" --version "<app_version>" --host m-sonar-addr.ru --replace-version --dry-run
```

`--replace-version` выполняет remote `rm -rf` target version-папки и не является
atomic. Live replacement требует отдельного свежего подтверждения точной
версии, archive count, backup и rollback source. Без проверенного восстановления
операция заблокирована.

Удаление старых version-папок описано отдельно: [delete_old_build_versions.md](delete_old_build_versions.md).

Если вход по паролю, а не по SSH key, разрешите prompt пароля:

```powershell
python scripts\upload_build_archives.py --source ".\dist\<app_version>" --version "<app_version>" --host m-sonar-addr.ru --allow-password --dry-run
python scripts\upload_build_archives.py --source ".\dist\<app_version>" --version "<app_version>" --host m-sonar-addr.ru --allow-password
```

Если ключ лежит не в стандартном месте:

```powershell
python scripts\upload_build_archives.py --source ".\dist\<app_version>" --version "<app_version>" --host m-sonar-addr.ru --key "$env:USERPROFILE\.ssh\id_ed25519"
```

Если архивы лежат в отдельной папке:

```powershell
python scripts\upload_build_archives.py --source "C:\path\to\archives" --version "<app_version>" --host m-sonar-addr.ru
```

Утилита использует системные `ssh/scp`, поэтому работает с обычными ключами из `.ssh`, `ssh-agent` и настройками OpenSSH.

Ручная загрузка без upload-скрипта:

```powershell
cd P:\projects\neiro\Sonar Fishing\02_sonar_app
$Version = "0.1.0"
$BuildsDir = "/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds/$Version"
$Archives = Get-ChildItem -Path ".\dist\$Version" -Recurse -File -Filter "*.zip" |
  Where-Object { $_.Name -match '^(?:[0-9a-f]{11}|[0-9a-f]{64})-.+(?:\.exe)?\.zip$' }
if (-not $Archives) { throw "No build archives found in .\dist" }

ssh root@m-sonar-addr.ru "mkdir -p '$BuildsDir'"
foreach ($Archive in $Archives) {
  scp "$($Archive.FullName)" "root@m-sonar-addr.ru:$BuildsDir/"
}
ssh root@m-sonar-addr.ru "find '$BuildsDir' -maxdepth 1 -type f -name '*.zip' | wc -l"
```

Если нужен GUI, используйте WinSCP и загрузите архивы вручную.

## Проверка скачанного архива

Скачать:

```powershell
curl.exe -L -OJ https://m-sonar-addr.ru/api/random-build.zip
```

Вытащить build key из скачанного zip:

```powershell
cd P:\projects\neiro\Sonar Fishing\02_sonar_app
python scripts\extract_build_key_from_exe.py "C:\path\to\<build_key>-<exe name>.zip" --no-map
```

Сверить seed:

```text
P:\projects\neiro\Sonar Fishing\config\sonar_build_keys.json
```
