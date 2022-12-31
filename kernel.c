#include "kernel.h"


uint16 vga_input(unsigned char ch, uint8 input_case_color, uint8 background_color) 
{
  uint16 ax = 0;
  uint8 ah = 0, al = 0;

  ah = background_color;
  ah <<= 4;
  ah |= input_case_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

void clear_buff(uint16 **buffer, uint8 input_case_color, uint8 background_color)
{
  uint32 i;
  for(i = 0; i < BUF_SIZE; i++){
    (*buffer)[i] = vga_input(NULL, input_case_color, background_color);
  }
}

//init buffer for vga
void init_vga(uint8 input_case_color, uint8 background_color)
{
  buff_vga = (uint16*)vga_addr;  //point buff_vga pointer to vga_addr 
  clear_buff(&buff_vga, input_case_color, background_color);  //clear buffer
}

void kernel_main()
{
  // initialte vga color
   init_vga(b, b);
  // start print
  buff_vga[0] = vga_input('H', w, b);
  buff_vga[1] = vga_input('e', w, b);
  buff_vga[2] = vga_input('l', w, b);
  buff_vga[3] = vga_input('l', w, b);
  buff_vga[4] = vga_input('o', w, b);
}
