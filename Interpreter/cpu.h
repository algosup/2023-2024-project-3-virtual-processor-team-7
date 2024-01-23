// cpu.h
#ifndef CPU_H
#define CPU_H

// enum for the instructions
typedef enum
{
    MOV_IMM,
    MOV_REG,
    LOAD,
    STOR,
    COMP,
    JUMP,
    JUMP_IF,
    CALL,
    RETURN,
    ADD,
    SUB,
    MUL,
    DIV,
    OR,
    AND,
    XOR,
    NOT,
    HLT
} instructions;

// enum for registers
typedef enum
{
    R1,
    R2,
    R3
} registers;

// Cpu function prototypes
void initializeCpu();
void executeInstruction(instructions instruction, int operand1, int operand2);

#endif // CPU_H
