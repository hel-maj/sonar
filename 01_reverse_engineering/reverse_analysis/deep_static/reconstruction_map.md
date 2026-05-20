# Reconstruction map

This is a static map from Nuitka metadata. It gives module/function coverage, arguments, lines, and strings. It is not original Python source and not a control-flow decompilation.

## Custom modules

## Next reverse-engineering steps
- Use the code-object report to assign each function to a module and expected signature.
- Use the string report to recover constants, UI labels, template filenames, config keys, and log messages.
- Use a native decompiler on `main.dll` to inspect the generated C-level function bodies for the custom modules.
- Treat the license modules as architecture notes only; do not implement bypass logic.

## High-value custom areas
