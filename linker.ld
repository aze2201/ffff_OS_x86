/* entry point of our kernel */
ENTRY(_start)

SECTIONS
{
	/* 1MB of space */
	. = 1M;

  	/* text section */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	/* read only data */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	/* data */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* bss */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}

}
