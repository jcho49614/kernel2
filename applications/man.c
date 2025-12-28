//this is for MAN.
//im going to reuse apphandler code here.
#include <tty.h>

int appnameparser(const char* string1, const char* string2);


//this is all I need: ref "appnameparser" for first word basis.

char* man(const char* input){
	//okay we are getting everything after the word "man", so starting from position 4.

	static char tmparr[100];

	int tmpcnt = 0; while(input[tmpcnt] != '\0') tmpcnt++;


	int tmpcnt2 = 0;
	for(int i = 4; i < tmpcnt; i++){
		tmparr[i-4] = input[i];
		tmpcnt2++;
	}
	tmparr[tmpcnt2] = '\0';

	//okay now using appnameparser.
	if(appnameparser(tmparr, "calc") == 0){
		/*basic format
		terminal_writestring("CALC HELP");
		NEW_LINE;
		terminal_writestring("---------");
		NEW_LINE;
		terminal_writestring("A basic calculator app. Has 4 operators: addition(+), subtraction(-), multiplication(*), and division(/).")
		NEW_LINE;
		terminal_writestring("SYNTAX: calc (NUMBER1) (whitespace) (OPERATOR (+,-,*,/)) (whitespace) (NUMBER2) (enter)");
		NEW_LINE; NEW_LINE; */
		return "CALC HELP\n---------\nA basic calculator app. Has 4 operators: addition(+), subtraction(-), multiplication(*), and division(/).\nSYNTAX: calc (NUMBER1) (whitespace) (OPERATOR (+,-,*,/)) (whitespace) (NUMBER2) (enter)\n\n";
	}



	else return "MAN: NOT A PROPER FUNCTION";
}