# Object-Oriented Programming and Design - Assignment 1

**Student Name:** Nishant Kharwal  
**Roll Number:** MT26181  
**Course:** Object-Oriented Programming and Design (Monsoon 2026)  
**Environment:** x86_64 Linux, NASM Assembler, GNU G++ (Freestanding, No Standard Libraries)

---

## Overview

This repository contains the complete implementation for **Assignment 1: Basic Programming Practices**. The core objective of this assignment is to design and build freestanding C++ applications in a 64-bit Linux environment without relying on standard C/C++ libraries (`<iostream>`, `<cstdlib>`, `<stdio.h>`, etc.), heap memory management (`new`, `malloc`), or C++ runtime support (exceptions, RTTI).

All lower-level operating system interactions—including reading input from standard input (`sys_read`), printing characters to standard output (`sys_write`), and exiting processes (`sys_exit`)—are written directly in x86_64 NASM assembly.

---

## Repository Architecture & Core Components

### Custom Low-Level I/O Framework (Supplied Modules)
* **`syscall.S`**: NASM 64-bit assembly source defining direct Linux system calls (`sys_read` = syscall 0, `sys_write` = syscall 1, `sys_exit` = syscall 60).
* **`basicIO.h` / `basicIO.cpp`**: Custom C++ I/O driver class (`BasicIO`) that wraps assembly system calls into high-level methods for string and integer operations (`inputstring`, `outputstring`, `inputint`, `outputint`).

### Assignment Program Breakdown

#### Branch: `main`
* **`MT26181_q2.cpp` & `MT26181_build_q2.sh`**
  * Minimal freestanding C++ program returning `0` on execution.
  * Demonstrates proper compilation using `-ffreestanding -nostdlib` flags without invoking standard C/C++ runtimes.
* **`MT26181_q3.cpp` & `MT26181_build_q3.sh`**
  * Single-record user profile entry program that accepts a user's name and age via assembly syscalls.
  * Implements compulsory input validation loops ensuring age inputs fall strictly within valid numeric bounds (1 to 99).
  * Prompts the user with an explicit confirmation step (`y`/`n`).

#### Branch: `Q4_and_Q5`
* **`MT26181_q4.cpp` & `MT26181_build_q4.sh`**
  * Multi-record dynamic data collection tool utilizing stack-allocated structures (`Person`).
  * Asks for total record count upfront while enforcing strict upper-bound limits (max 100 entries) to guarantee prevention of stack memory overflows.
* **`MT26181_q5.cpp` & `MT26181_build_q5.sh`**
  * Extended multi-record management utility enabling runtime expansion/modification of existing active records.
  * Includes compulsory age validation loops across both primary entries and secondary additions, ensuring total counts remain within hard stack boundaries.

---

## Technical Constraints & Safety Guarantees

1. **Freestanding Execution:** Compiled strictly with `-ffreestanding -nostdlib -fno-exceptions -fno-rtti` to disallow all external runtime libraries.
2. **Memory Safety & No-Heap Rule:** Operates without dynamic heap allocations (`malloc`, `free`, `new`, `delete`). Stack arrays are bounded to a maximum capacity of 100 entries to eliminate buffer/stack overflows.
3. **Compulsory Input Validation:** All program entry points strictly validate numeric input, trapping out-of-range age values (e.g., negative integers, zero, or age >= 100) inside interactive prompt loops until valid data is supplied.
4. **Header Comments:** Every non-supplied source file (`.cpp`) and shell script (`.sh`) starts with mandatory Roll Number and Name identification comments.

---

## Build and Execution Instructions

### Prerequisites
Ensure `g++`, `nasm`, and `bash` are installed on your x86_64 Linux environment.

### Toolchain Flags
* **Assembly Compilation:** `nasm -f elf64 syscall.S -o syscall.o`
* **Freestanding C++ Compilation:** `g++ -ffreestanding -nostdlib -fno-exceptions -fno-rtti -c <file>.cpp -o <file>.o`
* **Custom Entry Point Linker:** `g++ -nostdlib -e _start syscall.o basicIO.o <file>.o -o <file>.out`

### LLM Prompts Used During Development
"Write a C++ program that does nothing except returns 0 utilizing g++ options that exclude standard library files (-ffreestanding, -nostdlib)."

"How to write a NASM x86_64 assembly source file (syscall.S) to perform direct sys_read and sys_write syscalls without standard C library support?"

"Write input validation in freestanding C++ to ensure age input is a valid number between 1 and 99 without using <iostream> or std::cin."

"According to the assignment specifications, do I need to check input validity (whether age is a number) as compulsory logic for Questions 3, 4, and 5?"

"How to handle dynamic record bounds on the stack safely using C++ structures without new or malloc while preventing stack overflows?"

"How to apply the required RollNo_Filename.extension naming convention and prepend name/roll number header comments across .cpp and .sh files using shell commands?"

"How to fix git push rejections ([rejected] main -> main (fetch first)) and handle repository sync safely when updating files across dual branches (main and Q4_and_Q5)?"

### Automated Build Commands

#### Running Questions
```bash
git checkout main

# Build & Run Question 2
chmod +x MT26181_build_q2.sh && ./MT26181_build_q2.sh

# Build & Run Question 3
chmod +x MT26181_build_q3.sh && ./MT26181_build_q3.sh

#### Running Questions 4 and 5 (Q4_and_Q5 branch)
```bash
git checkout Q4_and_Q5

# Build & Run Question 4
chmod +x MT26181_build_q4.sh && ./MT26181_build_q4.sh

# Build & Run Question 5
chmod +x MT26181_build_q5.sh && ./MT26181_build_q5.sh


