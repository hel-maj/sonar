# Native Engine IPC session control

Статус: deterministic native admission/lifecycle slice; live GTA, capture и
physical input не подключены.

## Контракт

Engine выбирает один immutable bootstrap mode до подключения pipes:

- `offline_diagnostics` - `diagnostic_mode=true`, side-effect support не
  рекламируется, capability `fishing-session.control` отсутствует;
- `production` - `diagnostic_mode=false`, side-effect support и
  `fishing-session.control` 1.0 рекламируются только после принятого native
  production bootstrap mode. Этот mode также требует exact
  `SONAR_FISHING_HOST_BUILD_ID`, `SONAR_FISHING_ENGINE_BUILD_ID` и
  `SONAR_FISHING_BUNDLE_MANIFEST_HASH`; offline identity в production
  handshake не переиспользуется.

Host acceptance может включить side effects только во втором mode. Даже тогда
`StartFishingSessionRequest` остается fail-closed, пока одновременно не
выполнены все условия:

1. handshake действительно negotiated `side_effects_enabled=true`;
2. `expected_revision` не равен нулю и точно совпадает с atomically accepted
   runtime-settings revision;
3. current settings snapshot существует;
4. Engine принял signed entitlement с ненулевой generation;
5. entitlement еще не истек по Engine system clock.

Offline mode сохраняет отдельный read-only `StartEngineSession` diagnostic.
Product `StartFishingSessionRequest` в нем возвращает typed rejection и не
может повысить authority.

## Ordering и state ownership

Управление остается coarse:

```text
StartFishingSessionRequest (command_id=start-fishing-session)
  -> CONTROL CommandResult
  -> exactly one queued EVENTS FishingSessionSnapshot

StopAutomation (command_id=stop-automation)
  -> CONTROL CommandResult
  -> exactly one queued EVENTS FishingSessionSnapshot
```

`FishingSessionLifecycle` является единственным owner состояния
idle/running. Accepted start pin-ит settings revision и entitlement generation;
duplicate start fail-closed. Stop idempotent, останавливает session timer и
очищает pinned revisions. Rejected start тоже публикует один current aggregate,
но не меняет state.

Snapshot delivery использует существующий bounded latest-only writer. Поэтому
одна команда делает ровно одну публикацию aggregate, но transport вправе
coalesce-ить устаревший snapshot того же topic при backpressure.

## Safety boundary

Этот slice не конструирует live observer, capture source, mutation adapter или
input lease и не вызывает whole fishing episode. Current production Keygen RSA
trust root по-прежнему отсутствует, поэтому реальный production entitlement и
accepted start остаются закрыты. Перед будущим live composition нужны отдельные
continuous entitlement/settings/window/focus gates непосредственно у final
mutation port и fresh readiness-gated acceptance.

## Offline tests

`SonarFishingSessionControlTests` компилируется с `/W4 /WX` и проверяет:

- exact offline/production handshake flags и capability advertisement;
- rejection каждого production admission gap;
- expiry boundary и exact settings revision;
- accepted start, duplicate-start rejection, stop и idempotent stop;
- очистку pinned settings/entitlement state.

`sonar_fishing.ipc.offline_authority_gate` дополнительно доказывает, что Engine
без явного bootstrap mode по-прежнему завершается fail-closed.
