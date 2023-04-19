#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

#include "include/cpu.h"
#include "include/memory.h"

// TODO: Add interface for video output.
// TODO: Add interface for audio output.
// TODO: Make it run DOOM.
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
		// add 1 + 2 and store the result in accumulator
		// BEGIN Code
		memory[0x0000] = (byte) Instruction::LDA_IM;
		memory[0x0001] = 0x01;
		memory[0x0002] = (byte) Instruction::ADC_IM;
		memory[0x0003] = 0x02;
		memory[0x0004] = (byte) Instruction::STA_ZP;
		memory[0x0005] = 0x00;
		// END Code

		std::ofstream file("test.bin", std::ios::binary);
		if (file.is_open())
		{
			file.write((char*) buffer.data(), (std::streamsize) buffer.size());
			file.close();
		}

		std::cout << "Done." << std::endl;
		cpu.execute(14);
	}

	return EXIT_SUCCESS;
}
