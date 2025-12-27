#include "keyboardio.h"
#include "keyboard_polling.h" //unneccesary but good practice ig?
#define BUFFER_SIZE 100

static char buffer[BUFFER_SIZE];
static int buffer_read = 0;
//buffer_read is where we input, we always post from 0 index

const char scancode_to_ascii[] = {
    0,   0,   '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0,   // 0x00-0x0E
    0,   'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',     // 0x0F-0x1C
    0,   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',          // 0x1D-0x29
    0,   '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,            // 0x2A-0x36
    '*', 0,   ' '  // 0x37-0x39 (space bar is 0x39)
};

void queue_init(){
	for(int i = 0; i < BUFFER_SIZE; i++){
		buffer[i] = 0;
	}
}
void queue_input(){ //for queue input
	unsigned char status = inb(0x64);
	unsigned char input = 0;
	if(status & 0x01){
		unsigned char scancode1 = inb(0x60);
		//bitwise and. if bit 0 is 0, no input. if bit 0 is 1, input.
		if(scancode1 < 0x80) input = scancode_to_ascii[scancode1]; //now get the actual data now.
	}

	 //if the queue fills up, cancel it lmao. not here.
	if(buffer_read != BUFFER_SIZE && input != 0){ //put the shit in buffer,
		buffer[buffer_read] = input;
		buffer_read++;
	}
}

void queue_pop(){
	for(int i = 1; i < BUFFER_SIZE - 1; i++){
		buffer[i-1] = buffer[i];
	}

	buffer[BUFFER_SIZE-1] = 0;

	buffer_read--;
}


unsigned char keyboard_poll(void){

	//check if the initial value is a 0. if not, then there is a code to output.
	if (buffer[0] != 0){
		unsigned char temp=buffer[0];
		queue_pop();
		return temp;
	}

	return 0; //womp womp nothing in the queue anymore.
}
