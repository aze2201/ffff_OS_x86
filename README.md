# ffff_OS_x86
Custom OS for x86 PC arch. Only Prints  "Hello"


There is a standard for loading various x86 kernels using a boot loader; called as Multiboot specification.
GRUB will only load our kernel if it complies with the Multiboot spec.


## How to compuile and use


assemble boot part of kernel

```$ as --32 boot.s -o boot.o```

Compile kernel.c file

```$ gcc -m32 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra```

Linkinng compiled file

```$ ld -m elf_i386  boot.o kernel.o -nostdlib -T linker.ld -o FFFF.bin ```

Make a ISO file including .bin file

```
$ mkdir -p iso/boot/grub
$ cp FFFF.bin iso/boot/FFFF.bin
$ cp grub.cfg iso/boot/grub/grub.cfg
$ grub-mkrescue -o FFFF.iso iso
```

How to RUN. 
1. You can download ISO file and use Oracle VM
2. Use QEMU. `qemu-system-x86_64 -cdrom FFFF.iso`


Here is screeshots.

![OS list from GRUB](https://github.com/aze2201/ffff_OS_x86/blob/main/assets/screenshots/grub.png)

![loaded OS screen](https://github.com/aze2201/ffff_OS_x86/blob/main/assets/screenshots/screen.png)

