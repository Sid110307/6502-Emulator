#pragma once

using byte = unsigned char;
using word = unsigned short;
using dword = unsigned int;

// TODO: Add more instructions.
enum class Instruction : byte
{
	LDA_IM = 0xA9,   // LDA Immediate
	LDA_ZP = 0xA5,   // LDA Zero Page
	LDA_ZPX = 0xB5,  // LDA Zero Page X
	LDA_AB = 0xAD,   // LDA Absolute
	LDA_ABX = 0xBD,  // LDA Absolute X
	LDA_ABY = 0xB9,  // LDA Absolute Y
	LDA_INX = 0xA1,  // LDA Indirect X
	LDA_INY = 0xB1,  // LDA Indirect Y

	STA_ZP = 0x85,   // STA Zero Page
	STA_ZPX = 0x95,  // STA Zero Page X
	STA_AB = 0x8D,   // STA Absolute
	STA_ABX = 0x9D,  // STA Absolute X
	STA_ABY = 0x99,  // STA Absolute Y
	STA_INX = 0x81,  // STA Indirect X
	STA_INY = 0x91,  // STA Indirect Y

	LDX_IM = 0xA2,   // LDX Immediate
	LDX_ZP = 0xA6,   // LDX Zero Page
	LDX_ZPY = 0xB6,  // LDX Zero Page Y
	LDX_AB = 0xAE,   // LDX Absolute
	LDX_ABY = 0xBE,  // LDX Absolute Y

	STX_ZP = 0x86,   // STX Zero Page
	STX_ZPY = 0x96,  // STX Zero Page Y
	STX_AB = 0x8E,   // STX Absolute

	LDY_IM = 0xA0,   // LDY Immediate
	LDY_ZP = 0xA4,   // LDY Zero Page
	LDY_ZPX = 0xB4,  // LDY Zero Page X
	LDY_AB = 0xAC,   // LDY Absolute
	LDY_ABX = 0xBC,  // LDY Absolute X

	STY_ZP = 0x84,   // STY Zero Page
	STY_ZPX = 0x94,  // STY Zero Page X
	STY_AB = 0x8C,   // STY Absolute

	// TODO: TAX, TAY, TXA, TYA.

	ADC_IM = 0x69,   // ADC Immediate
	ADC_ZP = 0x65,   // ADC Zero Page
	ADC_ZPX = 0x75,  // ADC Zero Page X
	ADC_AB = 0x6D,   // ADC Absolute
	ADC_ABX = 0x7D,  // ADC Absolute X
	ADC_ABY = 0x79,  // ADC Absolute Y
	ADC_INX = 0x61,  // ADC Indirect X
	ADC_INY = 0x71,  // ADC Indirect Y

	SBC_IM = 0xE9,   // SBC Immediate
	SBC_ZP = 0xE5,   // SBC Zero Page
	SBC_ZPX = 0xF5,  // SBC Zero Page X
	SBC_AB = 0xED,   // SBC Absolute
	SBC_ABX = 0xFD,  // SBC Absolute X
	SBC_ABY = 0xF9,  // SBC Absolute Y
	SBC_INX = 0xE1,  // SBC Indirect X
	SBC_INY = 0xF1,  // SBC Indirect Y

	AND_IM = 0x29,   // AND Immediate
	AND_ZP = 0x25,   // AND Zero Page
	AND_ZPX = 0x35,  // AND Zero Page X
	AND_AB = 0x2D,   // AND Absolute
	AND_ABX = 0x3D,  // AND Absolute X
	AND_ABY = 0x39,  // AND Absolute Y
	AND_INX = 0x21,  // AND Indirect X
	AND_INY = 0x31,  // AND Indirect Y

	ORA_IM = 0x09,   // ORA Immediate
	ORA_ZP = 0x05,   // ORA Zero Page
	ORA_ZPX = 0x15,  // ORA Zero Page X
	ORA_AB = 0x0D,   // ORA Absolute
	ORA_ABX = 0x1D,  // ORA Absolute X
	ORA_ABY = 0x19,  // ORA Absolute Y
	ORA_INX = 0x01,  // ORA Indirect X
	ORA_INY = 0x11,  // ORA Indirect Y

	EOR_IM = 0x49,   // EOR Immediate
	EOR_ZP = 0x45,   // EOR Zero Page
	EOR_ZPX = 0x55,  // EOR Zero Page X
	EOR_AB = 0x4D,   // EOR Absolute
	EOR_ABX = 0x5D,  // EOR Absolute X
	EOR_ABY = 0x59,  // EOR Absolute Y
	EOR_INX = 0x41,  // EOR Indirect X
	EOR_INY = 0x51,  // EOR Indirect Y

