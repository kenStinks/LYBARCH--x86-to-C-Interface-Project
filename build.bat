:: This script helps to assemble and compile ASM source code using 
:: a driver program. If you need to assemble any additional files, 
:: uncomment the NASM command, providing the ASM file as input.

@echo off

set arg1="sdot_asm"

:: nasm -f win32 asm_io.asm

nasm -f win64 "%arg1%.asm"

:: -Zi produces debug symbols, can be used for debugging/disassembling
gcc -c main.c -o main.o
gcc -o main "%arg1%.obj" main.o