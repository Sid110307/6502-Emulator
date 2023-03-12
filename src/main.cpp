#include <iostream>

#include "include/cpu.h"
#include "include/memory.h"

int main()
{
	Memory memory = Memory();

	CPU cpu = CPU();
	cpu.reset(memory);

	// BEGIN Code
	memory[0xFFFC] = (byte) Instruction::LDA_ZP;
	memory[0xFFFD] = 0x42;
	memory[0x0042] = 0x69;
	// END Code

	// TODO: Implement some way to automatically get the number of cycles.
	cpu.execute(3, memory);
	return EXIT_SUCCESS;
}
