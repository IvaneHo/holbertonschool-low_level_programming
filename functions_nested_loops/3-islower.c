#include "main.h"

/**
 * _islower - Checks for lowercase character.
 *
 * @c: Recives the letter to compare.
 *
 * Return: Returns 1 if the letter if a lowercase, 0 if not.
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
