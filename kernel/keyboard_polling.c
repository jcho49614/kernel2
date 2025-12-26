#include "keyboardio.h"
#include "keyboard_polling.h" //unneccesary but good practice ig?

unsigned char keyboard_poll(void){
	unsigned char status = inb(0x64);
	
	if(status & 0x01){
		//bitwise and. if bit 0 is 0, no keyboard input. if bit 0 is 1, keyboard input, start getting the data.
		return inb(0x60); //now get the actual data now.
	}

	return 0; //womp womp nothing clicked on :(
}