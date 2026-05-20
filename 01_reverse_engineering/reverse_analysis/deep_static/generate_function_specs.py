#!/usr/bin/env python3
"""Generate per-module reconstruction specs from Nuitka and Ghidra artifacts."""

from __future__ import annotations

import csv
import difflib
import json
import pathlib
import re
from collections import defaultdict
from typing import Any


ROOT = pathlib.Path(__file__).resolve().parent
OUT = ROOT.parent / "function_specs"
DECOMP_OUT = OUT / "decompiled_impls"


QUAL_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*(?:\.[A-Za-z_<>][A-Za-z0-9_<>]*)+$")
MOJIBAKE_RE = re.compile(r"[РС][\u0400-\u04ff]|[рР]џ")


def load_json(path: pathlib.Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def repair_mojibake_text(text: str) -> str:
    if not MOJIBAKE_RE.search(text):
        return text
    try:
        repaired = text.encode("cp1251").decode("utf-8")
    except UnicodeError:
        return text
    original_noise = text.count("Р") + text.count("С") + text.count("рџ")
    repaired_noise = repaired.count("Р") + repaired.count("С") + repaired.count("рџ")
    if repaired_noise < original_noise:
        return repaired
    return text


def compact(value: Any, limit: int = 280) -> str:
    if isinstance(value, str):
        value = repair_mojibake_text(value)
    text = repr(value)
    text = text.replace("\r", "\\r").replace("\n", "\\n")
    if len(text) > limit:
        text = text[: limit - 3] + "..."
    return text


def module_to_dump_name(module: str) -> str:
    if module == "":
        return "_root_"
    return module.replace(".", "__").replace("-", "_")


def dump_name_to_module(name: str) -> str:
    stem = pathlib.Path(name).stem
    if stem == "_root_":
        return ""
    if stem == "__main__":
        return "__main__"
    if stem == "__parents_main__":
        return "__parents_main__"
    return stem.replace("__", ".")


def is_function_qualname(text: Any, module: str = "") -> bool:
    if not isinstance(text, str):
        return False
    if text == module:
        return False
    if "\\" in text or "/" in text:
        return False
    if text.startswith("<module "):
        return False
    if "<locals>" in text:
        return False
    if text.startswith(("PyQt6.", "aiogram.", "telegram.")) and "<locals>" not in text:
        # Keep the project telegram modules via dump module matching, but skip imported package names.
        return False
    return bool(QUAL_RE.match(text)) and "." in text


def is_varname_list(value: Any) -> bool:
    if not isinstance(value, list) or not value:
        return False
    if not all(isinstance(item, str) for item in value):
        return False
    if value == ["__class__"]:
        return True
    if value[0] in {"self", ".0"}:
        return True
    return any(item in value for item in ("self", "return", "args", "kwargs"))


def is_structured(value: Any) -> bool:
    if isinstance(value, dict):
        return True
    if isinstance(value, list) and value:
        if all(isinstance(item, (int, float, bool, type(None))) for item in value):
            return True
        if all(isinstance(item, list) for item in value):
            return True
    return False


def normalize_module_label(label: str, modules: list[str]) -> str:
    if label in modules:
        return label
    prefix_candidates: list[str] = []
    for module in modules:
        if not module:
            continue
        if module.startswith(label) or label.startswith(module):
            prefix_candidates.append(module)
    if prefix_candidates:
        return sorted(prefix_candidates, key=len, reverse=True)[0]
    # Ghidra labels are truncated. Use fuzzy matching for the few truncated labels.
    match = difflib.get_close_matches(label, modules, n=1, cutoff=0.72)
    if match:
        return match[0]
    return label


def split_decompiled_sections(path: pathlib.Path) -> dict[str, str]:
    text = path.read_text(encoding="utf-8", errors="replace")
    sections: dict[str, str] = {}
    pattern = re.compile(r"(?ms)^/\* ===== (?P<addr>[0-9a-f]+) (?P<label>.*?) ===== \*/\n(?P<body>.*?)(?=^/\* ===== |\Z)")
    for match in pattern.finditer(text):
        addr = match.group("addr")
        sections[addr] = match.group(0).rstrip() + "\n"
    return sections


def load_csv(path: pathlib.Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as f:
        return list(csv.DictReader(f))


def write_text(path: pathlib.Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")


def impl_to_addr(impl: str) -> str:
    return impl.removeprefix("FUN_").removeprefix("LAB_")


def value_context(values: list[Any], index: int, before: int = 8, after: int = 14) -> list[str]:
    start = max(0, index - before)
    end = min(len(values), index + after + 1)
    lines: list[str] = []
    for pos in range(start, end):
        marker = "=>" if pos == index else "  "
        lines.append(f"{marker} `{pos}` {compact(values[pos])}")
    return lines


def extract_module_info(module: str, values: list[Any]) -> dict[str, Any]:
    qualnames: list[dict[str, Any]] = []
    seen_qual = set()
    for i, value in enumerate(values):
        if is_function_qualname(value, module) and value not in seen_qual:
            seen_qual.add(value)
            qualnames.append({"index": i, "qualname": value})

    varlists = [{"index": i, "varnames": value} for i, value in enumerate(values) if is_varname_list(value)]
    structured = [{"index": i, "value": value} for i, value in enumerate(values) if is_structured(value)]
    source_paths = [
        value
        for value in values
        if isinstance(value, str)
        and value.endswith(".py")
        and "\n" not in value
        and " " not in value
        and ("\\" in value or "/" in value)
    ]
    docstrings = [
        {"index": i, "text": value}
        for i, value in enumerate(values)
        if isinstance(value, str) and ("\n" in value or len(value) > 80)
    ]

    return {
        "module": module,
        "qualnames": qualnames,
        "varlists": varlists,
        "structured": structured,
        "source_paths": source_paths,
        "docstrings": docstrings,
    }


def map_impls_to_qualnames(module: str, impls: list[dict[str, str]], qualnames: list[dict[str, Any]]) -> list[dict[str, Any]]:
    # Keep module-relevant qualnames. Nuitka includes helper/imported class code in
    # several modules, so do not over-filter by class name.
    impls_sorted = sorted(
        impls,
        key=lambda r: (
            10**9 if not r.get("line") else int(r["line"]),
            r.get("impl_entry", ""),
        ),
    )
    qual_sorted = list(qualnames)

    # Skip pure class-body entries and DAT pseudo-entries when assigning function names.
    assignable_impls = [r for r in impls_sorted if r.get("impl_entry", "").startswith(("FUN_", "LAB_"))]
    mapped: list[dict[str, Any]] = []

    qual_index = 0
    for impl in assignable_impls:
        if impl.get("qualname_hint"):
            qual = impl["qualname_hint"]
            qmatch = next((q for q in qual_sorted if q["qualname"] == qual), None)
            qindex = qmatch["index"] if qmatch else ""
        else:
            qual = qual_sorted[qual_index]["qualname"] if qual_index < len(qual_sorted) else ""
            qindex = qual_sorted[qual_index]["index"] if qual_index < len(qual_sorted) else ""
            qual_index += 1
        mapped.append({**impl, "inferred_qualname": qual, "qualname_constant_index": qindex})

    return mapped


def write_decompiled_impls(module: str, mapped: list[dict[str, Any]], decompiled: dict[str, str]) -> None:
    safe_module = module_to_dump_name(module)
    for row in mapped:
        impl = row.get("impl_entry", "")
        if not impl.startswith(("FUN_", "LAB_")):
            continue
        addr = impl_to_addr(impl)
        section = decompiled.get(addr)
        if not section:
            continue
        qual = row.get("inferred_qualname") or row.get("module_label") or "unknown"
        safe_name = re.sub(r"[^A-Za-z0-9_.-]+", "_", qual).strip("_") or "unknown"
        write_text(DECOMP_OUT / safe_module / f"{addr}_{safe_name}.c", section)


def build_module_markdown(
    module: str,
    values: list[Any],
    info: dict[str, Any],
    mapped_impls: list[dict[str, Any]],
    decompiled: dict[str, str],
) -> str:
    lines: list[str] = []
    title = module or "<root>"
    lines.append(f"# Function Specification: `{title}`")
    lines.append("")
    lines.append("This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.")
    lines.append("")

    if info["source_paths"]:
        lines.append("## Source Path Hints")
        for path in info["source_paths"]:
            lines.append(f"- `{path}`")
        lines.append("")

    if info["docstrings"]:
        lines.append("## Docstrings / Long Text")
        for row in info["docstrings"][:20]:
            lines.append(f"- `{row['index']}` {compact(row['text'], 500)}")
        if len(info["docstrings"]) > 20:
            lines.append(f"- ... {len(info['docstrings']) - 20} more")
        lines.append("")

    lines.append("## Function Inventory")
    if not mapped_impls and info["qualnames"]:
        for q in info["qualnames"]:
            lines.append(f"- `{q['qualname']}` at constant `{q['index']}`")
    elif mapped_impls:
        lines.append("| Inferred qualname | Impl | Source line | Arg count | Decompiled C |")
        lines.append("|---|---:|---:|---:|---|")
        for row in mapped_impls:
            impl = row.get("impl_entry", "")
            addr = impl_to_addr(impl)
            has_c = "yes" if addr in decompiled else "no"
            lines.append(
                f"| `{row.get('inferred_qualname') or '?'}` | `{impl}` | "
                f"{row.get('line') or '?'} | {row.get('arg_count') or '?'} | {has_c} |"
            )
    else:
        lines.append("- No function candidates recovered for this module.")
    lines.append("")

    if info["varlists"]:
        lines.append("## Local Variable Lists")
        for row in info["varlists"]:
            lines.append(f"- `{row['index']}` `{', '.join(row['varnames'])}`")
        lines.append("")

    if info["structured"]:
        lines.append("## Structured Constants")
        for row in info["structured"]:
            lines.append(f"- `{row['index']}` {compact(row['value'], 520)}")
        lines.append("")

    if mapped_impls:
        lines.append("## Per-Function Context")
        for row in mapped_impls:
            qual = row.get("inferred_qualname") or "?"
            impl = row.get("impl_entry", "")
            lines.append(f"### `{qual}`")
            lines.append("")
            lines.append(f"- implementation: `{impl}`")
            lines.append(f"- source line hint: `{row.get('line') or '?'}`")
            lines.append(f"- Nuitka codevar: `{row.get('codevar') or '?'}`")
            lines.append(f"- factory: `{row.get('factory') or '?'}`")
            qindex = row.get("qualname_constant_index")
            if isinstance(qindex, int):
                lines.append("- nearby constants:")
                for context_line in value_context(values, qindex):
                    lines.append(f"  {context_line}")
            impl_addr = impl_to_addr(impl)
            if impl_addr in decompiled:
                safe_module = module_to_dump_name(module)
                safe_name = re.sub(r"[^A-Za-z0-9_.-]+", "_", qual).strip("_") or "unknown"
                rel = DECOMP_OUT / safe_module / f"{impl_addr}_{safe_name}.c"
                lines.append(f"- decompiled C file: `{rel}`")
            lines.append("")

    return "\n".join(lines).rstrip() + "\n"


def main() -> int:
    OUT.mkdir(parents=True, exist_ok=True)
    DECOMP_OUT.mkdir(parents=True, exist_ok=True)

    dump_dir = ROOT / "custom_constant_dumps"
    modules: dict[str, list[Any]] = {
        dump_name_to_module(path.name): load_json(path)
        for path in sorted(dump_dir.glob("*.json"))
    }
    module_names = sorted(modules)

    raw_impls = load_csv(ROOT / "ghidra_exports" / "ghidra_custom_impl_candidates.csv")
    impls_by_module: dict[str, list[dict[str, str]]] = defaultdict(list)
    for row in raw_impls:
        module = normalize_module_label(row["module_label"], module_names)
        impls_by_module[module].append(row)

    decompiled = split_decompiled_sections(ROOT / "ghidra_exports" / "ghidra_decompile_custom_impls.c")

    index_lines = ["# Function Specs Index", ""]
    all_rows: list[dict[str, Any]] = []

    for module, values in sorted(modules.items()):
        info = extract_module_info(module, values)
        mapped = map_impls_to_qualnames(module, impls_by_module.get(module, []), info["qualnames"])
        write_decompiled_impls(module, mapped, decompiled)

        spec_path = OUT / f"{module_to_dump_name(module)}.md"
        write_text(spec_path, build_module_markdown(module, values, info, mapped, decompiled))

        index_lines.append(
            f"- [`{module or '<root>'}`]({spec_path}) "
            f"- qualnames={len(info['qualnames'])}, impls={len(mapped)}, varlists={len(info['varlists'])}"
        )
        for row in mapped:
            all_rows.append(
                {
                    "module": module,
                    "inferred_qualname": row.get("inferred_qualname", ""),
                    "impl_entry": row.get("impl_entry", ""),
                    "line": row.get("line", ""),
                    "arg_count": row.get("arg_count", ""),
                    "codevar": row.get("codevar", ""),
                    "qualname_hint": row.get("qualname_hint", ""),
                    "has_decompiled_c": impl_to_addr(row.get("impl_entry", "")) in decompiled,
                }
            )

    write_text(OUT / "INDEX.md", "\n".join(index_lines) + "\n")
    with (OUT / "function_map.csv").open("w", encoding="utf-8", newline="") as f:
        fieldnames = [
            "module",
            "inferred_qualname",
            "impl_entry",
            "line",
            "arg_count",
            "codevar",
            "qualname_hint",
            "has_decompiled_c",
        ]
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(all_rows)

    summary = {
        "module_count": len(modules),
        "mapped_function_count": len(all_rows),
        "decompiled_function_count": sum(1 for row in all_rows if row["has_decompiled_c"]),
        "output": str(OUT),
    }
    write_text(OUT / "SUMMARY.json", json.dumps(summary, ensure_ascii=False, indent=2))
    print(json.dumps(summary, ensure_ascii=False, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
