# Object-Oriented Programming and Design - Assignment 1
**Course:** Object-Oriented Programming and Design (Monsoon 2026)  
**Environment:** Linux x86_64, NASM, GNU G++ (Freestanding, No Standard Libraries)

---

## Overview

This repository contains the implementation for **Assignment 1: Basic Programming Practices**. The objective is to build freestanding C++ applications on a 64-bit Linux environment without relying on the C/C++ standard library (`<iostream>`, `<cstdlib>`, `<stdio.h>`, etc.), heap memory allocation (`malloc`, `new`), or runtime features like exceptions and RTTI.

All system interaction (I/O, process exit) is handled via direct assembly system calls using NASM.

---

## Repository Structure & Assignments

- `syscall.S`: NASM assembly source wrapping direct Linux x86_64 system calls (`sys_read`, `sys_write`, `sys_exit`).
- `basicIO.h` / `basicIO.cpp`: Low-level I/O class implementing custom string and integer input/output functionality.

### Assignments Breakdown
1. **Question 2 (`q2.cpp`, `build_q2.sh`)**
   - A minimal C++ program returning 0 compiled with `-ffreestanding -nostdlib`.
2. **Question 3 (`q3.cpp`, `build_q3.sh`)**
   - Single-entry record program reading name and age, validating numeric bounds, and asking for confirmation using direct assembly syscalls.
3. **Question 4 (`q4.cpp`, `build_q4.sh`) [Branch: `Q4_and_Q5`]**
   - Multi-record program using C++ classes/structures and stack arrays. Asks for total count upfront and prevents stack overflows with hard upper bounds.
4. **Question 5 (`q5.cpp`, `build_q5.sh`) [Branch: `Q4_and_Q5`]**
   - Extension allowing user interaction to modify or expand total active records dynamically at runtime.

---

## Build and Execution Instructions

### Prerequisites
Ensure `g++`, `nasm`, and `bash` are installed on your Linux x86_64 system.

### Build Flags
- **NASM Compilation:** `nasm -f elf64 syscall.S -o syscall.o`
- **G++ Compilation:** `g++ -ffreestanding -nostdlib -fno-exceptions -fno-rtti -c <file>.cpp -o <file>.o`
- **Linker Step:** `g++ -nostdlib -e _start syscall.o basicIO.o <file>.o -o <file>.out`

### Running the Code
Run the shell scripts to build and execute each program:

```bash
# Build Question 2
chmod +x build_q2.sh && ./build_q2.sh

# Build Question 3
chmod +x build_q3.sh && ./build_q3.sh

# Switch to Q4_and_Q5 branch for Q4 and Q5
git checkout Q4_and_Q5

# Build Question 4
chmod +x build_q4.sh && ./build_q4.sh

# Build Question 5
chmod +x build_q5.sh && ./build_q5.sh
