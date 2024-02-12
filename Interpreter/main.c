#include "Headers/parser.h"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <assembly_code_file> <output_binary_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    

    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL)
    {
        printf("Error opening file %s\n", argv[2]);
        fclose(inputFile);
        return 1;
    }

    // Machine code instructions
    unsigned char machineCode[MEMORY_SIZE];
    int machineCodeSize;

    // Convert assembly code to machine code
    parser(inputFile, machineCode, &machineCodeSize);

      // Write the machine code to the binary file line by line
    for (int i = 0; i < machineCodeSize; ++i)
    {
        fwrite(&machineCode[i], sizeof(unsigned char), 1, outputFile);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
