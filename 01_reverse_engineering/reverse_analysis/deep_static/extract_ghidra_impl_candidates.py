#!/usr/bin/env python3
"""Extract Nuitka function implementation candidates from Ghidra module init decompilation."""

from __future__ import annotations

import csv
import pathlib
import re
from collections import defaultdict
from dataclasses import dataclass


ROOT = pathlib.Path(__file__).resolve().parent
GHIDRA_EXPORTS = ROOT / "ghidra_exports"
INPUT = GHIDRA_EXPORTS / "ghidra_decompile_custom_module_inits.c"
CANDIDATES_CSV = GHIDRA_EXPORTS / "ghidra_custom_impl_candidates.csv"
ADDRESS_LIST = GHIDRA_EXPORTS / "custom_impl_addresses.txt"
FUNCTIONS_CSV = GHIDRA_EXPORTS / "ghidra_functions.csv"
DUMP_DIR = ROOT / "custom_constant_dumps"


SECTION_RE = re.compile(
    r"(?ms)^/\* ===== (?P<addr>[0-9a-f]+) (?P<label>.*?) ===== \*/\n(?P<body>.*?)(?=^/\* ===== |\Z)"
)

FACTORY_SPECS = {
    # impl, name, qualname, code object
    "FUN_23e93e1e0": {"impl": 0, "name": 1, "qual": 2, "codevar": 3},
    "FUN_23e93e480": {"impl": 0, "name": 1, "qual": 2, "codevar": 3},
    # closure/function factory used heavily by telegram handlers and several helpers.
    # Its qualname is not consistently the 8th argument, so descriptor matching falls
    # back to the function name symbol when exact matching misses.
    "FUN_23e93df40": {"impl": 0, "name": 1, "qual": 7, "codevar": 2},
}

INFERRED_RANGES = [
    {
        "module_label": "workers.fishing.fishing_bot",
        "module_init_entry": "23e780c30",
        "low_exclusive": "23e71b350",
        "high_exclusive": "23e780c30",
        "class_name": "FishingBot",
        "include_class_body": True,
    },
    {
        "module_label": "workers.fishing.memory_reeling",
        "module_init_entry": "23e81e380",
        "low_exclusive": "23e7fb4a0",
        "high_exclusive": "23e81e380",
        "class_name": "MemoryReelingTracker",
        "include_class_body": False,
    },
]


@dataclass
class Call:
    name: str
    args: list[str]
    source_line: int
    start: int


@dataclass
class CodeDescriptor:
    source_line: str = ""
    flags: str = ""
    name_symbol: str = ""
    qual_symbol: str = ""
    varnames_symbol: str = ""
    arg_count: str = ""


def compact_arg(value: str) -> str:
    value = re.sub(r"\s+", "", value)
    while value.startswith("&"):
        value = value[1:]
    while True:
        new_value = re.sub(r"^\([^()]+\)", "", value)
        if new_value == value:
            break
        value = new_value
    return value


def parse_int_literal(value: str) -> str:
    value = compact_arg(value)
    try:
        return str(int(value, 0))
    except ValueError:
        return value


def line_at(text: str, offset: int) -> int:
    return text.count("\n", 0, offset) + 1


def split_args(arg_text: str) -> list[str]:
    args: list[str] = []
    start = 0
    depth = 0
    in_string: str | None = None
    escaped = False
    for i, ch in enumerate(arg_text):
        if in_string:
            if escaped:
                escaped = False
            elif ch == "\\":
                escaped = True
            elif ch == in_string:
                in_string = None
            continue
        if ch in ("'", '"'):
            in_string = ch
            continue
        if ch in "([{":
            depth += 1
            continue
        if ch in ")]}":
            depth -= 1
            continue
        if ch == "," and depth == 0:
            args.append(compact_arg(arg_text[start:i]))
            start = i + 1
    tail = arg_text[start:].strip()
    if tail:
        args.append(compact_arg(tail))
    return args


def find_calls(text: str, names: set[str]) -> list[Call]:
    calls: list[Call] = []
    pattern = re.compile(r"\b(" + "|".join(re.escape(name) for name in sorted(names)) + r")\s*\(")
    for match in pattern.finditer(text):
        name = match.group(1)
        open_index = text.find("(", match.start())
        depth = 0
        close_index = -1
        in_string: str | None = None
        escaped = False
        for i in range(open_index, len(text)):
            ch = text[i]
            if in_string:
                if escaped:
                    escaped = False
                elif ch == "\\":
                    escaped = True
                elif ch == in_string:
                    in_string = None
                continue
            if ch in ("'", '"'):
                in_string = ch
                continue
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0:
                    close_index = i
                    break
        if close_index == -1:
            continue
        arg_text = text[open_index + 1 : close_index]
        calls.append(Call(name=name, args=split_args(arg_text), source_line=line_at(text, match.start()), start=match.start()))
    return calls


def choose_descriptor(
    descriptors: list[CodeDescriptor],
    used: set[int],
    factory: str,
    name_symbol: str,
    qual_symbol: str,
) -> CodeDescriptor:
    keys: list[tuple[str, str]] = []
    if name_symbol and qual_symbol:
        keys.append((name_symbol, qual_symbol))
    if factory == "FUN_23e93df40" and name_symbol:
        keys.append((name_symbol, name_symbol))

    for name_key, qual_key in keys:
        for i, descriptor in enumerate(descriptors):
            if i in used:
                continue
            if descriptor.name_symbol == name_key and descriptor.qual_symbol == qual_key:
                used.add(i)
                return descriptor

    if name_symbol:
        for i, descriptor in enumerate(descriptors):
            if i in used:
                continue
            if descriptor.name_symbol == name_symbol:
                used.add(i)
                return descriptor

    return CodeDescriptor()


