# set magic number to 0x1BADB002 to identified by bootloader 
.set MAGIC,    0x1BADB002

.set FLAGS,    0

# set the checksum
.set CHECKSUM, -(MAGIC + FLAGS)

# set multiboot enabled
.section .multiboot

# define type to long
.long MAGIC
.long FLAGS
.long CHECKSUM


# set the stack bottom 
stackBottom:

# define the MAX stack size 
.skip 1024


stackTop:

.section .text
.global _start
.type _start, @function


_start:

  # assign current stack pointer location to stackTop
	mov $stackTop, %esp

  # call the kernel main source
	call kernel_main

	cli


# system infinite loop
hltLoop:

	hlt
	jmp hltLoop

.size _start, . - _start




