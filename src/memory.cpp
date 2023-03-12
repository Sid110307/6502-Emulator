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
