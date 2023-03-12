#include "include/cpu.h"

void CPU::reset(Memory &memory)
{
	PC = 0xFFFC;
	SP = 0x00;
	A = 0x00;
	X = 0x00;
	Y = 0x00;
	C = 0x00;
	Z = 0x00;
	I = 0x00;
	D = 0x00;
	B = 0x00;
	U = 0x00;
	V = 0x00;
	N = 0x00;

	memory.init();
}

void CPU::execute(dword cycles, Memory &memory)
{
	while (cycles > 0)
	{
		byte opcode = fetchByte(cycles, memory);
		switch (opcode)
		{
			case (byte) Instruction::LDA_IM:
			{
				byte data = fetchByte(cycles, memory);

				A = data;
				setStatusFlags();
				break;
			}
			case (byte) Instruction::LDA_ZP:
			{
				byte address = fetchByte(cycles, memory);

				A = readByte(cycles, address, memory);
				setStatusFlags();
				break;
			}
			case (byte) Instruction::LDA_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				A = readByte(cycles, address + X, memory);
				setStatusFlags();
				break;
			}
			case (byte) Instruction::LDA_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				byte data = memory[address];

				A = data;
				setStatusFlags();
				break;
			}
			case (byte) Instruction::LDA_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				byte data = memory[address + X];

				A = data;
				setStatusFlags();
				break;
			}
			case (byte) Instruction::LDA_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				byte data = memory[address + Y];

				A = data;
				setStatusFlags();
				break;
			}
			case (byte) Instruction::LDA_INX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word data = memory[address + X];
				data |= memory[address + X + 1] << 8;
				A = memory[data];

				setStatusFlags();
				break;
			}
			case (byte) Instruction::LDA_INY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word data = memory[address];
				data |= memory[address + 1] << 8;
				A = memory[data + Y];

				setStatusFlags();
				break;
			}
			default:
			{
				std::cerr << "Unknown opcode: " << std::hex << (int) opcode << std::endl;
				break;
			}
		}
	}
}

byte CPU::fetchByte(dword &cycles, Memory &memory)
{
	byte data = memory[PC];
	PC++;
	cycles--;

	return data;
}

word CPU::fetchWord(dword &cycles, Memory &memory)
{
	word data = memory[PC];
	data |= memory[PC] << 8;
	PC += 2;
	cycles -= 2;

	#ifdef PLATFORM_BIG_ENDIAN
	data = ((data & 0xFF00) >> 8) | ((data & 0x00FF) << 8);
	#endif

	return data;
}

byte CPU::readByte(dword &cycles, byte address, Memory &memory)
{
	byte data = memory[address];
	cycles--;

	return data;
}

void CPU::setStatusFlags()
{
	Z = A == 0x00;
	N = (A & 0x80) != 0;
}
