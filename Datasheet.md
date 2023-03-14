# 6502 Data Sheet

## Instruction Set

<details>
<summary>Sorted alphabetically</summary>

| Instruction | Opcode | Addressing Mode | Cycles |
|-------------|--------|-----------------|--------|
| ADC         | 0x69   | Immediate       | 2      |
| ADC         | 0x65   | Zero Page       | 3      |
| ADC         | 0x75   | Zero Page, X    | 4      |
| ADC         | 0x6D   | Absolute        | 4      |
| ADC         | 0x7D   | Absolute, X     | 4*     |
| ADC         | 0x79   | Absolute, Y     | 4*     |
| ADC         | 0x61   | (Indirect, X)   | 6      |
| ADC         | 0x71   | (Indirect), Y   | 5*     |
| AND         | 0x29   | Immediate       | 2      |
| AND         | 0x25   | Zero Page       | 3      |
| AND         | 0x35   | Zero Page, X    | 4      |
| AND         | 0x2D   | Absolute        | 4      |
| AND         | 0x3D   | Absolute, X     | 4*     |
| AND         | 0x39   | Absolute, Y     | 4*     |
| AND         | 0x21   | (Indirect, X)   | 6      |
| AND         | 0x31   | (Indirect), Y   | 5*     |
| ASL         | 0x0A   | Accumulator     | 2      |
| ASL         | 0x06   | Zero Page       | 5      |
| ASL         | 0x16   | Zero Page, X    | 6      |
| ASL         | 0x0E   | Absolute        | 6      |
| ASL         | 0x1E   | Absolute, X     | 7      |
| BCC         | 0x90   | Relative        | 2**    |
| BCS         | 0xB0   | Relative        | 2**    |
| BEQ         | 0xF0   | Relative        | 2**    |
| BIT         | 0x24   | Zero Page       | 3      |
| BIT         | 0x2C   | Absolute        | 4      |
| BMI         | 0x30   | Relative        | 2**    |
| BNE         | 0xD0   | Relative        | 2**    |
| BPL         | 0x10   | Relative        | 2**    |
| BRK         | 0x00   | Implied         | 7      |
| BVC         | 0x50   | Relative        | 2**    |
| BVS         | 0x70   | Relative        | 2**    |
| CLC         | 0x18   | Implied         | 2      |
| CLD         | 0xD8   | Implied         | 2      |
| CLI         | 0x58   | Implied         | 2      |
| CLV         | 0xB8   | Implied         | 2      |
| CMP         | 0xC9   | Immediate       | 2      |
| CMP         | 0xC5   | Zero Page       | 3      |
| CMP         | 0xD5   | Zero Page, X    | 4      |
| CMP         | 0xCD   | Absolute        | 4      |
| CMP         | 0xDD   | Absolute, X     | 4*     |
| CMP         | 0xD9   | Absolute, Y     | 4*     |
| CMP         | 0xC1   | (Indirect, X)   | 6      |
| CMP         | 0xD1   | (Indirect), Y   | 5*     |
| CPX         | 0xE0   | Immediate       | 2      |
| CPX         | 0xE4   | Zero Page       | 3      |
| CPX         | 0xEC   | Absolute        | 4      |
| CPY         | 0xC0   | Immediate       | 2      |
| CPY         | 0xC4   | Zero Page       | 3      |
| CPY         | 0xCC   | Absolute        | 4      |
| DEC         | 0xC6   | Zero Page       | 5      |
| DEC         | 0xD6   | Zero Page, X    | 6      |
| DEC         | 0xCE   | Absolute        | 6      |
| DEC         | 0xDE   | Absolute, X     | 7      |
| DEX         | 0xCA   | Implied         | 2      |
| DEY         | 0x88   | Implied         | 2      |
| EOR         | 0x49   | Immediate       | 2      |
| EOR         | 0x45   | Zero Page       | 3      |
| EOR         | 0x55   | Zero Page, X    | 4      |
| EOR         | 0x4D   | Absolute        | 4      |
| EOR         | 0x5D   | Absolute, X     | 4*     |
| EOR         | 0x59   | Absolute, Y     | 4*     |
| EOR         | 0x41   | (Indirect, X)   | 6      |
| EOR         | 0x51   | (Indirect), Y   | 5*     |
| INC         | 0xE6   | Zero Page       | 5      |
| INC         | 0xF6   | Zero Page, X    | 6      |
| INC         | 0xEE   | Absolute        | 6      |
| INC         | 0xFE   | Absolute, X     | 7      |
| INX         | 0xE8   | Implied         | 2      |
| INY         | 0xC8   | Implied         | 2      |
| JMP         | 0x4C   | Absolute        | 3      |
| JMP         | 0x6C   | Indirect        | 5      |
| JSR         | 0x20   | Absolute        | 6      |
| LDA         | 0xA9   | Immediate       | 2      |
| LDA         | 0xA5   | Zero Page       | 3      |
| LDA         | 0xB5   | Zero Page, X    | 4      |
| LDA         | 0xAD   | Absolute        | 4      |
| LDA         | 0xBD   | Absolute, X     | 4*     |
| LDA         | 0xB9   | Absolute, Y     | 4*     |
| LDA         | 0xA1   | (Indirect, X)   | 6      |
| LDA         | 0xB1   | (Indirect), Y   | 5*     |
| LDX         | 0xA2   | Immediate       | 2      |
| LDX         | 0xA6   | Zero Page       | 3      |
| LDX         | 0xB6   | Zero Page, Y    | 4      |
| LDX         | 0xAE   | Absolute        | 4      |
| LDX         | 0xBE   | Absolute, Y     | 4*     |
| LDY         | 0xA0   | Immediate       | 2      |
| LDY         | 0xA4   | Zero Page       | 3      |
| LDY         | 0xB4   | Zero Page, X    | 4      |
| LDY         | 0xAC   | Absolute        | 4      |
| LDY         | 0xBC   | Absolute, X     | 4*     |
| LSR         | 0x4A   | Accumulator     | 2      |
| LSR         | 0x46   | Zero Page       | 5      |
| LSR         | 0x56   | Zero Page, X    | 6      |
| LSR         | 0x4E   | Absolute        | 6      |
| LSR         | 0x5E   | Absolute, X     | 7      |
| NOP         | 0xEA   | Implied         | 2      |
| ORA         | 0x09   | Immediate       | 2      |
| ORA         | 0x05   | Zero Page       | 3      |
| ORA         | 0x15   | Zero Page, X    | 4      |
| ORA         | 0x0D   | Absolute        | 4      |
| ORA         | 0x1D   | Absolute, X     | 4*     |
| ORA         | 0x19   | Absolute, Y     | 4*     |
| ORA         | 0x01   | (Indirect, X)   | 6      |
| ORA         | 0x11   | (Indirect), Y   | 5*     |
| PHA         | 0x48   | Implied         | 3      |
| PHP         | 0x08   | Implied         | 3      |
| PLA         | 0x68   | Implied         | 4      |
| PLP         | 0x28   | Implied         | 4      |
| ROL         | 0x2A   | Accumulator     | 2      |
| ROL         | 0x26   | Zero Page       | 5      |
| ROL         | 0x36   | Zero Page, X    | 6      |
| ROL         | 0x2E   | Absolute        | 6      |
| ROL         | 0x3E   | Absolute, X     | 7      |
| ROR         | 0x6A   | Accumulator     | 2      |
| ROR         | 0x66   | Zero Page       | 5      |
| ROR         | 0x76   | Zero Page, X    | 6      |
| ROR         | 0x6E   | Absolute        | 6      |
| ROR         | 0x7E   | Absolute, X     | 7      |
| RTI         | 0x40   | Implied         | 6      |
| RTS         | 0x60   | Implied         | 6      |
| SBC         | 0xE9   | Immediate       | 2      |
| SBC         | 0xE5   | Zero Page       | 3      |
| SBC         | 0xF5   | Zero Page, X    | 4      |
| SBC         | 0xED   | Absolute        | 4      |
| SBC         | 0xFD   | Absolute, X     | 4*     |
| SBC         | 0xF9   | Absolute, Y     | 4*     |
| SBC         | 0xE1   | (Indirect, X)   | 6      |
| SBC         | 0xF1   | (Indirect), Y   | 5*     |
| SEC         | 0x38   | Implied         | 2      |
| SED         | 0xF8   | Implied         | 2      |
| SEI         | 0x78   | Implied         | 2      |
| STA         | 0x85   | Zero Page       | 3      |
| STA         | 0x95   | Zero Page, X    | 4      |
| STA         | 0x8D   | Absolute        | 4      |
| STA         | 0x9D   | Absolute, X     | 5      |
| STA         | 0x99   | Absolute, Y     | 5      |
| STA         | 0x81   | (Indirect, X)   | 6      |
| STA         | 0x91   | (Indirect), Y   | 6      |
| STX         | 0x86   | Zero Page       | 3      |
| STX         | 0x96   | Zero Page, Y    | 4      |
| STX         | 0x8E   | Absolute        | 4      |
| STY         | 0x84   | Zero Page       | 3      |
| STY         | 0x94   | Zero Page, X    | 4      |
| STY         | 0x8C   | Absolute        | 4      |
| TAX         | 0xAA   | Implied         | 2      |
| TAY         | 0xA8   | Implied         | 2      |
| TSX         | 0xBA   | Implied         | 2      |
| TXA         | 0x8A   | Implied         | 2      |
| TXS         | 0x9A   | Implied         | 2      |
| TYA         | 0x98   | Implied         | 2      |

