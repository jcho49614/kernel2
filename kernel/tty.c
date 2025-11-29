//c is infinitely better than c++ i hate c++

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
//for string just use char*. I'm not definig a new string.h hell no

#include "vga.h"
#include "tty.h"

static const size_t VGA_WIDTH=80;
static const size_t VGA_HEIGHT=25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

#define background  VGA_COLOR_BLUE
#define foreground  VGA_COLOR_LIGHT_GREY

size_t strlen(const char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}


void terminal_initialize(void){ //for init the terminal
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(background, foreground);
	terminal_buffer = VGA_MEMORY;
	for(size_t y = 0; y < VGA_HEIGHT; y++){
		for(size_t x = 0; x < VGA_WIDTH; x++){
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color){	//for setting terminal
	terminal_color = color;
}

void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y){
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color); //index of 0xB8000 + index, color, c;
} //russian name

void terminal_scroll(void) {
    // Shift all rows up
    for (int row = 0; row < VGA_HEIGHT - 1; row++) {
        for (int col = 0; col < VGA_WIDTH; col++) {
            terminal_buffer[row * VGA_WIDTH + col] = terminal_buffer[(row + 1) * VGA_WIDTH + col];
        }
    }

    // Clear the last row
    for (int col = 0; col < VGA_WIDTH; col++) {
        putentryat(' ', terminal_colorm col, VGA_HEIGHT - 1);
    }
}

/* 

i hate this so much what the hell
what the hell is this terminal scroll why is it so fucking complicated
bro terminal scroll is going to be the bane of my existance something
so fucking simple is so fucking hard ughhhhh
what the hell man this aint it

*/

void terminal_putchar(char c){ //used for handling entry + scrolling,
	int line; unsigned char uc = c;

	if(c == "\n"){
		terminal_column = 0;
		if(++terminal_row == VGA_HEIGHT) {
			terminal_scroll();
			terminal_row = VGA_HEIGHT-1;
		}
		return;
	}

	terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
	if(++terminal_column == VGA_WIDTH){
		terminal_column = 0;
		if(++terminal_row == VGA_HEIGHT){
			terminal_scroll();
			terminal_row = VGA_HEIGHT-1;
		}
	}
}

void terminal_write(const char* data, size_t size){
	for(size_t i = 0; i < size; i++){
		terminal_putchar(data[i]);
	}
}

void terminal_writestring(const char* data){
	terminal_write(data, strlen(data));
}