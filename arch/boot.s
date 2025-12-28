.intel_syntax noprefix
.set ALIGN, 1 << 0
.set MEMINFO, 1 << 1
.set FLAGS, ALIGN | MEMINFO
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .align 4
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .bss
    .align 16
stack_bottom:
    .skip 16384
stack_top:

.section .text
    .global _start
    .type _start, @function
_start:
    mov esp, offset stack_top    # Use mov instead of lea in Intel syntax
    call kernel_main
    
    # If kernel_main returns (shouldn't happen), halt
    cli
.hang:
    hlt
    jmp .hang

.size _start, . - _start