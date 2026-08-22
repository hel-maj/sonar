# Удаленная блокировка запуска

Этот механизм нужен только для мягкой блокировки запуска. Программа не удаляет себя, не меняет свои файлы, не чистит конфиги и не повреждает установку. Если текущий build key или license key попал в серверный список блокировки, основное окно не открывается. Вместо него показывается отдельное окно Sonar с текстом:

```text
Возможно у вас взломанная версия программы, обновите до последней версии: <ссылка>
```

Ссылка кликабельная и должна вести на актуальную страницу скачивания, обычно `https://m-sonar-addr.ru/download`.

## Как работает проверка

1. При запуске приложение сначала проверяет лицензию обычным способом.
2. Затем до создания `MainWindow` выполняется отдельный POST-запрос на startup block URL.
3. Этот URL не берется из `download_link` и не выводится из `/download`. Он вшивается в сборку отдельно как `startup_block_url`.
4. Клиент отправляет на endpoint текущие `build_key`, `build_hash`, `app_name` и сохраненный `license_key`.
5. Сервер читает приватный JSON blocklist, сравнивает build/license key и формирует ответ.
6. Ответ подписывается Ed25519 private key на сервере.
7. Клиент проверяет подпись pinned Ed25519 public key, вшитым в сборку.
8. Если подпись валидна и `blocked: true`, основное окно не создается, показывается только окно блокировки.
9. Во время работы приложение повторяет ту же проверку каждые 5 минут. Если пришел валидный подписанный ответ `blocked: true`, основной UI скрывается, активные runtime-задачи останавливаются, и показывается окно блокировки.

Endpoint остается обязательным условием первого запуска текущей сессии. Если при стартовой проверке endpoint недоступен, вернул HTTP-ошибку, прислал невалидный JSON или подпись не прошла проверку, проверка считается непрошедшей, основной интерфейс не открывается, а приложение показывает окно обновления. После успешного открытия основного окна сетевые ошибки повторной проверки не скрывают UI: работающее приложение блокируется только по валидному подписанному ответу `blocked: true`.

## Формат ответа сервера

Endpoint возвращает JSON только с решением, ссылкой и подписью:

```json
{
  "blocked": true,
  "download_url": "https://m-sonar-addr.ru/download",
  "signature": "<base64url-ed25519-signature>"
}
```

Если блокировки нет:

```json
{
  "blocked": false,
  "download_url": "",
  "signature": "<base64url-ed25519-signature>"
}
```

Подписывается canonical JSON без поля `signature`, с отсортированными ключами и без пробелов:

```json
{"blocked":true,"download_url":"https://m-sonar-addr.ru/download"}
```

или:

```json
{"blocked":false,"download_url":""}
```

## Где хранится список блокировки

Blocklist хранится на сервере в отдельном JSON-файле, например:

```text
/opt/sonar-keygen/startup-blocklist.json
```

Файл не должен лежать в публичной web-root директории и не должен отдаваться Caddy/Nginx напрямую. HTTP-доступ должен быть только к endpoint `/api/startup-block`, который читает этот файл локально и возвращает подписанное решение.

Пример blocklist:

```json
{
  "build_keys": [
    "abc123def45"
  ],
  "license_keys": [
    "FA5B1-ABCDE-G2K34"
  ],
  "download_url": "https://m-sonar-addr.ru/download"
}
```

`build_keys` сравниваются без учета регистра. `license_keys` сравниваются как точные строки после trim.

## Как обновить список заблокированных ключей

1. Подключитесь к серверу по SSH.
2. Откройте приватный файл blocklist, например `/opt/sonar-keygen/startup-blocklist.json`.
3. Добавьте build key в `build_keys` или license key в `license_keys`.
4. Проверьте JSON-синтаксис:

```bash
jq empty /opt/sonar-keygen/startup-blocklist.json
```

5. Если download URL изменился, обновите `download_url`.
6. Перезапуск приложения на клиенте не обязателен: работающие клиенты повторяют проверку каждые 5 минут.

## Настройка native-сборки

Целевой клиент реализован в C# в `src/dotnet/Sonar.Fishing.Host/StartupGate/` и
проверяет подпись через exact-pinned `Sonar.Licensing.Verification 0.1.3`.
Offline build и acceptance:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_dotnet.ps1
powershell -ExecutionPolicy Bypass -File .\scripts\test_dotnet.ps1
```

Эти команды не подставляют production endpoint/key и не выполняют сетевой
запрос. Demo/offline composition остается network-denied. Реальный HTTPS URL,
32-byte Ed25519 public key, build identity и release policy должны быть
встроены product release pipeline как подписанные/immutable metadata; отсутствие
любого из них обязано оставлять production startup fail closed. Точный wiring
отслеживается как `H04` в
`docs/architecture/PRODUCTION_CUTOVER_CHECKLIST.md`.

Private key хранится только на сервере в
`SONAR_STARTUP_BLOCK_PRIVATE_KEY`. В EXE, bundle, client config и репозиторий
его не добавлять. Legacy build parameters и executable tooling удалены из
product graph; целевой build contract принадлежит PowerShell/.NET/CMake
entrypoints.

## Проверка Ed25519-подписи

Клиент делает так:

1. Берет из ответа поля `blocked` и `download_url`.
2. Строит exact UTF-8 canonical JSON без пробелов в порядке `blocked`,
   `download_url`.
3. Декодирует `signature` из base64url.
4. Проверяет Ed25519 подпись pinned public key.
5. Доверяет `blocked` только если проверка подписи успешна.

Подмена `blocked`, `download_url` или самой подписи приводит к отказу проверки, и клиент не применяет блокировку.

При обязательной проверке отказ проверки не означает "можно запускать". Он означает, что проверка не пройдена, поэтому основной интерфейс не должен работать до успешного подписанного ответа `blocked: false`.
