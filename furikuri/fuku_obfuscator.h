#pragma once

#include "fuku_mutation_imp.h"

class fuku_obfuscator {
    fuku_analyzed_code code;

    uint64_t destination_virtual_address;

    fuku_ob_settings settings;

    std::vector<fuku_code_association>*     association_table;
    std::vector<fuku_code_relocation>*      relocation_table;
    std::vector<fuku_code_ip_relocation>*   ip_relocation_table;

    void    fuku_obfuscator::spagetti_code(linestorage& lines, uint64_t virtual_address);
    void    fuku_obfuscator::handle_jmps(linestorage& lines);
    void    fuku_obfuscator::lines_correction(linestorage& lines, uint64_t virtual_address);
    void    fuku_obfuscator::finalize_code();
    void    fuku_obfuscator::useless_flags_profiler(); 

    std::vector<uint8_t>  fuku_obfuscator::lines_to_bin(linestorage&  lines);

    uint32_t fuku_obfuscator::set_label(fuku_instruction& line);
    uint32_t fuku_obfuscator::get_maxlabel() const;
public:
    fuku_obfuscator::fuku_obfuscator();
    fuku_obfuscator::~fuku_obfuscator();

    void fuku_obfuscator::obfuscate_code();
    std::vector<uint8_t> fuku_obfuscator::get_code();
public:
    void fuku_obfuscator::set_code(const fuku_code_analyzer& code);
    void fuku_obfuscator::set_code(const fuku_analyzed_code& code);

    void fuku_obfuscator::set_destination_virtual_address(uint64_t destination_virtual_address);
    void fuku_obfuscator::set_settings(const fuku_ob_settings& settings);

    void fuku_obfuscator::set_association_table(std::vector<fuku_code_association>*	associations);
    void fuku_obfuscator::set_relocation_table(std::vector<fuku_code_relocation>* relocations);
    void fuku_obfuscator::set_ip_relocation_table(std::vector<fuku_code_ip_relocation>* relocations); //be returned only external rip relocations
public:  
    fuku_arch    fuku_obfuscator::get_arch() const;
    const linestorage& fuku_obfuscator::get_lines() const;
    uint64_t     fuku_obfuscator::get_destination_virtual_address() const;
    fuku_ob_settings fuku_obfuscator::get_settings() const;

    const std::vector<fuku_code_association>    fuku_obfuscator::get_association_table() const;
    const std::vector<fuku_code_relocation>     fuku_obfuscator::get_relocation_table() const;
    const std::vector<fuku_code_ip_relocation>  fuku_obfuscator::get_ip_relocation_table() const;
};
