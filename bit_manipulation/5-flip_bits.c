#include "main.h"

/**
 * flip_bits - counts number of bits to flip to go from n to m
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int count = 0;

	while (xor)
	{
		if (xor & 1)
			count++;
		xor = xor >> 1;
	}

	return (count);
}
