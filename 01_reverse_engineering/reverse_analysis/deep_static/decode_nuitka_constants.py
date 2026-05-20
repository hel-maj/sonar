#!/usr/bin/env python3
"""Static decoder for Nuitka constant blobs embedded in main.dll resources.

The decoder mirrors Nuitka's HelpersConstantsBlob.c format closely enough to
recover module names, constants, code object metadata, strings, and blob-data
statistics without executing the target program.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import math
import pathlib
import re
import struct
from dataclasses import dataclass
from typing import Any


TAG_PREVIOUS = ord("p")
TAG_NONE = ord("n")
TAG_TRUE = ord("t")
TAG_FALSE = ord("F")
TAG_TUPLE = ord("T")
TAG_LIST = ord("L")
TAG_DICT = ord("D")
TAG_SET = ord("S")
TAG_FROZENSET = ord("P")
TAG_LONG_POSITIVE_SMALL = ord("l")
TAG_LONG_NEGATIVE_SMALL = ord("q")
TAG_LONG_POSITIVE_LARGE = ord("g")
TAG_LONG_NEGATIVE_LARGE = ord("G")
TAG_INT_POSITIVE = ord("i")
TAG_INT_NEGATIVE = ord("I")
TAG_FLOAT_SPECIAL = ord("Z")
TAG_FLOAT = ord("f")
TAG_TEXT_EMPTY = ord("s")
TAG_TEXT_SINGLE = ord("w")
TAG_TEXT_UTF8_LENGTH_PREFIXED = ord("v")
TAG_TEXT_UTF8_ZERO_TERMINATED = ord("u")
TAG_ATTRIBUTE_NAME = ord("a")
TAG_BYTES_LENGTH_PREFIXED = ord("b")
TAG_BYTES_ZERO_TERMINATED = ord("c")
TAG_BYTES_SINGLE = ord("d")
TAG_SLICE = ord(":")
TAG_RANGE = ord(";")
TAG_COMPLEX_SPECIAL = ord("J")
TAG_COMPLEX = ord("j")
TAG_BYTEARRAY = ord("B")
TAG_BUILTIN_ANON = ord("M")
TAG_BUILTIN_SPECIAL = ord("Q")
TAG_BLOB_DATA = ord("X")
TAG_GENERIC_ALIAS = ord("A")
TAG_UNION_TYPE = ord("H")
TAG_BUILTIN_NAMED = ord("O")
TAG_BUILTIN_EXCEPTION = ord("E")
TAG_CODE_OBJECT = ord("C")
TAG_END = ord(".")

CODE_FLAG_QUALNAME = 0x0000000000000001
CODE_FLAG_FREE_VARS = 0x0000000000000002
CODE_FLAG_KW_ONLY = 0x0000000000000004
CODE_FLAG_POS_ONLY = 0x0000000000000008
CODE_KIND_MASK = 0x0000000000000030
CODE_KIND_GENERATOR = 0x0000000000000010
CODE_KIND_COROUTINE = 0x0000000000000020
CODE_KIND_ASYNCGEN = 0x0000000000000030
CODE_FLAG_OPTIMIZED = 0x0000000000000040
CODE_FLAG_NEWLOCALS = 0x0000000000000080
CODE_FLAG_VARARGS = 0x0000000000000100
CODE_FLAG_VARKEYWORDS = 0x0000000000000200
CODE_FLAG_FUTURE_DIVISION = 0x0000000000000400
CODE_FLAG_FUTURE_UNICODE_LITERALS = 0x0000000000000800
CODE_FLAG_FUTURE_PRINT_FUNCTION = 0x0000000000001000
CODE_FLAG_FUTURE_ABSOLUTE_IMPORT = 0x0000000000002000
CODE_FLAG_FUTURE_GENERATOR_STOP = 0x0000000000004000
CODE_FLAG_FUTURE_ANNOTATIONS = 0x0000000000008000
CODE_FLAG_FUTURE_BARRY_AS_BDFL = 0x0000000000010000


CUSTOM_PREFIXES = (
    "",
    "__main__",
    "__parents_main__",
    "config_manager",
    "license",
    "telegram",
    "ui",
    "workers",
)


@dataclass
class BlobData:
    size: int
    sha256: str
    preview_hex: str


@dataclass
class CodeObject:
    module: str
    name: str
    qualname: str
    line: int
    arg_names: list[str]
    arg_count: int
    flags: int
    flag_names: list[str]
    kind: str
    kw_only_count: int
    pos_only_count: int
    free_vars: list[str]
    offset: int


class DecodeError(RuntimeError):
    pass


class Decoder:
    def __init__(self, data: bytes, module: str) -> None:
        self.data = data
        self.pos = 0
        self.module = module
        self.code_objects: list[CodeObject] = []
        self.strings: list[str] = []
        self.type_counts: dict[str, int] = {}

    def read(self, size: int) -> bytes:
        if self.pos + size > len(self.data):
            raise DecodeError(f"read past end at {self.pos}, size {size}, len {len(self.data)}")
        value = self.data[self.pos : self.pos + size]
        self.pos += size
        return value

    def read_u16(self) -> int:
        return struct.unpack("<H", self.read(2))[0]

    def read_u32(self) -> int:
        return struct.unpack("<I", self.read(4))[0]

    def read_double(self) -> float:
        return struct.unpack("<d", self.read(8))[0]

    def read_cstring_bytes(self) -> bytes:
        end = self.data.find(b"\x00", self.pos)
        if end < 0:
            raise DecodeError(f"missing null terminator at {self.pos}")
        value = self.data[self.pos : end]
        self.pos = end + 1
        return value

    def read_cstring(self) -> str:
        return self.read_cstring_bytes().decode("utf-8", "surrogatepass")

    def read_varint(self) -> int:
        result = 0
        factor = 1
        while True:
            value = self.read(1)[0]
            result += (value & 127) * factor
            if value < 128:
                return result
            factor <<= 7

    def bump(self, tag: int) -> None:
        key = chr(tag) if 32 <= tag < 127 else f"0x{tag:02x}"
        self.type_counts[key] = self.type_counts.get(key, 0) + 1

    def decode_all(self) -> list[Any]:
        count = self.read_u16()
        return self.decode_many(count)

    def decode_many(self, count: int) -> list[Any]:
        out: list[Any] = []
        for _ in range(count):
            out.append(self.decode_one(out))
        return out

    def decode_one(self, current_output: list[Any]) -> Any:
        start = self.pos
        tag = self.read(1)[0]
        self.bump(tag)

        if tag == TAG_PREVIOUS:
            if not current_output:
                raise DecodeError(f"previous tag without previous value at {start}")
            return current_output[-1]

        if tag == TAG_TUPLE:
            return tuple(self.decode_many(self.read_varint()))

        if tag == TAG_LIST:
            return self.decode_many(self.read_varint())

        if tag == TAG_DICT:
            size = self.read_varint()
            keys = self.decode_many(size)
            values = self.decode_many(size)
            return {"__dict_items__": list(zip(keys, values))}

        if tag in (TAG_SET, TAG_FROZENSET):
            size = self.read_varint()
            values = self.decode_many(size)
            return {"__set__" if tag == TAG_SET else "__frozenset__": values}

        if tag in (TAG_INT_POSITIVE, TAG_LONG_POSITIVE_SMALL):
            return self.read_varint()

        if tag in (TAG_INT_NEGATIVE, TAG_LONG_NEGATIVE_SMALL):
            return -self.read_varint()

        if tag in (TAG_LONG_POSITIVE_LARGE, TAG_LONG_NEGATIVE_LARGE):
            size = self.read_varint()
            result = 0
            for _ in range(size):
                result <<= 31
                result += self.read_varint()
            return -result if tag == TAG_LONG_NEGATIVE_LARGE else result

        if tag == TAG_FLOAT:
            return self.read_double()

        if tag == TAG_COMPLEX:
            return {"__complex__": [self.read_double(), self.read_double()]}

        if tag == TAG_COMPLEX_SPECIAL:
            parts = self.decode_many(2)
            return {"__complex__": parts}

        if tag == TAG_FLOAT_SPECIAL:
            value = self.read(1)[0]
            if value == 0:
                return 0.0
            if value == 1:
                return -0.0
            if value in (2, 3):
                return "-nan" if value == 3 else "nan"
            if value == 4:
                return math.inf
            if value == 5:
                return -math.inf
            raise DecodeError(f"unknown float special {value} at {start}")

        if tag == TAG_BYTES_ZERO_TERMINATED:
            raw = self.read_cstring_bytes()
            return {"__bytes__": raw.hex(), "size": len(raw)}

        if tag == TAG_BYTES_SINGLE:
            raw = self.read(1)
            return {"__bytes__": raw.hex(), "size": 1}

        if tag == TAG_BYTES_LENGTH_PREFIXED:
            size = self.read_varint()
            raw = self.read(size)
            return {"__bytes__": raw[:80].hex(), "size": size, "sha256": hashlib.sha256(raw).hexdigest()}

        if tag == TAG_BYTEARRAY:
            size = self.read_varint()
            raw = self.read(size)
            return {"__bytearray__": raw[:80].hex(), "size": size, "sha256": hashlib.sha256(raw).hexdigest()}

        if tag == TAG_TEXT_SINGLE:
            text = self.read(1).decode("utf-8", "surrogatepass")
            self.strings.append(text)
            return text

        if tag == TAG_TEXT_EMPTY:
            self.strings.append("")
            return ""

        if tag in (TAG_TEXT_UTF8_ZERO_TERMINATED, TAG_ATTRIBUTE_NAME):
            text = self.read_cstring()
            self.strings.append(text)
            return text

        if tag == TAG_TEXT_UTF8_LENGTH_PREFIXED:
            size = self.read_varint()
            text = self.read(size).decode("utf-8", "surrogatepass")
            self.strings.append(text)
            return text

        if tag == TAG_NONE:
            return None

        if tag == TAG_TRUE:
            return True

        if tag == TAG_FALSE:
            return False

        if tag == TAG_SLICE:
            return {"__slice__": self.decode_many(3)}

        if tag == TAG_RANGE:
            return {"__range__": self.decode_many(3)}

        if tag == TAG_BUILTIN_ANON:
            return {"__builtin_anon__": self.read(1)[0]}

        if tag == TAG_BUILTIN_SPECIAL:
            return {"__builtin_special__": self.read(1)[0]}

        if tag == TAG_BUILTIN_NAMED:
            return {"__builtin__": self.read_cstring()}

        if tag == TAG_BUILTIN_EXCEPTION:
            return {"__builtin_exception__": self.read_cstring()}

        if tag == TAG_BLOB_DATA:
            size = self.read_varint()
            raw = self.read(size)
            return BlobData(size=size, sha256=hashlib.sha256(raw).hexdigest(), preview_hex=raw[:48].hex())

        if tag == TAG_GENERIC_ALIAS:
            return {"__generic_alias__": self.decode_many(2)}

        if tag == TAG_UNION_TYPE:
            return {"__union_type__": self.decode_many(1)}

        if tag == TAG_CODE_OBJECT:
            return self.decode_code_object(start)

        if tag == TAG_END:
            raise DecodeError(f"unexpected END tag at {start}")

        raise DecodeError(f"unknown tag 0x{tag:02x} ({chr(tag)!r}) at {start}")

    def decode_code_object(self, start: int) -> CodeObject:
        flags = self.read_varint()
        function_name = self.decode_one([])
        line_number = self.read_varint() + 1
        arg_names_raw = self.decode_one([])
        arg_count = self.read_varint()

        if flags & CODE_FLAG_QUALNAME:
            qualname = self.decode_one([])
        else:
            qualname = function_name

        free_vars_raw: Any = ()
        if flags & CODE_FLAG_FREE_VARS:
            free_vars_raw = self.decode_one([])

        kw_only_count = self.read_varint() + 1 if flags & CODE_FLAG_KW_ONLY else 0
        pos_only_count = self.read_varint() + 1 if flags & CODE_FLAG_POS_ONLY else 0

        code = CodeObject(
            module=self.module,
            name=as_text(function_name),
            qualname=as_text(qualname),
            line=line_number,
            arg_names=as_string_list(arg_names_raw),
            arg_count=arg_count,
            flags=flags,
            flag_names=flag_names(flags),
            kind=code_kind(flags),
            kw_only_count=kw_only_count,
            pos_only_count=pos_only_count,
            free_vars=as_string_list(free_vars_raw),
            offset=start,
        )
        self.code_objects.append(code)
        return code


def as_text(value: Any) -> str:
    if isinstance(value, str):
        return value
    return repr(value)


def as_string_list(value: Any) -> list[str]:
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    if isinstance(value, (list, tuple)):
        return [as_text(item) for item in value]
    return [as_text(value)]


def flag_names(flags: int) -> list[str]:
    pairs = [
        ("QUALNAME", CODE_FLAG_QUALNAME),
        ("FREE_VARS", CODE_FLAG_FREE_VARS),
        ("KW_ONLY", CODE_FLAG_KW_ONLY),
        ("POS_ONLY", CODE_FLAG_POS_ONLY),
        ("OPTIMIZED", CODE_FLAG_OPTIMIZED),
        ("NEWLOCALS", CODE_FLAG_NEWLOCALS),
        ("VARARGS", CODE_FLAG_VARARGS),
        ("VARKEYWORDS", CODE_FLAG_VARKEYWORDS),
        ("FUTURE_DIVISION", CODE_FLAG_FUTURE_DIVISION),
        ("FUTURE_UNICODE_LITERALS", CODE_FLAG_FUTURE_UNICODE_LITERALS),
        ("FUTURE_PRINT_FUNCTION", CODE_FLAG_FUTURE_PRINT_FUNCTION),
        ("FUTURE_ABSOLUTE_IMPORT", CODE_FLAG_FUTURE_ABSOLUTE_IMPORT),
        ("FUTURE_GENERATOR_STOP", CODE_FLAG_FUTURE_GENERATOR_STOP),
        ("FUTURE_ANNOTATIONS", CODE_FLAG_FUTURE_ANNOTATIONS),
        ("FUTURE_BARRY_AS_BDFL", CODE_FLAG_FUTURE_BARRY_AS_BDFL),
    ]
    return [name for name, bit in pairs if flags & bit]


def code_kind(flags: int) -> str:
    kind = flags & CODE_KIND_MASK
    if kind == CODE_KIND_GENERATOR:
        return "generator"
    if kind == CODE_KIND_COROUTINE:
        return "coroutine"
    if kind == CODE_KIND_ASYNCGEN:
        return "asyncgen"
    return "function"


def json_safe(value: Any) -> Any:
    if isinstance(value, CodeObject):
        return {
            "__code_object__": value.qualname,
            "line": value.line,
            "args": value.arg_names,
            "kind": value.kind,
        }
    if isinstance(value, BlobData):
        return {
            "__blob_data__": value.size,
            "sha256": value.sha256,
            "preview_hex": value.preview_hex,
        }
    if isinstance(value, tuple):
        return [json_safe(item) for item in value]
    if isinstance(value, list):
        return [json_safe(item) for item in value]
    if isinstance(value, dict):
        return {str(json_safe(key)): json_safe(val) for key, val in value.items()}
    if isinstance(value, float):
        if math.isnan(value):
            return "nan"
        if math.isinf(value):
            return "inf" if value > 0 else "-inf"
    return value


def compact_value(value: Any, limit: int = 180) -> str:
    if isinstance(value, CodeObject):
        text = f"<code {value.qualname} line={value.line}>"
    elif isinstance(value, BlobData):
        text = f"<blob size={value.size} sha256={value.sha256[:12]}>"
    else:
        text = repr(json_safe(value))
    text = text.replace("\r", "\\r").replace("\n", "\\n")
    if len(text) > limit:
        text = text[: limit - 3] + "..."
    return text


def parse_blob_table(data: bytes) -> list[dict[str, Any]]:
    start = 8 if data[8:18] == b".bytecode\x00" else 0
    offset = start
    rows: list[dict[str, Any]] = []
    while offset < len(data):
        end = data.find(b"\x00", offset)
        if end < 0:
            raise DecodeError(f"missing blob name terminator at {offset}")
        name = data[offset:end].decode("utf-8", "replace")
        offset = end + 1
        if offset + 4 > len(data):
            raise DecodeError(f"missing blob size for {name!r} at {offset}")
        size = struct.unpack_from("<I", data, offset)[0]
        offset += 4
        rows.append(
            {
                "index": len(rows),
                "name": name,
                "payload_offset": offset,
                "size": size,
                "payload_end": offset + size,
            }
        )
        offset += size
    return rows


def is_custom_module(name: str) -> bool:
    if name in ("", "__main__"):
        return True
    return any(name == prefix or name.startswith(prefix + ".") for prefix in CUSTOM_PREFIXES if prefix)


def iter_resource_files(resources_dir: pathlib.Path) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    if not resources_dir.exists():
        return rows

    for path in sorted(resources_dir.rglob("*")):
        if not path.is_file():
            continue
        raw = path.read_bytes()
        width = height = None
        file_type = path.suffix.lower().lstrip(".")
        if raw.startswith(b"\x89PNG\r\n\x1a\n") and len(raw) >= 24:
            width, height = struct.unpack(">II", raw[16:24])
            file_type = "png"
        rows.append(
            {
                "path": str(path),
                "relative_path": str(path.relative_to(resources_dir)),
                "group": str(path.relative_to(resources_dir)).split("\\")[0],
                "type": file_type,
                "size": len(raw),
                "width": width,
                "height": height,
                "sha256": hashlib.sha256(raw).hexdigest(),
            }
        )
    return rows


def write_csv(path: pathlib.Path, rows: list[dict[str, Any]], fieldnames: list[str]) -> None:
    with path.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        for row in rows:
            writer.writerow({field: row.get(field, "") for field in fieldnames})


def write_module_code_objects(path: pathlib.Path, code_objects: list[CodeObject]) -> None:
    by_module: dict[str, list[CodeObject]] = {}
    for code in code_objects:
        by_module.setdefault(code.module, []).append(code)

    lines = ["# Nuitka code objects by module", ""]
    for module in sorted(by_module):
        lines.append(f"## {module or '<root>'}")
        for code in sorted(by_module[module], key=lambda item: (item.line, item.qualname)):
            args = ", ".join(code.arg_names)
            flags = ", ".join(code.flag_names) if code.flag_names else "-"
            lines.append(
                f"- line {code.line}: `{code.qualname}({args})` "
                f"[arg_count={code.arg_count}, kind={code.kind}, flags={flags}]"
            )
        lines.append("")
    path.write_text("\n".join(lines), encoding="utf-8")


def write_strings_by_module(path: pathlib.Path, module_strings: dict[str, list[str]]) -> None:
    lines = ["# Strings by custom module", ""]
    for module in sorted(module_strings):
        strings = sorted(set(s for s in module_strings[module] if s))
        lines.append(f"## {module or '<root>'}")
        for text in strings:
            compact = text.replace("\r", "\\r").replace("\n", "\\n")
            if len(compact) > 240:
                compact = compact[:237] + "..."
            lines.append(f"- `{compact}`")
        lines.append("")
    path.write_text("\n".join(lines), encoding="utf-8")


def write_reconstruction_map(path: pathlib.Path, code_objects: list[CodeObject], module_strings: dict[str, list[str]]) -> None:
    custom_modules = sorted({code.module for code in code_objects if is_custom_module(code.module)})
    lines = [
        "# Reconstruction map",
        "",
        "This is a static map from Nuitka metadata. It gives module/function coverage, arguments, lines, and strings. "
        "It is not original Python source and not a control-flow decompilation.",
        "",
        "## Custom modules",
    ]
    for module in custom_modules:
        module_codes = [code for code in code_objects if code.module == module]
        lines.append(f"- `{module or '<root>'}`: {len(module_codes)} code objects, {len(set(module_strings.get(module, [])))} unique strings")
    lines.extend(
        [
            "",
            "## Next reverse-engineering steps",
            "- Use the code-object report to assign each function to a module and expected signature.",
            "- Use the string report to recover constants, UI labels, template filenames, config keys, and log messages.",
            "- Use a native decompiler on `main.dll` to inspect the generated C-level function bodies for the custom modules.",
            "- Treat the license modules as architecture notes only; do not implement bypass logic.",
            "",
            "## High-value custom areas",
        ]
    )
    for prefix in [
        "workers.fishing.fishing_bot",
        "workers.fishing.fish_recognition",
        "workers.fishing.trigger_monitor",
        "workers.fishing.store_fish",
        "workers.fishing.garbage_disposal",
        "workers.fishing.meal_system",
        "workers.fishing.window_capture",
        "ui.fishing_tab",
        "telegram",
        "config_manager",
    ]:
        count = sum(1 for code in code_objects if code.module == prefix or code.module.startswith(prefix + "."))
        if count:
            lines.append(f"- `{prefix}`: {count} functions/classes/method code objects")
    lines.append("")
    path.write_text("\n".join(lines), encoding="utf-8")


QUALNAME_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*(?:\.[A-Za-z_<>][A-Za-z0-9_<>]*)+$")
IDENT_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]{2,}$")


COMMON_IDENTIFIERS = {
    "__class__",
    "__dict__",
    "__doc__",
    "__file__",
    "__init__",
    "__loader__",
    "__module__",
    "__name__",
    "__package__",
    "__path__",
    "__spec__",
    "append",
    "clear",
    "connect",
    "copy",
    "emit",
    "format",
    "get",
    "items",
    "join",
    "keys",
    "lower",
    "open",
    "read",
    "set",
    "sleep",
    "split",
    "start",
    "stop",
    "time",
    "upper",
    "values",
    "write",
}


def symbol_kind(text: str) -> str | None:
    if QUALNAME_RE.match(text):
        if "<locals>" in text:
            return "local_qualname"
        if text.split(".")[-1][:1].isupper():
            return "class_qualname"
        return "qualname"

    if IDENT_RE.match(text) and text not in COMMON_IDENTIFIERS:
        if text[:1].isupper():
            return "class_or_import"
        if text.startswith("_") or text.islower():
            return "function_or_attr"

    return None


def build_symbol_candidates(module_strings: dict[str, list[str]]) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    seen: set[tuple[str, str, str]] = set()

    for module, strings in sorted(module_strings.items()):
        if not is_custom_module(module):
            continue

        for index, text in enumerate(strings):
            kind = symbol_kind(text)
            if kind is None:
                continue
            key = (module, text, kind)
            if key in seen:
                continue
            seen.add(key)
            rows.append(
                {
                    "module": module,
                    "candidate": text,
                    "kind": kind,
                    "first_string_index": index,
                }
            )

    return rows


def write_symbol_inventory(path: pathlib.Path, rows: list[dict[str, Any]]) -> None:
    by_module: dict[str, list[dict[str, Any]]] = {}
    for row in rows:
        by_module.setdefault(row["module"], []).append(row)

    lines = ["# Custom symbol/function inventory", ""]
    lines.append(
        "These candidates come from Nuitka module constants. They include real "
        "classes/functions/methods plus some imported identifiers that need native "
        "decompiler confirmation."
    )
    lines.append("")

    for module in sorted(by_module):
        lines.append(f"## {module or '<root>'}")
        module_rows = sorted(by_module[module], key=lambda item: (item["kind"], item["candidate"]))
        for row in module_rows:
            lines.append(f"- `{row['candidate']}` ({row['kind']})")
        lines.append("")

    path.write_text("\n".join(lines), encoding="utf-8")


def write_function_contexts(path: pathlib.Path, custom_values: dict[str, list[Any]]) -> None:
    lines = ["# Custom function context windows", ""]
    lines.append(
        "Each block shows nearby top-level constants around a recovered qualname. "
        "This is useful for reconstructing docstrings, annotations, default values, "
        "called helper names, log messages, ROI constants, and state transitions."
    )
    lines.append("")

    for module in sorted(custom_values):
        values = custom_values[module]
        hits: list[tuple[int, str]] = []
        for index, value in enumerate(values):
            if isinstance(value, str):
                kind = symbol_kind(value)
                if kind in {"qualname", "local_qualname", "class_qualname"}:
                    hits.append((index, value))

        if not hits:
            continue

        lines.append(f"## {module or '<root>'}")
        for index, name in hits:
            lines.append(f"### {name} @ top-level constant {index}")
            start = max(0, index - 12)
            end = min(len(values), index + 25)
            for pos in range(start, end):
                marker = "=>" if pos == index else "  "
                lines.append(f"{marker} `{pos}` {compact_value(values[pos])}")
            lines.append("")
        lines.append("")

    path.write_text("\n".join(lines), encoding="utf-8")


def is_varname_list(value: Any) -> bool:
    if not isinstance(value, (list, tuple)) or not value:
        return False
    if not all(isinstance(item, str) for item in value):
        return False
    first = value[0]
    return first in {"self", ".0", "__class__"} or any(item in value for item in ("self", "args", "kwargs", "return"))


def collect_varname_lists(custom_values: dict[str, list[Any]]) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    for module, values in sorted(custom_values.items()):
        for index, value in enumerate(values):
            if is_varname_list(value):
                rows.append(
                    {
                        "module": module,
                        "constant_index": index,
                        "count": len(value),
                        "varnames": ", ".join(value),
                    }
                )
    return rows


def write_varname_lists(path: pathlib.Path, rows: list[dict[str, Any]]) -> None:
    by_module: dict[str, list[dict[str, Any]]] = {}
    for row in rows:
        by_module.setdefault(row["module"], []).append(row)

    lines = ["# Custom varname/local lists", ""]
    lines.append(
        "Nuitka leaves many function local-variable tuples as constants. "
        "The exact function binding still needs confirmation in the native "
        "decompiler, but these lists expose internal variables and workflow steps."
    )
    lines.append("")
    for module in sorted(by_module):
        lines.append(f"## {module or '<root>'}")
        for row in by_module[module]:
            lines.append(f"- `{row['constant_index']}` ({row['count']}): `{row['varnames']}`")
        lines.append("")
    path.write_text("\n".join(lines), encoding="utf-8")


def looks_structured_constant(value: Any) -> bool:
    if isinstance(value, dict):
        return True
    if isinstance(value, (list, tuple)) and value:
        if all(isinstance(item, (int, float, bool, type(None))) for item in value):
            return True
        if all(isinstance(item, (list, tuple)) for item in value):
            return True
    return False


def write_structured_constants(path: pathlib.Path, custom_values: dict[str, list[Any]]) -> None:
    lines = ["# Custom structured constants", ""]
    lines.append("Dictionaries and numeric/list constants that often represent ROI coordinates, defaults, and static maps.")
    lines.append("")
    for module in sorted(custom_values):
        hits = [(index, value) for index, value in enumerate(custom_values[module]) if looks_structured_constant(value)]
        if not hits:
            continue
        lines.append(f"## {module or '<root>'}")
        for index, value in hits:
            lines.append(f"- `{index}` {compact_value(value, limit=320)}")
        lines.append("")
    path.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--blob", required=True, type=pathlib.Path)
    parser.add_argument("--resources", required=True, type=pathlib.Path)
    parser.add_argument("--out", required=True, type=pathlib.Path)
    args = parser.parse_args()

    args.out.mkdir(parents=True, exist_ok=True)
    data = args.blob.read_bytes()
    entries = parse_blob_table(data)

    blob_catalog: list[dict[str, Any]] = []
    code_objects: list[CodeObject] = []
    module_strings: dict[str, list[str]] = {}
    custom_values: dict[str, list[Any]] = {}
    decode_errors: list[dict[str, Any]] = []
    module_summaries: list[dict[str, Any]] = []

    for entry in entries:
        name = entry["name"]
        payload = data[entry["payload_offset"] : entry["payload_end"]]
        blob_catalog.append(
            {
                **entry,
                "sha256": hashlib.sha256(payload).hexdigest(),
                "custom": is_custom_module(name),
            }
        )

        decoder = Decoder(payload, name)
        try:
            values = decoder.decode_all()
            if decoder.pos == len(payload) - 1 and payload[-1] == TAG_END:
                decoder.pos += 1
            if decoder.pos != len(payload):
                decode_errors.append(
                    {
                        "module": name,
                        "error": f"trailing bytes: pos {decoder.pos}, len {len(payload)}",
                    }
                )
            code_objects.extend(decoder.code_objects)
            module_strings[name] = decoder.strings
            blob_data_count = sum(1 for value in values if isinstance(value, BlobData))
            module_summaries.append(
                {
                    "name": name,
                    "index": entry["index"],
                    "size": entry["size"],
                    "constant_count": len(values),
                    "code_object_count": len(decoder.code_objects),
                    "string_count": len(decoder.strings),
                    "unique_string_count": len(set(decoder.strings)),
                    "blob_data_count": blob_data_count,
                    "type_counts": decoder.type_counts,
                    "custom": is_custom_module(name),
                }
            )

            if is_custom_module(name):
                custom_values[name] = values
                dump_path = args.out / "custom_constant_dumps"
                dump_path.mkdir(exist_ok=True)
                safe_name = (name or "_root_").replace(".", "__").replace("-", "_")
                (dump_path / f"{safe_name}.json").write_text(
                    json.dumps(json_safe(values), ensure_ascii=False, indent=2),
                    encoding="utf-8",
                )
        except Exception as exc:  # noqa: BLE001 - keep going across 1300+ modules.
            decode_errors.append({"module": name, "error": str(exc), "offset": decoder.pos})

    write_csv(
        args.out / "nuitka_blob_catalog.csv",
        blob_catalog,
        ["index", "name", "payload_offset", "size", "payload_end", "sha256", "custom"],
    )

    code_rows = [
        {
            "module": code.module,
            "qualname": code.qualname,
            "name": code.name,
            "line": code.line,
            "arg_names": ", ".join(code.arg_names),
            "arg_count": code.arg_count,
            "kind": code.kind,
            "flags_hex": f"0x{code.flags:x}",
            "flag_names": ", ".join(code.flag_names),
            "kw_only_count": code.kw_only_count,
            "pos_only_count": code.pos_only_count,
            "free_vars": ", ".join(code.free_vars),
            "constant_offset": code.offset,
            "custom": is_custom_module(code.module),
        }
        for code in code_objects
    ]
    write_csv(
        args.out / "code_objects.csv",
        code_rows,
        [
            "module",
            "qualname",
            "name",
            "line",
            "arg_names",
            "arg_count",
            "kind",
            "flags_hex",
            "flag_names",
            "kw_only_count",
            "pos_only_count",
            "free_vars",
            "constant_offset",
            "custom",
        ],
    )

    write_module_code_objects(args.out / "module_code_objects.md", code_objects)
    write_strings_by_module(
        args.out / "strings_by_module.md",
        {module: strings for module, strings in module_strings.items() if is_custom_module(module)},
    )

    symbol_rows = build_symbol_candidates(module_strings)
    write_csv(
        args.out / "custom_symbol_candidates.csv",
        symbol_rows,
        ["module", "candidate", "kind", "first_string_index"],
    )
    write_symbol_inventory(args.out / "custom_symbol_inventory.md", symbol_rows)
    write_function_contexts(args.out / "custom_function_contexts.md", custom_values)
    varname_rows = collect_varname_lists(custom_values)
    write_csv(
        args.out / "custom_varname_lists.csv",
        varname_rows,
        ["module", "constant_index", "count", "varnames"],
    )
    write_varname_lists(args.out / "custom_varname_lists.md", varname_rows)
    write_structured_constants(args.out / "custom_structured_constants.md", custom_values)

    write_reconstruction_map(args.out / "reconstruction_map.md", code_objects, module_strings)

    resources = iter_resource_files(args.resources)
    write_csv(
        args.out / "resource_catalog.csv",
        resources,
        ["relative_path", "group", "type", "size", "width", "height", "sha256", "path"],
    )

    summary = {
        "blob_file": str(args.blob),
        "blob_sha256": hashlib.sha256(data).hexdigest(),
        "blob_size": len(data),
        "blob_table_header_skip": 8 if data[8:18] == b".bytecode\x00" else 0,
        "module_count": len(entries),
        "custom_module_count": sum(1 for row in module_summaries if row["custom"]),
        "code_object_count": len(code_objects),
        "custom_code_object_count": sum(1 for code in code_objects if is_custom_module(code.module)),
        "custom_symbol_candidate_count": len(symbol_rows),
        "custom_varname_list_count": len(varname_rows),
        "resource_file_count": len(resources),
        "decode_error_count": len(decode_errors),
        "decode_errors": decode_errors[:200],
        "modules": module_summaries,
    }
    (args.out / "constant_blob_summary.json").write_text(
        json.dumps(summary, ensure_ascii=False, indent=2),
        encoding="utf-8",
    )

    print(json.dumps({k: summary[k] for k in summary if k not in ("modules", "decode_errors")}, ensure_ascii=False, indent=2))
    if decode_errors:
        print(f"decode_errors={len(decode_errors)}; see constant_blob_summary.json")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
