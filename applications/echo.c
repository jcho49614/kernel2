#include <tty.h>
//all I need rn use terminal_writestring

//for echo, I need to get EVERYTHING after the phrase "echo " and replay it to terminal_writestring

char* echo(const char* input){
	//get the input, starting from position 5 put it into an array ~ 10^4 letters
	//input is the array, strating from pos 5 regurgitate until sizeof(input).
	//later, maybe add some sort of filesystem support. Need an option to install the operating system first, which will require a separate boot media etc etc
	//find input length tho

	int input_length = 0;

	while(input[input_length] != '\0') input_length++;

	static char tmparr[10000];
	if(input_length > 10000) return "ECHO: requested phrase is too long.";
	
	int nullterminate = 0;
	for(int i = 5; i < input_length; i++){
		tmparr[i-5] = input[i];
		nullterminate++;
	}

	tmparr[nullterminate] = '\0';

	return tmparr;
}