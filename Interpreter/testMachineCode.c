#include "Headers/assembleCode.h"

int main()
{
    CPU cpu;
    initializeCPU(&cpu);
    // Open the assembly code file
    FILE *file = fopen("testMC.asm", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Machine code instructions
    unsigned char machineCode[MEMORY_SIZE];
    int machineCodeSize;

    // Convert assembly code to machine code
    assembleCode(file, machineCode, &machineCodeSize);

    // Close the file
    fclose(file);

    // Registers
    unsigned char registers[16] = {0}; // R1, R2, R3, R4, R5, HLT
    // Memory
    unsigned char memory[MEMORY_SIZE] = {0};

    // Execute the program
    executeProgram(&cpu, machineCode);

    // Display memory contents after execution
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        if (memory[i] != 0)
        {
            printf("Memory[%d]: %d\n", i, memory[i]);
        }
    }

    return 0;
}
