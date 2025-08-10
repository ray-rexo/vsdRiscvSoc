# 🛠 Task 2: Prove Your Local RISC‑V Setup (Run, Disassemble, Decode)

---

## Objective

* Run 4 RISC‑V C programs locally using the installed toolchain and spike pk
* Embed uniqueness via username, hostname, machine ID, and timestamps
* Disassemble and decode main section of each binary
* Decode RISC-V integer instructions manually

---

## Set Up Unique Identity Variables

### Objective

Set identity variables in the Linux host shell so that each build is uniquely tied to the system.




##  - Create Common Header unique.h

###  Objective

Create a reusable header for printing build/run metadata like user, host, machine ID, build time, etc.

### File: unique.h

Contains:

* Preprocessor macros
* fnv1a64() hash function
* uniq_print_header() function that prints a unique proof block

##  Program 1: factorial.c

###  Objective

Run a recursive factorial calculation while embedding unique metadata


### 📷 Screenshots
**Spike Run Output:**
<img width="729" height="330" alt="factorial_spike_pk" src="https://github.com/user-attachments/assets/eeefc6fd-42da-494c-8a05-f639bd1f38d6" />

**main: Assembly:**
<img width="772" height="707" alt="factorial_main_asm" src="https://github.com/user-attachments/assets/768b6487-6c42-41a2-8cec-927f706b46e4" />

---

##  Program 2: max\_array.c

### Objective

Find the maximum in an array and print with proof header

(Repeat same steps as Task 2.3 for compile, run, assembly, and disassembly)

### 📷 Screenshots
**Spike Run Output:**
<img width="730" height="281" alt="max_array_spike_pk" src="https://github.com/user-attachments/assets/f7df8ba1-268e-48b0-aaba-893833358cfd" />

**main: Assembly:**
<img width="544" height="495" alt="max_array_main_asm" src="https://github.com/user-attachments/assets/010e4754-eeed-41bb-ac0a-8ad2dafe66cc" />

---

##  Program 3: bitops.c

### Objective

Perform basic bitwise operations and show uniqueness

(Repeat same steps as Task 2.3)

### 📷 Screenshots
**Spike Run Output:**
<img width="637" height="350" alt="bitops_spike_pk" src="https://github.com/user-attachments/assets/f43c78b0-5941-4909-abf2-f29a13e833d2" />

**main: Assembly:**
<img width="568" height="814" alt="bitops_main_asm1" src="https://github.com/user-attachments/assets/63f51ab9-8724-4fcd-b8bc-100bf59f73cc" />
<img width="568" height="722" alt="bitops_main_asm2" src="https://github.com/user-attachments/assets/9ac98d93-1876-48ca-9b65-4af04fe3786f" />

---

## Program 4: bubble\_sort.c

###  Objective

Perform bubble sort and print sorted array with proof header

(Repeat same steps as Task 2.3)

### 📷 Screenshots
**Spike Run Output:**
<img width="660" height="293" alt="bubble_sort_spike_pk" src="https://github.com/user-attachments/assets/103b8d09-dc05-4317-a943-2ca13d3c7250" />

**main: Assembly:**
<img width="664" height="587" alt="bubble_sort_main_asm" src="https://github.com/user-attachments/assets/a561cda6-3427-4150-8e3a-20ebe4a28f60" />

---

##  Instruction Decoding

### Objective

Manually decode at least 5 RISC‑V integer instructions from .s or .objdump output

