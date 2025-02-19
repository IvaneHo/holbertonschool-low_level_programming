#include "main.h"

/**
 * print_alphabet_x10 - Prints 10 times the alphabet in lowercase.
 */

void print_alphabet_x10(void)
{
	int i;
	int ascii;

	for (i = 1; i <= 10; i++)
	{
		for (ascii = 97; ascii <= 122; ascii++)
		{
			_putchar(ascii);
		}
		_putchar('\n');
	}
}
