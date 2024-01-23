// fread.h
#ifndef FREAD_H
#define FREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"

// function prototypes
long getFileSize(const char *filename);
char *readFile(const char *filename);
void parseAndExecute(const char *content);

// Function to get the size of the file
long getFileSize(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    return size;
}

// Function to read the content of the file
// Function to read the content of the file
char *readFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    long size = getFileSize(filename);

    char *content = (char *)malloc(size + 1);
    if (content == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_SET);
    fread(content, 1, size, file);
    fclose(file);

    content[size] = '\0';

    return content;
}

void parseAndExecute(const char *content)
{
    char *line = strtok((char *)content, "\n");

    while (line != NULL)
    {
        // Debug: print the line being processed
        printf("Processing line: %s\n", line);

        // Ignore comments marked by semicolon
        char *comment = strchr(line, ';');
        if (comment != NULL)
        {
            *comment = '\0'; // Null terminate to ignore comments
        }

        // Check if the line is empty
        if (strspn(line, " \t\r\n") == strlen(line))
        {
            line = strtok(NULL, "\n");
            continue;
        }

        char instruction[20], operand1[20], operand2[20];

        // Use sscanf to parse the operands
        int items = sscanf(line, "%s %19s %19s", instruction, operand1, operand2);

        // Debug: print instruction details
        printf("Parsed: %s %s %s\n", instruction, operand1, operand2);

        // Check if sscanf successfully read at least one item
        if (items < 1)
        {
            printf("Invalid instruction format: %s\n", line);
            break;
        }

        // Convert the instruction string to the corresponding enum
        instructions inst;
        if (strcmp(instruction, "MOV_IMM") == 0)
        {
            inst = MOV_IMM;
        }
        else if (strcmp(instruction, "MOV_REG") == 0)
        {
            inst = MOV_REG;
        }
        else if (strcmp(instruction, "HLT") == 0)
        {
            inst = HLT;

            // No need to check for operands in HLT instruction
            executeInstruction(inst, 0, 0);
            line = strtok(NULL, "\n");
            continue;
        }
        else
        {
            printf("Unknown instruction: %s\n", instruction);
            break;
        }

        // Check if sscanf successfully read all three items
        if (items != 3)
        {
            printf("Invalid instruction format: %s\n", line);
            break;
        }

        int op1 = atoi(operand1);
        int op2 = atoi(operand2);

        // Debug: print operands
        printf("Operands: %d %d\n", op1, op2);

        // Now call executeInstruction with the correct enum
        executeInstruction(inst, op1, op2);

        line = strtok(NULL, "\n");
    }
}


#endif // FREAD_H