</details>

<details>
<summary>Sorted by number of cycles</summary>

| Instruction | Opcode | Addressing Mode | Cycles |
|-------------|--------|-----------------|--------|
| ADC         | 0x69   | Immediate       | 2      |
| AND         | 0x29   | Immediate       | 2      |
| ASL         | 0x0A   | Accumulator     | 2      |
| CLC         | 0x18   | Implied         | 2      |
| CLD         | 0xD8   | Implied         | 2      |
| CLI         | 0x58   | Implied         | 2      |
| CLV         | 0xB8   | Implied         | 2      |
| CMP         | 0xC9   | Immediate       | 2      |
| CPX         | 0xE0   | Immediate       | 2      |
| CPY         | 0xC0   | Immediate       | 2      |
| DEX         | 0xCA   | Implied         | 2      |
| DEY         | 0x88   | Implied         | 2      |
| EOR         | 0x49   | Immediate       | 2      |
| INX         | 0xE8   | Implied         | 2      |
| INY         | 0xC8   | Implied         | 2      |
| LDA         | 0xA9   | Immediate       | 2      |
| LDX         | 0xA2   | Immediate       | 2      |
| LDY         | 0xA0   | Immediate       | 2      |
| LSR         | 0x4A   | Accumulator     | 2      |
| NOP         | 0xEA   | Implied         | 2      |
| ORA         | 0x09   | Immediate       | 2      |
| ROL         | 0x2A   | Accumulator     | 2      |
| ROR         | 0x6A   | Accumulator     | 2      |
| SBC         | 0xE9   | Immediate       | 2      |
| SEC         | 0x38   | Implied         | 2      |
| SED         | 0xF8   | Implied         | 2      |
| SEI         | 0x78   | Implied         | 2      |
| TAX         | 0xAA   | Implied         | 2      |
| TAY         | 0xA8   | Implied         | 2      |
| TSX         | 0xBA   | Implied         | 2      |
| TXA         | 0x8A   | Implied         | 2      |
| TXS         | 0x9A   | Implied         | 2      |
| TYA         | 0x98   | Implied         | 2      |
| BCC         | 0x90   | Relative        | 2**    |
| BCS         | 0xB0   | Relative        | 2**    |
| BEQ         | 0xF0   | Relative        | 2**    |
| BMI         | 0x30   | Relative        | 2**    |
| BNE         | 0xD0   | Relative        | 2**    |
| BPL         | 0x10   | Relative        | 2**    |
| BVC         | 0x50   | Relative        | 2**    |
| BVS         | 0x70   | Relative        | 2**    |
| ADC         | 0x65   | Zero Page       | 3      |
| AND         | 0x25   | Zero Page       | 3      |
| BIT         | 0x24   | Zero Page       | 3      |
| CMP         | 0xC5   | Zero Page       | 3      |
| CPX         | 0xE4   | Zero Page       | 3      |
| CPY         | 0xC4   | Zero Page       | 3      |
| EOR         | 0x45   | Zero Page       | 3      |
| JMP         | 0x4C   | Absolute        | 3      |
| LDA         | 0xA5   | Zero Page       | 3      |
| LDX         | 0xA6   | Zero Page       | 3      |
| LDY         | 0xA4   | Zero Page       | 3      |
| ORA         | 0x05   | Zero Page       | 3      |
| PHA         | 0x48   | Implied         | 3      |
| PHP         | 0x08   | Implied         | 3      |
| SBC         | 0xE5   | Zero Page       | 3      |
| STA         | 0x85   | Zero Page       | 3      |
| STX         | 0x86   | Zero Page       | 3      |
| STY         | 0x84   | Zero Page       | 3      |
| ADC         | 0x75   | Zero Page, X    | 4      |
| ADC         | 0x6D   | Absolute        | 4      |
| AND         | 0x35   | Zero Page, X    | 4      |
| AND         | 0x2D   | Absolute        | 4      |
| BIT         | 0x2C   | Absolute        | 4      |
| CMP         | 0xD5   | Zero Page, X    | 4      |
| CMP         | 0xCD   | Absolute        | 4      |
| CPX         | 0xEC   | Absolute        | 4      |
| CPY         | 0xCC   | Absolute        | 4      |
| EOR         | 0x55   | Zero Page, X    | 4      |
| EOR         | 0x4D   | Absolute        | 4      |
| LDA         | 0xB5   | Zero Page, X    | 4      |
| LDA         | 0xAD   | Absolute        | 4      |
| LDX         | 0xB6   | Zero Page, Y    | 4      |
| LDX         | 0xAE   | Absolute        | 4      |
| LDY         | 0xB4   | Zero Page, X    | 4      |
| LDY         | 0xAC   | Absolute        | 4      |
| ORA         | 0x15   | Zero Page, X    | 4      |
| ORA         | 0x0D   | Absolute        | 4      |
| PLA         | 0x68   | Implied         | 4      |
| PLP         | 0x28   | Implied         | 4      |
| SBC         | 0xF5   | Zero Page, X    | 4      |
| SBC         | 0xED   | Absolute        | 4      |
| STA         | 0x95   | Zero Page, X    | 4      |
| STA         | 0x8D   | Absolute        | 4      |
| STX         | 0x96   | Zero Page, Y    | 4      |
| STX         | 0x8E   | Absolute        | 4      |
| STY         | 0x94   | Zero Page, X    | 4      |
| STY         | 0x8C   | Absolute        | 4      |
| ADC         | 0x7D   | Absolute, X     | 4*     |
| ADC         | 0x79   | Absolute, Y     | 4*     |
| AND         | 0x3D   | Absolute, X     | 4*     |
| AND         | 0x39   | Absolute, Y     | 4*     |
| CMP         | 0xDD   | Absolute, X     | 4*     |
| CMP         | 0xD9   | Absolute, Y     | 4*     |
| EOR         | 0x5D   | Absolute, X     | 4*     |
| EOR         | 0x59   | Absolute, Y     | 4*     |
| LDA         | 0xBD   | Absolute, X     | 4*     |
| LDA         | 0xB9   | Absolute, Y     | 4*     |
| LDX         | 0xBE   | Absolute, Y     | 4*     |
| LDY         | 0xBC   | Absolute, X     | 4*     |
| ORA         | 0x1D   | Absolute, X     | 4*     |
| ORA         | 0x19   | Absolute, Y     | 4*     |
| SBC         | 0xFD   | Absolute, X     | 4*     |
| SBC         | 0xF9   | Absolute, Y     | 4*     |
| ASL         | 0x06   | Zero Page       | 5      |
| DEC         | 0xC6   | Zero Page       | 5      |
| INC         | 0xE6   | Zero Page       | 5      |
| JMP         | 0x6C   | Indirect        | 5      |
| LSR         | 0x46   | Zero Page       | 5      |
| ROL         | 0x26   | Zero Page       | 5      |
| ROR         | 0x66   | Zero Page       | 5      |
| STA         | 0x9D   | Absolute, X     | 5      |
| STA         | 0x99   | Absolute, Y     | 5      |
| ADC         | 0x71   | (Indirect), Y   | 5*     |
| AND         | 0x31   | (Indirect), Y   | 5*     |
| CMP         | 0xD1   | (Indirect), Y   | 5*     |
| EOR         | 0x51   | (Indirect), Y   | 5*     |
| LDA         | 0xB1   | (Indirect), Y   | 5*     |
| ORA         | 0x11   | (Indirect), Y   | 5*     |
| SBC         | 0xF1   | (Indirect), Y   | 5*     |
| ADC         | 0x61   | (Indirect, X)   | 6      |
| AND         | 0x21   | (Indirect, X)   | 6      |
| ASL         | 0x16   | Zero Page, X    | 6      |
| ASL         | 0x0E   | Absolute        | 6      |
| CMP         | 0xC1   | (Indirect, X)   | 6      |
| DEC         | 0xD6   | Zero Page, X    | 6      |
| DEC         | 0xCE   | Absolute        | 6      |
| EOR         | 0x41   | (Indirect, X)   | 6      |
| INC         | 0xF6   | Zero Page, X    | 6      |
| INC         | 0xEE   | Absolute        | 6      |
| JSR         | 0x20   | Absolute        | 6      |
| LDA         | 0xA1   | (Indirect, X)   | 6      |
| LSR         | 0x56   | Zero Page, X    | 6      |
| LSR         | 0x4E   | Absolute        | 6      |
| ORA         | 0x01   | (Indirect, X)   | 6      |
| ROL         | 0x36   | Zero Page, X    | 6      |
| ROL         | 0x2E   | Absolute        | 6      |
| ROR         | 0x76   | Zero Page, X    | 6      |
| ROR         | 0x6E   | Absolute        | 6      |
| RTI         | 0x40   | Implied         | 6      |
| RTS         | 0x60   | Implied         | 6      |
| SBC         | 0xE1   | (Indirect, X)   | 6      |
| STA         | 0x81   | (Indirect, X)   | 6      |
| STA         | 0x91   | (Indirect), Y   | 6      |
| ASL         | 0x1E   | Absolute, X     | 7      |
| BRK         | 0x00   | Implied         | 7      |
| DEC         | 0xDE   | Absolute, X     | 7      |
| INC         | 0xFE   | Absolute, X     | 7      |
| LSR         | 0x5E   | Absolute, X     | 7      |
| ROL         | 0x3E   | Absolute, X     | 7      |
| ROR         | 0x7E   | Absolute, X     | 7      |

