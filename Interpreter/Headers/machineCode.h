#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 256

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
    for (int i = 0; i < 16; i++)
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

void executeProgram(CPU *cpu, unsigned char machineCode[])
{
    int pc = 0; // Program Counter

    while (machineCode[pc] != 0xFF)
    {
        switch (machineCode[pc])
        {
        // MOV source_register, destination_register
        case 0x20:
            cpu->registers[machineCode[pc + 2]] = cpu->registers[machineCode[pc + 1]];
            printf("MOV R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2]);
            pc += 3;
            break;
        // LOAD address_register, destination_register
        case 0x30:
            cpu->registers[machineCode[pc + 2]] = cpu->memory[cpu->registers[machineCode[pc + 1]]];
            printf("LOAD R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2]);
            pc += 3;
            break;
        // STR source_register, address_register
        case 0x41:
            cpu->memory[cpu->registers[machineCode[pc + 2]]] = cpu->registers[machineCode[pc + 1]];
            printf("STR R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2]);
            pc += 3;
            break;
        // CMP source_register1, source_register2
        case 0x52:
            if (cpu->registers[machineCode[pc + 1]] == cpu->registers[machineCode[pc + 2]])
            {
                printf("CMP R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2]);
                printf("Comparison is TRUE\n");
            }
            else
            {
                printf("CMP R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2]);
                printf("Comparison is FALSE\n");
            }
            pc += 3;
            break;
        case 0x58:
            printf("PRT R%d: %d\n", machineCode[pc + 1], cpu->registers[machineCode[pc + 1]]);
            pc += 2;
            break;
        // JMP label
        case 0x70: // JMP label
            cpu->program_counter = machineCode[cpu->program_counter + 1];
            printf("JMP %d\n", machineCode[cpu->program_counter + 1]);
            break;

        case 0x81: // JMPT condition, label
            if (machineCode[cpu->program_counter + 1])
            {
                cpu->program_counter = machineCode[cpu->program_counter + 2];
                printf("JMPT TRUE, %d\n", machineCode[cpu->program_counter + 2]);
            }
            else
            {
                cpu->program_counter += 3;
            }
            break;

        case 0x92: // JMPF condition, label
            if (!machineCode[cpu->program_counter + 1])
            {
                cpu->program_counter = machineCode[cpu->program_counter + 2];
            }
            else
            {
                cpu->program_counter += 3;
            }
            break;

        case 0xA0: // CALL subroutine_label
            // Save the return address (next instruction) on the stack
            cpu->stack[cpu->stack_pointer++] = cpu->program_counter + 2;
            cpu->program_counter = machineCode[cpu->program_counter + 1];
            printf("CALL %d\n", machineCode[cpu->program_counter + 1]);
            break;

        case 0xB0: // RETURN
            // Retrieve the return address from the stack
            cpu->program_counter = cpu->stack[--cpu->stack_pointer];
            printf("RETURN to %d\n", cpu->program_counter);
            break;
        // ADD source_register1, source_register2, destination_register
        case 0xC0:
            cpu->registers[machineCode[pc + 3]] = cpu->registers[machineCode[pc + 1]] + cpu->registers[machineCode[pc + 2]];
            printf("ADD R%d, R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2], machineCode[pc + 3]);
            pc += 4;
            break;
        // SUB source_register1, source_register2, destination_register
        case 0xD1:
        {
            int result = cpu->registers[machineCode[pc + 1]] - cpu->registers[machineCode[pc + 2]];
            if (result < 0)
            {
                // Handle underflow, for example, set a flag or take appropriate action
                printf("Underflow in subtraction detected\n");
                return;
                // You may choose to set a flag and handle it outside the switch statement
            }
            else
            {
                cpu->registers[machineCode[pc + 3]] = (unsigned char)result;
                printf("SUB R%d, R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2], machineCode[pc + 3]);
                pc += 4;
            }

            break;
        }
        // MUL source_register1, source_register2, destination_register
        case 0xE2:
        {
            int result = cpu->registers[machineCode[pc + 1]] * cpu->registers[machineCode[pc + 2]];
            if (result > 255)
            {
                // Handle overflow, for example, set a flag or take appropriate action
                printf("Overflow in multiplication detected\n");
                return;
                // You may choose to set a flag and handle it outside the switch statement
            }
            else
            {
                cpu->registers[machineCode[pc + 3]] = (unsigned char)result;
                printf("MUL R%d, R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2], machineCode[pc + 3]);
                pc += 4;
            }
            break;
        }
        // DIV source_register1, source_register2, destination_register
        case 0xF3:
        {
            unsigned char divisor = cpu->registers[machineCode[pc + 2]];
            unsigned char dividend = cpu->registers[machineCode[pc + 1]];
            if (divisor == 0 || dividend == 0)
            {
                // Handle division by zero, for example, set a flag or take appropriate action
                printf("Division by zero detected\n");
                return;
            }
            else
            {
                cpu->registers[machineCode[pc + 3]] = cpu->registers[machineCode[pc + 1]] / divisor;
                printf("DIV R%d, R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2], machineCode[pc + 3]);
            }
            pc += 4;
            break;
        }
        // OR source_register1, source_register2, destination_register
        case 0x14:
            cpu->registers[machineCode[pc + 3]] = cpu->registers[machineCode[pc + 1]] | cpu->registers[machineCode[pc + 2]];
            printf("OR R%d, R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2], machineCode[pc + 3]);
            pc += 4;
            break;
        // AND source_register1, source_register2, destination_register
        case 0x25:
            cpu->registers[machineCode[pc + 3]] = cpu->registers[machineCode[pc + 1]] & cpu->registers[machineCode[pc + 2]];
            printf("AND R%d, R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2], machineCode[pc + 3]);
            pc += 4;
            break;
        // XOR source_register1, source_register2, destination_register
        case 0x36:
            cpu->registers[machineCode[pc + 3]] = cpu->registers[machineCode[pc + 1]] ^ cpu->registers[machineCode[pc + 2]];
            printf("XOR R%d, R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2], machineCode[pc + 3]);
            pc += 4;
            break;
        // NOT source_register, destination_register
        case 0x47:
            cpu->registers[machineCode[pc + 2]] = ~cpu->registers[machineCode[pc + 1]];
            printf("NOT R%d, R%d\n", machineCode[pc + 1], machineCode[pc + 2]);
            pc += 3;
            break;
        case 0xFF:
            printf("HLT\n");
            return;
        default:
            printf("Invalid instruction\n");
            return;
        }
    }
}

// int main()
// {
//     // Machine code instructions
//     unsigned char machineCode[] = {
//         // Example instructions:
//         0x20, 0x08, 0x03,       // MOV 42, R1
//         0X58, 0x03,             // PRT R1
//         0x20, 0x05, 0x02,       // MOV R1, R2
//         0x30, 0x03, 0x04,       // LOAD R3, R4
//         0x21, 0x03, 0x05,       // MOV R3, R5
//         0x58, 0x05,             // PRT R5
//         0x21, 0x02, 0x04,       // MOV R2, R4
//         0x58, 0x04,             // PRT R4
//         0x41, 0x02, 0x05,       // STR R2, R5

//         0xC0, 0x03, 0x02, 0x01, // ADD R1, R2, R3
//         0x58, 0x01,
//         0xD1, 0x02, 0x01, 0x03, // SUB R1, R2, R3
//         0xE2, 0x01, 0x02, 0x03, // MUL R1, R2, R3
//         0x58, 0x01,
//         0x58, 0x02,
//         0xF3, 0x01, 0x02, 0x03, // DIV R1, R2, R3
//         0x58, 0x03,
//         0x14, 0x01, 0x02, 0x03, // OR R1, R2, R3
//         0x58, 0x01,
//         0x58, 0x02,
//         0x25, 0x01, 0x02, 0x03, // AND R1, R2, R3
//         0x58, 0x03,
//         0x36, 0x01, 0x02, 0x03, // XOR R1, R2, R3
//         0x58, 0x03,
//         0x47, 0x01, 0x02,       // NOT R1, R4

//         0xFF                    // HLT
//     };

//     // Registers
//     unsigned char registers[6] = {0}; // R1, R2, R3, R4, R5, HLT
//     // Memory
//     unsigned char memory[MEMORY_SIZE] = {0};

//     // Execute the program
//     executeProgram(machineCode, registers, memory);

//     // Display memory contents after execution
//     for (int i = 0; i < MEMORY_SIZE; i++)
//     {
//         if (memory[i] != 0)
//         {
//             printf("Memory[%d]: %d\n", i, memory[i]);
//         }
//     }

//     return 0;
// }
