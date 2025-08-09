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

* factorial_output.png
* factorial_main_asm.png

---

##  Program 2: max\_array.c

### Objective

Find the maximum in an array and print with proof header

(Repeat same steps as Task 2.3 for compile, run, assembly, and disassembly)

### 📷 Screenshots

* max_array_output.png
* max_array_main_asm.png

---

##  Program 3: bitops.c

### Objective

Perform basic bitwise operations and show uniqueness

(Repeat same steps as Task 2.3)

### 📷 Screenshots

* bitops_output.png
* bitops_main_asm.png

---

## Program 4: bubble\_sort.c

###  Objective

Perform bubble sort and print sorted array with proof header

(Repeat same steps as Task 2.3)

### 📷 Screenshots

* bubble_sort_output.png
* bubble_sort_main_asm.png

---

##  Instruction Decoding

### Objective

Manually decode at least 5 RISC‑V integer instructions from .s or .objdump output

### File: instruction_decoding.md


