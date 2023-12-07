#!/bin/sh

nasm -f elf32 kernel.asm -o ../target/kasm.o
gcc -m32 -c kernel.c -o ../target/kc.o
ld -m elf_i386 -T link.ld -o ../target/kernel.bin ../target/kasm.o ../target/kc.o
qemu-system-i386 -kernel ../target/kernel.bin
cp ../target/kernel.bin ../0s/boot/
# grub-mkrescue -o ../target/0s.iso ../0s
