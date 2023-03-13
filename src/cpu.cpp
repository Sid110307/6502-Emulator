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
//#region LDA
			case (byte) Instruction::LDA_IM:
			{
				byte data = fetchByte(cycles, memory);
				LDA(data);

				break;
			}
			case (byte) Instruction::LDA_ZP:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				LDA(readByte(cycles, address, memory));
				break;
			}
			case (byte) Instruction::LDA_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				LDA(readByte(cycles, address + X, memory));
				break;
			}
			case (byte) Instruction::LDA_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				cycles -= 2;

				LDA(readByte(cycles, address, memory));
				break;
			}
			case (byte) Instruction::LDA_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				cycles -= 2;

				LDA(readByte(cycles, address + X, memory));
				break;
			}
			case (byte) Instruction::LDA_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				cycles -= 2;

				LDA(readByte(cycles, address + Y, memory));
				break;
			}
			case (byte) Instruction::LDA_INX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address + X, memory);
				indirectAddress |= readByte(cycles, address + X + 1, memory) << 8;
				cycles--;

				LDA(readByte(cycles, indirectAddress, memory));
				break;
			}
			case (byte) Instruction::LDA_INY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address, memory);
				indirectAddress |= readByte(cycles, address + 1, memory) << 8;
				cycles--;

				LDA(readByte(cycles, indirectAddress + Y, memory));
				break;
			}
//#endregion
//#region STA
			case (byte) Instruction::STA_ZP:
			{
				byte address = fetchByte(cycles, memory);

				memory[address] = A;
				cycles--;
				break;
			}
			case (byte) Instruction::STA_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				memory[address + X] = A;
				cycles--;
				break;
			}
			case (byte) Instruction::STA_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				memory[address] = A;
				cycles -= 2;
				break;
			}
			case (byte) Instruction::STA_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				memory[address + X] = A;
				cycles -= 2;
				break;
			}
			case (byte) Instruction::STA_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				memory[address + Y] = A;
				cycles -= 2;
				break;
			}
			case (byte) Instruction::STA_INX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word data = memory[address + X];
				data |= memory[address + X + 1] << 8;

				memory[data] = A;
				cycles -= 2;
				break;
			}
			case (byte) Instruction::STA_INY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word data = memory[address];
				data |= memory[address + 1] << 8;

				memory[data + Y] = A;
				cycles -= 2;
				break;
			}
//#endregion
//#region LDX
			case (byte) Instruction::LDX_IM:
			{
				byte data = fetchByte(cycles, memory);

				X = data;
				LDX();
				break;
			}
			case (byte) Instruction::LDX_ZP:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				X = readByte(cycles, address, memory);
				LDX();
				break;
			}
			case (byte) Instruction::LDX_ZPY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				X = readByte(cycles, address + Y, memory);
				LDX();
				break;
			}
			case (byte) Instruction::LDX_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				byte data = memory[address];

				X = data;
				LDX();
				break;
			}
			case (byte) Instruction::LDX_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				byte data = memory[address + Y];

				X = data;
				LDX();
				break;
			}
//#endregion
//#region STX
			case (byte) Instruction::STX_ZP:
			{
				byte address = fetchByte(cycles, memory);

				memory[address] = X;
				cycles--;
				break;
			}
			case (byte) Instruction::STX_ZPY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				memory[address + Y] = X;
				cycles--;
				break;
			}
			case (byte) Instruction::STX_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				memory[address] = X;
				cycles -= 2;
				break;
			}
//#endregion
//#region LDY
			case (byte) Instruction::LDY_IM:
			{
				byte data = fetchByte(cycles, memory);

				Y = data;
				LDX();
				break;
			}
			case (byte) Instruction::LDY_ZP:
			{
				byte address = fetchByte(cycles, memory);

				Y = readByte(cycles, address, memory);
				LDX();
				break;
			}
			case (byte) Instruction::LDY_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				Y = readByte(cycles, address + X, memory);
				LDX();
				break;
			}
			case (byte) Instruction::LDY_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				byte data = memory[address];

				Y = data;
				LDX();
				break;
			}
			case (byte) Instruction::LDY_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;
				byte data = memory[address + X];

				Y = data;
				LDX();
				break;
			}
