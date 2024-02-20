#include "cpu.h"
#include <stdint.h>


void executeInstructions(CPU *cpu, unsigned char machineCode[])
{
    int pc = 0; // Program Counter

    while (1){
        switch (machineCode[pc])
        {
        // MOV immediate_value, destination_register
        case 0x20:
        {
            if (machineCode[pc + 1] > 255) {
                // Handle overflow
                printf("Overflow in MOV detected\n");
                return;
            } else {
                int destReg = machineCode[pc + 2];
                cpu->registers[destReg] = machineCode[pc + 1];
                printf("MOV %d, R%d\n", machineCode[pc + 1], destReg);
                pc += 3;
            }
            break;
        }

        // MOV source_register, destination_register
        case 0x21:
        {
            if (cpu->registers[machineCode[pc + 1]] > 255) {
                // Handle overflow
                printf("Overflow in MOV detected\n");
                return;
            } else {
                int destReg = machineCode[pc + 2];
                int srcReg = machineCode[pc + 1];
                
                    cpu->registers[destReg] = cpu->registers[srcReg];
                    printf("MOV R%d, R%d\n", srcReg, destReg);
                    pc += 3;
            }
            break;
        }
        // LOAD address_register, destination_register
        case 0x30:
        {
            int address = cpu->registers[machineCode[pc + 1]];
            if (address > MEMORY_SIZE) {
                // Handle out of bounds memory access
                printf("Out of bounds memory access in LOAD\n");
                return;
            } else {
                int destReg = machineCode[pc + 2];
                
                    cpu->registers[destReg] = cpu->memory[address];
                    printf("LOAD R%d, R%d\n", machineCode[pc + 1], destReg);
                    pc += 3;
            }
            break;
        }
        // STR source_register, address_register
        case 0x41:
        {
            int address = cpu->registers[machineCode[pc + 2]];
            if (address > MEMORY_SIZE) {
                // Handle out of bounds memory access
                printf("Out of bounds memory access in STR\n");
                return;
            } else {
                int srcReg = machineCode[pc + 1];
               
                    cpu->memory[address] = cpu->registers[srcReg];
                    printf("STR R%d, R%d\n", srcReg, machineCode[pc + 2]);
                    pc += 3;
            }
            break;
        }
        // CMP source_register1, source_register2
        case 0x52:
        {
            int srcReg1 = machineCode[pc + 1];
            int srcReg2 = machineCode[pc + 2];
            
                if (cpu->registers[srcReg1] == cpu->registers[srcReg2]) {
                    printf("CMP R%d, R%d\n", srcReg1, srcReg2);
                    printf("Comparison is TRUE\n");
                } else {
                    printf("CMP R%d, R%d\n", srcReg1, srcReg2);
                    printf("Comparison is FALSE\n");
                }
                pc += 3;
            
            break;
        }

        case 0x58:
        {
            if (machineCode[pc + 1] < 16) {
                
                printf("PRT R%d: %d\n", machineCode[pc + 1], cpu->registers[machineCode[pc + 1]]);
                pc += 2;
            } else {
                // It's a string literal
            printf("PRT: %s\n", &machineCode[pc + 1]);
            // Increment pc by the length of the string plus one for the null byte
            pc += strlen((char*)&machineCode[pc + 1]) + 2;
            }
            break;
        }

        case 0x59:
        {
            if (machineCode[pc + 1] < 16) {
                // It's a register number
                printf("PRT R%d: %c\n", machineCode[pc + 1], cpu->registers[machineCode[pc + 1]]);
                pc += 2;
            } else {
                // It's a string literal
                printf("PRT: %s\n", &machineCode[pc + 1]);
                // Increment pc by the length of the string plus one for the null byte
                pc += strlen((char*)&machineCode[pc + 1]) + 2;
            }
            break;
        }
        
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
            pc += 2;
            break;

        case 0xB0: // RETURN
            // Retrieve the return address from the stack
            cpu->program_counter = cpu->stack[--cpu->stack_pointer];
            printf("RETURN to %d\n", cpu->program_counter);
            break;
        
        // ADD source_register1, source_register2, destination_register
        case 0xC0:
        {
            int srcReg1 = machineCode[pc + 1];
            int srcReg2 = machineCode[pc + 2];
            int destReg = machineCode[pc + 3];
            
                int result = cpu->registers[srcReg1] + cpu->registers[srcReg2];
                if (result > 255) {
                    // Handle overflow
                    printf("Overflow in addition detected\n");
                    return;
                }
                else{
                cpu->registers[destReg] = (unsigned char)result;
                printf("ADD R%d, R%d, R%d\n", srcReg1, srcReg2, destReg);
                pc += 4;
                }
            break;
        } 
        // SUB source_register1, source_register2, destination_register
        case 0xD1:
        {
            int srcReg1 = machineCode[pc + 1];
            int srcReg2 = machineCode[pc + 2];
            int destReg = machineCode[pc + 3];
           
                int result = cpu->registers[srcReg1] - cpu->registers[srcReg2];
                if (result < 0)
                {
                    // Handle underflow
                    printf("Underflow in subtraction detected\n");
                    return;
                }
                else
                {
                    cpu->registers[destReg] = (unsigned char)result;
                    printf("SUB R%d, R%d, R%d\n", srcReg1, srcReg2, destReg);
                    pc += 4;
                }
            }

            break;
        
        // MUL source_register1, source_register2, destination_register
        case 0xE2:
        {
            int srcReg1 = machineCode[pc + 1];
            int srcReg2 = machineCode[pc + 2];
            int destReg = machineCode[pc + 3];
            
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
            int srcReg1 = machineCode[pc + 1];
            int srcReg2 = machineCode[pc + 2];
            int destReg = machineCode[pc + 3];
    
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
                pc += 4;
            }
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