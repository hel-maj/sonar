# H08: подписанная транзакция обновления Sonar Fishing

Статус: offline core verified, production activation partial

Дата проверки: 2026-08-22

## Граница ответственности

Host владеет проверкой подписанного release manifest, загрузкой и staging.
Активация выполняется только после завершения обычных Host/Engine процессов:
работающий `Sonar.exe` не пытается заменить собственный файл. Product release
pipeline по-прежнему владеет подписью готовой пары, final bundle и внешним
after-exit activator. Container может только вызвать каноническую product
команду и не дублирует эту семантику.

В manifest версии `1` подпись Ed25519 покрывает canonical JSON со следующими
полями: product, canonical semantic version, строго возрастающая generation и
ровно три payload в фиксированном порядке:

1. `Sonar.Engine.exe`;
2. `Sonar.exe`;
3. `bundle-manifest.json`.

Для каждого payload подписаны имя, размер, SHA-256 и HTTPS URL. Неизвестное
поле, duplicate JSON property, HTTP, userinfo, fragment, payload больше
512 MiB, неправильный порядок или повтор version/generation валят проверку.
Raw envelope ограничен 64 KiB. Ключ проверки передается через Common
`Ed25519DetachedSignatureVerifier`; приватный ключ и signing operation в
продукт не входят.

## Staging, swap и recovery

`HttpReleasePayloadSource` получает только response headers, требует `200`,
точный `Content-Length` и безопасный конечный HTTPS URI. `ReleasePayloadStager`
стримит каждый файл в direct-child `.update-<32 hex>`, ограничивает число байт
подписанным размером и проверяет SHA-256 до выдачи staging lease.

`ReleaseSwapTransaction` сохраняет текущие три release payload в matching
`.rollback-<id>`, переносит проверенную новую пару и manifest, проверяет
steady-state allowlist и удаляет transaction state. Исключение немедленно
возвращает старую согласованную тройку. `ReleaseSwapRecovery` на следующем
безопасном старте распознает только одну точную generation, откатывает
частичный swap и удаляет staging/backup. Неизвестный файл, каталог, reparse
point или неоднозначная transaction generation валит операцию fail closed.

Пользовательские `config/state.dat` и файлы внутри `logs/` не перемещаются и
не удаляются обновлением. `SafeUninstallPlan` лишь формирует точный проверенный
план после ввода фразы `УДАЛИТЬ SONAR FISHING`; текущий Host не удаляет себя и
не содержит recursive self-delete.

## Offline acceptance

`scripts/test_dotnet.ps1` выполняет fake-only transport/filesystem matrix без
сети, запуска внешнего процесса или изменения установленного продукта:

- exact canonical manifest, signature и unsafe-input rejection;
- headers-only HTTP source и mismatch `Content-Length`;
- bounded staging, size/hash verification и lease cleanup;
- version + generation replay rejection;
- successful swap с сохранением state/logs и exact allowlist;
- exception rollback и recovery после прерванной generation;
- exact-confirmation uninstall plan и unsafe-root/loose-path rejection.

Последний полный результат: `136/136` WPF/Host tests, managed warnings/errors
`0/0`. Этот результат не означает production update acceptance.

## Осталось до production authority

- выдать точный production Ed25519 public key и release metadata endpoint;
- встроить вызов проверки/staging в licensed production composition;
- реализовать и подписать after-exit activator/uninstaller без третьей loose
  steady-state dependency;
- прогнать signed two-EXE install, normal update, interrupted update, recovery,
  remote rollback и uninstall matrix;
- после каждого сценария повторить exact allowlist, no-Python, process-tree,
  `%TEMP%\.net`, signature и secret scans.

До этих gates UI может отображать только недоступное/проверяемое состояние;
offline/demo режим не выполняет network, swap или uninstall side effect.