//#endregion
//#region STY
			case (byte) Instruction::STY_ZP:
			{
				byte address = fetchByte(cycles, memory);

				memory[address] = Y;
				cycles--;
				break;
			}
			case (byte) Instruction::STY_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				memory[address + X] = Y;
				cycles--;
				break;
			}
			case (byte) Instruction::STY_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				memory[address] = Y;
				cycles -= 2;
				break;
			}
//#endregion
//#region ADC
			case (byte) Instruction::ADC_IM:
			{
				byte data = fetchByte(cycles, memory);

				ADC(data);
				break;
			}
			case (byte) Instruction::ADC_ZP:
			{
				byte address = fetchByte(cycles, memory);

				ADC(readByte(cycles, address, memory));
				break;
			}
			case (byte) Instruction::ADC_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				ADC(readByte(cycles, address + X, memory));
				break;
			}
			case (byte) Instruction::ADC_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ADC(memory[address]);
				break;
			}
			case (byte) Instruction::ADC_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ADC(memory[address + X]);
				break;
			}
			case (byte) Instruction::ADC_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ADC(memory[address + Y]);
				break;
			}
			case (byte) Instruction::ADC_INX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address + X, memory);
				indirectAddress |= readByte(cycles, address + X + 1, memory) << 8;

				ADC(memory[indirectAddress]);
				break;
			}
			case (byte) Instruction::ADC_INY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address, memory);
				indirectAddress |= readByte(cycles, address + 1, memory) << 8;

				ADC(memory[indirectAddress + Y]);
				break;
			}
//#endregion
//#region SBC
			case (byte) Instruction::SBC_IM:
			{
				byte data = fetchByte(cycles, memory);

				SBC(data);
				break;
			}
			case (byte) Instruction::SBC_ZP:
			{
				byte address = fetchByte(cycles, memory);

				SBC(readByte(cycles, address, memory));
				break;
			}
			case (byte) Instruction::SBC_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				SBC(readByte(cycles, address + X, memory));
				break;
			}
			case (byte) Instruction::SBC_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				SBC(memory[address]);
				break;
			}
			case (byte) Instruction::SBC_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				SBC(memory[address + X]);
				break;
			}
			case (byte) Instruction::SBC_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				SBC(memory[address + Y]);
				break;
			}
			case (byte) Instruction::SBC_INX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address + X, memory);
				indirectAddress |= readByte(cycles, address + X + 1, memory) << 8;

				SBC(memory[indirectAddress]);
				break;
			}
			case (byte) Instruction::SBC_INY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address, memory);
				indirectAddress |= readByte(cycles, address + 1, memory) << 8;

				SBC(memory[indirectAddress + Y]);
				break;
			}
//#endregion
//#region AND
			case (byte) Instruction::AND_IM:
			{
				byte data = fetchByte(cycles, memory);

				AND(data);
				break;
			}
			case (byte) Instruction::AND_ZP:
			{
				byte address = fetchByte(cycles, memory);

				AND(readByte(cycles, address, memory));
				break;
			}
			case (byte) Instruction::AND_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				AND(readByte(cycles, address + X, memory));
				break;
			}
			case (byte) Instruction::AND_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				AND(memory[address]);
				break;
			}
			case (byte) Instruction::AND_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				AND(memory[address + X]);
				break;
			}
			case (byte) Instruction::AND_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				AND(memory[address + Y]);
				break;
			}
			case (byte) Instruction::AND_INX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address + X, memory);
				indirectAddress |= readByte(cycles, address + X + 1, memory) << 8;

				AND(memory[indirectAddress]);
				break;
			}
			case (byte) Instruction::AND_INY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address, memory);
				indirectAddress |= readByte(cycles, address + 1, memory) << 8;

				AND(memory[indirectAddress + Y]);
				break;
			}
