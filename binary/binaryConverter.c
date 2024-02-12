#include "../Interpreter/Headers/executeInstructions.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <binary_file>\n", argv[0]);
        // return 1;
    }

    FILE *binaryFile = fopen(argv[1], "rb");
    if (binaryFile == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        // return 1;
    }

    CPU cpu;
    initializeCPU(&cpu);

    // Read the machine code from the binary file
    fseek(binaryFile, 0, SEEK_END);
    long fileSize = ftell(binaryFile);
    rewind(binaryFile);

    unsigned char *machineCode = malloc(fileSize);

    if (machineCode == NULL)
    {
        printf("Memory allocation error\n");
        fclose(binaryFile);
        return 1;
    }

    fread(machineCode, sizeof(unsigned char), fileSize, binaryFile);

    // Close the binary file
    fclose(binaryFile);

    binaryFile = fopen(argv[1], "wb");
    fclose(binaryFile);

    // Execute the program
    executeInstructions(&cpu, machineCode);

    // Free allocated memory
    free(machineCode);

    return 0;
}