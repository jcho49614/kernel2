ENTRY(_start)
SECTIONS
{
    . = 1M;
    
    .multiboot : { KEEP(*(.multiboot)) }
    .text      : { *(.text) }
    .rodata    : { *(.rodata) }
    .data      : { *(.data) }
    .bss       : { *(.bss) *(COMMON) }
}

/*apparantly i dont need aligning lmao*/