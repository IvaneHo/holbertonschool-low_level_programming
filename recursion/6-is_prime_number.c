#include "main.h"

/**
 * check_prime - Recursively checks if a number is prime.
 * @n: The number to check.
 * @div: The current divisor.
 *
 * Return: 1 if n is a prime number, 0 otherwise.
 */
int check_prime(int n, int div)
{
	if (n <= 1)
		return (0);
	if (div * div > n)
		return (1);
	if (n % div == 0)
		return (0);

	return (check_prime(n, div + 1));
}

/**
 * is_prime_number - Determines if a number is a prime number.
 * @n: The number to check.
 *
 * Return: 1 if n is a prime number, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (check_prime(n, 2));
}
