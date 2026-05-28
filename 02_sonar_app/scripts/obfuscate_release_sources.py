from __future__ import annotations

import argparse
import io
import json
import keyword
import random
import re
import tokenize
from pathlib import Path
from token import NAME, STRING


PRIVATE_IDENTIFIER_RE = re.compile(r"\b_[A-Za-z][A-Za-z0-9_]*\b")
EXCLUDED_FILES = {
    Path("sonar") / "build_metadata.py",
    Path("sonar") / "security" / "literals.py",
}
SPECIAL_PRIVATE_NAMES = {
    "_",
    "_asdict",
    "_field_defaults",
    "_fields",
    "_fields_",
    "_generate_next_value_",
    "_make",
    "_missing_",
    "_name_",
    "_replace",
    "_source",
    "_value_",
}


def iter_python_files(source_root: Path) -> list[Path]:
    sonar_root = source_root / "sonar"
    return sorted(
        path
        for path in sonar_root.rglob("*.py")
        if path.is_file() and path.relative_to(source_root) not in EXCLUDED_FILES
    )


def is_private_candidate(name: str) -> bool:
    return (
        name not in SPECIAL_PRIVATE_NAMES
        and not keyword.iskeyword(name)
        and name.startswith("_")
        and not name.startswith("__")
        and not name.endswith("__")
    )


def tokens_for(path: Path) -> list[tokenize.TokenInfo]:
    return list(tokenize.generate_tokens(io.StringIO(path.read_text(encoding="utf-8")).readline))


def collect_names(paths: list[Path]) -> set[str]:
    candidates: set[str] = set()
    string_refs: set[str] = set()
    for path in paths:
        for token in tokens_for(path):
            if token.type == NAME and is_private_candidate(token.string):
                candidates.add(token.string)
            elif token.type == STRING:
                string_refs.update(PRIVATE_IDENTIFIER_RE.findall(token.string))
    return candidates - string_refs


def build_mapping(names: set[str], seed: str) -> dict[str, str]:
    rng = random.Random(seed)
    mapping: dict[str, str] = {}
    used = set(names)
    for name in sorted(names):
        while True:
            candidate = f"_sx{rng.getrandbits(64):016x}"
            if candidate not in used and candidate not in mapping.values():
                mapping[name] = candidate
                used.add(candidate)
                break
    return mapping


def rewrite_file(path: Path, mapping: dict[str, str]) -> int:
    tokens = tokens_for(path)
    changed = 0
    out: list[tokenize.TokenInfo] = []
    for token in tokens:
        replacement = mapping.get(token.string) if token.type == NAME else None
        if replacement:
            token = tokenize.TokenInfo(token.type, replacement, token.start, token.end, token.line)
            changed += 1
        out.append(token)
    if changed:
        path.write_text(tokenize.untokenize(out), encoding="utf-8")
    return changed


def obfuscate_release_sources(source_root: Path, seed: str) -> dict[str, object]:
    paths = iter_python_files(source_root)
    mapping = build_mapping(collect_names(paths), seed)
    changed_tokens = sum(rewrite_file(path, mapping) for path in paths)
    return {
        "seed": seed,
        "renamed_identifiers": len(mapping),
        "changed_tokens": changed_tokens,
        "excluded_files": sorted(str(path.as_posix()) for path in EXCLUDED_FILES),
    }


def main() -> int:
    parser = argparse.ArgumentParser(description="Obfuscate private Sonar identifiers in release sources.")
    parser.add_argument("--source-root", required=True, type=Path)
    parser.add_argument("--seed", required=True)
    parser.add_argument("--metadata-out", type=Path)
    args = parser.parse_args()
    metadata = obfuscate_release_sources(args.source_root.resolve(), args.seed)
    if args.metadata_out:
        args.metadata_out.parent.mkdir(parents=True, exist_ok=True)
        args.metadata_out.write_text(json.dumps(metadata, ensure_ascii=False, indent=2), encoding="utf-8")
    print(json.dumps(metadata, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
