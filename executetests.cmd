@ECHO OFF
cd interpreter
gcc -o main main.c
main tests/syntacticalError.all ../binary/output.bin
cd ..
cd binary
gcc -o binaryConverter binaryConverter.c
binaryConverter output.bin
PAUSE