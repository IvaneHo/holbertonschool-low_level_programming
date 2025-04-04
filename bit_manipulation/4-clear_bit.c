#include "main.h"

/**
 * clear_bit - clears the value of a bit to 0 at given index
 * @n: pointer to the number
 * @index: index of bit to clear
 *
 * Return: 1 if success, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = *n & ~(1 << index);
	return (1);
}
