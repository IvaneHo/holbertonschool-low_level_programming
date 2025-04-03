#include "main.h"

/**
 * get_bit - gets value of a bit at a given index
 * @n: the number
 * @index: index of the bit
 *
 * Return: the bit at index or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);
	if ((n & (1 << index)) != 0)
	{
		return (1);
	}
	return (0);
}
