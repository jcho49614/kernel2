#ifndef keyboard_polling_h
#define keyboard_polling_h

void queue_input(void);
void queue_pop(void);
unsigned char keyboard_poll(void);


#endif