#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/*putchar function prototype*/
int _putchar(char c);

/*Conversion Specifier Functions*/
int print_integer(va_list args);
int print_decimal(va_list args);
/*Handlers*/
int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);

/*Helper Functions*/
int _strlen(const char *s);
void _printnum(int n);
int _printf(const char *format, ...);
int _printstr(char *str);

#endif /* MAIN_H */