//#endregion
//#region ORA
			case (byte) Instruction::ORA_IM:
			{
				byte data = fetchByte(cycles, memory);

				ORA(data);
				break;
			}
			case (byte) Instruction::ORA_ZP:
			{
				byte address = fetchByte(cycles, memory);

				ORA(readByte(cycles, address, memory));
				break;
			}
			case (byte) Instruction::ORA_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				ORA(readByte(cycles, address + X, memory));
				break;
			}
			case (byte) Instruction::ORA_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ORA(memory[address]);
				break;
			}
			case (byte) Instruction::ORA_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ORA(memory[address + X]);
				break;
			}
			case (byte) Instruction::ORA_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ORA(memory[address + Y]);
				break;
			}
			case (byte) Instruction::ORA_INX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address + X, memory);
				indirectAddress |= readByte(cycles, address + X + 1, memory) << 8;

				ORA(memory[indirectAddress]);
				break;
			}
			case (byte) Instruction::ORA_INY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address, memory);
				indirectAddress |= readByte(cycles, address + 1, memory) << 8;

				ORA(memory[indirectAddress + Y]);
				break;
			}
//#endregion
//#region EOR
			case (byte) Instruction::EOR_IM:
			{
				byte data = fetchByte(cycles, memory);

				EOR(data);
				break;
			}
			case (byte) Instruction::EOR_ZP:
			{
				byte address = fetchByte(cycles, memory);

				EOR(readByte(cycles, address, memory));
				break;
			}
			case (byte) Instruction::EOR_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				EOR(readByte(cycles, address + X, memory));
				break;
			}
			case (byte) Instruction::EOR_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				EOR(memory[address]);
				break;
			}
			case (byte) Instruction::EOR_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				EOR(memory[address + X]);
				break;
			}
			case (byte) Instruction::EOR_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				EOR(memory[address + Y]);
				break;
			}
			case (byte) Instruction::EOR_INX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address + X, memory);
				indirectAddress |= readByte(cycles, address + X + 1, memory) << 8;

				EOR(memory[indirectAddress]);
				break;
			}
			case (byte) Instruction::EOR_INY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word indirectAddress = readByte(cycles, address, memory);
				indirectAddress |= readByte(cycles, address + 1, memory) << 8;

				EOR(memory[indirectAddress + Y]);
				break;
			}
//#endregion
//#region BIT
			case (byte) Instruction::BIT_ZP:
			{
				byte address = fetchByte(cycles, memory);

				BIT(readByte(cycles, address, memory));
				break;
			}
			case (byte) Instruction::BIT_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				BIT(memory[address]);
				break;
			}
//#endregion
//#region ASL
			case (byte) Instruction::ASL_ACC:
			{
				ASL(A); // void ASL(byte& data)
				break;
			}
			case (byte) Instruction::ASL_ZP:
			{
				byte address = fetchByte(cycles, memory);
				byte data = readByte(cycles, address, memory);

				ASL(data);
				break;
			}
			case (byte) Instruction::ASL_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				byte data = readByte(cycles, address + X, memory);

				ASL(data);
				break;
			}
			case (byte) Instruction::ASL_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ASL(memory[address]);
				break;
			}
			case (byte) Instruction::ASL_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ASL(memory[address + X]);
				break;
			}
//#endregion
//#region LSR
			case (byte) Instruction::LSR_ACC:
			{
				LSR(A);
				break;
			}
			case (byte) Instruction::LSR_ZP:
			{
				byte address = fetchByte(cycles, memory);
				byte data = readByte(cycles, address, memory);

				LSR(data);
				break;
			}
			case (byte) Instruction::LSR_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				byte data = readByte(cycles, address + X, memory);

				LSR(data);
				break;
			}
			case (byte) Instruction::LSR_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				LSR(memory[address]);
				break;
			}
			case (byte) Instruction::LSR_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				LSR(memory[address + X]);
				break;
			}
