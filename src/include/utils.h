#pragma once

using byte = unsigned char;
using word = unsigned short;
using dword = unsigned int;

enum class Instruction : byte
{
    BRK = 0x00,      // BRK Implied (1 byte, 7 cycles)
    NOP = 0xEA,      // NOP Implied (1 byte, 2 cycles)

    ADC_IM = 0x69,   // ADC Immediate (2 bytes, 2 cycles)
    ADC_ZP = 0x65,   // ADC Zero Page (2 bytes, 3 cycles)
    ADC_ZPX = 0x75,  // ADC Zero Page X (2 bytes, 4 cycles)
    ADC_AB = 0x6D,   // ADC Absolute (3 bytes, 4 cycles)
    ADC_ABX = 0x7D,  // ADC Absolute X (3 bytes, 4 cycles)
    ADC_ABY = 0x79,  // ADC Absolute Y (3 bytes, 4 cycles)
    ADC_INX = 0x61,  // ADC Indirect X (2 bytes, 6 cycles)
    ADC_INY = 0x71,  // ADC Indirect Y (2 bytes, 5 cycles)

    AND_IM = 0x29,   // AND Immediate (2 bytes, 2 cycles)
    AND_ZP = 0x25,   // AND Zero Page (2 bytes, 3 cycles)
    AND_ZPX = 0x35,  // AND Zero Page X (2 bytes, 4 cycles)
    AND_AB = 0x2D,   // AND Absolute (3 bytes, 4 cycles)
    AND_ABX = 0x3D,  // AND Absolute X (3 bytes, 4 cycles)
    AND_ABY = 0x39,  // AND Absolute Y (3 bytes, 4 cycles)
    AND_INX = 0x21,  // AND Indirect X (2 bytes, 6 cycles)
    AND_INY = 0x31,  // AND Indirect Y (2 bytes, 5 cycles)

    ASL_ACC = 0x0A,  // ASL Accumulator (1 byte, 2 cycles)
    ASL_ZP = 0x06,   // ASL Zero Page (2 bytes, 5 cycles)
    ASL_ZPX = 0x16,  // ASL Zero Page X (2 bytes, 6 cycles)
    ASL_AB = 0x0E,   // ASL Absolute (3 bytes, 6 cycles)
    ASL_ABX = 0x1E,  // ASL Absolute X (3 bytes, 7 cycles)

    BCC = 0x90,      // BCC Relative (2 bytes, 2 cycles)
    BCS = 0xB0,      // BCS Relative (2 bytes, 2 cycles)
    BEQ = 0xF0,      // BEQ Relative (2 bytes, 2 cycles)
    BMI = 0x30,      // BMI Relative (2 bytes, 2 cycles)
    BNE = 0xD0,      // BNE Relative (2 bytes, 2 cycles)
    BPL = 0x10,      // BPL Relative (2 bytes, 2 cycles)
    BVC = 0x50,      // BVC Relative (2 bytes, 2 cycles)
    BVS = 0x70,      // BVS Relative (2 bytes, 2 cycles)

    BIT_ZP = 0x24,   // BIT Zero Page (2 bytes, 3 cycles)
    BIT_AB = 0x2C,   // BIT Absolute (3 bytes, 4 cycles)

    CLC = 0x18,      // CLC Implied (1 byte, 2 cycles)
    CLD = 0xD8,      // CLD Implied (1 byte, 2 cycles)
    CLI = 0x58,      // CLI Implied (1 byte, 2 cycles)
    CLV = 0xB8,      // CLV Implied (1 byte, 2 cycles)

    CMP_IM = 0xC9,   // CMP Immediate (2 bytes, 2 cycles)
    CMP_ZP = 0xC5,   // CMP Zero Page (2 bytes, 3 cycles)
    CMP_ZPX = 0xD5,  // CMP Zero Page X (2 bytes, 4 cycles)
    CMP_AB = 0xCD,   // CMP Absolute (3 bytes, 4 cycles)
    CMP_ABX = 0xDD,  // CMP Absolute X (3 bytes, 4 cycles)
    CMP_ABY = 0xD9,  // CMP Absolute Y (3 bytes, 4 cycles)
    CMP_INX = 0xC1,  // CMP Indirect X (2 bytes, 6 cycles)
    CMP_INY = 0xD1,  // CMP Indirect Y (2 bytes, 5 cycles)

    CPX_IM = 0xE0,   // CPX Immediate (2 bytes, 2 cycles)
    CPX_ZP = 0xE4,   // CPX Zero Page (2 bytes, 3 cycles)
    CPX_AB = 0xEC,   // CPX Absolute (3 bytes, 4 cycles)

    CPY_IM = 0xC0,   // CPY Immediate (2 bytes, 2 cycles)
    CPY_ZP = 0xC4,   // CPY Zero Page (2 bytes, 3 cycles)
    CPY_AB = 0xCC,   // CPY Absolute (3 bytes, 4 cycles)

