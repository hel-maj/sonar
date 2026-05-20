# Reverse Analysis Status

## Folder Layout

- `P:\projects\Majestic\Sonar\00_original` contains the untouched original executable and config files.
- `P:\projects\Majestic\Sonar\01_reverse_engineering` contains extraction tools, extracted Nuitka files, Ghidra, and generated analysis.

## Static Nuitka Extraction

- Correct extraction: `01_reverse_engineering\kortexworker.exe_extracted_noskip`
- Main compiled module: `main.dll`
- Nuitka constant blob: `reverse_analysis\deep_static\pe_resource_type_10_id_3_lang_0.bin`
- Decoded blob modules: 1324
- Custom modules identified: 44
- Resource files cataloged: 191
- Decode errors: 0

Important generated reports:

- `constant_blob_summary.json`: full decoded module summary.
- `nuitka_blob_catalog.csv`: all internal Nuitka blob names and sizes.
- `custom_constant_dumps\*.json`: constants for each custom module.
- `strings_by_module.md`: custom strings/docstrings/log messages/config keys by module.
- `custom_symbol_inventory.md`: recovered class/function/method candidates.
- `custom_function_contexts.md`: nearby constants around each recovered qualname.
- `custom_varname_lists.md`: recovered local variable lists for functions.
- `custom_structured_constants.md`: ROI/default/config/template constants.
- `resource_catalog.csv`: PNG/icon resource dimensions, hashes, and groups.

## Ghidra Native Analysis

- Installed locally: `01_reverse_engineering\_tools\ghidra_12.1_PUBLIC`
- Project: `reverse_analysis\deep_static\ghidra_project\SonarMain`
- Program: `main.dll`
- Ghidra function count: 23348

Generated Ghidra reports:

- `ghidra_exports\ghidra_program_info.txt`
- `ghidra_exports\ghidra_functions.csv`
- `ghidra_exports\ghidra_symbols.csv`
- `ghidra_exports\ghidra_external_locations.csv`
- `ghidra_exports\ghidra_custom_string_refs.csv`
- `ghidra_exports\ghidra_module_native_map.md`
- `ghidra_exports\ghidra_decompile_custom_module_inits.c`
- `ghidra_exports\ghidra_custom_impl_candidates.csv`
- `ghidra_exports\ghidra_decompile_custom_impls.c`

The module-init pass now includes the app entry modules, license modules, UI, Telegram handlers, and fishing worker modules. `workers.fishing.fishing_bot` initially exceeded Ghidra's default response buffer, but decompiled successfully after increasing the decompiler payload limit.

The implementation pass currently maps 367 function/method entries to decompiled native pseudocode, backed by 364 unique decompiled entrypoint sections. The difference is duplicate/alias mappings that share native entrypoints. No current `ghidra_decompile_custom_impls.c` section contains `decompile failed` or `no function found`.

Generated function-spec reports:

- `reverse_analysis\function_specs\INDEX.md`
- `reverse_analysis\function_specs\COVERAGE.md`
- `reverse_analysis\function_specs\function_map.csv`
- `reverse_analysis\function_specs\decompiled_impls\...\*.c`
- one Markdown dossier per custom module.

## Practical Meaning

The original Python source is not stored as source text. Nuitka compiled it to native code. What is now recovered:

- module names and package structure,
- class/function/method names,
- many docstrings and log/UI messages,
- function local variable lists,
- argument/annotation/default-value hints,
- ROI coordinates, timing constants, template filenames, config defaults,
- native C pseudocode for all currently mapped custom implementation functions,
- asset catalog for fish/garbage/meal/trigger image templates.

Known gap: `workers.fishing.memory_reeling` has 21 recovered native implementation bodies while the constants list 25 `MemoryReelingTracker.*` qualnames. The remaining names are still represented by constants/local-variable lists, but need a lower-level pass if exact native bodies are required.

Remaining work is to turn the C pseudocode and recovered constants into human-readable behavioral specifications per function, then later rewrite new source from that specification.
