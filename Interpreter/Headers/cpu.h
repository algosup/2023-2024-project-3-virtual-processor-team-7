#include "parser.h"

typedef struct
{
    int registers[16];
    unsigned char memory[MEMORY_SIZE];
    int program_counter;
    int stack[MEMORY_SIZE];
    int stack_pointer;
} CPU;

void initializeCPU(CPU *cpu)
{
    // Initialize CPU state
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        cpu->registers[i] = 0;
    }

    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        cpu->memory[i] = 0;
    }

    cpu->program_counter = 0;

    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        cpu->stack[i] = 0;
    }

    cpu->stack_pointer = 0;
}