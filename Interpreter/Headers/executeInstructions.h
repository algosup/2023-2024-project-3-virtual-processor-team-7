#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"

void executeInstructions(CPU *cpu, unsigned char machineCode[])
{
    int pc = 0; // Program Counter

    while (1)
    {
        switch (machineCode[pc])
        {
        // MOV immediate_value, destination_register
        case 0x20:
            cpu->registers[machineCode[pc + 2]] = machineCode[pc + 1];
            printf("MOV %d, R%d\n", machineCode[pc + 1], machineCode[pc + 2]);
            pc += 3;
            break;
        // MOV source_register, destination_register
        case 0x21:
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
        {
            // Assuming operand is a 16-bit address
            uint16_t address = (machineCode[cpu->program_counter + 1] << 8) | machineCode[cpu->program_counter + 2];
            cpu->program_counter = address;
            printf("JMP %04X\n", address);
            pc += 2;
            break;
        }

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
                // Handle overflow
                printf("Overflow in multiplication detected\n");
                return;
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
                // Handle division by zero
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
