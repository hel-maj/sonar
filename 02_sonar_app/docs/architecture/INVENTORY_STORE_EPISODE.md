# Native inventory and store-fish episode

Status: offline boundary design accepted for E15; production observation and
mutation adapters are not composed.

## Goal and non-goals

The Engine must own one bounded inventory operation from the latest coherent
observation through decision, immediate final safety validation, input intent,
confirmation, reflow handling, cleanup and optional return to fishing.

This slice does not implement live capture, OCR, process/window attachment or
physical input. It does not add a Host frame, cursor, detector-step or key RPC.
The rich legacy `item_info.py` parser remains characterization evidence for the
future native item detector; the episode consumes only a canonical item ID,
confidence and normalized bounds and never guesses an ID from display text.

## Current and target boundary

Legacy behavior is split between `game_menu.py`, `inventory_stage.py`,
`store_fish.py`, `item_info.py` and `FishingBot`. Capture and mutation are
interleaved across those owners. Inventory open has two hotkey attempts, menu
dismissal is throttled, active reeling blocks stage exit, fish are right-clicked
one at a time, the remove context action is separately located, inventory items
may reflow after each removal, and return to fishing closes inventory before
pressing the fishing entry key.

The target `SonarFishingInventoryStore` boundary has:

- one immutable coarse observation containing a strictly increasing sequence,
  surface, E14 fishing-stage value, canonical item candidates and optional
  context action;
- one state-machine runner that owns all retries, time budgets, confirmations,
  reflow and recovery;
- one narrow observer port and one final mutation port;
- mutation intents carrying the exact observation sequence on which the
  decision was based;
- one disabled mutation implementation for fail-closed composition.

The future live mutation port must use the shared exclusive Engine input lease
and immediately revalidate entitlement, settings revision, lifecycle,
process/window generation, foreground identity and Common packet budget. A
prior observation or preflight is not transferable authorization.

## State machine and failures

The episode validates every observation, closes a visible game menu, exits only
non-reeling fishing stages, opens inventory with a bounded retry, repeatedly
selects one fresh matching item, confirms its context action, confirms a lower
matching-item count after removal, then closes inventory. If requested, it
presses the fishing entry key and requires a fresh non-idle stage observation.

Coordinates are E14 normalized rectangles and are converted to physical pixels
only by a future mutation adapter using the current client snapshot. A stale or
non-monotonic sequence, ambiguous surface, invalid geometry, capture error,
unconfirmed menu/inventory/context/removal/resume, cancellation or rejected
final gate fails closed. Recovery only attempts to close a context menu and
inventory; it never resumes fishing after a failed store operation.

## Fixtures, rollback and acceptance

`tests/fixtures/inventory_store/episode-v1.tsv` is the language-neutral scenario
oracle. It freezes observations, request policy, final outcome, confirmed count
and ordered intents. Native tests also cover bounded timeout, cancellation,
invalid geometry, stale observations and final-gate rejection.

This target is not linked into the offline Engine and changes no production
authority. Rollback is removal of the isolated target, fixture row and
documentation entry. Production cutover requires native menu/inventory/item
detectors, guarded capture and mutation adapters, hard-crash cleanup, signed
entitlement admission and the full release allowlist matrix.
