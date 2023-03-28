#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/*putchar function prototype*/
int _putchar(char c);
/* function prototype*/

int _printf(const char *format, ...);
int _printstr(char *str);
char *itoa(int n);
int _print_integer(int n);
int print_binary(unsigned int n);

#endif /* MAIN_H */

