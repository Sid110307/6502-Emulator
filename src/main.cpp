#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "include/cpu.h"
#include "include/memory.h"

std::vector<byte> parseFile(const std::vector<char> &buffer)
{
    std::unordered_map<std::string, word> symbols;
    std::vector<bool> conditionStack;
    std::vector<byte> result;

    std::istringstream iss(buffer.data());
    std::string line;

    while (std::getline(iss, line))
    {
        std::istringstream lineIss(line);
        std::string opcode;
        lineIss >> opcode;

        if (!opcode.empty())
        {
            if (opcode[0] == ';') continue;
            else if (opcode[0] == '.')
            {
                std::string directive;
                lineIss >> directive;

                if (directive == "org")
                {
                    std::string address;
                    lineIss >> address;

                    std::istringstream addressIss(address);
                    word addressValue = 0;
                    addressIss >> std::hex >> addressValue;

                    result.resize(addressValue);
                } else if (directive == "byte")
                {
                    std::string byteStr;
                    lineIss >> byteStr;

                    std::istringstream byteIss(byteStr);
                    word byteValue = 0;
                    byteIss >> std::hex >> byteValue;

                    result.push_back(static_cast<byte>(byteValue));
                } else if (directive == "word")
                {
                    std::string wordStr;
                    lineIss >> wordStr;

                    std::istringstream wordIss(wordStr);
                    word wordValue = 0;
                    wordIss >> std::hex >> wordValue;

                    result.push_back(static_cast<byte>((wordValue >> 8)));
                    result.push_back(static_cast<byte>(wordValue));
                } else if (directive == "text" || directive == "code")
                {
                    std::cerr << "Text/code section directives are not supported yet" << std::endl;
                    return {};
                } else if (directive == "data")
                {
                    std::string dataValue;
                    while (lineIss >> dataValue)
                    {
                        std::istringstream dataIss(dataValue);
                        word dataByte = 0;

                        dataIss >> std::hex >> dataByte;
                        result.push_back(static_cast<byte>(dataByte));
                    }
                } else if (directive == "asciiz" || directive == "asciz")
                {
                    std::string string;
                    lineIss >> string;

                    for (char c: string) result.push_back(static_cast<byte>(c));
                    result.push_back(static_cast<byte>(0));
                } else if (directive == "equ")
                {
                    std::string symbol;
                    lineIss >> symbol;

                    std::string value;
                    lineIss >> value;

                    std::istringstream valueIss(value);
                    word valueValue = 0;
                    valueIss >> std::hex >> valueValue;

                    symbols[symbol] = valueValue;
                } else if (directive == "ifdef")
                {
                    std::string symbol;
                    lineIss >> symbol;

                    conditionStack.push_back(symbols.find(symbol) != symbols.end());
                } else if (directive == "ifndef")
                {
                    std::string symbol;
                    lineIss >> symbol;

                    conditionStack.push_back(symbols.find(symbol) == symbols.end());
                } else if (directive == "else")
                {
                    if (!conditionStack.empty()) conditionStack.back() = !conditionStack.back();
                    else std::cerr << "Unexpected 'else' without corresponding 'ifdef' or 'ifndef'" << std::endl;
                } else if (directive == "endif")
                {
                    if (!conditionStack.empty()) conditionStack.pop_back();
                    else std::cerr << "Unexpected 'endif' without corresponding 'ifdef' or 'ifndef'" << std::endl;
                } else if (directive == "include")
                {
                    std::string filename;
                    lineIss >> filename;

                    std::ifstream file(filename, std::ios::binary | std::ios::ate);
                    if (!file.is_open())
                    {
                        std::cerr << "Failed to open file: " << filename << std::endl;
                        return {};
                    }

                    std::streampos size = file.tellg();
                    std::vector<char> includeBuffer(size);
                    file.seekg(0, std::ios::beg);
                    file.read(includeBuffer.data(), size);
                    file.close();

                    std::vector<byte> included = parseFile(includeBuffer);
                    result.insert(result.end(), included.begin(), included.end());
                } else if (directive == "macro" || directive == "endmacro")
                {
                    std::cerr << "Macros are not supported yet" << std::endl;
                    return {};
                } else
                {
                    std::cerr << "Unknown directive: " << directive << std::endl;
                    return {};
                }
            } else
            {
                std::istringstream opcodeIss(opcode);
                word opcodeValue = 0;
                opcodeIss >> std::hex >> opcodeValue;

                result.push_back(static_cast<byte>(opcodeValue));
            }
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename.s>" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Initializing... " << std::flush;
    Memory memory = Memory();
    CPU cpu = CPU(memory);

    std::cout << "Done." << std::endl;
    std::cout << "Loading ROM... " << std::flush;

    std::ifstream rom(argv[1], std::ios::binary | std::ios::ate);
    if (!rom.is_open())
    {
        std::cerr << "Failed to open ROM: " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    std::streampos size = rom.tellg();
    std::vector<char> buffer(size);
    rom.seekg(0, std::ios::beg);
    rom.read(buffer.data(), size);
    rom.close();

    memory.load(parseFile(buffer));
    std::cout << "Done." << std::endl;

    std::cout << "Running... " << std::flush;
    cpu.execute();
    std::cout << "Done." << std::endl;

    return EXIT_SUCCESS;
}
