# H07 streaming runtime

Статус: lifecycle core и compile-isolated Local Access composition **done
offline**, live capture/network acceptance **pending**.

## Goal and non-goals

`StreamingRuntimeController` является одним coarse Host-owned owner для
start/stop, controlled restart, chat-mode bridge и immutable revisioned
snapshot. Внутри одной generation он последовательно владеет embedded tool
lease, authenticated loopback media session, contained encoder и contained
tunnel. UI, Telegram и Overview продолжают потреблять только существующий
`IStreamingController`; fine-grained process/network операции наружу не
выносятся.

Compile-isolated Local Access composition подключает этот controller к
hash-pinned embedded FFmpeg, Win32 HWND capture, authenticated loopback
HLS/viewer и contained cloudflared tunnel. Ordinary licensed composition не
встраивает эти payloads и поэтому сохраняет `UnavailableStreamingController`.
Chat use-case bridge пока отсутствует в обеих compositions: chat-mode action
не рекламируется и fail-closed возвращает `streaming_chat_bridge_unavailable`.

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
cadence and never infers a physical display resolution. The Local Access
`Win32GtaStreamingCaptureSource` requires exactly one non-minimized `GTA5`
window, validates HWND ownership and non-zero current client bounds, then gives
FFmpeg a `gdigrab` `hwnd=...` descriptor. Chat zoom is derived from the current
client width/height instead of fixed screen coordinates. This source has not
yet passed live target-loss, DPI, resize or restart acceptance.

Default lifecycle budgets are 20 seconds startup, 5 seconds total cleanup,
1-second health observation, 500 ms retry delay, two retries, 5-minute
no-viewer autostop and 2-second coarse chat command. Bounds are validated when
the runtime is constructed.

## Two-EXE boundary

`EmbeddedStreamingExecutableProvider` reads manifest resources, writes each
generation into an exact random session directory with `CreateNew`, verifies
the declared SHA-256 after materialization and deletes only that validated
directory when the contained processes have stopped. The backend rejects any
provider that reports a loose-file origin. Therefore runtime composition has no
supported loose dependency fallback.

The compile-isolated Local Access bundle embeds these exact resources in
`Sonar.exe`:

| Tool | Manifest version | SHA-256 |
| --- | --- | --- |
| FFmpeg | `8.1.1-essentials_build-www.gyan.dev` | `228D7A8556258DE907FDB55F36850078EBC7680B84EC30D84EA02E99BEC1D1EB` |
| cloudflared | `2026.5.2` | `20B9638F685333D623798E733EFFBAD2487093F15BA592F6C7752360FF3B7AB7` |

The build verifies the source files against this manifest before embedding;
each runtime extraction verifies the same hash. Encoder and tunnel are assigned
to Common kill-on-close Jobs. The loopback owner binds only `127.0.0.1`, creates
a cryptographically random 256-bit path token, serves the viewer/playlist/
segments only under that path, bounds request headers and concurrent clients,
tracks recent viewers and deletes only its exact session workspace. The public
HTTPS URL is accepted only from bounded cloudflared diagnostics without
userinfo/query/fragment; the secret media path remains part of the published
stream URL.

Third-party binaries may contain byte sequences that resemble high-confidence
secret markers. The Local Access release scan grants no filename-wide or
directory-wide exception: it first verifies the exact manifest hashes, derives
the sorted marker **multiset** from those two exact files and requires the
embedded `Sonar.exe` multiset to be byte-for-byte equal. Any additional marker
in `Sonar.exe`, any marker in `Sonar.Engine.exe`/other files, a hash mismatch or
an unlisted payload fails the bundle.

This is not permission to publish the third-party payloads as an ordinary
licensed release. Redistribution notices/source-offer obligations, product
signing, installed/update/rollback allowlist and real process/network recovery
must be accepted separately. Until then ordinary licensed composition remains
on `UnavailableStreamingController`.

## Проверка допустимого Windows encoder path

Историческая Python-версия не содержала собственного encoder: она скачивала и
запускала внешний FFmpeg для HLS, а публичный URL давала через cloudflared или
tunnelmole. Local Access теперь использует frozen manifest выше: Gyan static
GPLv3 FFmpeg примерно 101 MiB с x264 и cloudflared примерно 54 MiB. Exact hash
и origin закрывают воспроизводимость локальной сборки, но не заменяют отдельное
решение по redistribution license/notices/source offer для обычного релиза.

Встроенный Windows path исследован по Microsoft documentation:

- `Windows.Graphics.Capture` поддерживает создание capture item по HWND;
- Media Foundation предоставляет H.264 encoder и Sink Writer;
- штатные Media Foundation sinks перечисляют MP4/3GP/ASF/MP3, но не HLS;
- Sink Writer не выполняет автоматически resize и frame-rate conversion.

Следовательно, Media Foundation может заменить часть capture/encode chain, но
не является готовой заменой legacy HLS pipeline. Для production всё равно нужны
product-owned color/scale/timing conversion, HLS mux/segment sink, authenticated
viewer/session server, viewer accounting, public HTTPS tunnel and cleanup.
Канонические ссылки: [capture by HWND](https://learn.microsoft.com/en-us/windows/win32/api/windows.graphics.capture.interop/nf-windows-graphics-capture-interop-igraphicscaptureiteminterop-createforwindow),
[Sink Writer](https://learn.microsoft.com/en-us/windows/win32/medfound/using-the-sink-writer),
[supported formats](https://learn.microsoft.com/en-us/windows/win32/medfound/supported-media-formats-in-media-foundation),
[codec objects](https://learn.microsoft.com/en-us/windows/win32/medfound/codecobjects).

## Offline acceptance

Thirteen managed H07 cases cover the exact six quality/FPS combinations, safe
tunnel URL parsing, startup order, reverse cleanup, partial-start rollback,
loose-tool and unauthenticated-viewer rejection, total cleanup timeout,
in-flight startup cancellation, serialized restart without overlap, bounded
retry and bounded chat command. Eleven cases remain fake-adapter lifecycle
tests. One additional test uses a real loopback socket and temporary media
workspace to prove the secret-path viewer boundary and cleanup; one verifies
that Local Access composition can exist only when all three exact embedded
resources are present. They do not start FFmpeg/cloudflared or capture GTA.

The final compile-isolated bundle gate must additionally prove exact resource
embedding, deterministic output, strict two-EXE layout, dependency closure,
no-Python and the exact secret-marker multiset rule. These are offline release
receipts; they do not claim live capture, public-network throughput or recovery.

## Remaining production gates

- accept the current Win32 HWND capture under live target loss, DPI, resize,
  alt-tab and GTA restart without fixed display geometry;
- accept the real FFmpeg/HLS/cloudflared start, public HTTPS reachability,
  authenticated secret-path viewer, viewer accounting and stale-workspace/
  process crash recovery;
- connect one coarse chat-mode use case; it remains unavailable today;
- decide whether the exact third-party payloads and their redistribution
  obligations are acceptable for the ordinary licensed composition;
- complete privacy/security review of the public tunnel and authenticated viewer
  surface;
- run separately authorized real process/network acceptance, start/exit/crash
  recovery, signing/update and final two-EXE allowlist gates.