    DEC_ZP = 0xC6,   // DEC Zero Page (2 bytes, 5 cycles)
    DEC_ZPX = 0xD6,  // DEC Zero Page X (2 bytes, 6 cycles)
    DEC_AB = 0xCE,   // DEC Absolute (3 bytes, 6 cycles)
    DEC_ABX = 0xDE,  // DEC Absolute X (3 bytes, 7 cycles)

    DEX = 0xCA,      // DEX Implied (1 byte, 2 cycles)
    DEY = 0x88,      // DEY Implied (1 byte, 2 cycles)

    EOR_IM = 0x49,   // EOR Immediate (2 bytes, 2 cycles)
    EOR_ZP = 0x45,   // EOR Zero Page (2 bytes, 3 cycles)
    EOR_ZPX = 0x55,  // EOR Zero Page X (2 bytes, 4 cycles)
    EOR_AB = 0x4D,   // EOR Absolute (3 bytes, 4 cycles)
    EOR_ABX = 0x5D,  // EOR Absolute X (3 bytes, 4 cycles)
    EOR_ABY = 0x59,  // EOR Absolute Y (3 bytes, 4 cycles)
    EOR_INX = 0x41,  // EOR Indirect X (2 bytes, 6 cycles)
    EOR_INY = 0x51,  // EOR Indirect Y (2 bytes, 5 cycles)

    INC_ZP = 0xE6,   // INC Zero Page (2 bytes, 5 cycles)
    INC_ZPX = 0xF6,  // INC Zero Page X (2 bytes, 6 cycles)
    INC_AB = 0xEE,   // INC Absolute (3 bytes, 6 cycles)
    INC_ABX = 0xFE,  // INC Absolute X (3 bytes, 7 cycles)

    INX = 0xE8,      // INX Implied (1 byte, 2 cycles)
    INY = 0xC8,      // INY Implied (1 byte, 2 cycles)

    JMP_AB = 0x4C,   // JMP Absolute (3 bytes, 3 cycles)
    JMP_IN = 0x6C,   // JMP Indirect (3 bytes, 5 cycles)
    JSR = 0x20,      // JSR Absolute (3 bytes, 6 cycles)

    LDA_IM = 0xA9,   // LDA Immediate (2 bytes, 2 cycles)
    LDA_ZP = 0xA5,   // LDA Zero Page (2 bytes, 3 cycles)
    LDA_ZPX = 0xB5,  // LDA Zero Page X (2 bytes, 4 cycles)
    LDA_AB = 0xAD,   // LDA Absolute (3 bytes, 4 cycles)
    LDA_ABX = 0xBD,  // LDA Absolute X (3 bytes, 4 cycles)
    LDA_ABY = 0xB9,  // LDA Absolute Y (3 bytes, 4 cycles)
    LDA_INX = 0xA1,  // LDA Indirect X (2 bytes, 6 cycles)
    LDA_INY = 0xB1,  // LDA Indirect Y (2 bytes, 5 cycles)

    LDX_IM = 0xA2,   // LDX Immediate (2 bytes, 2 cycles)
    LDX_ZP = 0xA6,   // LDX Zero Page (2 bytes, 3 cycles)
    LDX_ZPY = 0xB6,  // LDX Zero Page Y (2 bytes, 4 cycles)
    LDX_AB = 0xAE,   // LDX Absolute (3 bytes, 4 cycles)
    LDX_ABY = 0xBE,  // LDX Absolute Y (3 bytes, 4 cycles)

    LDY_IM = 0xA0,   // LDY Immediate (2 bytes, 2 cycles)
    LDY_ZP = 0xA4,   // LDY Zero Page (2 bytes, 3 cycles)
    LDY_ZPX = 0xB4,  // LDY Zero Page X (2 bytes, 4 cycles)
    LDY_AB = 0xAC,   // LDY Absolute (3 bytes, 4 cycles)
    LDY_ABX = 0xBC,  // LDY Absolute X (3 bytes, 4 cycles)

    LSR_ACC = 0x4A,  // LSR Accumulator (1 byte, 2 cycles)
    LSR_ZP = 0x46,   // LSR Zero Page (2 bytes, 5 cycles)
    LSR_ZPX = 0x56,  // LSR Zero Page X (2 bytes, 6 cycles)
    LSR_AB = 0x4E,   // LSR Absolute (3 bytes, 6 cycles)
    LSR_ABX = 0x5E,  // LSR Absolute X (3 bytes, 7 cycles)

