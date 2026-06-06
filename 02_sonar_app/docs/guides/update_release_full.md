# Полный порядок обновления Sonar

Этот гайд нужен, когда надо выпустить новую версию приложения и раздать ее пользователям через ссылку обновления.

## Что важно помнить

- Готовые архивы лежат на сервере в папках вида `/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds/<app_version>`.
- Пользователь открывает `https://m-sonar-addr.ru/download`.
- `https://m-sonar-addr.ru` - текущий нейтральный публичный домен релиза.
- Сервер выбирает latest version folder внутри `builds`, затем случайный архив только из этой папки и отдает его пользователю.
- Архивы заранее создаются локально во время `build_secure.ps1`.
- Имя архива всегда такое: `<build_key>-<exe name>.zip`.
- Внутри архива лежит обычный exe с тем же именем, которое выбрала сборка по картинке из `assets/game_icons`.
- Карта `build_key -> seed` хранится локально в `P:\projects\Majestic\Sonar\config\sonar_build_keys.json`.

## 1. Обновить версию в коде

Откройте файл:

```text
P:\projects\Majestic\Sonar\02_sonar_app\src\sonar\version.py
```

Поставьте новую версию:

```python
APP_VERSION = "1.2.3"
```

Версия должна совпадать с тем, что вы потом укажете в `sonar-release.json` или metadata Keygen.

## 2. Запустить тесты

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\run_tests.py
```

Если тесты упали, сборку пользователям не отдавать.

## 3. Собрать защищенные exe и zip

Один билд:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
```

Много билдов для случайной выдачи:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall --count 20
```

В PowerShell также будет работать форма `-Count 20`, но в гайдах дальше используется `--count`.

Если уже есть нейтральный публичный домен, сразу передайте его в сборку:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall --count 20 -LicenseServerUrl "https://m-sonar-addr.ru"
```

Иначе exe будет собран с dev-placeholder `https://updates.example.invalid`, который не подходит для пользователей.

Если непонятно, куда вставлять переменные окружения, см. отдельный гайд:

```text
docs/guides/environment_variables.md
```

Короткий вариант для текущего окна PowerShell:

```powershell
$env:SONAR_LICENSE_SERVER_URL = "https://m-sonar-addr.ru"
$env:SONAR_UPLOAD_HOST = "m-sonar-addr.ru"
```

`SONAR_LICENSE_SERVER_URL` задается перед сборкой exe. `SONAR_UPLOAD_HOST` задается перед загрузкой zip на сервер.

После каждого билда рядом будут два файла:

```text
dist\<app_version>\<имя exe>\<имя exe>.exe
dist\<app_version>\<имя exe>\<build_key>-<имя exe>.zip
```

Пример:

```text
dist\1.2.3\Warhammer 40,000 - Darktide\Warhammer 40,000 - Darktide.exe
dist\1.2.3\Warhammer 40,000 - Darktide\bd68400c3c8ad1380fed102e28afd5d6a02451cf58d9fdddb01c4b098164cd4b-Warhammer 40,000 - Darktide.zip
```

`build_secure.ps1` также обновит:

```text
P:\projects\Majestic\Sonar\config\sonar_build_keys.json
```

Там хранится `build_key`, `obfuscation_seed`, имя exe, путь к exe и путь к архиву.

## 4. Проверить build key в exe или zip

Для exe:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<имя exe>\<имя exe>.exe"
```

Для архива:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<имя exe>\<build_key>-<имя exe>.zip"
```

JSON-вывод для копирования или автоматизации:

```powershell
python scripts\extract_build_key_from_exe.py ".\dist\<app_version>\<имя exe>\<имя exe>.exe" --json
```

## 5. Загрузить архивы на сервер

На сервер загружать надо именно zip, не exe.

Папка на сервере:

```text
/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds/<app_version>
```

Если на ПК настроен SSH key и команда `ssh root@m-sonar-addr.ru` входит без пароля, используйте готовую утилиту:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\upload_build_archives.py --host m-sonar-addr.ru
```

Скрипт сам читает `APP_VERSION` из `src\sonar\version.py` и загружает архивы в `builds/<APP_VERSION>`. Если внутри `dist` есть папка этой версии, скрипт сканирует только `dist/<APP_VERSION>`, чтобы не залить старые локальные архивы. Вместо постоянного `--host` можно задать переменную окружения `SONAR_UPLOAD_HOST`.

Сначала можно проверить, что будет загружено:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --dry-run
```

