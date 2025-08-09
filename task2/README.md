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
  <img width="729" height="330" alt="factorial_output" src="https://github.com/user-attachments/assets/b21b42f4-25fb-4421-be50-a2768458b1cf" />
* factorial_main_asm.png
<img width="772" height="707" alt="factorial_main_asm" src="https://github.com/user-attachments/assets/1a9412bd-76fd-4581-afc5-f061f1d4a617" />

---

##  Program 2: max\_array.c

### Objective

Find the maximum in an array and print with proof header

(Repeat same steps as Task 2.3 for compile, run, assembly, and disassembly)

### 📷 Screenshots

* max_array_output.png
  <img width="730" height="281" alt="max_array_output" src="https://github.com/user-attachments/assets/7500408f-df33-4da7-85e8-1cdfb61bc546" />

* max_array_main_asm.png
<img width="544" height="495" alt="max_array_main_asm" src="https://github.com/user-attachments/assets/0276f9b4-f82b-4ece-96d5-80e3ed7c47e6" />

---

##  Program 3: bitops.c

### Objective

Perform basic bitwise operations and show uniqueness

(Repeat same steps as Task 2.3)

### 📷 Screenshots

* bitops_output.png
  <img width="637" height="350" alt="bitops_output" src="https://github.com/user-attachments/assets/14a37615-d934-4858-b1dc-2eaca32c7abc" />

* bitops_main_asm.png
<img width="568" height="814" alt="bitops_main_asm1" src="https://github.com/user-attachments/assets/98f94a49-b75e-4d80-bda6-793522e93302" />
<img width="568" height="722" alt="bitops_main_asm2" src="https://github.com/user-attachments/assets/1cc66cf4-5f49-4389-964f-80f6cd895f92" />

---

## Program 4: bubble\_sort.c

###  Objective

Perform bubble sort and print sorted array with proof header

(Repeat same steps as Task 2.3)

### 📷 Screenshots

* bubble_sort_output.png
  <img width="660" height="293" alt="bubble_sort_output" src="https://github.com/user-attachments/assets/33440754-4e15-4f19-a095-4984873965d5" />

* bubble_sort_main_asm.png
<img width="664" height="587" alt="bubble_sort_main_asm" src="https://github.com/user-attachments/assets/7f92ab01-7af6-4b01-b842-85ceb7357cec" />

---

##  Instruction Decoding

### Objective

Manually decode at least 5 RISC‑V integer instructions from .s or .objdump output

### File: instruction_decoding.md


