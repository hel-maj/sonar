# Случайная выдача готовых build archives

Эта схема используется для скачивания обновления:

```text
пользователь открывает /download -> сервер выбирает случайный zip из builds -> браузер скачивает выбранный zip
```

На сервере не запускается сборка и не создается zip на лету. Все архивы должны быть подготовлены заранее локальной сборкой.

## Где лежат архивы на сервере

```text
/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds
```

В эту папку кладутся только готовые build archives:

```text
<build_key>-<exe name>.zip
```

Пример:

```text
bd68400c3c8ad1380fed102e28afd5d6a02451cf58d9fdddb01c4b098164cd4b-Warhammer 40,000 - Darktide.exe.zip
```

Внутри архива лежит exe:

```text
Warhammer 40,000 - Darktide.exe
```

## Как создать такие архивы

Один билд:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall
```

Много билдов:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 -SkipInstall --count 20
```

После сборки в каждой папке `dist\<имя>` будет:

```text
<имя>.exe
<build_key>-<имя>.exe.zip
```

Загружать на сервер надо zip-файлы.

## Как сервер выбирает файл

Сервис смотрит папку `builds` рекурсивно и берет только zip, имя которых подходит под шаблон:

```text
64-hex-build-key + "-" + имя exe + ".zip"
```

Файлы вроде `test.zip`, `Sonar.zip`, `old-build.zip` игнорируются.

Если валидных архивов нет, `/api/random-build.zip` вернет ошибку `No build .zip archives found`.

## Публичные URL

Страница с loader:

```text
https://m-sonar-addr.ru/download
```

Прямая ссылка на случайный архив:

```text
https://m-sonar-addr.ru/api/random-build.zip
```

Проверка статуса:

```text
https://m-sonar-addr.ru/random-build-health
```

`m-sonar-addr.ru` - текущий домен релиза. Для будущих доменов используйте нейтральное имя без слов `keygen`, `license`, `admin`, `ui` и без `nip.io`.

Полный список доступных URL лежит отдельно:

```text
docs/guides/available_urls.md
```

На сервере выдачей занимается Docker-контейнер `sonar-random-build-download` в сети `sonar-keygen`.
Caddy проксирует `/download`, `/api/random-build.zip` и `/random-build-health` в этот контейнер.

Проверить контейнер на сервере:

```bash
docker ps --filter name=sonar-random-build-download
docker logs --tail 50 sonar-random-build-download
```

## Что писать в download_link

В `sonar-release.json` или Keygen metadata указывайте:

```json
{
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Так пользователь увидит loader, а потом браузер начнет скачивание.

## Загрузка архивов через SSH key

Если `ssh root@m-sonar-addr.ru` входит без пароля, загрузить все архивы из `dist` можно так:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\upload_build_archives.py --host m-sonar-addr.ru
```

Вместо постоянного `--host` можно задать переменную окружения `SONAR_UPLOAD_HOST`.

Проверить без загрузки:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --dry-run
```

Если ключ лежит не в стандартном месте:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --key "$env:USERPROFILE\.ssh\id_ed25519"
```

Если архивы лежат в отдельной папке:

```powershell
python scripts\upload_build_archives.py --host m-sonar-addr.ru --source "C:\path\to\archives"
```

Утилита использует системные `ssh/scp`, поэтому работает с обычными ключами из `.ssh`, `ssh-agent` и настройками OpenSSH.

Если SSH key не настроен, используйте WinSCP и загрузите архивы вручную.

## Проверка скачанного архива

Скачать:

```powershell
curl.exe -L -OJ https://m-sonar-addr.ru/api/random-build.zip
```

Вытащить build key из скачанного zip:

```powershell
cd P:\projects\Majestic\Sonar\02_sonar_app
python scripts\extract_build_key_from_exe.py "C:\path\to\<build_key>-<exe name>.zip"
```

Сверить seed:

```text
P:\projects\Majestic\Sonar\config\sonar_build_keys.json
```




