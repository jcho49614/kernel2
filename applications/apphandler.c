#include <tty.h>

//for different apps
#include "calc.h"
#include "helloworld.h"


//really has everything I need.

/*
ALRIGHT HOW APPHANDLER IS GOING TO WORK:
kernel.c is going to give apphandler the full, unredacted
version of the code I type in kernel.c. now, this
can be retained through a function, but i will need
to return it as a character array.

It's going to parse the first word, separated by
the whitespace. this first word will be put into
if cases and be sent to different applications.
I will implement automation later on for like
if I just want to constantly create apps, but
I'm too lazy now and I only have 26 percent battery
left.

ORDER OF OPERATIONS:
1. input string
2. parse first word
3. connect to different apps in apps folder
4. return a char string of output.
*/


//for killing eveyrthing using acpi
void acpi_shutdown(void) {
    terminal_writestring("Shutting down via ACPI...\n");
    
    // This is a simplified version - real ACPI is more complex
    // Sending shutdown signal to ACPI
    outb(0xB004, 0x2000);  // old
    outb(0x604, 0x2000);   // new
    outb(0x4004, 0x3400);  // also?
    
    // Fallback to halt
    terminal_writestring("Shutdown failed, halting...\n");
    while (1) {
        asm volatile("hlt");
    }
}


int appnameparser(const char* string1, const char* string2){
	//comparing string1, string2 to it lol
	int cnt = 0;
	int tracker = 0;
	while(string1[tracker] != '\0' && string2[tracker] != '\0'){
		//compare the two.
		if(string1[tracker] == string2[tracker]) tracker++;
		else{
			cnt++; break;
		}
	}

	return cnt;
}

char* app_handler(const char* string) {
    int i = 0;

    while (string[i] != ' ' && string[i] != '\0')
        i++;

    char command[i + 1];
    for (int j = 0; j < i; j++)
        command[j] = string[j];
    command[i] = '\0';

    terminal_writestring("\n");

    if (appnameparser(command, "calc") == 0)
        return calc(string);
    else if(appnameparser(command, "helloworld") == 0)
    	return helloworld();
    else if(appnameparser(command, "exit") == 0)
    	acpi_shutdown(); 

    return "Unknown command";
}
