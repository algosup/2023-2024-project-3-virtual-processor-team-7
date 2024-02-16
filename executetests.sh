#!/bin/bash

cd interpreter
gcc -o main main.c
./main tests/not.all ../binary/output.bin
cd ..
cd binary
gcc -o binaryConverter binaryConverter.c
./binaryConverter output.bin
read -p "Press Enter to continue..."