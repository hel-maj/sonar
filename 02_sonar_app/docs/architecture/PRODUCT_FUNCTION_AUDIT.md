# Аудит пользовательских функций Sonar Fishing

Статус: current native implementation audited offline

Дата проверки: 2026-08-24

Этот документ отделяет реально доступные функции исторической Python-версии от
текущего native owner и внешних runtime prerequisites. Наличие UI, router или
fake adapter не считается работающей production-функцией.

Compile-isolated local-access bundle снимает только внешние licensing/entitlement
и signed startup availability/update-block admission gates
и не меняет строки этой матрицы: отсутствующий adapter или неподтверждённые
GTA semantic anchors остаются недоступными, а все memory/window/capture/input safety gates
остаются обязательными. Product UI показывает `Локальный доступ` без key prompt,
raw feature IDs и build terminology; техническая identity остается в manifest и
diagnostics. См. [ADR-0002](ADR-0002-DEVELOPER-FULL-ACCESS-AUTHORITY.md).

## Матрица parity

| Legacy capability | Native owner | Runtime dependency | Проверено / осталось |
| --- | --- | --- | --- |
| Обычный запуск приложения | `Sonar.exe` без аргументов + supervised `Sonar.Engine.exe` | .NET Desktop Runtime 10 x64; startup admission | Product command и package contract есть. Offline demo cycles и inert packaged Engine crash/replacement проверяются отдельно; normal launch зависит от реального startup endpoint |
| Запуск/остановка рыбалки из UI и hotkey | одна coarse Engine automation session; Host и global hotkey вызывают тот же command | подписанная entitlement, Common trusted GTA module, unique semantic player/replay/fish anchors, exact process/window generation, foreground и final input gates | Реализация и offline state-machine/IPC gates есть; availability больше не зависит от GTA hash/version/size/timestamp. Нужны свежая live semantic capture и отдельная physical-input acceptance |
| Catch/inventory/menu/mini-game/meal/bait/equipment/statistics | C++ production episodes + revisioned aggregate IPC; session statistics только в памяти | та же live authority; authentic UI/game evidence | Отдельный Engine worker получает Common 0.1.19 product-neutral inventory snapshot (open, weight, grid, items/images/metadata) и публикует latest-changed typed event; Host не вызывает мелкие read RPC. Reeling path остаётся независимым и не блокируется cold inventory discovery. Обычная и Local Access композиции используют одинаковые publisher/file/process/generation gates; identity admission не привязан к exact profile. Incomplete/unstable evidence публикуется unavailable без stale replay. Menu/mini-game/current-frame automation geometry остаются product-owned. Confirmed fish `1 -> 0` commit-ится только после coherent success. Полная матрица: [runtime observation parity](RUNTIME_OBSERVATION_PARITY.md) |
| Настройки и hotkeys | Host state coordinator, atomic `config/state.dat`, DPAPI secrets, revisioned Engine apply | текущий Windows user | Save/coalescing, rapid toggle, navigation/focus и hotkey lifecycle покрываются managed tests; live hotkey side effect не выполнялся |
| Legacy license settings | `LegacyLicenseKeyImporter` через local maintenance command | точный существующий `license_settings.json`; backend для повторной проверки | Импортируется только `license_key` в DPAPI state. Legacy id/role/features/dates никогда не становятся trust evidence; source сохраняется |
| Лицензирование | Common verification + product HTTPS transport/cache + independent Engine admission | действующий backend response и entitlement | Полный offline signature/cache/revocation contract есть; production credential/backend acceptance внешняя |
| Telegram transport, меню, start/stop, statistics, tackle | bounded HTTPS long poll + `TelegramCommandDispatcher` + native fishing use case | token/admin IDs, feature entitlement, сеть | Credential-independent routing/composition покрыты. Реальный transport требует пользовательскую конфигурацию |
| Telegram automatic catch/start-stop/meal/inventory/bait/focus notifications | typed production Engine occurrence stream -> current-generation supervisor source -> bounded Host publisher | те же token/admin IDs/network плюс authentic production Engine facts | Producer, wire, generation/sequence dedupe, no-replay и send-failure isolation покрыты offline. Фото не делается. Реальная сеть не запускалась; live GTA event delivery остается acceptance |
| Telegram player status / rescan | DTO/formatters существуют, production coarse Engine query отсутствует | authenticated WebEngine semantics + new coarse aggregate IPC operation | Legacy команда была product-facing; сейчас menu скрывает capability и dispatcher fail-closed. Нельзя подменять Host-side memory read |
| Telegram screenshot | production adapter отсутствует | отдельный fresh capture gate, exact target/generation and privacy policy | Legacy команда была product-facing; current router сохраняет intent, но menu скрывает его и direct call rejects |
| Telegram focus game | production adapter отсутствует | exact target/generation + user-approved foreground activation | Legacy команда была product-facing; Host-side `SetForegroundWindow` shortcut запрещён, нужен coarse Engine operation и final gate |
| Telegram close game | production adapter отсутствует | exact process generation, explicit destructive policy and confirmation semantics | Legacy команда была product-facing; current route не рекламируется и rejects |
| Telegram shutdown PC | production adapter отсутствует | authenticated admin, explicit destructive policy, final confirmation and OS authority | Legacy команда была product-facing; намеренно не реализована как неограждённый Host shortcut |
| Streaming capture/HLS/public link/chat mode | `StreamingRuntimeController`; compile-isolated Local Access composition embeds hash-pinned FFmpeg 8.1.1/cloudflared 2026.5.2, resolves one current GTA HWND, serves authenticated secret-path loopback HLS/viewer and launches contained encoder/tunnel. Ordinary licensed composition uses `UnavailableStreamingController`; chat bridge is unavailable | current GTA HWND/client bounds, exact embedded resources, authenticated loopback path, bounded safe HTTPS endpoint and Common Job containment; live capture/network/recovery acceptance remains separate | Legacy process/network path is now present for Local Access without Python or loose runtime dependencies. It is offline-built/tested, not yet live-accepted. Ordinary licensed streaming remains unavailable pending redistribution/signing policy; chat remains unavailable |
| Local install/update/rollback/interrupted recovery | product-owned local maintenance executor + общий `ReleaseSwapTransaction` | exact development-unsigned bundle; production path дополнительно требует signing/backend metadata | Product wrapper фактически прошёл isolated install/update/rollback/interrupted recovery с allowlist/no-Python после каждого этапа; production-signed activation не имитируется |
| Remote signed update | signed manifest/stager/swap core | production public key, metadata endpoint, Authenticode certificate/timestamp and signed distribution acceptance | Core проверен fake transport/filesystem. Remote production composition остаётся fail-closed |
| Game overlay | отсутствовал как product-facing legacy owner и отсутствует в native composition | не применимо | `overlay` в legacy встречался только как detector rejection term и Pillow visual layer; game/stream overlay window, toggle или consumer не найден. Поэтому Fishing overlay нечего активировать или визуально принимать |

