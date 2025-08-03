# vsdRiscvSoc
🏗️🔧⚙️ RISC-V Toolchain Setup & Uniqueness Test ⚙️🔧🏗️
🎯 Objective

Install the RISC-V toolchain on Ubuntu (or WSL), configure environment variables, and verify that essential binaries (GCC, objdump, GDB, etc.) function correctly for cross-compilation using the Spike simulator and Proxy Kernel.
🛠️ Step 1 — Install Base Developer Tools

Install common prerequisites needed to build the RISC-V toolchain and Spike.

sudo apt-get update
sudo apt-get install -y git vim autoconf automake autotools-dev curl \
  libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex \
  texinfo gperf libtool patchutils bc zlib1g-dev libexpat1-dev gtkwave

🗂️ Step 2 — Create Workspace Directory

Keep everything inside a workspace folder ~/riscv_toolchain for easy navigation and maintenance.

cd
pwd=$PWD
mkdir -p riscv_toolchain
cd riscv_toolchain

📥 Step 3 — Get Prebuilt RISC-V GCC Toolchain

Download and extract the prebuilt toolchain from SiFive:

wget "https://static.dev.sifive.com/dev-tools/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14.tar.gz"
tar -xvzf riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14.tar.gz

🔗 Step 4 — Add Toolchain to PATH

echo 'export PATH=$HOME/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/bin:$PATH' >> ~/.bashrc
source ~/.bashrc

🧬 Step 5 — Install Device Tree Compiler (DTC)

sudo apt-get install -y device-tree-compiler

🖥️ Step 6 — Build and Install Spike (ISA Simulator)

cd $pwd/riscv_toolchain
git clone https://github.com/riscv/riscv-isa-sim.git
cd riscv-isa-sim
mkdir -p build && cd build
../configure --prefix=$pwd/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14
make -j$(nproc)
sudo make install

🧩 Step 7 — Build and Install RISC‑V Proxy Kernel (PK)

cd $pwd/riscv_toolchain
git clone https://github.com/riscv/riscv-pk.git
cd riscv-pk
git checkout v1.0.0  # Ensures compatibility with older toolchains
mkdir -p build && cd build
../configure --prefix=$pwd/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14 --host=riscv64-unknown-elf
make -j$(nproc)
sudo make install

🛤️ Step 8 — Ensure Proxy Kernel is in PATH

echo 'export PATH=$HOME/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/riscv64-unknown-elf/bin:$PATH' >> ~/.bashrc
source ~/.bashrc

🔬 Step 9 — (Optional) Install Icarus Verilog

cd $pwd/riscv_toolchain
git clone https://github.com/steveicarus/iverilog.git
cd iverilog
git checkout --track -b v10-branch origin/v10-branch
git pull
chmod +x autoconf.sh
./autoconf.sh
./configure
make -j$(nproc)
sudo make install

✅ Step 10 — Sanity Checks

which riscv64-unknown-elf-gcc
riscv64-unknown-elf-gcc -v

which spike
spike --version || spike -h

which pk

🧪 Final Deliverable — Unique C Test
📄 unique_test.c

#include <stdint.h>
#include <stdio.h>

#ifndef USERNAME
#define USERNAME "rayrexo"
#endif
#ifndef HOSTNAME
#define HOSTNAME "sarath-VirtualBox"
#endif

static uint64_t fnv1a64(const char *s) {
    const uint64_t FNV_OFFSET = 1469598103934665603ULL;
    const uint64_t FNV_PRIME  = 1099511628211ULL;
    uint64_t h = FNV_OFFSET;
    for (const unsigned char *p = (const unsigned char*)s; *p; ++p) {
        h ^= (uint64_t)(*p);
        h *= FNV_PRIME;
    }
    return h;
}

int main(void) {
    const char *user = USERNAME;
    const char *host = HOSTNAME;

    char buf[256];
    int n = snprintf(buf, sizeof(buf), "%s@%s", user, host);
    if (n <= 0) return 1;

    uint64_t uid = fnv1a64(buf);

    printf("RISC-V Uniqueness Check\n");
    printf("User: %s\n", user);
    printf("Host: %s\n", host);
    printf("UniqueID: 0x%016llx\n", (unsigned long long)uid);

#ifdef __VERSION__
    unsigned long long vlen = (unsigned long long)sizeof(__VERSION__) - 1;
    printf("GCC_VLEN: %llu\n", vlen);
#endif
    return 0;
}

⚙️ Compile Command

riscv64-unknown-elf-gcc -O2 -Wall -march=rv64imac -mabi=lp64 \
  -DUSERNAME="\"$(id -un)\"" -DHOSTNAME="\"$(hostname -s)\"" \
  unique_test.c -o unique_test

▶️ Run on Spike

spike $HOME/riscv_toolchain/riscv-pk/build/pk ./unique_test

🖥️ Sample Output

bbl loader
RISC-V Uniqueness Check
User: rayrexo
Host: sarath-VirtualBox
UniqueID: 0x740616a6b0af98a9
GCC_VLEN: 5
