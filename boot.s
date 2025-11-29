.intel_syntax noprefix

.set ALIGN, 1 << 0
.set MEMINFO, 1 << 1
.set FLAGS, ALIGN | MEMINFO 	#this is going to be 0x3.
.set MAGIC, 0x1BADB002			#magic bootloader number
.set CHECKSUM, -(MAGIC + FLAGS)		#checksum for bootloader
	
.section .multiboot			#multib
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

		mov esp, offset stack_top
		call kernel_main

cli

1:

	hlt
	jmp 1b

	.size _start, . - _start