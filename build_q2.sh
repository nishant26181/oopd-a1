#!/bin/bash
nasm -f elf64 syscall.S -o syscall.o
g++ -ffreestanding -nostdlib -fno-exceptions -fno-rtti -c q2.cpp -o q2.o
g++ -nostdlib -e _start syscall.o q2.o -o q2.out
