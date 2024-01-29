#include <stdlib.h>
#include <string.h>
#include "machineCode.h"

// Function to convert assembly code to machine code
void assembleCode(FILE *file, unsigned char machineCode[], int *machineCodeSize)
{
    char line[256];
    int index = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Skip comments and empty lines
        if (line[0] == ';' || line[0] == '\n')
            continue;

        // Tokenize the line to extract instruction and operands
        char *token = strtok(line, " \t\n");
        if (token == NULL)
            continue; // No instruction on this line

        // Decode the instruction and convert to machine code
        if (strcmp(token, "MOV") == 0)
        {
            machineCode[index++] = 0x20; // MOV opcode

            // Parse source operand (immediate or register)
            token = strtok(NULL, " \t\n");
            if (token[0] == 'R')
            {
                machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
            }
            else
            {
                machineCode[index++] = strtol(token, NULL, 10); // Immediate value
            }

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "LOAD") == 0)
        {
            machineCode[index++] = 0x30; // LOAD opcode

            // Parse address register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "STR") == 0)
        {
            machineCode[index++] = 0x41; // STR opcode

            // Parse source register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse address register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "CMP") == 0)
        {
            machineCode[index++] = 0x52; // CMP opcode

            // Parse source register 1
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse source register 2
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "PRT") == 0)
        {
            machineCode[index++] = 0x58; // PRT opcode

            // Parse register or immediate value to print
            token = strtok(NULL, " \t\n");
            if (token[0] == 'R')
            {
                machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
            }
            else
            {
                unsigned int immediateValue = atoi(token) & 0xFF; // Ensure immediate value is within 8 bits
                machineCode[index++] = (1 << 7) | immediateValue; // Immediate value with MSB set
            }
        }

        else if (strcmp(token, "JMP") == 0)
        {
            machineCode[index++] = 0x70; // JMP opcode

            // Parse label
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token, NULL, 10); // Label value
        }
        else if (strcmp(token, "JMPT") == 0)
        {
            machineCode[index++] = 0x81; // JMPT opcode

            // Parse condition
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token, NULL, 10); // Condition value

            // Parse label
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token, NULL, 10); // Label value
        }
        else if (strcmp(token, "JMPF") == 0)
        {
            machineCode[index++] = 0x92; // JMPF opcode

            // Parse condition
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token, NULL, 10); // Condition value

            // Parse label
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token, NULL, 10); // Label value
        }
        else if (strcmp(token, "CALL") == 0)
        {
            machineCode[index++] = 0xA0; // CALL opcode

            // Parse subroutine label
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token, NULL, 10); // Subroutine label value
        }
        else if (strcmp(token, "RETURN") == 0)
        {
            machineCode[index++] = 0xB0; // RETURN opcode
        }
        else if (strcmp(token, "ADD") == 0)
        {
            machineCode[index++] = 0xC0; // ADD opcode

            // Parse source register 1
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse source register 2
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "SUB") == 0)
        {
            machineCode[index++] = 0xD1; // SUB opcode

            // Parse source register 1
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse source register 2
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "MUL") == 0)
        {
            machineCode[index++] = 0xE2; // MUL opcode

            // Parse source register 1
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse source register 2
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "DIV") == 0)
        {
            machineCode[index++] = 0xF3; // DIV opcode

            // Parse source register 1
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse source register 2
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "OR") == 0)
        {
            machineCode[index++] = 0x14; // OR opcode

            // Parse source register 1
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse source register 2
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "AND") == 0)
        {
            machineCode[index++] = 0x25; // AND opcode

            // Parse source register 1
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse source register 2
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "XOR") == 0)
        {
            machineCode[index++] = 0x36; // XOR opcode

            // Parse source register 1
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse source register 2
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "NOT") == 0)
        {
            machineCode[index++] = 0x47; // NOT opcode

            // Parse source register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number

            // Parse destination register
            token = strtok(NULL, " \t\n");
            machineCode[index++] = strtol(token + 1, NULL, 10); // Register number
        }
        else if (strcmp(token, "HLT") == 0)
        {
            machineCode[index++] = 0xFF; // HLT opcode
        }
        else
        {
            printf("Unknown instruction: %s\n", token);
            exit(1);
        }
    }

    *machineCodeSize = index;
}