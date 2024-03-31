@echo off

set arg1="sdot_asm"

nasm -f win64 "%arg1%.asm"

gcc -c main.c -o main.o
gcc -o main "%arg1%.obj" main.o
main