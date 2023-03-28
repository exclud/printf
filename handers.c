#include "main.h"
/**
 * print_char - prints a character
 * @args: va_list that contains a character to print
 * Return: 1
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list that contains a string to print
 * Return: the length of the string
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int length = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		length++;
		str++;
	}

	return (length);
}

/**
 * print_number - prints a number
 * @args: va_list that contains a number to print
 * Return: the number of digits printed
 */
int print_number(va_list args)
{
	int n = va_arg(args, int);
	int digits = 0;

	if (n == 0)
	{
		_putchar('0');
		digits++;
	}
	else if (n < 0)
	{
		_putchar('-');
		digits++;
		n = -n;
	}

	digits += count_digits(n);
	print_number_recursion(n);

	return (digits);
}

