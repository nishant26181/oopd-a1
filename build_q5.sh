#!/bin/bash

# Syscalls entry point
nasm -f elf64 syscall.S -o syscall.o

# Removing standard library and adding basicIO.o library
g++ -ffreestanding -nostdlib -fno-exceptions -fno-rtti -c basicIO.cpp -o basicIO.o

# Compiling the code
g++ -ffreestanding -nostdlib -fno-exceptions -fno-rtti -c q5.cpp -o q5.o

# Link object files into final executable setting _start as entry point
g++ -nostdlib -e _start syscall.o basicIO.o q5.o -o q5.out