## Почему Telegram gaps не закрыты Host-side WinAPI

Screenshot, game focus, player-memory scan и game shutdown относятся к одному
exact process/window generation и safety lifecycle. Разнести observation,
foreground activation и side effect по Host callbacks означало бы потерять
generation/final-gate invariant. Их target state — отдельные coarse Engine
operations с bounded aggregate result. PC shutdown дополнительно требует
отдельной destructive-command policy; наличие старого callback не является
достаточной авторизацией.

## Streaming boundary

Историческая версия могла скачать и запустить FFmpeg/cloudflared. Local Access
теперь встраивает exact hash-pinned FFmpeg 8.1.1 и cloudflared 2026.5.2 в
`Sonar.exe`, materialize-ит их только во временную owned session, проверяет hash,
использует Win32 HWND capture, authenticated loopback HLS/viewer и Common
kill-on-close containment. Secret scan разрешает только exact marker multiset
этих двух уже hash-verified payloads; дополнительный marker в любом bundle file
остаётся ошибкой. Реальный GTA capture/public network/recovery ещё не принят,
chat bridge отсутствует. Ordinary licensed composition обязана оставаться
fail-closed до отдельного решения по redistribution/signing и live acceptance.
Подробности: [H07 runtime](H07_STREAMING_RUNTIME.md).

## Overlay semantics

Fishing использует captured game frame для semantic detectors, но это не
overlay. Native Host показывает обычные WPF pages и не создаёт topmost,
click-through или injected game surface. Stream viewer тоже не является game
overlay. Проверка Hunting/Poker overlays выполняется их владельцами и не может
служить доказательством Fishing.

## Release evidence rule

Offline test, fake adapter, development-unsigned lifecycle и production live
acceptance записываются раздельно. Отсутствие внешнего секрета не скрывает UI и
contract функции, но также не разрешает fake entitlement, wildcard build
profile, unsigned production claim или сетевой payload неизвестного
происхождения.
