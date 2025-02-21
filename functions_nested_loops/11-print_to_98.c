#include "main.h"

/**
 * print_int - Prints a number.
 *
 * @num: Numbert to print.
 */

void print_int(int num)
{
	char digits[12];
	int i = 0, abs;

	if (num < 0)
	{
		_putchar('-');
		abs = -num;
	}
	else
	{
		abs = num;
	}

	do {
		digits[i++] = ('0' + (abs % 10));
		abs /= 10;
	} while (abs > 0);

	while (i > 0)
	{
		_putchar(digits[--i]);
	}
}

/**
 * print_to_98 - Prints all natural numbers from n (Passed to function) to 98.
 *
 * @n: Number to start to print.
 */

void print_to_98(int n)
{
	while (n != 98)
	{
		print_int(n);
		_putchar(',');
		_putchar(' ');
		n += ((n < 98) ? 1 : -1);
	}

		_putchar('0' + n / 10);
		_putchar('0' + n % 10);
		_putchar('\n');
}
