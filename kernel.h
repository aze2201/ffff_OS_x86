#ifndef KERNEL_H
#define KERNEL_H
#define vga_addr 0xB8000
#define BUF_SIZE 2280 // 2024+256
#define NULL 0

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

uint16* buff_vga;

enum vga_color {
    b,
    w
};

#endif
