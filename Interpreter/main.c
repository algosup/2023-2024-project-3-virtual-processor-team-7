// main.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Headers/cpu.h"
#include "Headers/fread.h"

int registersArray[3] = {0};

void initializeCpu()
{
    printf("Initializing CPU...\n");
}

void executeInstruction(instructions instruction, int operand1, int operand2)
{
    switch (instruction)
    {
    case MOV_IMM:
        registersArray[operand2] = operand1;
        break;
    case MOV_REG:
        registersArray[operand2] = registersArray[operand1];
        break;
    case HLT:
        exit(0);
        break;
    default:
        printf("Unknown instruction: %d\n", instruction);
        break;
    }
}

int main()
{
    initializeCpu();

    char *content = readFile("example.asm");
    printf("Assembly File Content:\n%s\n", content);

    parseAndExecute(content);

    printf("R1: %d\n", registersArray[R1]);
    printf("R2: %d\n", registersArray[R2]);
    printf("R3: %d\n", registersArray[R3]);

    return 0;
}

