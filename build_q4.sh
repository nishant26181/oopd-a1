#!/bin/bash

# Syscalls entry point
nasm -f elf64 syscall.S -o syscall.o

# Removing standard library and adding basicIO.o library
g++ -ffreestanding -nostdlib -fno-exceptions -fno-rtti -c basicIO.cpp -o basicIO.o

# Compiling the code
g++ -ffreestanding -nostdlib -fno-exceptions -fno-rtti -c q4.cpp -o q4.o

# Link object files into final executable setting _start as entry point
g++ -nostdlib -e _start syscall.o basicIO.o q4.o -o q4.out