	BIT_ZP = 0x24,   // BIT Zero Page
	BIT_AB = 0x2C,   // BIT Absolute

	ASL_ACC = 0x0A,  // ASL Accumulator
	ASL_ZP = 0x06,   // ASL Zero Page
	ASL_ZPX = 0x16,  // ASL Zero Page X
	ASL_AB = 0x0E,   // ASL Absolute
	ASL_ABX = 0x1E,  // ASL Absolute X

	LSR_ACC = 0x4A,  // LSR Accumulator
	LSR_ZP = 0x46,   // LSR Zero Page
	LSR_ZPX = 0x56,  // LSR Zero Page X
	LSR_AB = 0x4E,   // LSR Absolute
	LSR_ABX = 0x5E,  // LSR Absolute X

	ROL_ACC = 0x2A,  // ROL Accumulator
	ROL_ZP = 0x26,   // ROL Zero Page
	ROL_ZPX = 0x36,  // ROL Zero Page X
	ROL_AB = 0x2E,   // ROL Absolute
	ROL_ABX = 0x3E,  // ROL Absolute X

	ROR_ACC = 0x6A,  // ROR Accumulator
	ROR_ZP = 0x66,   // ROR Zero Page
	ROR_ZPX = 0x76,  // ROR Zero Page X
	ROR_AB = 0x6E,   // ROR Absolute
	ROR_ABX = 0x7E,  // ROR Absolute X

	INC_ZP = 0xE6,   // INC Zero Page
	INC_ZPX = 0xF6,  // INC Zero Page X
	INC_AB = 0xEE,   // INC Absolute
	INC_ABX = 0xFE,  // INC Absolute X

	DEC_ZP = 0xC6,   // DEC Zero Page
	DEC_ZPX = 0xD6,  // DEC Zero Page X
	DEC_AB = 0xCE,   // DEC Absolute
	DEC_ABX = 0xDE,  // DEC Absolute X

	CMP_IM = 0xC9,   // CMP Immediate
	CMP_ZP = 0xC5,   // CMP Zero Page
	CMP_ZPX = 0xD5,  // CMP Zero Page X
	CMP_AB = 0xCD,   // CMP Absolute
	CMP_ABX = 0xDD,  // CMP Absolute X
	CMP_ABY = 0xD9,  // CMP Absolute Y
	CMP_INX = 0xC1,  // CMP Indirect X
	CMP_INY = 0xD1,  // CMP Indirect Y

	CPX_IM = 0xE0,   // CPX Immediate
	CPX_ZP = 0xE4,   // CPX Zero Page
	CPX_AB = 0xEC,   // CPX Absolute

	CPY_IM = 0xC0,   // CPY Immediate
	CPY_ZP = 0xC4,   // CPY Zero Page
	CPY_AB = 0xCC,   // CPY Absolute

	INX = 0xE8,  // INC X
	INY = 0xC8,  // INC Y
	DEX = 0xCA,  // DEC X
	DEY = 0x88,  // DEC Y

	CLC = 0x18,      // CLear Carry
	SEC = 0x38,      // SEt Carry
	CLI = 0x58,      // CLear Interrupt
	SEI = 0x78,      // SEt Interrupt
	CLV = 0xB8,      // CLear Overflow
	CLD = 0xD8,      // CLear Decimal
	SED = 0xF8,      // SEt Decimal

	BCC = 0x90,      // Branch if Carry Clear
	BCS = 0xB0,      // Branch if Carry Set
	BNE = 0xD0,      // Branch if Not Equal
	BEQ = 0xF0,      // Branch if Equal
	BPL = 0x10,      // Branch if Positive
	BMI = 0x30,      // Branch if Minus
	BVC = 0x50,      // Branch if Overflow Clear
	BVS = 0x70,      // Branch if Overflow Set

	JMP_AB = 0x4C,   // JMP Absolute
	JMP_IN = 0x6C,   // JMP Indirect
	JSR = 0x20,      // Jump to SubRoutine
	RTS = 0x60,      // ReTurn from Subroutine

	// TODO: TSX, TXS.
	PHA = 0x48,      // PusH Accumulator
	PLA = 0x68,      // PuLl Accumulator
	PHP = 0x08,      // PusH Processor status
	PLP = 0x28,      // PuLl Processor status

	BRK = 0x00,      // BReaK
	NOP = 0xEA,      // No OPeration
	RTI = 0x40,      // ReTurn from Interrupt
};