</details>

\*: Add 1 cycle if page boundary is crossed.
\*\*: Add 1 cycle if branch occurs to same page.

## Addressing Modes

The following table lists the addressing modes used by the 6502. The addressing mode is the method by which the CPU
determines the address of the operand. The operand is the data that is operated on by the instruction. The addressing
mode is specified by the instruction itself, and is not part of the instruction's opcode.

<details>

| Addressing Mode | Description                                                                                                                 |
|-----------------|-----------------------------------------------------------------------------------------------------------------------------|
| Accumulator     | The operand is in the accumulator.                                                                                          |
| Immediate       | The operand is the next byte in memory.                                                                                     |
| Implied         | The instruction does not use an operand.                                                                                    |
| Absolute        | The operand is the next two bytes in memory.                                                                                |
| Absolute, X     | The operand is the next two bytes in memory, plus the X register.                                                           |
| Absolute, Y     | The operand is the next two bytes in memory, plus the Y register.                                                           |
| Zero Page       | The operand is the next byte in memory.                                                                                     |
| Zero Page, X    | The operand is the next byte in memory, plus the X register.                                                                |
| Zero Page, Y    | The operand is the next byte in memory, plus the Y register.                                                                |
| (Indirect, X)   | The operand is the next byte in memory, plus the X register. The operand is the address of the operand.                     |
| (Indirect), Y   | The operand is the next byte in memory. The operand is the address of the operand, plus the Y register.                     |
| Relative        | The operand is the next byte in memory. The operand is the address of the operand, relative to the current program counter. |