//#endregion
//#region ROL
			case (byte) Instruction::ROL_ACC:
			{
				ROL(A);
				break;
			}
			case (byte) Instruction::ROL_ZP:
			{
				byte address = fetchByte(cycles, memory);
				byte data = readByte(cycles, address, memory);

				ROL(data);
				break;
			}
			case (byte) Instruction::ROL_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				byte data = readByte(cycles, address + X, memory);

				ROL(data);
				break;
			}
			case (byte) Instruction::ROL_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ROL(memory[address]);
				break;
			}
			case (byte) Instruction::ROL_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ROL(memory[address + X]);
				break;
			}
//#endregion
//#region ROR
			case (byte) Instruction::ROR_ACC:
			{
				ROR(A);
				break;
			}
			case (byte) Instruction::ROR_ZP:
			{
				byte address = fetchByte(cycles, memory);
				byte data = readByte(cycles, address, memory);

				ROR(data);
				break;
			}
			case (byte) Instruction::ROR_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				byte data = readByte(cycles, address + X, memory);

				ROR(data);
				break;
			}
			case (byte) Instruction::ROR_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ROR(memory[address]);
				break;
			}
			case (byte) Instruction::ROR_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				ROR(memory[address + X]);
				break;
			}
//#endregion
//#region INC
			case (byte) Instruction::INC_ZP:
			{
				byte address = fetchByte(cycles, memory);
				byte data = readByte(cycles, address, memory);

				INC(data);
				break;
			}
			case (byte) Instruction::INC_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				byte data = readByte(cycles, address + X, memory);

				INC(data);
				break;
			}
			case (byte) Instruction::INC_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				INC(memory[address]);
				break;
			}
			case (byte) Instruction::INC_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				INC(memory[address + X]);
				break;
			}
//#endregion
//#region DEC
			case (byte) Instruction::DEC_ZP:
			{
				byte address = fetchByte(cycles, memory);
				byte data = readByte(cycles, address, memory);

				DEC(data);
				break;
			}
			case (byte) Instruction::DEC_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				byte data = readByte(cycles, address + X, memory);

				DEC(data);
				break;
			}
			case (byte) Instruction::DEC_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				DEC(memory[address]);
				break;
			}
			case (byte) Instruction::DEC_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				DEC(memory[address + X]);
				break;
			}
//#endregion
//#region CMP
			case (byte) Instruction::CMP_IM:
			{
				byte data = fetchByte(cycles, memory);
				CMP(A, data);
				break;
			}
			case (byte) Instruction::CMP_ZP:
			{
				byte address = fetchByte(cycles, memory);
				byte data = readByte(cycles, address, memory);

				CMP(A, data);
				break;
			}
			case (byte) Instruction::CMP_ZPX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				byte data = readByte(cycles, address + X, memory);

				CMP(A, data);
				break;
			}
			case (byte) Instruction::CMP_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				CMP(A, memory[address]);
				break;
			}
			case (byte) Instruction::CMP_ABX:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				CMP(A, memory[address + X]);
				break;
			}
			case (byte) Instruction::CMP_ABY:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				CMP(A, memory[address + Y]);
				break;
			}
			case (byte) Instruction::CMP_INX:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word data = readByte(cycles, address + X, memory);
				data |= readByte(cycles, address + X + 1, memory) << 8;

				CMP(A, memory[data]);
				break;
			}
			case (byte) Instruction::CMP_INY:
			{
				byte address = fetchByte(cycles, memory);
				cycles--;

				word data = readByte(cycles, address, memory);
				data |= readByte(cycles, address + 1, memory) << 8;

				CMP(A, memory[data + Y]);
				break;
			}
//#endregion
//#region CPX
			case (byte) Instruction::CPX_IM:
			{
				byte data = fetchByte(cycles, memory);
				CMP(X, data);
				break;
			}
			case (byte) Instruction::CPX_ZP:
			{
				byte address = fetchByte(cycles, memory);
				byte data = readByte(cycles, address, memory);

				CMP(X, data);
				break;
			}
			case (byte) Instruction::CPX_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				CMP(X, memory[address]);
				break;
			}
