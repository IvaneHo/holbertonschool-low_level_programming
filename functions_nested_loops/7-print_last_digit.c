#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number.
 *
 * @n: Recives the number to work in.
 *
 * Return: Returns the last digit of a number.
 */

int print_last_digit(int n)
{	
	int lastDigit =  (((n < 0) ? n *= -1 : n) % 10);

	_putchar('0' + lastDigit);
	return (lastDigit);
}
