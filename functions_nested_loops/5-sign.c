#include "main.h"

/**
 * print_sign - Prints the sign of a number.
 *
 * @n: Recives a number to compare.
 *
 * Return: Returns 1 if n is greater than 0, 0 if is 0, -1 if is less than 0.
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else
	{
		if (n < 0)
		{
			_putchar('-');
			return (-1);
		}
		else
		{
			_putchar('0');
			return (0);
		}
	}
}