//#endregion
//#region CPY
			case (byte) Instruction::CPY_IM:
			{
				byte data = fetchByte(cycles, memory);
				CMP(Y, data);
				break;
			}
			case (byte) Instruction::CPY_ZP:
			{
				byte address = fetchByte(cycles, memory);
				byte data = readByte(cycles, address, memory);

				CMP(Y, data);
				break;
			}
			case (byte) Instruction::CPY_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				CMP(Y, memory[address]);
				break;
			}
//#endregion
//#region Register Instructions
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
//#endregion
//#region Status Flag Instructions
			case (byte) Instruction::CLC:
			{
				C = false;
				break;
			}
			case (byte) Instruction::SEC:
			{
				C = true;
				break;
			}
			case (byte) Instruction::CLI:
			{
				I = false;
				break;
			}
			case (byte) Instruction::SEI:
			{
				I = true;
				break;
			}
			case (byte) Instruction::CLV:
			{
				V = false;
				break;
			}
			case (byte) Instruction::CLD:
			{
				D = false;
				break;
			}
			case (byte) Instruction::SED:
			{
				D = true;
				break;
			}
//#endregion
//#region Branch Instructions
			case (byte) Instruction::BCC:
			{
				byte offset = fetchByte(cycles, memory);
				cycles--;

				if (!C)
				{
					PC += offset;
					cycles--;
				}
				break;
			}
			case (byte) Instruction::BCS:
			{
				byte offset = fetchByte(cycles, memory);
				cycles--;

				if (C)
				{
					PC += offset;
					cycles--;
				}
				break;
			}
			case (byte) Instruction::BNE:
			{
				byte offset = fetchByte(cycles, memory);
				cycles--;

				if (!Z)
				{
					PC += offset;
					cycles--;
				}
				break;
			}
			case (byte) Instruction::BEQ:
			{
				byte offset = fetchByte(cycles, memory);
				cycles--;

				if (Z)
				{
					PC += offset;
					cycles--;
				}
				break;
			}
			case (byte) Instruction::BPL:
			{
				byte offset = fetchByte(cycles, memory);
				cycles--;

				if (!N)
				{
					PC += offset;
					cycles--;
				}
				break;
			}
			case (byte) Instruction::BMI:
			{
				byte offset = fetchByte(cycles, memory);
				cycles--;

				if (N)
				{
					PC += offset;
					cycles--;
				}
				break;
			}
			case (byte) Instruction::BVC:
			{
				byte offset = fetchByte(cycles, memory);
				cycles--;

				if (!V)
				{
					PC += offset;
					cycles--;
				}
				break;
			}
			case (byte) Instruction::BVS:
			{
				byte offset = fetchByte(cycles, memory);
				cycles--;

				if (V)
				{
					PC += offset;
					cycles--;
				}
				break;
			}
//#endregion
//#region Jump-Return Instructions
			case (byte) Instruction::JMP_AB:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				PC = address;
				break;
			}
			case (byte) Instruction::JMP_IN:
			{
				word address = fetchByte(cycles, memory);
				address |= fetchByte(cycles, memory) << 8;

				PC = memory[address];
				PC |= memory[address + 1] << 8;
				break;
			}
			case (byte) Instruction::JSR:
			{
				word address = fetchWord(cycles, memory);

				SP--;
				memory[SP] = PC >> 8;
				SP--;
				memory[SP] = PC & 0xFF;

				PC = address;
				break;
			}
			case (byte) Instruction::RTS:
			{
				SP++;
				PC = memory[SP];
				SP++;
				PC |= memory[SP] << 8;

				PC++;
				break;
			}
			case (byte) Instruction::RTI:
			{
				SP++;
				byte status = memory[SP];
				SP++;
				PC = memory[SP];
				SP++;
				PC |= memory[SP] << 8;

				C = status & 0x01;
				Z = status & 0x02;
				I = status & 0x04;
				D = status & 0x08;
				B = status & 0x10;
				V = status & 0x40;
				N = status & 0x80;
				break;
			}
