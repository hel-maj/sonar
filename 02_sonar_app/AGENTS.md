# Agent Notes

## Code quality: OOP, SOLID, and Clean Code

- Apply OOP and SOLID pragmatically when they protect invariants, reduce
  coupling, and make behavior easier to test or replace. Correctness, safety,
  compatibility, simplicity, and measured performance take priority over a
  formal number of classes, interfaces, patterns, or layers.
- Do not create abstractions for hypothetical future use. Pure transformations,
  DTOs, parsers, OCR/image pipelines, and measured hot loops may remain
  functional or data-oriented.
- Follow SRP and separate domain policy from UI, memory/input, IPC, network,
  storage, and other side effects. High-level policy depends on narrow stable
  contracts, while concrete adapters are wired in the composition root.
- Keep interfaces consumer-oriented, preserve observable contract semantics
  across implementations, and prefer composition over inheritance.
- Use intention-revealing names, one term per concept, small cohesive units,
  explicit dependencies, and visible side effects. Do not swallow errors.
- Remove duplicated knowledge and rules, but extract a shared abstraction only
  after its semantics are proven common. Small local duplication is better than
  the wrong abstraction.
- Comments explain why a constraint or non-obvious decision exists, rather than
  restating code. Remove dead code, commented-out implementations, and stale
  comments.
- Capture legacy behavior with characterization or parity tests before
  refactoring. Keep language ports, behavior changes, and structural cleanup in
  separate steps; add regression tests for fixed bugs.
- Document non-obvious exceptions caused by a measured hot path, framework or
  interoperability constraint, compatibility, or a safe migration, and support
  them with a test or measurement.

## Architecture before implementation

- Before a non-trivial feature, inspect its entrypoint and composition root,
  domain/state-machine ownership, UI/presenter layer, external adapters,
  consumers, contracts, and tests. Define current, transitional, and target
  architecture before production code.
- Use an explicit State Machine for multi-step fishing flows, Strategy/Provider
  for real algorithm variants, Ports and Adapters for memory, input, vision,
  Telegram, streaming, storage, and UI boundaries, and MVVM for the target WPF
  UI. A pattern must solve a named problem rather than satisfy a checklist.
- Keep domain policy out of Qt widgets, callbacks, transport handlers, and
  catch-all `utils`, `helpers`, or `common` modules. Wire concrete dependencies
  only at the entrypoint/composition root.
- Do not introduce reverse or cyclic imports, god windows/controllers/services,
  or a new unrelated responsibility in an already large file. Split by
  capability and reason to change, not by an arbitrary line limit.
- Do not replace a monolithic file with one flat folder of unrelated files.
  Define the target Fishing directory tree before moving code, using
  feature/capability ownership, a narrow public surface, and explicit allowed
  dependencies. Global technical-type folders must not mix unrelated fishing,
  UI, memory, Telegram, streaming, and release flows.
- Check current official documentation and primary sources before decisions
  involving unfamiliar or changing frameworks, security, interoperability,
  persistence, lifecycle, or performance. Record cross-cutting or hard-to-reverse
  decisions in a design note or ADR before production cutover.

## Test cadence

- During implementation, run only the smallest relevant set of tests for the
  changed module, bug, contract, and immediate consumers. Do not repeatedly run
  the full suite after intermediate edits.
- Prefer the owning managed or native target for focused feedback. The stable
  product wrapper runs the complete offline WPF/C++ suite:

  ```powershell
  powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\test.ps1
  ```

- After all code and documentation for the task are complete and focused tests
  pass, run the full relevant offline suite once as the final quality gate:

  ```powershell
  powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\setup_native.ps1
  powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\test_native.ps1
  ```

- If the final suite exposes a failure, fix it, rerun the affected focused
  tests, and then repeat the full suite before completing the task.
- Documentation-only changes do not require the full suite. Validate the text,
  links, commands, and structure instead. Live or external integration checks
  remain separate and run only when the change requires them.

## User-facing text

- Use only ASCII hyphen-minus `U+002D` (`-`) as a dash in UI copy,
  descriptions, documentation, notifications, and release notes.
- Do not add Unicode em dash `U+2014` or en dash `U+2013`.
- A technical exception is allowed only for an exact external input format
  without which parsing cannot work. Represent it as a Unicode escape in
  source code and normalize it to `-` before showing it to the user.

## Live GTA capture

- If a check requires user actions in GTA, a focused GTA window, or an
  unminimized game, prepare the capture first and explain the complete action
  sequence and sound legend.
- Before starting a timer, recording, or live capture, explicitly ask the user
  to perform the required action and confirm it. Stop and wait for an
  unambiguous contextual reply such as `готов`, `открыл`, `закрыл`, or
  `перешел`. Do not require one exact word when the reply clearly confirms the
  requested action.
- In the user-facing instruction, bold the suggested confirmation word or
  short phrase, for example `Reply **готов**` or `Reply **открыл**`, so it is
  immediately visible. Treat it as a highlighted suggestion, not a password;
  accept another unambiguous contextual confirmation.
- Never reuse readiness or an action confirmation from an earlier capture.
- After the required confirmation, allow 5 seconds for returning to the game
  unless another delay was stated in advance.
- Short tonal or MIDI cues may combine a low dull tone, a high bright tone, and
  repetition counts. State the exact meaning and order before every capture;
  always use clearly announced start and finish cues.

## GTA/Majestic observations

- Product Python memory/capture utilities were retired with the native cutover.
- Use only the C++ observation adapters and frozen language-neutral fixtures
  documented by the owning native capability.
- Live target attach, capture or input always requires a fresh readiness gate;
  ordinary setup, test and build commands remain offline.
