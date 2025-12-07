#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "vga.h"
#include "tty.h"

void kernel_main(void){
	terminal_writestring("hello, world!");
}