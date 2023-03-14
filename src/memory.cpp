#include "include/memory.h"

void Memory::init()
{
	for (byte &i: data) i = 0x00;
}

byte Memory::operator[](dword index) const
{
	if (index >= MAX_MEMORY)
	{
		std::cerr << "Memory index out of bounds: " << index << std::endl;
		exit(EXIT_FAILURE);
	}

	return data[index];
}

byte &Memory::operator[](dword index)
{
	if (index >= MAX_MEMORY)
	{
		std::cerr << "Memory index out of bounds: " << index << std::endl;
		exit(EXIT_FAILURE);
	}

	return data[index];
}

void Memory::writeWord(word index, dword address, dword &cycles)
{
	data[index] = address & 0xFF;
	data[index + 1] = (address >> 8) & 0xFF;

	cycles -= 2;
}

void Memory::load(const std::vector<byte> &buffer)
{
	std::copy(buffer.begin(), buffer.end(), data);

	for (word i = 0; i < (word) buffer.size();)
	{
		auto instruction = (Instruction) data[i];
		byte size = 0;

		switch (instruction)
		{
			case Instruction::BRK:
			case Instruction::NOP:
			case Instruction::ASL_ACC:
			case Instruction::CLC:
			case Instruction::CLD:
			case Instruction::CLI:
			case Instruction::CLV:
			case Instruction::DEX:
			case Instruction::DEY:
			case Instruction::INX:
			case Instruction::INY:
			case Instruction::LSR_ACC:
			case Instruction::PHA:
			case Instruction::PHP:
			case Instruction::PLA:
			case Instruction::PLP:
			case Instruction::ROL_ACC:
			case Instruction::ROR_ACC:
			case Instruction::RTI:
			case Instruction::RTS:
			case Instruction::SEC:
			case Instruction::SED:
			case Instruction::SEI:
			case Instruction::TAX:
			case Instruction::TXA:
			case Instruction::TAY:
			case Instruction::TYA:
			case Instruction::TSX:
			case Instruction::TXS:
			{
				size = 1;
				break;
			}
			case Instruction::ADC_IM:
			case Instruction::ADC_ZP:
			case Instruction::ADC_ZPX:
			case Instruction::ADC_INX:
			case Instruction::ADC_INY:
			case Instruction::AND_IM:
			case Instruction::AND_ZP:
			case Instruction::AND_ZPX:
			case Instruction::AND_INX:
			case Instruction::AND_INY:
			case Instruction::ASL_ZP:
			case Instruction::ASL_ZPX:
			case Instruction::BCC:
			case Instruction::BCS:
			case Instruction::BEQ:
			case Instruction::BMI:
			case Instruction::BNE:
			case Instruction::BPL:
			case Instruction::BVC:
			case Instruction::BVS:
			case Instruction::BIT_ZP:
			case Instruction::CMP_IM:
			case Instruction::CMP_ZP:
			case Instruction::CMP_ZPX:
			case Instruction::CMP_INX:
			case Instruction::CMP_INY:
			case Instruction::CPX_IM:
			case Instruction::CPX_ZP:
			case Instruction::CPY_IM:
			case Instruction::CPY_ZP:
			case Instruction::DEC_ZP:
			case Instruction::DEC_ZPX:
			case Instruction::EOR_IM:
			case Instruction::EOR_ZP:
			case Instruction::EOR_ZPX:
			case Instruction::EOR_INX:
			case Instruction::EOR_INY:
			case Instruction::INC_ZP:
			case Instruction::INC_ZPX:
			case Instruction::LDA_IM:
			case Instruction::LDA_ZP:
			case Instruction::LDA_ZPX:
			case Instruction::LDA_INX:
			case Instruction::LDA_INY:
			case Instruction::LDX_IM:
			case Instruction::LDX_ZP:
			case Instruction::LDX_ZPY:
			case Instruction::LDY_IM:
			case Instruction::LDY_ZP:
			case Instruction::LDY_ZPX:
			case Instruction::LSR_ZP:
			case Instruction::LSR_ZPX:
			case Instruction::ORA_IM:
			case Instruction::ORA_ZP:
			case Instruction::ORA_ZPX:
			case Instruction::ORA_INX:
			case Instruction::ORA_INY:
			case Instruction::ROL_ZP:
			case Instruction::ROL_ZPX:
			case Instruction::ROR_ZP:
			case Instruction::ROR_ZPX:
			case Instruction::SBC_IM:
			case Instruction::SBC_ZP:
			case Instruction::SBC_ZPX:
			case Instruction::SBC_INX:
			case Instruction::SBC_INY:
			case Instruction::STA_ZP:
			case Instruction::STA_ZPX:
			case Instruction::STA_INX:
			case Instruction::STA_INY:
			case Instruction::STX_ZP:
			case Instruction::STX_ZPY:
			case Instruction::STY_ZP:
			case Instruction::STY_ZPX:
			{
				size = 2;
				break;
			}
			case Instruction::ADC_AB:
			case Instruction::ADC_ABX:
			case Instruction::ADC_ABY:
			case Instruction::AND_AB:
			case Instruction::AND_ABX:
			case Instruction::AND_ABY:
			case Instruction::ASL_AB:
			case Instruction::ASL_ABX:
			case Instruction::BIT_AB:
			case Instruction::CMP_AB:
			case Instruction::CMP_ABX:
			case Instruction::CMP_ABY:
			case Instruction::CPX_AB:
			case Instruction::CPY_AB:
			case Instruction::DEC_AB:
			case Instruction::DEC_ABX:
			case Instruction::EOR_AB:
			case Instruction::EOR_ABX:
			case Instruction::EOR_ABY:
			case Instruction::INC_AB:
			case Instruction::INC_ABX:
			case Instruction::JMP_AB:
			case Instruction::JMP_IN:
			case Instruction::JSR:
			case Instruction::LDA_AB:
			case Instruction::LDA_ABX:
			case Instruction::LDA_ABY:
			case Instruction::LDX_AB:
			case Instruction::LDX_ABY:
			case Instruction::LDY_AB:
			case Instruction::LDY_ABX:
			case Instruction::LSR_AB:
			case Instruction::LSR_ABX:
			case Instruction::ORA_AB:
			case Instruction::ORA_ABX:
			case Instruction::ORA_ABY:
			case Instruction::ROL_AB:
			case Instruction::ROL_ABX:
			case Instruction::ROR_AB:
			case Instruction::ROR_ABX:
			case Instruction::SBC_AB:
			case Instruction::SBC_ABX:
			case Instruction::SBC_ABY:
			case Instruction::STA_AB:
			case Instruction::STA_ABX:
			case Instruction::STA_ABY:
			case Instruction::STX_AB:
			case Instruction::STY_AB:
			{
				size = 3;
				break;
			}
			default:
			{
				std::cerr << "Unknown opcode: " << std::hex << (int) instruction << std::endl;
				size = 1;

				break;
			}
		}

		i += size;
	}
}
