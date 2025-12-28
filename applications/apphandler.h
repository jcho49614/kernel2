#ifndef apphandler_h
#define apphandler_h

#include <tty.h>
#include "calc.h"
#include "helloworld.h"
#include "echo.h"
#include "man.h"

int appnameparser(const char* string1, const char* string2);
char* app_handler(const char* string);

#endif