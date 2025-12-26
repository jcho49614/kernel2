#ifndef keyboardio_h
#define keyboardio_h

static inline unsigned char inb(unsigned short port){
	unsigned char result;
	__asm__ volatile("inb %1, %0" : "=a"(result) :"Nd"(port)); //CODE, OUTPUT, INPUT.
	return result;
}

static inline unsigned char outb(unsigned short port, unsigned short data){
	__asm__ volatile("outb %0, %1": :"a"(data), "Nd"(port)); //NO OUTPUT, ONLY INPUT, PUTTING VALUE OF =a INTO THE PORT
}

#endif