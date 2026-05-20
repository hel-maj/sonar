// Dump xrefs to custom Nuitka string labels created by Ghidra.
// @category Sonar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

public class DumpCustomStringRefs extends GhidraScript {
    private String csv(String value) {
        if (value == null) {
            value = "";
        }
        return "\"" + value.replace("\"", "\"\"").replace("\r", "\\r").replace("\n", "\\n") + "\"";
    }

    private boolean isCustomStringLabel(String name) {
        if (!name.startsWith("s_")) {
            return false;
        }
        return name.contains("__main__") ||
            name.contains("__parents_main__") ||
            name.contains("LicensedApplication") ||
            name.contains("workers.") ||
            name.contains("FishingBot") ||
            name.contains("FishRecognition") ||
            name.contains("FishStorer") ||
            name.contains("TriggerMonitor") ||
            name.contains("MealSystem") ||
            name.contains("GarbageDisposal") ||
            name.contains("WindowCapture") ||
            name.contains("WindowActivator") ||
            name.contains("ConfigManager") ||
            name.contains("LicenseClient") ||
            name.contains("ActivationDialog") ||
            name.contains("HWID") ||
            name.contains("license.") ||
            name.contains("telegram.") ||
            name.contains("ui.") ||
            name.contains("config_manager");
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            throw new IllegalArgumentException("Usage: DumpCustomStringRefs.java <output-dir>");
        }
        File outDir = new File(args[0]);
        outDir.mkdirs();
        File out = new File(outDir, "ghidra_custom_string_refs.csv");
        ReferenceManager refs = currentProgram.getReferenceManager();

        try (BufferedWriter w = new BufferedWriter(new FileWriter(out))) {
            w.write("string_address,string_label,ref_from,ref_type,ref_function_entry,ref_function_name\n");
            SymbolIterator it = currentProgram.getSymbolTable().getAllSymbols(true);
            while (it.hasNext() && !monitor.isCancelled()) {
                Symbol s = it.next();
                String name = s.getName();
                if (!isCustomStringLabel(name)) {
                    continue;
                }
                Address target = s.getAddress();
                ReferenceIterator refIt = refs.getReferencesTo(target);
                boolean wrote = false;
                while (refIt.hasNext() && !monitor.isCancelled()) {
                    Reference ref = refIt.next();
                    Function f = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
                    w.write(
                        csv(target.toString()) + "," +
                        csv(name) + "," +
                        csv(ref.getFromAddress().toString()) + "," +
                        csv(ref.getReferenceType().toString()) + "," +
                        csv(f == null ? "" : f.getEntryPoint().toString()) + "," +
                        csv(f == null ? "" : f.getName()) + "\n"
                    );
                    wrote = true;
                }
                if (!wrote) {
                    w.write(csv(target.toString()) + "," + csv(name) + ",,,,\n");
                }
            }
        }
        println("DumpCustomStringRefs complete: " + out.getAbsolutePath());
    }
}
