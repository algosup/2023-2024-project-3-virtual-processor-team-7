// cpu.h
#ifndef CPU_H
#define CPU_H

//enum for the instructions
enum instructions{
    MOV_IMM = 0,
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
};

//enum for registers
enum registers{
    R0,
    R1,
    R2,
    R3
    //Other registers may be added
};

// Cpu function prototypes
void initializeCpu();
void executeInstruction();

#endif // CPU_H
