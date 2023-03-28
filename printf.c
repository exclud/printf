#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings), or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				count += _putchar(num / 10 + '0');
				count += _putchar(num % 10 + '0');
			}
			else if (*format == 'c')
			{
				count += _putchar(va_arg(args, int));
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					count += _putchar(*str);
					str++;
				}
			}
			else if (*format == '%')
			{
				count += _putchar('%');
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (count);
}


/**
 * _printstr - Prints a string to stdout
 * @str: The string to print
 *
 * Return: Number of characters printed (excluding the null byte used to end output to strings)
 */
int _printstr(char *str)
{
        int i;

        if (str == NULL)
        {
                str = "(null)";
        }

        for (i = 0; str[i] != '\0'; i++)
        {
                putchar(str[i]);
        }

        return (i);
}


