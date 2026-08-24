# Sonar Fishing docs

Документация относится к текущему WPF/C++ продукту. Python-era build, test,
wheelhouse, upload и diagnostic guides удалены вместе с legacy product owner.
Исторические ссылки внутри migration evidence описывают baseline, а не
действующий entrypoint.

## Архитектура и миграция

- [Product ADR: WPF Host и C++ Engine](architecture/ADR-0001-WPF-CSHARP-CPP-ENGINE.md)
- [Compile-isolated developer authority](architecture/ADR-0002-DEVELOPER-FULL-ACCESS-AUTHORITY.md)
- [Bounded Engine notification events](architecture/ADR-0003-BOUNDED-ENGINE-NOTIFICATION-EVENTS.md)
- [Code-backed Engine migration evidence](architecture/ENGINE_MIGRATION.md)
- [Production cutover checklist](architecture/PRODUCTION_CUTOVER_CHECKLIST.md)
- [Performance evidence и safe optimization](architecture/MIGRATION_PERFORMANCE.md)
- [Machine-readable runtime authority](migration/runtime-authority.json)
- [Historical effective behavior fixture](migration/effective-python-behavior.json)

## Engine capabilities

- [Fishing stage detection](architecture/FISHING_STAGE_DETECTION.md)
- [Coherent memory observation](architecture/MEMORY_OBSERVATION_NATIVE.md)
- [Controlled inventory-state characterization](architecture/INVENTORY_STATE_CHARACTERIZATION.md)
- [Whole fishing episode](architecture/FISHING_EPISODE_NATIVE.md)
- [Inventory/store episode](architecture/INVENTORY_STORE_EPISODE.md)
- [Maintenance episodes](architecture/MAINTENANCE_EPISODES.md)

## Host и release

- [Streaming runtime](architecture/H07_STREAMING_RUNTIME.md)
- [Signed release transaction](architecture/H08_RELEASE_TRANSACTION.md)
- [Native release pipeline](architecture/NATIVE_RELEASE_PIPELINE.md)
- [UI parity ledger](architecture/UI_PARITY_LEDGER.md)
- [Common UI primitive delta](architecture/UI_PRIMITIVE_DELTA.md)

## Product operations

Канонические setup/test/build/run/package/smoke команды перечислены в
[README](../README.md) и `product-commands.json`. Product release не выполняет
upload автоматически.

Backend/license documents, не являющиеся build entrypoints:

- [Ключи подписки](subscription_keys.md)
- [Keygen feature policy](guides/keygen_license_features.md)
- [Remote startup block contract](guides/remote_startup_block.md)
- [Доступные backend URL](guides/available_urls.md)
