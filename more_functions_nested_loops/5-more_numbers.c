#include "main.h"
/**
 * more_numbers - check the code
 *
 * Return: Always 0.
 */

void more_numbers(void)
{
	int i;
	int compteur;

	for (compteur = 0; compteur < 10; compteur++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i > 9)
				_putchar((i / 10) + '0');
			_putchar((i % 10) + '0');
		}

		_putchar('\n');
	}
}
