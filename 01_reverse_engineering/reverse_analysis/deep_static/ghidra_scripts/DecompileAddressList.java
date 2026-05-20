// Decompile specific functions by entry address.
// @category Sonar

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class DecompileAddressList extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 3) {
            throw new IllegalArgumentException("Usage: DecompileAddressList.java <address-file> <output-file> <timeout-seconds> [max-payload-mbytes]");
        }

        File addressFile = new File(args[0]);
        File outputFile = new File(args[1]);
        int timeout = Integer.parseInt(args[2]);
        int maxPayloadMBytes = args.length >= 4 ? Integer.parseInt(args[3]) : 512;
        outputFile.getParentFile().mkdirs();

        DecompInterface decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        options.grabFromProgram(currentProgram);
        options.setMaxPayloadMBytes(maxPayloadMBytes);
        options.setMaxInstructions(Math.max(options.getMaxInstructions(), 2000000));
        decompiler.setOptions(options);
        decompiler.openProgram(currentProgram);

        try (BufferedReader reader = new BufferedReader(new FileReader(addressFile));
             BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {
            String line;
            while ((line = reader.readLine()) != null && !monitor.isCancelled()) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }
                String[] parts = line.split(",", 2);
                String addressText = parts[0].trim();
                String label = parts.length > 1 ? parts[1].trim() : "";

                Address address = currentProgram.getAddressFactory().getAddress(addressText);
                Function function = currentProgram.getFunctionManager().getFunctionAt(address);
                if (function == null) {
                    function = currentProgram.getFunctionManager().getFunctionContaining(address);
                }
                String forceMessage = "";
                if (function == null) {
                    try {
                        disassemble(address);
                        createFunction(address, "forced_" + addressText);
                        function = currentProgram.getFunctionManager().getFunctionAt(address);
                    } catch (Exception e) {
                        forceMessage = "/* force-create function failed at " + addressText + ": " +
                            e.getMessage() + " */\n";
                    }
                }

                writer.write("\n/* ===== " + addressText + " " + label + " ===== */\n");
                if (!forceMessage.isEmpty()) {
                    writer.write(forceMessage);
                }
                if (function == null) {
                    writer.write("/* no function found */\n");
                    continue;
                }

                writer.write("/* ghidra_name=" + function.getName() + " entry=" + function.getEntryPoint() +
                    " size=" + function.getBody().getNumAddresses() + " */\n");
                monitor.setMessage("Decompiling " + function.getName() + " " + function.getEntryPoint());
                DecompileResults results = decompiler.decompileFunction(function, timeout, monitor);
                if (results != null && results.decompileCompleted() && results.getDecompiledFunction() != null) {
                    writer.write(results.getDecompiledFunction().getC());
                    writer.write("\n");
                } else {
                    writer.write("/* decompile failed */\n");
                    if (results != null) {
                        writer.write("/* " + results.getErrorMessage() + " */\n");
                    }
                }
            }
        } finally {
            decompiler.dispose();
        }

        println("DecompileAddressList complete: " + outputFile.getAbsolutePath());
    }
}
