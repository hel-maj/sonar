// Ghidra headless post-script for static function/import/export summaries.
// @category Sonar

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Program;
import ghidra.program.model.symbol.ExternalLocation;
import ghidra.program.model.symbol.ExternalManager;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolTable;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

public class DumpSonarAnalysis extends GhidraScript {
    private String csv(String value) {
        if (value == null) {
            value = "";
        }
        return "\"" + value.replace("\"", "\"\"").replace("\r", "\\r").replace("\n", "\\n") + "\"";
    }

    private String addr(Address address) {
        return address == null ? "" : address.toString();
    }

    private void writeFunctions(File outDir) throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        File out = new File(outDir, "ghidra_functions.csv");
        try (BufferedWriter w = new BufferedWriter(new FileWriter(out))) {
            w.write("entry,name,namespace,signature,body_min,body_max,body_num_addresses,is_external,is_thunk,calling_convention\n");
            FunctionIterator it = fm.getFunctions(true);
            while (it.hasNext() && !monitor.isCancelled()) {
                Function f = it.next();
                String bodyMin = f.getBody() == null || f.getBody().isEmpty() ? "" : f.getBody().getMinAddress().toString();
                String bodyMax = f.getBody() == null || f.getBody().isEmpty() ? "" : f.getBody().getMaxAddress().toString();
                w.write(
                    csv(addr(f.getEntryPoint())) + "," +
                    csv(f.getName()) + "," +
                    csv(f.getParentNamespace().getName(true)) + "," +
                    csv(f.getSignature().toString()) + "," +
                    csv(bodyMin) + "," +
                    csv(bodyMax) + "," +
                    f.getBody().getNumAddresses() + "," +
                    f.isExternal() + "," +
                    f.isThunk() + "," +
                    csv(f.getCallingConventionName()) + "\n"
                );
            }
        }
    }

    private void writeSymbols(File outDir) throws Exception {
        SymbolTable symbols = currentProgram.getSymbolTable();
        File out = new File(outDir, "ghidra_symbols.csv");
        try (BufferedWriter w = new BufferedWriter(new FileWriter(out))) {
            w.write("address,name,namespace,type,source,is_external,is_primary\n");
            SymbolIterator it = symbols.getAllSymbols(true);
            while (it.hasNext() && !monitor.isCancelled()) {
                Symbol s = it.next();
                w.write(
                    csv(addr(s.getAddress())) + "," +
                    csv(s.getName()) + "," +
                    csv(s.getParentNamespace().getName(true)) + "," +
                    csv(s.getSymbolType().toString()) + "," +
                    csv(s.getSource().toString()) + "," +
                    s.isExternal() + "," +
                    s.isPrimary() + "\n"
                );
            }
        }
    }

    private void writeExternalLocations(File outDir) throws Exception {
        ExternalManager ext = currentProgram.getExternalManager();
        File out = new File(outDir, "ghidra_external_locations.csv");
        try (BufferedWriter w = new BufferedWriter(new FileWriter(out))) {
            w.write("library,label,address,original_imported_name\n");
            for (String libName : ext.getExternalLibraryNames()) {
                Iterator<ExternalLocation> it = ext.getExternalLocations(libName);
                while (it.hasNext() && !monitor.isCancelled()) {
                    ExternalLocation loc = it.next();
                    w.write(
                        csv(libName) + "," +
                        csv(loc.getLabel()) + "," +
                        csv(addr(loc.getAddress())) + "," +
                        csv(loc.getOriginalImportedName()) + "\n"
                    );
                }
            }
        }
    }

    private void writeProgramInfo(File outDir) throws Exception {
        File out = new File(outDir, "ghidra_program_info.txt");
        try (BufferedWriter w = new BufferedWriter(new FileWriter(out))) {
            w.write("Name: " + currentProgram.getName() + "\n");
            w.write("Executable path: " + currentProgram.getExecutablePath() + "\n");
            w.write("Language: " + currentProgram.getLanguageID() + "\n");
            w.write("Compiler: " + currentProgram.getCompilerSpec().getCompilerSpecID() + "\n");
            w.write("Image base: " + currentProgram.getImageBase() + "\n");
            w.write("Min address: " + currentProgram.getMinAddress() + "\n");
            w.write("Max address: " + currentProgram.getMaxAddress() + "\n");
            w.write("Function count: " + currentProgram.getFunctionManager().getFunctionCount() + "\n");
        }
    }

    private void decompileNamedOrLargest(File outDir, int maxFunctions) throws Exception {
        if (maxFunctions <= 0) {
            return;
        }

        List<Function> functions = new ArrayList<>();
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            Function f = it.next();
            if (!f.isExternal() && !f.isThunk()) {
                functions.add(f);
            }
        }
        Collections.sort(functions, new Comparator<Function>() {
            public int compare(Function a, Function b) {
                long diff = b.getBody().getNumAddresses() - a.getBody().getNumAddresses();
                if (diff < 0) return -1;
                if (diff > 0) return 1;
                return a.getEntryPoint().compareTo(b.getEntryPoint());
            }
        });

        DecompInterface decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        options.grabFromProgram(currentProgram);
        decompiler.setOptions(options);
        decompiler.openProgram(currentProgram);

        File out = new File(outDir, "ghidra_decompile_largest.c");
        try (BufferedWriter w = new BufferedWriter(new FileWriter(out))) {
            int count = Math.min(maxFunctions, functions.size());
            for (int i = 0; i < count && !monitor.isCancelled(); i++) {
                Function f = functions.get(i);
                monitor.setMessage("Decompiling " + f.getName() + " " + f.getEntryPoint());
                DecompileResults res = decompiler.decompileFunction(f, 60, monitor);
                w.write("\n/* ===== " + f.getName() + " @ " + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses() + " ===== */\n");
                if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                    w.write(res.getDecompiledFunction().getC());
                    w.write("\n");
                } else {
                    w.write("/* decompile failed */\n");
                    if (res != null) {
                        w.write("/* " + res.getErrorMessage() + " */\n");
                    }
                }
            }
        } finally {
            decompiler.dispose();
        }
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            throw new IllegalArgumentException("Usage: DumpSonarAnalysis.java <output-dir> [max-largest-decompile]");
        }
        File outDir = new File(args[0]);
        outDir.mkdirs();
        int maxFunctions = 0;
        if (args.length >= 2) {
            maxFunctions = Integer.parseInt(args[1]);
        }

        writeProgramInfo(outDir);
        writeFunctions(outDir);
        writeSymbols(outDir);
        writeExternalLocations(outDir);
        decompileNamedOrLargest(outDir, maxFunctions);
        println("DumpSonarAnalysis complete: " + outDir.getAbsolutePath());
    }
}
