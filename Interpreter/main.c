// main.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"

int registersArray[3] = {0};

void initializeCpu()
{
    printf("Initializing CPU...\n");
}

//-----------------------------------------------------------

void executeInstruction(instructions instruction, int operand1, int operand2)
{
    switch (instruction)
    {
    case MOV_IMM:
        registersArray[operand2] = operand1;
        break;
    case MOV_REG:
        registersArray[operand2] = registersArray[operand1];
        registersArray[operand1] = NULL;
        break;
    default:
        printf("Unknown instruction\n");
        break;
    }
}


int main()
{
    initializeCpu();

    executeInstruction(MOV_IMM, 42, R1);

    printf("R1: %d\n", registersArray[R1]);
    printf("R2: %d\n", registersArray[R2]);
    printf("R3: %d\n", registersArray[R3]);

    printf("\n");

    executeInstruction(MOV_REG, R1, R2);
    printf("R1 : %d\n", registersArray[R1]);
    printf("R2 : %d\n", registersArray[R2]);

    return 0;
}

//-------------------------------------------------------------------