def module_to_dump_name(module: str) -> str:
    return module.replace(".", "__").replace("-", "_")


def load_qualname_hints(module: str, class_name: str, include_class_body: bool) -> list[str]:
    path = DUMP_DIR / f"{module_to_dump_name(module)}.json"
    if not path.exists():
        return []
    import json

    values = json.loads(path.read_text(encoding="utf-8"))
    hints: list[str] = []
    if include_class_body and class_name in values:
        hints.append(class_name)
    for value in values:
        if not isinstance(value, str):
            continue
        if value.startswith(f"{class_name}.") and "<locals>" not in value and value not in hints:
            hints.append(value)
    return hints


def load_function_entries() -> list[str]:
    if not FUNCTIONS_CSV.exists():
        return []
    entries: list[str] = []
    with FUNCTIONS_CSV.open(encoding="utf-8", newline="") as f:
        reader = csv.DictReader(f)
        for row in reader:
            entry = row.get("entry", "")
            if re.fullmatch(r"[0-9a-fA-F]+", entry):
                entries.append(entry.lower())
    return sorted(entries)


def main() -> int:
    text = INPUT.read_text(encoding="utf-8", errors="replace")

    rows: list[dict[str, str]] = []
    address_labels: dict[str, str] = {}
    factory_counts: defaultdict[str, int] = defaultdict(int)

    for section in SECTION_RE.finditer(text):
        module_init_entry = section.group("addr")
        module_label = section.group("label")
        body = section.group("body")

        descriptor_calls = find_calls(body, {"FUN_23e8d3980"})
        descriptors: list[CodeDescriptor] = []
        for call in descriptor_calls:
            if len(call.args) < 7:
                continue
            descriptors.append(
                CodeDescriptor(
                    source_line=parse_int_literal(call.args[1]),
                    flags=parse_int_literal(call.args[2]),
                    name_symbol=call.args[3],
                    qual_symbol=call.args[4],
                    varnames_symbol=call.args[5],
                    arg_count=parse_int_literal(call.args[6]),
                )
            )

        used_descriptors: set[int] = set()
        factory_calls = find_calls(body, set(FACTORY_SPECS))
        factory_calls.sort(key=lambda call: call.start)
        for call in factory_calls:
            spec = FACTORY_SPECS[call.name]
            if len(call.args) <= max(spec.values()):
                continue
            impl_entry = call.args[spec["impl"]]
            name_symbol = call.args[spec["name"]]
            qual_symbol = call.args[spec["qual"]]
            codevar = call.args[spec["codevar"]]
            descriptor = choose_descriptor(descriptors, used_descriptors, call.name, name_symbol, qual_symbol)

            rows.append(
                {
                    "module_label": module_label,
                    "module_init_entry": module_init_entry,
                    "factory": call.name,
                    "impl_entry": impl_entry,
                    "codevar": codevar,
                    "line": descriptor.source_line,
                    "flags": descriptor.flags,
                    "name_symbol": name_symbol,
                    "qual_symbol": qual_symbol,
                    "varnames_symbol": descriptor.varnames_symbol,
                    "arg_count": descriptor.arg_count,
                    "factory_c_line": str(call.source_line),
                }
            )
            factory_counts[call.name] += 1

            if impl_entry.startswith(("FUN_", "LAB_")):
                address = impl_entry.removeprefix("FUN_").removeprefix("LAB_")
                if re.fullmatch(r"[0-9a-fA-F]+", address) and address not in address_labels:
                    line_label = descriptor.source_line or f"c{call.source_line}"
                    address_labels[address] = f"{module_label}:{line_label}"

    existing_addresses = {
        row["impl_entry"].removeprefix("FUN_").removeprefix("LAB_").lower()
        for row in rows
        if row["impl_entry"].startswith(("FUN_", "LAB_"))
    }
    for inferred in INFERRED_RANGES:
        hints = load_qualname_hints(
            inferred["module_label"],
            inferred["class_name"],
            bool(inferred["include_class_body"]),
        )
        entries = [
            entry
            for entry in load_function_entries()
            if inferred["low_exclusive"] < entry < inferred["high_exclusive"] and entry not in existing_addresses
        ]
        for index, entry in enumerate(entries):
            qualname_hint = hints[index] if index < len(hints) else ""
            rows.append(
                {
                    "module_label": inferred["module_label"],
                    "module_init_entry": inferred["module_init_entry"],
                    "factory": "INFERRED_ADDRESS_RANGE",
                    "impl_entry": f"FUN_{entry}",
                    "codevar": "",
                    "line": "",
                    "flags": "",
                    "name_symbol": "",
                    "qual_symbol": "",
                    "varnames_symbol": "",
                    "arg_count": "",
                    "factory_c_line": "",
                    "qualname_hint": qualname_hint,
                }
            )
            existing_addresses.add(entry)
            address_labels.setdefault(entry, f"{inferred['module_label']}:{qualname_hint or 'inferred'}")

    CANDIDATES_CSV.parent.mkdir(parents=True, exist_ok=True)
    fieldnames = [
        "module_label",
        "module_init_entry",
        "factory",
        "impl_entry",
        "codevar",
        "line",
        "flags",
        "name_symbol",
        "qual_symbol",
        "varnames_symbol",
        "arg_count",
        "factory_c_line",
        "qualname_hint",
    ]
    with CANDIDATES_CSV.open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)

    ADDRESS_LIST.write_text(
        "".join(f"{address},{label}\n" for address, label in address_labels.items()),
        encoding="utf-8",
    )

    print(f"wrote {len(rows)} candidates to {CANDIDATES_CSV}")
    print(f"wrote {len(address_labels)} unique implementation addresses to {ADDRESS_LIST}")
    for factory, count in sorted(factory_counts.items()):
        print(f"{factory}: {count}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
