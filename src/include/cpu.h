#pragma once

#include <iostream>

#include "utils.h"
#include "memory.h"

class CPU
{
public:
	void reset(Memory &);
	void execute(dword, Memory &);

	byte fetchByte(dword &, Memory &);
	word fetchWord(dword &, Memory &);
	static byte readByte(dword &, byte, Memory &);

private:
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

	void setStatusFlags();
};
