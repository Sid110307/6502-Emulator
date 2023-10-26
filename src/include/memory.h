#pragma once

#include <iostream>
#include <vector>

#include "utils.h"

static constexpr dword MAX_MEMORY = 64 * 1024;

class Memory
{
public:
    void init();

    byte operator[](dword) const;
    byte &operator[](dword);

    void writeWord(word, dword, dword &);
    void load(const std::vector<byte> &);

private:
    byte data[MAX_MEMORY];
};