//#endregion
//#region Stack Instructions
			case (byte) Instruction::PHA:
			{
				memory[SP] = A;
				SP--;
				break;
			}
			case (byte) Instruction::PLA:
			{
				SP++;
				A = memory[SP];

				LDX();
				break;
			}
			case (byte) Instruction::PHP:
			{
				byte status = 0x20;
				status |= C;
				status |= Z << 1;
				status |= I << 2;
				status |= D << 3;
				status |= B << 4;
				status |= V << 6;
				status |= N << 7;

				memory[SP] = status;
				SP--;
				break;
			}
			case (byte) Instruction::PLP:
			{
				SP++;
				byte status = memory[SP];

				C = status & 0x01;
				Z = status & 0x02;
				I = status & 0x04;
				D = status & 0x08;
				B = status & 0x10;
				V = status & 0x40;
				N = status & 0x80;
				break;
			}
//#endregion
//#region Miscellaneous
			case (byte) Instruction::BRK:
			{
				PC++;
				memory[SP] = PC >> 8;
				SP--;
				memory[SP] = PC & 0xFF;
				SP--;

				byte status = 0x30;
				status |= C;
				status |= Z << 1;
				status |= I << 2;
				status |= D << 3;
				status |= B << 4;
				status |= V << 6;
				status |= N << 7;

				memory[SP] = status;
				SP--;

				I = true;

				PC = memory[0xFFFE];
				PC |= memory[0xFFFF] << 8;
				break;
			}
			case (byte) Instruction::NOP:
			{
				break;
			}
//#endregion
			default:
			{
				std::cerr << "Unknown instruction: " << std::hex << (int) opcode << std::endl;
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

	return data;
}

byte CPU::readByte(dword &cycles, byte address, Memory &memory)
{
	byte data = memory[address];
	cycles--;

	return data;
}

void CPU::LDA(byte data)
{
	A = data;
	LDX();
}

void CPU::LDX()
{
	Z = A == 0x00;
	N = (A & 0x80) != 0;
}

void CPU::ADC(byte data)
{
	word result = A + data + C;
	C = result > 0xFF;
	V = ((A ^ result) & (data ^ result) & 0x80) != 0;
	A = result & 0xFF;

	LDX();
}

void CPU::SBC(byte data)
{
	word result = A - data - (1 - C);
	C = result < 0x100;
	V = ((A ^ result) & (data ^ result) & 0x80) != 0;
	A = result & 0xFF;

	LDX();
}

void CPU::AND(byte data)
{
	A &= data;
	LDX();
}

void CPU::ORA(byte data)
{
	A |= data;
	LDX();
}

void CPU::EOR(byte data)
{
	A ^= data;
	LDX();
}

void CPU::BIT(byte data)
{
	Z = (A & data) == 0;
	N = (data & 0x80) != 0;
	V = (data & 0x40) != 0;
}

void CPU::ASL(byte &data)
{
	C = (data & 0x80) != 0;
	data <<= 1;
	Z = data == 0x00;
	N = (data & 0x80) != 0;
}

void CPU::LSR(byte &data)
{
	C = (data & 0x01) != 0;
	data >>= 1;
	Z = data == 0x00;
	N = (data & 0x80) != 0;
}

void CPU::ROL(byte &data)
{
	byte carry = C;
	C = (data & 0x80) != 0;
	data <<= 1;
	data |= carry;

	Z = data == 0x00;
	N = (data & 0x80) != 0;
}

void CPU::ROR(byte &data)
{
	byte carry = C;
	C = (data & 0x01) != 0;
	data >>= 1;
	data |= carry << 7;

	Z = data == 0x00;
	N = (data & 0x80) != 0;
}

void CPU::INC(byte &data)
{
	data++;
	Z = data == 0x00;
	N = (data & 0x80) != 0;
}

void CPU::DEC(byte &data)
{
	data--;
	Z = data == 0x00;
	N = (data & 0x80) != 0;
}

void CPU::CMP(byte first, byte second)
{
	word result = first - second;
	C = result < 0x100;
	Z = result == 0x00;
	N = (result & 0x80) != 0;
}
