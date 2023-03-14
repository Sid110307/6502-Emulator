#include "include/cpu.h"

CPU::CPU(Memory &memory) // NOLINT (cppcoreguidelines-pro-type-member-init)
{
	this->memory = memory;
	reset();
}

void CPU::reset()
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

void CPU::execute(dword cycles)
{
	while (cycles > 0)
	{
		byte opcode = fetchByte(cycles);
		switch (opcode)
		{
			case (byte) Instruction::BRK:
			{
				PC++;
				memory[SP] = (byte) (PC >> 8);
				SP--;
				memory[SP] = (byte) PC;
				SP--;

				byte status = 0x00;
				status |= C << 0;
				status |= Z << 1;
				status |= I << 2;
				status |= D << 3;
				status |= B << 4;
				status |= U << 5;
				status |= V << 6;
				status |= N << 7;

				memory[SP] = status;
				SP--;

				PC = memory[0xFFFE] | (memory[0xFFFF] << 8);
				break;
			}
			case (byte) Instruction::NOP:
			{
				break;
			}
			case (byte) Instruction::ADC_IM:
			{
				ADC(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::ADC_ZP:
			{
				ADC(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::ADC_ZPX:
			{
				ADC(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::ADC_AB:
			{
				ADC(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::ADC_ABX:
			{
				ADC(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::ADC_ABY:
			{
				ADC(memory[fetchWord(cycles) + Y]);
				break;
			}
			case (byte) Instruction::ADC_INX:
			{
				ADC(memory[memory[fetchByte(cycles) + X]]);
				break;
			}
			case (byte) Instruction::ADC_INY:
			{
				ADC(memory[memory[fetchByte(cycles)] + Y]);
				break;
			}
			case (byte) Instruction::AND_IM:
			{
				AND(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::AND_ZP:
			{
				AND(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::AND_ZPX:
			{
				AND(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::AND_AB:
			{
				AND(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::AND_ABX:
			{
				AND(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::AND_ABY:
			{
				AND(memory[fetchWord(cycles) + Y]);
				break;
			}
			case (byte) Instruction::AND_INX:
			{
				AND(memory[memory[fetchByte(cycles) + X]]);
				break;
			}
			case (byte) Instruction::AND_INY:
			{
				AND(memory[memory[fetchByte(cycles)] + Y]);
				break;
			}
			case (byte) Instruction::ASL_ACC:
			{
				ASL(A);
				break;
			}
			case (byte) Instruction::ASL_ZP:
			{
				ASL(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::ASL_ZPX:
			{
				ASL(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::ASL_AB:
			{
				ASL(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::ASL_ABX:
			{
				ASL(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::BCC:
			{
				BCC(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::BCS:
			{
				BCS(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::BEQ:
			{
				BEQ(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::BMI:
			{
				BMI(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::BNE:
			{
				BNE(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::BPL:
			{
				BPL(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::BVC:
			{
				BVC(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::BVS:
			{
				BVS(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::BIT_ZP:
			{
				BIT(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::BIT_AB:
			{
				BIT(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::CLC:
			{
				C = false;
				break;
			}
			case (byte) Instruction::CLD:
			{
				D = false;
				break;
			}
			case (byte) Instruction::CLI:
			{
				I = false;
				break;
			}
			case (byte) Instruction::CLV:
			{
				V = false;
				break;
			}
			case (byte) Instruction::CMP_IM:
			{
				CMP(A, fetchByte(cycles));
				break;
			}
			case (byte) Instruction::CMP_ZP:
			{
				CMP(A, memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::CMP_ZPX:
			{
				CMP(A, memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::CMP_AB:
			{
				CMP(A, memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::CMP_ABX:
			{
				CMP(A, memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::CMP_ABY:
			{
				CMP(A, memory[fetchWord(cycles) + Y]);
				break;
			}
			case (byte) Instruction::CMP_INX:
			{
				CMP(A, memory[memory[fetchByte(cycles) + X]]);
				break;
			}
			case (byte) Instruction::CMP_INY:
			{
				CMP(A, memory[memory[fetchByte(cycles)] + Y]);
				break;
			}
			case (byte) Instruction::CPX_IM:
			{
				CMP(X, fetchByte(cycles));
				break;
			}
			case (byte) Instruction::CPX_ZP:
			{
				CMP(X, memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::CPX_AB:
			{
				CMP(X, memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::CPY_IM:
			{
				CMP(Y, fetchByte(cycles));
				break;
			}
			case (byte) Instruction::CPY_ZP:
			{
				CMP(Y, memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::CPY_AB:
			{
				CMP(Y, memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::DEC_ZP:
			{
				DEC(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::DEC_ZPX:
			{
				DEC(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::DEC_AB:
			{
				DEC(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::DEC_ABX:
			{
				DEC(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::DEX:
			{
				DEC(X);
				break;
			}
			case (byte) Instruction::DEY:
			{
				DEC(Y);
				break;
			}
			case (byte) Instruction::EOR_IM:
			{
				EOR(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::EOR_ZP:
			{
				EOR(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::EOR_ZPX:
			{
				EOR(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::EOR_AB:
			{
				EOR(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::EOR_ABX:
			{
				EOR(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::EOR_ABY:
			{
				EOR(memory[fetchWord(cycles) + Y]);
				break;
			}
			case (byte) Instruction::EOR_INX:
			{
				EOR(memory[memory[fetchByte(cycles) + X]]);
				break;
			}
			case (byte) Instruction::EOR_INY:
			{
				EOR(memory[memory[fetchByte(cycles)] + Y]);
				break;
			}
			case (byte) Instruction::INC_ZP:
			{
				INC(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::INC_ZPX:
			{
				INC(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::INC_AB:
			{
				INC(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::INC_ABX:
			{
				INC(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::INX:
			{
				INC(X);
				break;
			}
			case (byte) Instruction::INY:
			{
				INC(Y);
				break;
			}
			case (byte) Instruction::JMP_AB:
			{
				PC = fetchWord(cycles);
				break;
			}
			case (byte) Instruction::JMP_IN:
			{
				PC = memory[fetchWord(cycles)];
				break;
			}
			case (byte) Instruction::JSR:
			{
				PC = fetchWord(cycles);
				break;
			}
			case (byte) Instruction::LDA_IM:
			{
				LDA(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::LDA_ZP:
			{
				LDA(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::LDA_ZPX:
			{
				LDA(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::LDA_AB:
			{
				LDA(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::LDA_ABX:
			{
				LDA(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::LDA_ABY:
			{
				LDA(memory[fetchWord(cycles) + Y]);
				break;
			}
			case (byte) Instruction::LDA_INX:
			{
				LDA(memory[memory[fetchByte(cycles) + X]]);
				break;
			}
			case (byte) Instruction::LDA_INY:
			{
				LDA(memory[memory[fetchByte(cycles)] + Y]);
				break;
			}
			case (byte) Instruction::LDX_IM:
			{
				LDX(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::LDX_ZP:
			{
				LDX(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::LDX_ZPY:
			{
				LDX(memory[fetchByte(cycles) + Y]);
				break;
			}
			case (byte) Instruction::LDX_AB:
			{
				LDX(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::LDX_ABY:
			{
				LDX(memory[fetchWord(cycles) + Y]);
				break;
			}
			case (byte) Instruction::LDY_IM:
			{
				LDY(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::LDY_ZP:
			{
				LDY(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::LDY_ZPX:
			{
				LDY(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::LDY_AB:
			{
				LDY(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::LDY_ABX:
			{
				LDY(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::LSR_ACC:
			{
				LSR(A);
				break;
			}
			case (byte) Instruction::LSR_ZP:
			{
				LSR(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::LSR_ZPX:
			{
				LSR(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::LSR_AB:
			{
				LSR(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::LSR_ABX:
			{
				LSR(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::ORA_IM:
			{
				ORA(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::ORA_ZP:
			{
				ORA(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::ORA_ZPX:
			{
				ORA(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::ORA_AB:
			{
				ORA(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::ORA_ABX:
			{
				ORA(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::ORA_ABY:
			{
				ORA(memory[fetchWord(cycles) + Y]);
				break;
			}
			case (byte) Instruction::ORA_INX:
			{
				ORA(memory[memory[fetchByte(cycles) + X]]);
				break;
			}
			case (byte) Instruction::ORA_INY:
			{
				ORA(memory[memory[fetchByte(cycles)] + Y]);
				break;
			}
			case (byte) Instruction::PHA:
			{
				memory[0x100 + SP] = A;
				SP--;
				break;
			}
			case (byte) Instruction::PHP:
			{
				memory[0x100 + SP] = (byte) (C | Z | I | D | B | U | V | N);
				SP--;
				break;
			}
			case (byte) Instruction::PLA:
			{
				SP++;
				A = memory[0x100 + SP];
				break;
			}
			case (byte) Instruction::PLP:
			{
				SP++;
				byte flags = memory[0x100 + SP];

				C = (flags & 0x01) != 0;
				Z = (flags & 0x02) != 0;
				I = (flags & 0x04) != 0;
				D = (flags & 0x08) != 0;
				B = (flags & 0x10) != 0;
				U = (flags & 0x20) != 0;
				V = (flags & 0x40) != 0;
				N = (flags & 0x80) != 0;

				break;
			}
			case (byte) Instruction::ROL_ACC:
			{
				ROL(A);
				break;
			}
			case (byte) Instruction::ROL_ZP:
			{
				ROL(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::ROL_ZPX:
			{
				ROL(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::ROL_AB:
			{
				ROL(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::ROL_ABX:
			{
				ROL(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::ROR_ACC:
			{
				ROR(A);
				break;
			}
			case (byte) Instruction::ROR_ZP:
			{
				ROR(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::ROR_ZPX:
			{
				ROR(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::ROR_AB:
			{
				ROR(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::ROR_ABX:
			{
				ROR(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::RTI:
			{
				SP++;
				byte status = memory[0x100 + SP];
				SP++;
				PC = memory[0x100 + SP];
				SP++;
				PC += memory[0x100 + SP] << 8;

				C = status & 0x01;
				Z = status & 0x02;
				I = status & 0x04;
				D = status & 0x08;
				B = status & 0x10;
				V = status & 0x40;
				N = status & 0x80;

				break;
			}
			case (byte) Instruction::RTS:
			{
				SP++;
				PC = memory[0x100 + SP];
				SP++;
				PC += memory[0x100 + SP] << 8;

				break;
			}
			case (byte) Instruction::SBC_IM:
			{
				SBC(fetchByte(cycles));
				break;
			}
			case (byte) Instruction::SBC_ZP:
			{
				SBC(memory[fetchByte(cycles)]);
				break;
			}
			case (byte) Instruction::SBC_ZPX:
			{
				SBC(memory[fetchByte(cycles) + X]);
				break;
			}
			case (byte) Instruction::SBC_AB:
			{
				SBC(memory[fetchWord(cycles)]);
				break;
			}
			case (byte) Instruction::SBC_ABX:
			{
				SBC(memory[fetchWord(cycles) + X]);
				break;
			}
			case (byte) Instruction::SBC_ABY:
			{
				SBC(memory[fetchWord(cycles) + Y]);
				break;
			}
			case (byte) Instruction::SBC_INX:
			{
				SBC(memory[memory[fetchByte(cycles) + X]]);
				break;
			}
			case (byte) Instruction::SBC_INY:
			{
				SBC(memory[memory[fetchByte(cycles)] + Y]);
				break;
			}
			case (byte) Instruction::SEC:
			{
				C = true;
				break;
			}
			case (byte) Instruction::SED:
			{
				D = true;
				break;
			}
			case (byte) Instruction::SEI:
			{
				I = true;
				break;
			}
			case (byte) Instruction::STA_ZP:
			{
				memory[fetchByte(cycles)] = A;
				break;
			}
			case (byte) Instruction::STA_ZPX:
			{
				memory[fetchByte(cycles) + X] = A;
				break;
			}
			case (byte) Instruction::STA_AB:
			{
				memory[fetchWord(cycles)] = A;
				break;
			}
			case (byte) Instruction::STA_ABX:
			{
				memory[fetchWord(cycles) + X] = A;
				break;
			}
			case (byte) Instruction::STA_ABY:
			{
				memory[fetchWord(cycles) + Y] = A;
				break;
			}
			case (byte) Instruction::STA_INX:
			{
				memory[memory[fetchByte(cycles) + X]] = A;
				break;
			}
			case (byte) Instruction::STA_INY:
			{
				memory[memory[fetchByte(cycles)] + Y] = A;
				break;
			}
			case (byte) Instruction::STX_ZP:
			{
				memory[fetchByte(cycles)] = X;
				break;
			}
			case (byte) Instruction::STX_ZPY:
			{
				memory[fetchByte(cycles) + Y] = X;
				break;
			}
			case (byte) Instruction::STX_AB:
			{
				memory[fetchWord(cycles)] = X;
				break;
			}
			case (byte) Instruction::STY_ZP:
			{
				memory[fetchByte(cycles)] = Y;
				break;
			}
			case (byte) Instruction::STY_ZPX:
			{
				memory[fetchByte(cycles) + X] = Y;
				break;
			}
			case (byte) Instruction::STY_AB:
			{
				memory[fetchWord(cycles)] = Y;
				break;
			}
			case (byte) Instruction::TAX:
			{
				X = A;
				break;
			}
			case (byte) Instruction::TXA:
			{
				A = X;
				break;
			}
			case (byte) Instruction::TAY:
			{
				Y = A;
				break;
			}
			case (byte) Instruction::TYA:
			{
				A = Y;
				break;
			}
			case (byte) Instruction::TSX:
			{
				X = SP;
				break;
			}
			case (byte) Instruction::TXS:
			{
				SP = X;
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

byte CPU::fetchByte(dword &cycles)
{
	byte data = memory[PC];
	PC++;
	cycles--;

	return data;
}

word CPU::fetchWord(dword &cycles)
{
	word data = memory[PC];
	data |= memory[PC] << 8;
	PC += 2;
	cycles -= 2;

	return data;
}

void CPU::ADC(byte data)
{
	word result = A + data + C;
	C = result > 0xFF;
	Z = (result & 0xFF) == 0;
	V = (~(A ^ data) & (A ^ result) & 0x80) != 0;
	N = (result & 0x80) != 0;
	A = result & 0xFF;
}

void CPU::AND(byte data)
{
	A &= data;
	Z = A == 0;
	N = (A & 0x80) != 0;
}

void CPU::ASL(byte &data)
{
	C = (data & 0x80) != 0;
	data <<= 1;
	Z = data == 0;
	N = (data & 0x80) != 0;
}

void CPU::BCC(byte data)
{
	if (!C) PC += data;
}

void CPU::BCS(byte data)
{
	if (C) PC += data;
}

void CPU::BEQ(byte data)
{
	if (Z) PC += data;
}

void CPU::BMI(byte data)
{
	if (N) PC += data;
}

void CPU::BNE(byte data)
{
	if (!Z) PC += data;
}

void CPU::BPL(byte data)
{
	if (!N) PC += data;
}

void CPU::BVC(byte data)
{
	if (!V) PC += data;
}

void CPU::BVS(byte data)
{
	if (V) PC += data;
}

void CPU::BIT(byte data)
{
	Z = (A & data) == 0;
	N = (data & 0x80) != 0;
	V = (data & 0x40) != 0;
}

void CPU::CMP(byte first, byte second)
{
	C = first >= second;
	Z = first == second;
	N = (first - second) & 0x80;
}

void CPU::DEC(byte &data)
{
	data--;
	Z = data == 0;
	N = (data & 0x80) != 0;
}

void CPU::EOR(byte data)
{
	A ^= data;
	Z = A == 0;
	N = (A & 0x80) != 0;
}

void CPU::INC(byte &data)
{
	data++;
	Z = data == 0;
	N = (data & 0x80) != 0;
}

void CPU::LDA(byte data)
{
	A = data;
	Z = A == 0;
	N = (A & 0x80) != 0;
}

void CPU::LDX(byte data)
{
	X = data;
	Z = X == 0;
	N = (X & 0x80) != 0;
}

void CPU::LDY(byte data)
{
	Y = data;
	Z = Y == 0;
	N = (Y & 0x80) != 0;
}

void CPU::LSR(byte &data)
{
	C = (data & 0x01) != 0;
	data >>= 1;
	Z = data == 0;
	N = (data & 0x80) != 0;
}

void CPU::ORA(byte data)
{
	A |= data;
	Z = A == 0;
	N = (A & 0x80) != 0;
}

void CPU::ROL(byte &data)
{
	bool carry = C;
	C = (data & 0x80) != 0;

	data <<= 1;
	data |= carry;
	Z = data == 0;
	N = (data & 0x80) != 0;
}

void CPU::ROR(byte &data)
{
	bool carry = C;
	C = (data & 0x01) != 0;

	data >>= 1;
	data |= carry << 7;
	Z = data == 0;
	N = (data & 0x80) != 0;
}

void CPU::SBC(byte data)
{
	word result = A - data - (1 - C);

	C = result < 0x100;
	Z = (result & 0xFF) == 0;
	V = ((A ^ result) & (A ^ data) & 0x80) != 0;
	N = (result & 0x80) != 0;
	A = result & 0xFF;
}
