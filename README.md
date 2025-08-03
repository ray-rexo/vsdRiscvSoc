# vsdRiscvSoc
# Your RISC‑V Project Title 🚀

**Author:** rayrexo  
**Date:** August 2025

---

## 1. Overview 🧠

Describe in a few lines what you accomplished:
- Installed RISC‑V GCC toolchain (v8.3.0)
- Built `riscv‑pk` with commit/tag `v1.0.0`
- Verified with simple C and assembly examples (hello, loop, array sum, unique_test)

---

## 2. Prerequisites ✅

- Ubuntu Linux installed (not live USB)
- Dependencies: `make`, `gcc`, `git`, etc.
- RISC‑V toolchain installed under `~/riscv_toolchain/…`

---

## 3. Environment Setup 🛠️

```bash
# Check compiler
which riscv64-unknown-elf-gcc

# Build Proxy Kernel
cd riscv-pk
git checkout v1.0.0
mkdir build && cd build
../configure --prefix=$HOME/.../riscv64-unknown-elf-gcc-8.3.0... --host=riscv64-unknown-elf
make
sudo make install
