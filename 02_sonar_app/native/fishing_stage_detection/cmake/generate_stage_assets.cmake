if(NOT DEFINED OUTPUT_FILE OR NOT DEFINED SOURCE_ROOT)
    message(FATAL_ERROR "OUTPUT_FILE and SOURCE_ROOT are required")
endif()

set(asset_rows
    "ad_fhd|AD.pgm"
    "ad_2k|AD_2k.pgm"
    "start_fhd|start_action.pgm"
    "start_2k|start_action_2k.pgm"
    "cast_fhd|cast_action.pgm"
    "cast_2k|cast_action_2k.pgm"
    "hook_fhd|hook_action.pgm"
    "hook_2k|hook_action_2k.pgm"
    "wait_fhd|wait_tension.pgm"
    "wait_2k|wait_tension_2k.pgm"
)

file(WRITE "${OUTPUT_FILE}"
    "#include \"embedded_stage_assets.h\"\n\n"
    "namespace sonar::fishing::stage_detection::detail {\nnamespace {\n")

foreach(row IN LISTS asset_rows)
    string(REPLACE "|" ";" fields "${row}")
    list(GET fields 0 symbol)
    list(GET fields 1 filename)
    file(READ "${SOURCE_ROOT}/${filename}" asset_hex HEX)
    string(LENGTH "${asset_hex}" hex_length)
    file(APPEND "${OUTPUT_FILE}"
        "static constexpr unsigned char k_${symbol}[] =\n")
    set(offset 0)
    while(offset LESS hex_length)
        math(EXPR remaining "${hex_length} - ${offset}")
        if(remaining GREATER 64)
            set(chunk_length 64)
        else()
            set(chunk_length ${remaining})
        endif()
        string(SUBSTRING "${asset_hex}" ${offset} ${chunk_length} chunk)
        string(REGEX REPLACE "(..)" "\\\\x\\1" escaped "${chunk}")
        file(APPEND "${OUTPUT_FILE}" "    \"${escaped}\"\n")
        math(EXPR offset "${offset} + ${chunk_length}")
    endwhile()
    file(APPEND "${OUTPUT_FILE}" ";\n")
endforeach()

file(APPEND "${OUTPUT_FILE}" "}  // namespace\n\n")
file(APPEND "${OUTPUT_FILE}"
    "std::span<const std::uint8_t> embedded_stage_asset(const embedded_stage_asset_id id) noexcept {\n"
    "  switch (id) {\n")
foreach(row IN LISTS asset_rows)
    string(REPLACE "|" ";" fields "${row}")
    list(GET fields 0 symbol)
    file(APPEND "${OUTPUT_FILE}"
        "    case embedded_stage_asset_id::${symbol}: return {k_${symbol}, sizeof(k_${symbol}) - 1};\n")
endforeach()
file(APPEND "${OUTPUT_FILE}"
    "  }\n  return {};\n}\n\n}  // namespace sonar::fishing::stage_detection\n")
