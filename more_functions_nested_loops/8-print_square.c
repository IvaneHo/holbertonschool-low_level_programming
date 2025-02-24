#include "main.h"
/**
 * print_square - check the code
 * @size: est un int
 * Return: Always 0.
 */

void print_square(int size)
{
	int hight, wid;

	if (size > 0)
	{
		for (hight = 0; hight < size; hight++)
		{
			for (wid = 0; wid < size; wid++)
				_putchar('#');

			if (hight == size - 1)
				continue;
			_putchar('\n');
		}
	}
	_putchar('\n');
}
