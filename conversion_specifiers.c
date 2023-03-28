#include "main.h"
#include <stdarg.h>

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of digits printed
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_number(num / 10);
	}

	count += _putchar(num % 10 + '0');

	return (count);
}

/**
 * print_integer - prints an integer
 * @args: va_list containing the integer to print
 *
 * Return: number of digits printed
 */
int print_integer(va_list args)
{
	return (print_number(va_arg(args, int)));
}

/**
 * print_decimal - prints a decimal
 * @args: va_list containing the decimal to print
 *
 * Return: number of digits printed
 */
int print_decimal(va_list args)
{
	return (print_number(va_arg(args, int)));
}

