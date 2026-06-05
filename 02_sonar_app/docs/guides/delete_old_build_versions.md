# Удаление старых version-папок build archives

Этот гайд нужен, когда на сервере накопились старые папки в:

```text
/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds
```

Публичные URL `/download` и `/api/random-build.zip` отдают только latest version folder, но старые папки всё равно занимают диск. Удалять надо именно папки версий, а не отдельные zip внутри latest version folder.

## 1. Проверить активную версию

```powershell
curl.exe https://m-sonar-addr.ru/random-build-health
curl.exe https://m-sonar-addr.ru/sonar-release.json
```

В `random-build-health` проверьте:

```json
{
  "latest_version": "1.2.3",
  "latest_builds_dir": "/builds/1.2.3",
  "archive_count": 20
}
```

Не удаляйте папку, которая указана в `latest_builds_dir`.

## 2. Посмотреть version-папки на сервере

```powershell
$BuildsDir = "/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds"
ssh root@m-sonar-addr.ru "find '$BuildsDir' -mindepth 1 -maxdepth 1 -type d -printf '%f\n' | sort -V"
```

Если в списке есть файлы zip прямо в корне `builds`, это legacy layout. Сначала перенесите их в папку текущей версии, потом удаляйте старое.

## 3. Сначала переместить старую папку в trash

Так безопаснее, чем сразу делать `rm -rf`: после перемещения можно проверить, что скачивание всё ещё работает.

```powershell
$BuildsDir = "/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds"
$TrashDir = "/root/sonar-builds-trash"
$VersionToDelete = "0.1.0"
$TrashName = "$VersionToDelete-$(Get-Date -Format yyyyMMdd-HHmmss)"

ssh root@m-sonar-addr.ru "mkdir -p '$TrashDir' && test -d '$BuildsDir/$VersionToDelete' && mv -- '$BuildsDir/$VersionToDelete' '$TrashDir/$TrashName'"
```

## 4. Проверить после перемещения

```powershell
curl.exe https://m-sonar-addr.ru/random-build-health
ssh root@m-sonar-addr.ru "find '$BuildsDir' -mindepth 1 -maxdepth 1 -type d -printf '%f\n' | sort -V"
```

Нормально, если `version_count` уменьшился. `archive_count` должен оставаться больше нуля.

Если надо проверить реальное скачивание, скачайте один архив во временный файл и удалите его:

```powershell
$CheckZip = Join-Path $env:TEMP "sonar-random-build-check.zip"
curl.exe -L -o "$CheckZip" https://m-sonar-addr.ru/api/random-build.zip
Remove-Item -LiteralPath "$CheckZip" -Force
```

## 5. Окончательно удалить из trash

Делайте это только после проверки `/random-build-health` и тестового скачивания.

```powershell
ssh root@m-sonar-addr.ru "rm -rf -- '$TrashDir/$TrashName'"
```

## 6. Удалить несколько старых версий

Сначала явно перечислите версии:

```powershell
$VersionsToDelete = @("0.1.0", "0.1.1")
```

Потом переместите их в trash:

```powershell
$BuildsDir = "/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds"
$TrashDir = "/root/sonar-builds-trash"

foreach ($VersionToDelete in $VersionsToDelete) {
  $TrashName = "$VersionToDelete-$(Get-Date -Format yyyyMMdd-HHmmss)"
  ssh root@m-sonar-addr.ru "mkdir -p '$TrashDir' && test -d '$BuildsDir/$VersionToDelete' && mv -- '$BuildsDir/$VersionToDelete' '$TrashDir/$TrashName'"
}
```

После проверки health удалите trash-копии вручную:

```powershell
ssh root@m-sonar-addr.ru "ls -lah '$TrashDir'"
ssh root@m-sonar-addr.ru "rm -rf -- '$TrashDir/<trash-folder-name>'"
```

## 7. Если случайно переместили не ту версию

Вернуть папку из trash:

```powershell
$BuildsDir = "/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds"
$TrashDir = "/root/sonar-builds-trash"
$TrashName = "1.2.3-20260605-120000"
$RestoreVersion = "1.2.3"

ssh root@m-sonar-addr.ru "mv -- '$TrashDir/$TrashName' '$BuildsDir/$RestoreVersion'"
curl.exe https://m-sonar-addr.ru/random-build-health
```
