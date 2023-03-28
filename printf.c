#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    for (const char *p = format; *p != '\0'; ++p)
    {
        if (*p == '%')
        {
            ++p;
            switch (*p)
            {
                case 'c':
                    {
                        char c = (char)va_arg(args, int);
                        putchar(c);
                        ++count;
                        break;
                    }
                case 's':
                    {
                        char *s = va_arg(args, char*);
                        fputs(s, stdout);
                        count += strlen(s);
                        break;
                    }
                case '%':
                    {
                        putchar('%');
                        ++count;
                        break;
                    }
                default:
                    {
                        // Unknown conversion specifier, ignore
                        break;
                    }
            }
        }
        else
        {
            putchar(*p);
            ++count;
        }
    }

    va_end(args);

    return count;
}

