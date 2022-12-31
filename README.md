# ffff_OS_x86
Custom OS for x86 PC arch. Only Prints  "Hello"

## How to compuile and use


assemble boot part of kernel

```$ as --32 boot.s -o boot.o```

Compile kernel.c file

```$ gcc -m32 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra```

Linkinng compiled file

```$ ld -m elf_i386 kernel.o boot.o -o FFFF.bin -nostdlib -T linker.ld```

Make a ISO file including .bin file

```
$ mkdir -p isodir/boot/grub
$ cp FFFF.bin isodir/boot/FFFF.bin
$ cp grub.cfg isodir/boot/grub/grub.cfg
$ grub-mkrescue -o FFFF.iso isodir
```

How to RUN. 
1. You can download ISO file and use Oracle VM
2. Use QEMU. `qemu-system-x86_64 -cdrom FFFF.iso`
