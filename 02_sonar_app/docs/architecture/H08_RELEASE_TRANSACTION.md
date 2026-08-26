# H08: подписанная транзакция обновления Sonar Fishing

Статус: offline core, local development и local-access maintenance verified;
production signed activation partial

Дата проверки: 2026-08-24

## Граница ответственности

Host владеет проверкой подписанного release manifest, загрузкой и staging.
Активация выполняется только после завершения обычных Host/Engine процессов:
работающий `Sonar.exe` не пытается заменить собственный файл. Product release
pipeline по-прежнему владеет подписью готовой пары, final bundle и внешним
after-exit activation policy. `Sonar.exe --release-maintenance` является
product-owned bounded executor: он запускается из проверенного source bundle,
ждёт максимум два точных PID и не поднимает UI, Engine, network, Telegram или
product runtime. Container может только вызвать каноническую product команду и
не дублирует эту семантику.

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
частичный swap и удаляет staging/backup. Steady-state validator
разрешает только direct `config/state.dat` и direct lowercase `logs/*.log`;
вложенный каталог, loose runtime file, любой reparse point или
неоднозначная transaction generation валит операцию fail closed.

Пользовательские `config/state.dat` и файлы внутри `logs/` не перемещаются и
не удаляются обновлением. `SafeUninstallPlan` лишь формирует точный проверенный
план после ввода фразы `УДАЛИТЬ SONAR FISHING`; текущий Host не удаляет себя и
не содержит recursive self-delete.

## Локальная install/update/rollback/recovery

`scripts/invoke_local_release_maintenance.ps1` требует свежий явный
`-DevelopmentUnsigned`. Обычный канал принимает только
`development-unsigned`; отдельный compile-isolated канал дополнительно требует
`-DeveloperFullAccess` и принимает только
`developer-full-access-unsigned` schema 2 с exact marker. Каналы не принимают
manifest, target или backup друг друга. `DevelopmentBundleVerifier` повторно
проверяет exact manifest schema, пару build IDs, SHA-256 обоих EXE, determinism
claim и отсутствие production-signature claim. Executor допускает ровно одну операцию:

- `Install` атомарно создаёт новую установку через sibling staging directory;
- `Update` сохраняет предыдущую проверенную тройку во внешний новый backup и
  применяет source через тот же `ReleaseSwapTransaction`;
- `Rollback` применяет явно выбранный проверенный backup и сохраняет текущую
  тройку в новый backup;
- `Recover` запускает fail-closed `ReleaseSwapRecovery` для одной точной
  interrupted generation;
- `ImportLicense` сохраняет только legacy `license_key` в DPAPI state. Legacy
  id, role, group, features, denial list и timestamps не считаются trust.

Product wrapper разрешает source, target и backup только как строгие потомки
канонического ignored-каталога `build/`. Сам `build/`, `scripts/`, `src/`,
внешние пути, файл вместо каталога и любой существующий reparse-компонент
отклоняются до создания receipt и запуска executor. Source, target и backup не
могут совпадать или содержать друг друга. Update/rollback не удаляют backup;
его lifecycle остаётся явным действием оператора. После non-dry-run wrapper
повторяет allowlist/no-Python lifecycle gate и пишет только sanitized receipt
без путей, PID или секретов. Это не подменяет production signing: без
сертификата и подписанных release metadata production-signed mode отвергается.

Фактическая local-access acceptance 2026-08-26 прошла на изолированной
установке: `1.0.0-local` install, update до `1.0.1-local`, rollback,
повторный update, финальный update до `1.0.2-local` и восстановление намеренно
прерванной generation. После каждого этапа allowlist/no-Python gate был зелёным;
`config/state.dat` и owned log сохранились, transaction residue после recovery
равен нулю. Установленная `1.0.2-local` дополнительно пережила принудительное
завершение Engine: Host поднял новое поколение без replay команд, сохранил
настройки и снова опубликовал inventory snapshot.

После exact repin на Common CEF inventory `0.1.18` и UI Kit `0.2.21` собран
deterministic `1.0.3-local` и выполнен фактический `Update` установленной
`1.0.2-local` с отдельным backup. Transaction вернул `accepted/updated`,
сохранил owned user state и повторно прошёл `Updated` allowlist/no-Python gate.
Затем из установленной `1.0.3-local` выполнен отдельный 30-секундный lifecycle:
неожиданное завершение Engine было восстановлено новым поколением, оба запуска
закончились normal exit, transaction residue и loose runtime files отсутствуют.

## Offline acceptance

`scripts/test_dotnet.ps1` выполняет fake-only transport/filesystem matrix без
сети, запуска внешнего процесса или изменения установленного продукта:

- exact canonical manifest, signature и unsafe-input rejection;
- headers-only HTTP source и mismatch `Content-Length`;
- bounded staging, size/hash verification и lease cleanup;
- version + generation replay rejection;
- successful swap с сохранением state/logs и exact allowlist;
- exception rollback и recovery после прерванной generation;
- rejection вложенных/loose runtime artifacts и reparse-point payload;
- exact-confirmation uninstall plan и unsafe-root/loose-path rejection;
- development bundle tamper rejection, local install/update/rollback,
  interrupted recovery, сохранение state/logs и key-only legacy license import;
- wrapper path-policy rejection для `scripts/`, `src/`, внешнего каталога,
  build-root, wrong path type и junction без filesystem mutation;
- bounded after-exit argument/PID/receipt contract.

На 2026-08-24 focused Host suite после local-maintenance slice зелёна:
`209/209`, managed warnings/errors `0/0`. Offline release plumbing прогоняет тот же exact
allowlist/no-Python validator для `FirstActivation`, `NormalExit`,
`CrashRecovery`, `Updated`, `InterruptedUpdateRecovery` и `RemoteRollback`.
Network-inert demo Host фактически подтвердил `FirstActivation`, а
manifest-bound packaged Engine — crash/replacement/cleanup и
`CrashRecovery`. Product-owned development-unsigned wrapper фактически прошёл
`Installed`, `Updated`, `RemoteRollback` и synthetic
`InterruptedUpdateRecovery` на изолированной local installation; state/logs,
allowlist, no-Python и отсутствие transaction residue проверены после каждого
этапа. Это всё ещё не означает production-signed installer/update acceptance.

## Осталось до production authority

- выдать точный production Ed25519 public key и release metadata endpoint;
- встроить вызов проверки/staging в licensed production composition;
- подписать и принять production after-exit activation path; local
  development-unsigned executor уже реализован без третьей loose steady-state
  dependency;
- реализовать confirmation-gated after-exit uninstall executor;
- предоставить Authenticode certificate thumbprint и HTTPS timestamp
  endpoint; текущие development EXE честно имеют `NotSigned`;
- прогнать signed two-EXE install, normal update, interrupted update, recovery,
  remote rollback и uninstall matrix;
- после каждого сценария повторить exact allowlist, no-Python, process-tree,
  `%TEMP%\.net`, signature и secret scans.

До этих gates UI может отображать только недоступное/проверяемое состояние;
offline/demo режим не выполняет network, swap или uninstall side effect.
