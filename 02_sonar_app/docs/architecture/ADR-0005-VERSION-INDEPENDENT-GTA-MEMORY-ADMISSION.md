# ADR-0005: version-independent admission GTA memory runtime

- Status: accepted
- Date: 2026-08-26
- Owner: Sonar Fishing
- Common dependency: `SonarPlatformWindows` 0.1.9

## Goal

Разрешать production-наблюдение и вытягивание рыбы на текущем подписанном
`GTA5.exe`, не связывая доступность функции с известной версией, SHA-256,
размером файла, PE timestamp или заранее известным loaded image size.

Не являются целью ослабление проверки игровых признаков, свежести процесса,
геометрии кадра, foreground/final action gates и бюджета input-пакетов.

## Решение

`Sonar::PlatformWindowsTrustedModule` владеет Win32-механикой допуска. Fishing
передаёт product policy: process/module `GTA5.exe` и accepted publisher
Rockstar Games. Common на одном pinned file handle проверяет уникальный модуль,
ненулевые bounds, равенство disk PE `SizeOfImage` loaded size, WinTrust signer
и timestamp, затем связывает cold/hot наблюдения fingerprint-ом process/module/
file identity.

После этого Fishing выполняет отдельный semantic admission:

1. полностью читает только executable sections текущего admitted module;
2. требует единственный валидный player endpoint и replay endpoint;
3. требует bounded replay count без fallback;
4. требует единственную активную рыбу с точным model hash и валидной геометрией;
5. переносит fingerprint Common lease в coarse capture profile, поэтому второй
   read session обязан подтвердить ту же authority;
6. revalidate-ит lease до и после discovery/read.

Embedded SHA-256 и exact selector остаются только для offline fixtures,
forensic provenance и replay. Shipping connector не вычисляет SHA-256 и не
использует exact selector.

## Границы и failure semantics

- Common владеет signer/file/process/module verifier; Fishing не копирует его.
- Fishing владеет Rockstar publisher policy и semantic layout/feature policy.
- Неоднозначный, неполный или устаревший scan возвращает address-free reason и
  не создаёт capture plan.
- Process/module/file drift отзывает lease; stale address, snapshot или input
  не replay-ятся.
- Физический ввод по-прежнему проходит automation lease, свежий coherent
  observation, foreground gate и final packet-budget gate.
- Common inventory-open facade остаётся независимым consumer и не проходит
  через Fishing legacy inventory resolver.

## Migration и rollback

Transitional exact mode доступен только через явно названный forensic connector
для non-shipping compatibility/characterization tools. Production composition
использует только trusted runtime connector. Rollback к SHA-gated production
запрещён; при дефекте semantic layout capability остаётся fail-closed до
исправления pattern/layout data.

## Verification

- `/W4 /WX` для Common consumer и всех затронутых Fishing targets;
- regressions trusted authority/fingerprint, unique/ambiguous anchors,
  executable-section full coverage, generation drift и coherent capture;
- production Engine/adapters/composition tests;
- one-shot read-only live preflight без input imports;
- exact profile fixture и forensic probe остаются детерминированными, но не
  являются runtime availability evidence.
