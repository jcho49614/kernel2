#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "vga.h"
#include "tty.h"
#include "keyboardio.h"
#include "keyboard_polling.h"

void kernel_main(void){
	terminal_initialize();
	terminal_writestring("hello, world!");
	terminal_writestring("\nohmygoshitfinallyworks");

	while(1){
		unsigned char scancode = keyboard_poll();
		if(scancode != 0){
			//ohmygoshkeyboardpresslessgooo
			terminal_writestring("\nhelloqorld");
		}
	}
}