Если вы пересобираете ту же версию и хотите заменить набор архивов в ее папке, используйте явный флаг очистки:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --replace-version --dry-run
python scripts\upload_build_archives.py --host m-sonar-addr.ru --replace-version
```

Удаление старых version-папок вынесено в отдельный пошаговый гайд: [delete_old_build_versions.md](delete_old_build_versions.md).

Если SSH key не настроен, но вход по паролю работает, добавьте `--allow-password`. Пароль вводится в prompt `ssh/scp`; в команду его не вставляйте:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --allow-password --dry-run
python scripts\upload_build_archives.py --host m-sonar-addr.ru --allow-password
```

Если приватный ключ лежит не в стандартном месте:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --key "$env:USERPROFILE\.ssh\id_ed25519"
```

Если архивы лежат не в `dist`, укажите папку:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --source "C:\path\to\archives"
```

Утилита:

- рекурсивно сканирует `dist`;
- берет только zip с именем `<11 или 64 hex build_key>-<exe name>.zip`;
- создает удаленную папку `builds/<APP_VERSION>`, если ее нет;
- загружает архивы через системные `ssh/scp`;
- не хранит пароль и не требует его, если SSH key настроен.

Ручной вариант без upload-скрипта, если нужно сделать то же самое обычными `ssh/scp` командами:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
$Version = "1.2.3"
$BuildsDir = "/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds/$Version"
$Archives = Get-ChildItem -Path ".\dist" -Recurse -File -Filter "*.zip" |
  Where-Object { $_.Name -match '^(?:[0-9a-f]{11}|[0-9a-f]{64})-.+(?:\.exe)?\.zip$' }
if (-not $Archives) { throw "No build archives found in .\dist" }

