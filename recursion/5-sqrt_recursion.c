#include "main.h"

/**
 * find_sqrt - Recursively checks for the natural square root of a number.
 * @n: The number to find the square root of.
 * @guess: The current number to check as a potential square root.
 *
 * Return: The natural square root of n, or -1 if n has no natural square root.
 */
int find_sqrt(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);

	return (find_sqrt(n, guess + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root of n, or -1 if n has no natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (find_sqrt(n, 0));
}
