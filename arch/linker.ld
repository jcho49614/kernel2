ENTRY(_start)

SECTIONS
{
    . = 1M;

    .multiboot ALIGN(4):
    {
        KEEP(*(.multiboot))
    }   /* multiboot section — KEEP ensures the section is not discarded */

    .text ALIGN(4096):
    {
        *(.text)
    }   /* executable code (.text) */

    .rodata ALIGN(4096):
    {
        *(.rodata)
    }   /* read-only constants */

    .data ALIGN(4096):
    {
        *(.data)
    }   /* initialized global/static variables */

    .bss ALIGN(4096):
    {
        *(.bss)
        *(.COMMON)
    }   /* uninitialized global/static variables, zeroed at startup */
}