### File: instruction_decoding.md
[instruction_decoding.md](https://github.com/user-attachments/files/21704321/instruction_decoding.md)
# Instruction Decoding (Integer Type)

## factorial.s

| Instruction           | Opcode  | rd   | rs1  | rs2  | funct3 | funct7   | Binary                                      | Description              |
|-----------------------|---------|------|------|------|--------|----------|---------------------------------------------|--------------------------|
| addi sp, sp, -32      | 0010011 | x2   | x2   | —    | 000    | —        | 111111000000 00010 000 00010 0010011        | sp = sp - 32             |
| sd ra, 24(sp)         | 0100011 | —    | x2   | x1   | 011    | 0000000  | 0000000 00001 00010 011 11000 0100011       | store ra at sp+24        |
| sd s0, 16(sp)         | 0100011 | —    | x2   | x8   | 011    | 0000000  | 0000000 01000 00010 011 10000 0100011       | store s0 at sp+16        |
| addi s0, sp, 32       | 0010011 | x8   | x2   | —    | 000    | —        | 000000100000 00010 000 01000 0010011        | s0 = sp + 32             |
| lui a5, %hi(.LC20)    | 0110111 | x15  | —    | —    | —      | —        | 000000000001 11000 111 01111 0110111        | a5 = upper 20 bits addr  |

---

## max_array.s

| Instruction           | Opcode  | rd   | rs1  | rs2  | funct3 | funct7   | Binary                                      | Description              |
|-----------------------|---------|------|------|------|--------|----------|---------------------------------------------|--------------------------|
| addi sp, sp, -64      | 0010011 | x2   | x2   | —    | 000    | —        | 111111100000 00010 000 00010 0010011        | sp = sp - 64             |
| sd ra, 56(sp)         | 0100011 | —    | x2   | x1   | 011    | 0000000  | 0000000 00001 00010 011 11100 0100011       | store ra at sp+56        |
| sd s0, 48(sp)         | 0100011 | —    | x2   | x8   | 011    | 0000000  | 0000000 01000 00010 011 11000 0100011       | store s0 at sp+48        |
| addi s0, sp, 64       | 0010011 | x8   | x2   | —    | 000    | —        | 000001000000 00010 000 01000 0010011        | s0 = sp + 64             |
| lui a5, %hi(.LC21)    | 0110111 | x15  | —    | —    | —      | —        | 000000000001 11000 111 01111 0110111        | a5 = upper 20 bits addr  |

---

## bitops.s

| Instruction           | Opcode  | rd   | rs1  | rs2  | funct3 | funct7   | Binary                                      | Description              |
|-----------------------|---------|------|------|------|--------|----------|---------------------------------------------|--------------------------|
| addi sp, sp, -32      | 0010011 | x2   | x2   | —    | 000    | —        | 111111000000 00010 000 00010 0010011        | sp = sp - 32             |
| sd ra, 24(sp)         | 0100011 | —    | x2   | x1   | 011    | 0000000  | 0000000 00001 00010 011 11000 0100011       | store ra at sp+24        |
| sd s0, 16(sp)         | 0100011 | —    | x2   | x8   | 011    | 0000000  | 0000000 01000 00010 011 10000 0100011       | store s0 at sp+16        |
| addi s0, sp, 32       | 0010011 | x8   | x2   | —    | 000    | —        | 000000100000 00010 000 01000 0010011        | s0 = sp + 32             |
| lui a5, %hi(.LC20)    | 0110111 | x15  | —    | —    | —      | —        | 000000000001 11000 111 01111 0110111        | a5 = upper 20 bits addr  |

---

## bubble_sort.s

| Instruction           | Opcode  | rd   | rs1  | rs2  | funct3 | funct7   | Binary                                      | Description              |
|-----------------------|---------|------|------|------|--------|----------|---------------------------------------------|--------------------------|
| addi sp, sp, -64      | 0010011 | x2   | x2   | —    | 000    | —        | 111111100000 00010 000 00010 0010011        | sp = sp - 64             |
| sd ra, 56(sp)         | 0100011 | —    | x2   | x1   | 011    | 0000000  | 0000000 00001 00010 011 11100 0100011       | store ra at sp+56        |
| sd s0, 48(sp)         | 0100011 | —    | x2   | x8   | 011    | 0000000  | 0000000 01000 00010 011 11000 0100011       | store s0 at sp+48        |
| addi s0, sp, 64       | 0010011 | x8   | x2   | —    | 000    | —        | 000001000000 00010 000 01000 0010011        | s0 = sp + 64             |
| lui a5, %hi(.LC21)    | 0110111 | x15  | —    | —    | —      | —        | 000000000001 11000 111 01111 0110111        | a5 = upper 20 bits addr  |



