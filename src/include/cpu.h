#pragma once

#include <iostream>

#include "utils.h"
#include "memory.h"

class CPU
{
public:
	CPU(Memory &);
	~CPU() = default;

	void reset();
	void execute(dword);

	byte fetchByte(dword &);
	word fetchWord(dword &);
	byte readByte(dword &, byte);

private:
	Memory memory;

	word PC; // Program Counter
	byte SP; // Stack Pointer

	byte A; // Accumulator
	byte X; // X Register
	byte Y; // Y Register

	byte C: 1; // Carry Flag
	byte Z: 1; // Zero Flag
	byte I: 1; // Interrupt Disable
	byte D: 1; // Decimal Mode
	byte B: 1; // Break Command
	byte U: 1; // Unused
	byte V: 1; // Overflow Flag
	byte N: 1; // Negative Flag

	void LDA(byte);
	void LDX();
	void ADC(byte);
	void SBC(byte);
	void AND(byte);
	void ORA(byte);
	void EOR(byte);
	void BIT(byte);
	void ASL(byte &);
	void LSR(byte &);
	void ROL(byte &);
	void ROR(byte &);
	void INC(byte &);
	void DEC(byte &);
	void CMP(byte, byte);
};
