#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "vga.h"
#include "tty.h"
#include "keyboardio.h"
#include "keyboard_polling.h"

#define NEW_LINE terminal_writestring("\n");

void kernel_main(void){
	terminal_initialize();
	terminal_writestring("kernel2 test");
	NEW_LINE;
	terminal_writestring("---------------------------------------------------------------");
	NEW_LINE;
	terminal_writestring("KERNEL> ");


	queue_init();

	while(1){
		queue_input();

		unsigned char scancode = keyboard_poll();
		if(scancode != 0){
			if(scancode == '\n') terminal_writestring("\nKERNEL> ");
			else{
				char tmp[2];
				tmp[0] = scancode; tmp[1] = '\0';
				terminal_writestring(tmp);
			}
		}
	}
}