    ORA_IM = 0x09,   // ORA Immediate (2 bytes, 2 cycles)
    ORA_ZP = 0x05,   // ORA Zero Page (2 bytes, 3 cycles)
    ORA_ZPX = 0x15,  // ORA Zero Page X (2 bytes, 4 cycles)
    ORA_AB = 0x0D,   // ORA Absolute (3 bytes, 4 cycles)
    ORA_ABX = 0x1D,  // ORA Absolute X (3 bytes, 4 cycles)
    ORA_ABY = 0x19,  // ORA Absolute Y (3 bytes, 4 cycles)
    ORA_INX = 0x01,  // ORA Indirect X (2 bytes, 6 cycles)
    ORA_INY = 0x11,  // ORA Indirect Y (2 bytes, 5 cycles)

    PHA = 0x48,      // PHA Implied (1 byte, 3 cycles)
    PHP = 0x08,      // PHP Implied (1 byte, 3 cycles)
    PLA = 0x68,      // PLA Implied (1 byte, 4 cycles)
    PLP = 0x28,      // PLP Implied (1 byte, 4 cycles)

    ROL_ACC = 0x2A,  // ROL Accumulator (1 byte, 2 cycles)
    ROL_ZP = 0x26,   // ROL Zero Page (2 bytes, 5 cycles)
    ROL_ZPX = 0x36,  // ROL Zero Page X (2 bytes, 6 cycles)
    ROL_AB = 0x2E,   // ROL Absolute (3 bytes, 6 cycles)
    ROL_ABX = 0x3E,  // ROL Absolute X (3 bytes, 7 cycles)

    ROR_ACC = 0x6A,  // ROR Accumulator (1 byte, 2 cycles)
    ROR_ZP = 0x66,   // ROR Zero Page (2 bytes, 5 cycles)
    ROR_ZPX = 0x76,  // ROR Zero Page X (2 bytes, 6 cycles)
    ROR_AB = 0x6E,   // ROR Absolute (3 bytes, 6 cycles)
    ROR_ABX = 0x7E,  // ROR Absolute X (3 bytes, 7 cycles)

    RTI = 0x40,      // RTI Implied (1 byte, 6 cycles)
    RTS = 0x60,      // RTS Implied (1 byte, 6 cycles)

    SBC_IM = 0xE9,   // SBC Immediate (2 bytes, 2 cycles)
    SBC_ZP = 0xE5,   // SBC Zero Page (2 bytes, 3 cycles)
    SBC_ZPX = 0xF5,  // SBC Zero Page X (2 bytes, 4 cycles)
    SBC_AB = 0xED,   // SBC Absolute (3 bytes, 4 cycles)
    SBC_ABX = 0xFD,  // SBC Absolute X (3 bytes, 4 cycles)
    SBC_ABY = 0xF9,  // SBC Absolute Y (3 bytes, 4 cycles)
    SBC_INX = 0xE1,  // SBC Indirect X (2 bytes, 6 cycles)
    SBC_INY = 0xF1,  // SBC Indirect Y (2 bytes, 5 cycles)

    SEC = 0x38,      // SEC Implied (1 byte, 2 cycles)
    SED = 0xF8,      // SED Implied (1 byte, 2 cycles)
    SEI = 0x78,      // SEI Implied (1 byte, 2 cycles)

    STA_ZP = 0x85,   // STA Zero Page (2 bytes, 3 cycles)
    STA_ZPX = 0x95,  // STA Zero Page X (2 bytes, 4 cycles)
    STA_AB = 0x8D,   // STA Absolute (3 bytes, 4 cycles)
    STA_ABX = 0x9D,  // STA Absolute X (3 bytes, 5 cycles)
    STA_ABY = 0x99,  // STA Absolute Y (3 bytes, 5 cycles)
    STA_INX = 0x81,  // STA Indirect X (2 bytes, 6 cycles)
    STA_INY = 0x91,  // STA Indirect Y (2 bytes, 6 cycles)

    STX_ZP = 0x86,   // STX Zero Page (2 bytes, 3 cycles)
    STX_ZPY = 0x96,  // STX Zero Page Y (2 bytes, 4 cycles)
    STX_AB = 0x8E,   // STX Absolute (3 bytes, 4 cycles)

    STY_ZP = 0x84,   // STY Zero Page (2 bytes, 3 cycles)
    STY_ZPX = 0x94,  // STY Zero Page X (2 bytes, 4 cycles)
    STY_AB = 0x8C,   // STY Absolute (3 bytes, 4 cycles)

    TAX = 0xAA,      // TAX Implied (1 byte, 2 cycles)
    TXA = 0x8A,      // TXA Implied (1 byte, 2 cycles)
    TAY = 0xA8,      // TAY Implied (1 byte, 2 cycles)
    TYA = 0x98,      // TYA Implied (1 byte, 2 cycles)

    TSX = 0xBA,      // TSX Implied (1 byte, 2 cycles)
    TXS = 0x9A,      // TXS Implied (1 byte, 2 cycles)
};
