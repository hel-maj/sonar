# H07 streaming runtime

Статус: lifecycle core **done offline**, production activation **partial**.

## Goal and non-goals

`StreamingRuntimeController` является одним coarse Host-owned owner для
start/stop, controlled restart, chat-mode bridge и immutable revisioned
snapshot. Внутри одной generation он последовательно владеет embedded tool
lease, authenticated loopback media session, contained encoder и contained
tunnel. UI, Telegram и Overview продолжают потреблять только существующий
`IStreamingController`; fine-grained process/network операции наружу не
выносятся.

Этот slice не подключает production composition, не содержит и не запускает
реальные FFmpeg/cloudflared binaries, не открывает сокет, не ищет окно игры и
не выполняет GTA/capture/input/network действие. Он также не объявляет готовой
аутентифицированную viewer implementation или chat use-case bridge.

## Lifecycle and ownership

Одна generation выполняет следующий порядок:

1. получает hash-pinned executable lease только с origin
   `EmbeddedResource`; loose-file fallback запрещён;
2. получает один coarse capture descriptor;
3. поднимает authenticated loopback media session;
4. запускает encoder через product wrapper над Common
   `Sonar.Platform.Processes.KillOnCloseJob` и проверяет containment;
5. ждёт первый media segment в общем startup deadline;
6. запускает contained tunnel и принимает только bounded HTTPS base URL без
   credentials/query/fragment;
7. публикует один coherent Online snapshot и наблюдает component completion и
   viewer count.

Stop, disposal, startup rollback и restart чистят ресурсы в обратном порядке:
tunnel -> encoder -> media session -> embedded executable lease. Общий cleanup
budget ограничивает даже noncooperative adapter. Закрытие Common Job является
hard-stop fallback после graceful encoder command. Ошибка cleanup не маскируется
как успешный Offline lifecycle.

Смена quality/chat zoom/10-FPS во время Online не запускает второй параллельный
набор ресурсов. Текущая generation отменяется, replacement ждёт её bounded
cleanup и только затем начинает startup. Unexpected component exit имеет
ровно два автоматических retry по default policy; после исчерпания budget
snapshot переходит в Error. Stop и Host disposal не расходуют retry budget.

## Exact media policy

| Quality | Output | 30 FPS bitrate | 10 FPS bitrate |
| --- | ---: | ---: | ---: |
| `480p` | `854x480` | `1200k` | `600k` |
| `720p` | `1280x720` | `2900k` | `1500k` |
| `1080p` | `1920x1080` | `5000k` | `2300k` |

FFmpeg plan uses argument-list tokens rather than a shell command, preserves
aspect ratio through scale + letterbox padding, uses a two-second keyframe/HLS
cadence and never infers a physical display resolution. Actual game/chat
capture bounds remain the responsibility of the future guarded capture-source
adapter.

Default lifecycle budgets are 20 seconds startup, 5 seconds total cleanup,
1-second health observation, 500 ms retry delay, two retries, 5-minute
no-viewer autostop and 2-second coarse chat command. Bounds are validated when
the runtime is constructed.

## Two-EXE boundary

`EmbeddedStreamingExecutableProvider` reads manifest resources, writes each
generation into an exact random session directory with `CreateNew`, verifies
the declared SHA-256 after materialization and deletes only that validated
directory when the contained processes have stopped. The backend rejects any
provider that reports a loose-file origin. Therefore source/runtime composition
has no supported loose dependency fallback and a future release must embed the
two signed tools in `Sonar.exe`.

No executable payload is added by this slice. Before release, the product must
freeze redistributable versions/licenses/hashes, add them as embedded resources,
choose the product-owned transient root and prove normal-exit plus crash-recovery
cleanup against the strict two-EXE bundle allowlist. Until that happens the
production composition must continue using `UnavailableStreamingController`.

## Offline acceptance

Eleven new managed tests use only fake executable, process, capture and network
adapters. They cover the exact six quality/FPS combinations, safe tunnel URL
parsing, startup order, reverse cleanup, partial-start rollback, loose-tool and
unauthenticated-viewer rejection, total cleanup timeout, in-flight startup
cancellation, serialized restart without overlap, bounded retry and bounded
chat command. No real process or socket is created by these tests.

Current Release acceptance is 128/128 WPF tests with zero warnings. Five equal
offline process samples had median wall time 2219.172 ms, median CPU time
1437.5 ms and maximum peak working set 16,564,224 bytes. H07 adds no Engine IPC
operation or bytes. The sample demonstrates no isolated hotspot, so no
semantics-changing optimization was made.

## Remaining production gates

- freeze signed, redistributable FFmpeg/cloudflared payloads, licenses and exact
  hashes, then embed them in Host resources;
- implement the guarded product capture-source adapter for current game/chat
  client bounds without fixed display geometry;
- implement the authenticated loopback HLS/viewer server, bounded viewer count,
  media workspace lifecycle and stale-workspace crash recovery;
- connect one coarse chat-mode use case and the licensed production composition;
- complete privacy/security review of the public tunnel and authenticated viewer
  surface;
- run separately authorized real process/network acceptance, start/exit/crash
  recovery, signing/update and final two-EXE allowlist gates.

