#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints output according to a format.
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            count += putchar(*format);
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


