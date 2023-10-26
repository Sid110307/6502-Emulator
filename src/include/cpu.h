#pragma once

#include <iostream>

#include "utils.h"
#include "memory.h"

class CPU
{
public:
    explicit CPU(Memory &);
    ~CPU() = default;

    void reset();
    void execute();

    byte fetchByte(dword &);
    word fetchWord(dword &);

private:
    Memory memory;

    word PC; // Program Counter
    byte SP; // Stack Pointer

    byte A; // Accumulator
    byte X; // X Register
    byte Y; // Y Register

    byte C: 1; // Carry Flag
    byte Z: 1; // Zero Flag
    byte I: 1; // Interrupt Disable
    byte D: 1; // Decimal Mode
    byte B: 1; // Break Command
    byte U: 1; // Unused
    byte V: 1; // Overflow Flag
    byte N: 1; // Negative Flag

    void ADC(byte);
    void AND(byte);
    void ASL(byte &);
    void BCC(byte);
    void BCS(byte);
    void BEQ(byte);
    void BMI(byte);
    void BNE(byte);
    void BPL(byte);
    void BVC(byte);
    void BVS(byte);
    void BIT(byte);
    void CMP(byte, byte);
    void DEC(byte &);
    void EOR(byte);
    void INC(byte &);
    void LDA(byte);
    void LDX(byte);
    void LDY(byte);
    void LSR(byte &);
    void ORA(byte);
    void ROL(byte &);
    void ROR(byte &);
    void SBC(byte);

    static dword setOpcodeCycles(byte);
};
