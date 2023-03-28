#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - Prints output according to a format.
 * @format: A character string that specifies the output format.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
	{
	va_list args;
	int count = 0;
	char *str;

	va_start(args, format);

	while (*format)
		{
			if (*format == '%')
		{
		format++;
		switch (*format)
		{
				case 'c':
			count += _putchar(va_arg(args, int));
			break;

		case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
			count += _printstr(str);
					break;

		case 'd':
		case 'i';
			count += _print_integer(va_arg(args, int));
			break;
			str = itoa(va_arg(args, int));
			count += puts(str);
			free(str);
			break;
	case 'b':
	count += print_binary(va_arg(args, unsigned int));
	break;

	case '%':
	count += _putchar('%');
	break;

	default:
	count += _putchar('%');
	count += _putchar(*format);
	break;
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

/**
 * itoa - Converts an integer to a string.
 * @n: The integer to convert.
 *
 * Return: A pointer to the resulting string.
 */
char *itoa(int n)
	{
	int len = 0, tmp = n;
	char *str;

	if (n == 0)
	return ("0");

	while (tmp)
	{
	tmp /= 10;
	len++;
	}

	str = malloc(len + 1);

	if (!str)
	return (NULL);

	str[len--] = '\0';

	while (n)
	{
	str[len--] = (n % 10) + '0';
	n /= 10;
	}

	return (str);
	}

/**
 * _print_integer - print an integer
 * @n: integer to print
 * Return: number of characters printed
 */
int _print_integer(int n)
	{
	int div = 1, length = 0;

	if (n < 0)
	{
	length += _putchar('-');
	n *= -1;
	}

	while (n / div >= 10)
	{
	div *= 10;
	}
	while (div != 0)
	{
	length += _putchar((n / div) % 10 + '0');
	div /= 10;
	}
	return (length);
	}

/**
 * print_binary - prints a binary number
 * @n: the number to print
 * Return: the number of digits printed
 */
int print_binary(unsigned int n)
	{
	int count = 0;

	if (n > 1)
	count += print_binary(n >> 1);

	count += _putchar((n & 1) + '0');

	return (count);
	}

