#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "vga.h"
#include "tty.h"
#include "keyboardio.h"
#include "keyboard_polling.h"

#define NEW_LINE terminal_writestring("\n");

char* app_handler(const char* string);

void kernel_main(void){
	terminal_initialize();
	terminal_writestring("kernel2 test");
	NEW_LINE;
	terminal_writestring("---------------------------------------------------------------");
	NEW_LINE;
	terminal_writestring("KERNEL> ");


	queue_init();

	char command[10000];
	int characternum = 0;

	while(1){
		queue_input();

		unsigned char scancode = keyboard_poll();
		if(scancode != 0){
			if(scancode == '\n'){

				terminal_writestring(app_handler(command));
				//afterwards
				terminal_writestring("\nKERNEL> ");
				for(int i = 0; i < sizeof(command); i++) command[i] = 0;
				characternum = 0;
			}

			else{
				char tmp[2];
				tmp[0] = scancode; tmp[1] = '\0';
				terminal_writestring(tmp);
				command[characternum] = scancode;
				characternum++;
			}
		}
	}
}