ssh root@m-sonar-addr.ru "mkdir -p '$BuildsDir'"
foreach ($Archive in $Archives) {
  scp "$($Archive.FullName)" "root@m-sonar-addr.ru:$BuildsDir/"
}
ssh root@m-sonar-addr.ru "find '$BuildsDir' -maxdepth 1 -type f -name '*.zip' | wc -l && ls -lah '$BuildsDir' | tail"
```

Если удобнее GUI, можно загрузить архивы через WinSCP:

1. Подключитесь к `m-sonar-addr.ru` по SFTP.
2. Откройте `/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds/<app_version>`.
3. Перетащите туда все `*.zip` из локального `dist`.
4. Не загружайте туда случайные zip с другим именем. Сервис принимает только формат `<11 или 64 hex build_key>-<exe name>.zip`.

## 6. Обновить глобальную информацию об обновлении

Глобальный файл на сервере:

```text
/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/sonar-release.json
```

Пример:

```json
{
  "latest_version": "1.2.3",
  "update_message": "🚀 Вышла новая версия\nИсправлен запуск трансляции\nСкачивание отдаст случайную защищенную сборку",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Команды для обновления этого файла через SSH/SCP:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
$ReleaseJsonPath = Join-Path (Get-Location) "sonar-release.json"
$ReleaseJson = @'
{
  "latest_version": "1.2.3",
  "update_message": "🚀 Вышла новая версия\nИсправлен запуск трансляции\nСкачивание отдаст случайную защищенную сборку",
  "download_link": "https://m-sonar-addr.ru/download"
}
'@
$Utf8NoBom = New-Object System.Text.UTF8Encoding -ArgumentList $false
[System.IO.File]::WriteAllText($ReleaseJsonPath, $ReleaseJson, $Utf8NoBom)

ssh root@m-sonar-addr.ru 'cd /var/lib/docker/volumes/sonar-keygen-caddy-data/_data && if [ -f sonar-release.json ]; then cp sonar-release.json sonar-release.json.bak-$(date +%Y%m%d-%H%M%S); fi'
scp "$ReleaseJsonPath" "root@m-sonar-addr.ru:/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/sonar-release.json"
Remove-Item $ReleaseJsonPath
```

`update_message` поддерживает переносы через `\n` и emoji. В интерфейсе строки будут переноситься.

`download_link` должен вести на `/download`, если вы хотите случайную выдачу из папки `builds`.

`download_link` не должен включать номер версии. Публичный URL остается стабильным, а сервер сам выбирает latest version folder.

Не используйте публичный домен со словами `keygen`, `license`, `admin`, `ui`, а также `nip.io`, потому что он раскрывает IP и назначение сервиса. Нормальный вариант: `updates.<ваш-домен>` или `cdn.<ваш-домен>`.

## 7. Проверить сервер

Проверить metadata:

```powershell
curl.exe https://m-sonar-addr.ru/sonar-release.json
```

Проверить количество архивов:

```powershell
curl.exe https://m-sonar-addr.ru/random-build-health
```

Проверить файлы и контейнер прямо на сервере через SSH:

```powershell
ssh root@m-sonar-addr.ru "ls -lah /var/lib/docker/volumes/sonar-keygen-caddy-data/_data/sonar-release.json /var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds"
ssh root@m-sonar-addr.ru "find /var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds -mindepth 1 -maxdepth 1 -type d -printf '%f\n' | sort -V"
ssh root@m-sonar-addr.ru "docker ps --filter name=sonar-random-build-download && docker logs --tail 50 sonar-random-build-download"
```

Нормальный ответ выглядит примерно так:

```json
{
  "ok": true,
  "builds_dir": "/builds",
  "latest_version": "1.2.3",
  "latest_builds_dir": "/builds/1.2.3",
  "version_count": 2,
  "archive_count": 20,
  "invalid_archive_count": 0,
  "total_archive_count": 40
}
```

Если `archive_count` равен `0`, значит в latest version folder нет валидных архивов с именем `<build_key>-<exe name>.zip`.

Проверить скачивание:

```powershell
curl.exe -L -OJ https://m-sonar-addr.ru/api/random-build.zip
```

В заголовке скачивания должен быть файл вида:

```text
<build_key>-<exe name>.zip
```

## 8. Проверить приложение

Запустите локальный exe из `dist` и проверьте:

- приложение стартует;
- имя процесса совпадает с именем exe;
- иконка совпадает с выбранной картинкой из `assets/game_icons`;
- лицензия валидируется;
- на главной странице отображается карточка обновления;
- в карточке есть переносы строк и emoji;
- если `download_link` задан, появляется ссылка скачивания.

## 9. Что делать для разных групп лицензий

Если всем нужна одна версия и одна ссылка, используйте только `sonar-release.json`.

Если разным группам нужны разные тексты, фичи или ссылки, задавайте metadata на policy в Keygen. Подробно это описано в [keygen_license_features.md](keygen_license_features.md).

Для массового `latest_version` не надо редактировать сотни лицензий. Используйте:

- `sonar-release.json`, если версия общая для всех;
- policy metadata, если версия или сообщение отличаются по группе.

License metadata используйте только для исключений у конкретного пользователя.

## 10. Откат обновления

Если новую версию надо скрыть:

1. Откройте `/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/sonar-release.json`.
2. Верните старую версию или очистите поля:

```json
{
  "latest_version": "0.1.0",
  "update_message": "",
  "download_link": ""
}
```

Команды для отката через SSH/SCP:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
$ReleaseJsonPath = Join-Path (Get-Location) "sonar-release.json"
$ReleaseJson = @'
{
  "latest_version": "0.1.0",
  "update_message": "",
  "download_link": ""
}
'@
$Utf8NoBom = New-Object System.Text.UTF8Encoding -ArgumentList $false
[System.IO.File]::WriteAllText($ReleaseJsonPath, $ReleaseJson, $Utf8NoBom)

ssh root@m-sonar-addr.ru 'cd /var/lib/docker/volumes/sonar-keygen-caddy-data/_data && if [ -f sonar-release.json ]; then cp sonar-release.json sonar-release.json.bak-$(date +%Y%m%d-%H%M%S); fi'
scp "$ReleaseJsonPath" "root@m-sonar-addr.ru:/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/sonar-release.json"
Remove-Item $ReleaseJsonPath
```

3. Если metadata была задана в Keygen policy, уберите или измените ее там тоже.

Caddy перезапускать не нужно, если менялся только JSON.

## 11. Повторить конкретную сборку пользователя

Если пользователь прислал exe или zip:

1. Извлеките build key:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\extract_build_key_from_exe.py "C:\path\to\user-file.exe"
```

2. Найдите `obfuscation_seed` в:

```text
P:\projects\Majestic\Sonar\config\sonar_build_keys.json
```

3. Соберите точно с тем же ключом и seed:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall -BuildKey "<build_key>" -ObfuscationSeed "<seed>"
```

При таком запуске повторяются build key, seed обфускации, encrypted literals, имя exe и иконка.