</details>

## Enum

The following enum is used to represent the instructions and their opcodes (in C++). This can also be found in
the [`utils.h`](src/include/utils.h) file.

<details>

```cpp
using byte = unsigned char;

enum class Instruction : byte
{
    BRK_IMP = 0x00,  // BRK Implied (1 byte, 7 cycles)
    NOP_IMP = 0xEA,  // NOP Implied (1 byte, 2 cycles)

    ADC_IM = 0x69,   // ADC Immediate (2 bytes, 2 cycles)
    ADC_ZP = 0x65,   // ADC Zero Page (2 bytes, 3 cycles)
    ADC_ZPX = 0x75,  // ADC Zero Page X (2 bytes, 4 cycles)
    ADC_AB = 0x6D,   // ADC Absolute (3 bytes, 4 cycles)
    ADC_ABX = 0x7D,  // ADC Absolute X (3 bytes, 4 cycles)
    ADC_ABY = 0x79,  // ADC Absolute Y (3 bytes, 4 cycles)
    ADC_INX = 0x61,  // ADC Indirect X (2 bytes, 6 cycles)
    ADC_INY = 0x71,  // ADC Indirect Y (2 bytes, 5 cycles)

    AND_IM = 0x29,   // AND Immediate (2 bytes, 2 cycles)
    AND_ZP = 0x25,   // AND Zero Page (2 bytes, 3 cycles)
    AND_ZPX = 0x35,  // AND Zero Page X (2 bytes, 4 cycles)
    AND_AB = 0x2D,   // AND Absolute (3 bytes, 4 cycles)
    AND_ABX = 0x3D,  // AND Absolute X (3 bytes, 4 cycles)
    AND_ABY = 0x39,  // AND Absolute Y (3 bytes, 4 cycles)
    AND_INX = 0x21,  // AND Indirect X (2 bytes, 6 cycles)
    AND_INY = 0x31,  // AND Indirect Y (2 bytes, 5 cycles)

    ASL_ACC = 0x0A,  // ASL Accumulator (1 byte, 2 cycles)
    ASL_ZP = 0x06,   // ASL Zero Page (2 bytes, 5 cycles)
    ASL_ZPX = 0x16,  // ASL Zero Page X (2 bytes, 6 cycles)
    ASL_AB = 0x0E,   // ASL Absolute (3 bytes, 6 cycles)
    ASL_ABX = 0x1E,  // ASL Absolute X (3 bytes, 7 cycles)

    BCC_REL = 0x90,  // BCC Relative (2 bytes, 2 cycles)
    BCS_REL = 0xB0,  // BCS Relative (2 bytes, 2 cycles)
    BEQ_REL = 0xF0,  // BEQ Relative (2 bytes, 2 cycles)
    BMI_REL = 0x30,  // BMI Relative (2 bytes, 2 cycles)
    BNE_REL = 0xD0,  // BNE Relative (2 bytes, 2 cycles)
    BPL_REL = 0x10,  // BPL Relative (2 bytes, 2 cycles)
	BVC_REL = 0x50,  // BVC Relative (2 bytes, 2 cycles)
    BVS_REL = 0x70,  // BVS Relative (2 bytes, 2 cycles)

    BIT_ZP = 0x24,   // BIT Zero Page (2 bytes, 3 cycles)
    BIT_AB = 0x2C,   // BIT Absolute (3 bytes, 4 cycles)

    CLC_IMP = 0x18,  // CLC Implied (1 byte, 2 cycles)
    CLD_IMP = 0xD8,  // CLD Implied (1 byte, 2 cycles)
    CLI_IMP = 0x58,  // CLI Implied (1 byte, 2 cycles)
    CLV_IMP = 0xB8,  // CLV Implied (1 byte, 2 cycles)

    CMP_IM = 0xC9,   // CMP Immediate (2 bytes, 2 cycles)
    CMP_ZP = 0xC5,   // CMP Zero Page (2 bytes, 3 cycles)
    CMP_ZPX = 0xD5,  // CMP Zero Page X (2 bytes, 4 cycles)
    CMP_AB = 0xCD,   // CMP Absolute (3 bytes, 4 cycles)
    CMP_ABX = 0xDD,  // CMP Absolute X (3 bytes, 4 cycles)
    CMP_ABY = 0xD9,  // CMP Absolute Y (3 bytes, 4 cycles)
    CMP_INX = 0xC1,  // CMP Indirect X (2 bytes, 6 cycles)
    CMP_INY = 0xD1,  // CMP Indirect Y (2 bytes, 5 cycles)

    CPX_IM = 0xE0,   // CPX Immediate (2 bytes, 2 cycles)
    CPX_ZP = 0xE4,   // CPX Zero Page (2 bytes, 3 cycles)
    CPX_AB = 0xEC,   // CPX Absolute (3 bytes, 4 cycles)

    CPY_IM = 0xC0,   // CPY Immediate (2 bytes, 2 cycles)
    CPY_ZP = 0xC4,   // CPY Zero Page (2 bytes, 3 cycles)
    CPY_AB = 0xCC,   // CPY Absolute (3 bytes, 4 cycles)

    DEC_ZP = 0xC6,   // DEC Zero Page (2 bytes, 5 cycles)
    DEC_ZPX = 0xD6,  // DEC Zero Page X (2 bytes, 6 cycles)
    DEC_AB = 0xCE,   // DEC Absolute (3 bytes, 6 cycles)
    DEC_ABX = 0xDE,  // DEC Absolute X (3 bytes, 7 cycles)

    DEX_IMP = 0xCA,  // DEX Implied (1 byte, 2 cycles)
    DEY_IMP = 0x88,  // DEY Implied (1 byte, 2 cycles)

    EOR_IM = 0x49,   // EOR Immediate (2 bytes, 2 cycles)
    EOR_ZP = 0x45,   // EOR Zero Page (2 bytes, 3 cycles)
    EOR_ZPX = 0x55,  // EOR Zero Page X (2 bytes, 4 cycles)
    EOR_AB = 0x4D,   // EOR Absolute (3 bytes, 4 cycles)
    EOR_ABX = 0x5D,  // EOR Absolute X (3 bytes, 4 cycles)
    EOR_ABY = 0x59,  // EOR Absolute Y (3 bytes, 4 cycles)
    EOR_INX = 0x41,  // EOR Indirect X (2 bytes, 6 cycles)
    EOR_INY = 0x51,  // EOR Indirect Y (2 bytes, 5 cycles)

    INC_ZP = 0xE6,   // INC Zero Page (2 bytes, 5 cycles)
    INC_ZPX = 0xF6,  // INC Zero Page X (2 bytes, 6 cycles)
    INC_AB = 0xEE,   // INC Absolute (3 bytes, 6 cycles)
    INC_ABX = 0xFE,  // INC Absolute X (3 bytes, 7 cycles)

    INX_IMP = 0xE8,  // INX Implied (1 byte, 2 cycles)
    INY_IMP = 0xC8,  // INY Implied (1 byte, 2 cycles)

    JMP_AB = 0x4C,   // JMP Absolute (3 bytes, 3 cycles)
    JMP_IN = 0x6C,   // JMP Indirect (3 bytes, 5 cycles)
    JSR_AB = 0x20,   // JSR Absolute (3 bytes, 6 cycles)

    LDA_IM = 0xA9,   // LDA Immediate (2 bytes, 2 cycles)
    LDA_ZP = 0xA5,   // LDA Zero Page (2 bytes, 3 cycles)
    LDA_ZPX = 0xB5,  // LDA Zero Page X (2 bytes, 4 cycles)
    LDA_AB = 0xAD,   // LDA Absolute (3 bytes, 4 cycles)
    LDA_ABX = 0xBD,  // LDA Absolute X (3 bytes, 4 cycles)
    LDA_ABY = 0xB9,  // LDA Absolute Y (3 bytes, 4 cycles)
    LDA_INX = 0xA1,  // LDA Indirect X (2 bytes, 6 cycles)
    LDA_INY = 0xB1,  // LDA Indirect Y (2 bytes, 5 cycles)

    LDX_IM = 0xA2,   // LDX Immediate (2 bytes, 2 cycles)
    LDX_ZP = 0xA6,   // LDX Zero Page (2 bytes, 3 cycles)
    LDX_ZPY = 0xB6,  // LDX Zero Page Y (2 bytes, 4 cycles)
    LDX_AB = 0xAE,   // LDX Absolute (3 bytes, 4 cycles)
    LDX_ABY = 0xBE,  // LDX Absolute Y (3 bytes, 4 cycles)

    LDY_IM = 0xA0,   // LDY Immediate (2 bytes, 2 cycles)
    LDY_ZP = 0xA4,   // LDY Zero Page (2 bytes, 3 cycles)
    LDY_ZPX = 0xB4,  // LDY Zero Page X (2 bytes, 4 cycles)
    LDY_AB = 0xAC,   // LDY Absolute (3 bytes, 4 cycles)
    LDY_ABX = 0xBC,  // LDY Absolute X (3 bytes, 4 cycles)

    LSR_ACC = 0x4A,  // LSR Accumulator (1 byte, 2 cycles)
    LSR_ZP = 0x46,   // LSR Zero Page (2 bytes, 5 cycles)
    LSR_ZPX = 0x56,  // LSR Zero Page X (2 bytes, 6 cycles)
    LSR_AB = 0x4E,   // LSR Absolute (3 bytes, 6 cycles)
    LSR_ABX = 0x5E,  // LSR Absolute X (3 bytes, 7 cycles)

    ORA_IM = 0x09,   // ORA Immediate (2 bytes, 2 cycles)
    ORA_ZP = 0x05,   // ORA Zero Page (2 bytes, 3 cycles)
    ORA_ZPX = 0x15,  // ORA Zero Page X (2 bytes, 4 cycles)
    ORA_AB = 0x0D,   // ORA Absolute (3 bytes, 4 cycles)
    ORA_ABX = 0x1D,  // ORA Absolute X (3 bytes, 4 cycles)
    ORA_ABY = 0x19,  // ORA Absolute Y (3 bytes, 4 cycles)
    ORA_INX = 0x01,  // ORA Indirect X (2 bytes, 6 cycles)
    ORA_INY = 0x11,  // ORA Indirect Y (2 bytes, 5 cycles)

    PHA_IMP = 0x48,  // PHA Implied (1 byte, 3 cycles)
    PHP_IMP = 0x08,  // PHP Implied (1 byte, 3 cycles)
    PLA_IMP = 0x68,  // PLA Implied (1 byte, 4 cycles)
    PLP_IMP = 0x28,  // PLP Implied (1 byte, 4 cycles)

    ROL_ACC = 0x2A,  // ROL Accumulator (1 byte, 2 cycles)
    ROL_ZP = 0x26,   // ROL Zero Page (2 bytes, 5 cycles)
    ROL_ZPX = 0x36,  // ROL Zero Page X (2 bytes, 6 cycles)
    ROL_AB = 0x2E,   // ROL Absolute (3 bytes, 6 cycles)
    ROL_ABX = 0x3E,  // ROL Absolute X (3 bytes, 7 cycles)

    ROR_ACC = 0x6A,  // ROR Accumulator (1 byte, 2 cycles)
    ROR_ZP = 0x66,   // ROR Zero Page (2 bytes, 5 cycles)
    ROR_ZPX = 0x76,  // ROR Zero Page X (2 bytes, 6 cycles)
    ROR_AB = 0x6E,   // ROR Absolute (3 bytes, 6 cycles)
    ROR_ABX = 0x7E,  // ROR Absolute X (3 bytes, 7 cycles)

    RTI_IMP = 0x40,  // RTI Implied (1 byte, 6 cycles)
    RTS_IMP = 0x60,  // RTS Implied (1 byte, 6 cycles)

    SBC_IM = 0xE9,   // SBC Immediate (2 bytes, 2 cycles)
    SBC_ZP = 0xE5,   // SBC Zero Page (2 bytes, 3 cycles)
    SBC_ZPX = 0xF5,  // SBC Zero Page X (2 bytes, 4 cycles)
    SBC_AB = 0xED,   // SBC Absolute (3 bytes, 4 cycles)
    SBC_ABX = 0xFD,  // SBC Absolute X (3 bytes, 4 cycles)
    SBC_ABY = 0xF9,  // SBC Absolute Y (3 bytes, 4 cycles)
    SBC_INX = 0xE1,  // SBC Indirect X (2 bytes, 6 cycles)
    SBC_INY = 0xF1,  // SBC Indirect Y (2 bytes, 5 cycles)

    SEC_IMP = 0x38,  // SEC Implied (1 byte, 2 cycles)
    SED_IMP = 0xF8,  // SED Implied (1 byte, 2 cycles)
    SEI_IMP = 0x78,  // SEI Implied (1 byte, 2 cycles)

    STA_ZP = 0x85,   // STA Zero Page (2 bytes, 3 cycles)
    STA_ZPX = 0x95,  // STA Zero Page X (2 bytes, 4 cycles)
    STA_AB = 0x8D,   // STA Absolute (3 bytes, 4 cycles)
    STA_ABX = 0x9D,  // STA Absolute X (3 bytes, 5 cycles)
    STA_ABY = 0x99,  // STA Absolute Y (3 bytes, 5 cycles)
    STA_INX = 0x81,  // STA Indirect X (2 bytes, 6 cycles)
    STA_INY = 0x91,  // STA Indirect Y (2 bytes, 6 cycles)

    STX_ZP = 0x86,   // STX Zero Page (2 bytes, 3 cycles)
    STX_ZPY = 0x96,  // STX Zero Page Y (2 bytes, 4 cycles)
    STX_AB = 0x8E,   // STX Absolute (3 bytes, 4 cycles)

    STY_ZP = 0x84,   // STY Zero Page (2 bytes, 3 cycles)
    STY_ZPX = 0x94,  // STY Zero Page X (2 bytes, 4 cycles)
    STY_AB = 0x8C,   // STY Absolute (3 bytes, 4 cycles)

    TAX_IMP = 0xAA,  // TAX Implied (1 byte, 2 cycles)
    TXA_IMP = 0x8A,  // TXA Implied (1 byte, 2 cycles)
    TAY_IMP = 0xA8,  // TAY Implied (1 byte, 2 cycles)
    TYA_IMP = 0x98,  // TYA Implied (1 byte, 2 cycles)

    TSX_IMP = 0xBA,  // TSX Implied (1 byte, 2 cycles)
    TXS_IMP = 0x9A,  // TXS Implied (1 byte, 2 cycles)
};
```

</details>
