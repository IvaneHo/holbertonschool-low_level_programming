#include "main.h"
#include <stdio.h>

/**
 * print_last_digit - Prints the last digit of a number.
 *
 * @n: Recives the number to work in.
 *
 * Return: Returns the last digit of a number.
 */

int print_last_digit(int n)
{
	int lastDigit =  (n % 10);
	int abs = ((lastDigit < 0) ? -lastDigit : lastDigit);

	_putchar('0' + abs);
	return (abs);
}
