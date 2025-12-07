#!/bin/bash
set -e
set -u

ARCH=i686
CC=i686-elf-gcc
AS=i686-elf-as
LD=i686-elf-ld
OBJCOPY=i686-elf-objcopy

SRC_KERNEL=../kernel
SRC_ARCH=../arch
BUILD_DIR=../build-files
ISO_DIR=../iso
ISO_IMG=../kernel.iso

CFLAGS="-ffreestanding -O2 -Wall -Wextra -m32"
LDFLAGS="-T ${SRC_ARCH}/linker.ld -nostdlib"

KERNEL_ELF=${BUILD_DIR}/kernel.elf
KERNEL_BIN=${BUILD_DIR}/kernel.bin

export PATH=$HOME/opt/cross/bin:$PATH

mkdir -p ${BUILD_DIR} ${ISO_DIR}/boot/grub
rm -f ${BUILD_DIR}/*.o ${KERNEL_ELF} ${KERNEL_BIN} ${ISO_IMG}

echo "[1] Assembling boot.s..."
${AS} ${SRC_ARCH}/boot.s -o ${BUILD_DIR}/boot.o

echo "[2] Compiling C sources..."
for file in ${SRC_KERNEL}/*.c; do
    ${CC} ${CFLAGS} -c $file -o ${BUILD_DIR}/$(basename $file .c).o
done

echo "[3] Linking..."
${LD} ${LDFLAGS} -o ${KERNEL_ELF} ${BUILD_DIR}/*.o

echo "[4] Converting ELF to binary..."
${OBJCOPY} -O binary ${KERNEL_ELF} ${KERNEL_BIN}

echo "[5] Preparing ISO..."
cp ${KERNEL_ELF} ${ISO_DIR}/boot/kernel.elf

cat > ${ISO_DIR}/boot/grub/grub.cfg << EOF
set timeout=5
set default=0

menuentry "My OS Kernel" {
    multiboot /boot/kernel.elf
    boot
}
EOF

echo "[6] Creating bootable ISO..."
grub-mkrescue -o ${ISO_IMG} ${ISO_DIR}

echo "Build complete!"
echo "ELF: ${KERNEL_ELF}"
echo "BIN: ${KERNEL_BIN}"
echo "ISO: ${ISO_IMG}"