#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

#include "include/cpu.h"
#include "include/memory.h"

// TODO: Add a way to load a program from a binary.
// TODO: Add interface for video output.
// TODO: Add interface for audio output.
int main(int argc, char** argv)
{
	std::vector<byte> buffer;

	if (argc > 1)
	{
		if (!std::filesystem::exists(argv[1]))
		{
			std::cerr << "File '" << argv[1] << "' does not exist." << std::endl;
			return EXIT_FAILURE;
		}

		if (!std::filesystem::is_regular_file(argv[1]))
		{
			std::cerr << "File '" << argv[1] << "' is not a file." << std::endl;
			return EXIT_FAILURE;
		}

		std::ifstream file(argv[1], std::ios::binary | std::ios::ate);
		if (!file.is_open())
		{
			std::cerr << "Failed to open file '" << argv[1] << "'." << std::endl;
			return EXIT_FAILURE;
		}

		std::cout << "Loading program from file: '" << argv[1] << "'... " << std::flush;

		std::streampos size = file.tellg();
		buffer.resize(size);

		file.seekg(0, std::ios::beg);
		file.read((char*) buffer.data(), size);
		file.close();

		std::cout << "Done." << std::endl;
	}

	std::cout << "Initializing memory... " << std::flush;
	Memory memory = Memory();
	CPU cpu = CPU(memory);

	std::cout << "Done." << std::endl;

	if (!buffer.empty())
	{
		std::cout << "Loading program... " << std::flush;
		memory.load(buffer);
		std::cout << "Done." << std::endl;
	} else
	{
		std::cout << "Loading test program... " << std::flush;

		// BEGIN Code
		// Convert an 16 bit binary value into a 24 bit BCD value: http://6502.org/users/obelisk/6502/algorithms.html
		memory[0xFFFC] = (byte) Instruction::LDA_IM;
		memory[0xFFFD] = (byte) 0x00;
		memory[0xFFFE] = (byte) Instruction::STA_ZP;
		memory[0xFFFF] = (byte) 0x00;
		memory[0x0000] = (byte) Instruction::STA_ZP;
		memory[0x0001] = (byte) 0x01;
		memory[0x0002] = (byte) Instruction::STA_ZP;
		memory[0x0003] = (byte) 0x02;
		memory[0x0004] = (byte) Instruction::LDX_IM;
		memory[0x0005] = (byte) 0x10;
		memory[0x0006] = (byte) Instruction::SED;
		memory[0x0007] = (byte) Instruction::ASL_ZP;
		memory[0x0008] = (byte) 0x00;
		memory[0x0009] = (byte) Instruction::ROL_ZP;
		memory[0x000A] = (byte) 0x01;
		memory[0x000B] = (byte) Instruction::LDA_ZP;
		memory[0x000C] = (byte) 0x00;
		memory[0x000D] = (byte) Instruction::ADC_ZP;
		memory[0x000E] = (byte) 0x00;
		memory[0x000F] = (byte) Instruction::STA_ZP;
		memory[0x0010] = (byte) 0x00;
		memory[0x0011] = (byte) Instruction::LDA_ZP;
		memory[0x0012] = (byte) 0x01;
		memory[0x0013] = (byte) Instruction::ADC_ZP;
		memory[0x0014] = (byte) 0x01;
		memory[0x0015] = (byte) Instruction::STA_ZP;
		memory[0x0016] = (byte) 0x01;
		memory[0x0017] = (byte) Instruction::LDA_ZP;
		memory[0x0018] = (byte) 0x02;
		memory[0x0019] = (byte) Instruction::ADC_ZP;
		memory[0x001A] = (byte) 0x02;
		memory[0x001B] = (byte) Instruction::STA_ZP;
		memory[0x001C] = (byte) 0x02;
		memory[0x001D] = (byte) Instruction::DEX;
		memory[0x001E] = (byte) Instruction::BNE;
		memory[0x001F] = (byte) 0x07;
		memory[0x0020] = (byte) Instruction::CLD;
		// END Code

		std::ofstream file("test.bin", std::ios::binary);
		if (file.is_open())
		{
			file.write((char*) buffer.data(), (std::streamsize) buffer.size());
			file.close();
		}

		std::cout << "Done." << std::endl;
		cpu.execute(49);
	}

	return EXIT_SUCCESS;
}
