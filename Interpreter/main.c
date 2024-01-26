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
    case ADD:
        registersArray[R3] = registersArray[operand2] += registersArray[operand1];
        break;
    case SUB:
        registersArray[R3] = registersArray[operand2] -= registersArray[operand1];
        break;
    case MUL:
        registersArray[R3] = registersArray[operand2] *= registersArray[operand1];
        break;
    case OR:
        registersArray[R3] = registersArray[operand2] || registersArray[operand1];
        break;
    case AND:
        registersArray[R3] = registersArray[operand2] && registersArray[operand1];
        break;
    case NOT:
        registersArray[R3] = !(registersArray[operand2] && registersArray[operand1]);
        break;
    case XOR:
        registersArray[R3] = registersArray[operand2] ^ registersArray[operand1];
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

    //-------------------------------------------------

    executeInstruction(MOV_IMM, 42, R1);

    printf("R1: %d\n", registersArray[R1]);
    printf("R2: %d\n", registersArray[R2]);
    printf("R3: %d\n", registersArray[R3]);

    printf("\n");

    //-------------------------------------------------

    executeInstruction(MOV_REG, R1, R2);
    printf("R1 : %d\n", registersArray[R1]);
    printf("R2 : %d\n", registersArray[R2]);

    printf("\n");

    //-------------------------------------------------

    executeInstruction(ADD, R1, R2);
    printf("R3 : %d\n", registersArray[R3]);

    printf("\n");

    //-------------------------------------------------

    executeInstruction(SUB, R1, R2);
    printf("R3 : %d\n", registersArray[R3]);

    printf("\n");

    //-------------------------------------------------

    executeInstruction(MUL, R1, R2);
    printf("R3 : %d\n", registersArray[R3]);

    printf("\n");

    //-------------------------------------------------

    executeInstruction(OR, R1, R2);
    printf("R3 : %d\n", registersArray[R3]);

    printf("\n");

    //-------------------------------------------------

    executeInstruction(AND, R1, R2);
    printf("R3 : %d\n", registersArray[R3]);

    printf("\n");

    //-------------------------------------------------

    executeInstruction(NOT, R1, R2);
    printf("R3 : %d\n", registersArray[R3]);

    printf("\n");

    //-------------------------------------------------

    executeInstruction(XOR, R1, R2);
    printf("R3 : %d\n", registersArray[R3]);

    printf("\n");

    //-------------------------------------------------

    printf("LOAD : %d\n", );

    printf("\n");
    //-------------------------------------------------

    executeInstruction(HLT, 0, 0);


    return 0;
}

