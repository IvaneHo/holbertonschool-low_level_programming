#include "main.h"

/**
 * _isalpha - Checks for alphabetic character.
 *
 * @c: Recives a ascii char to compare.
 *
 * Return: Returns 1 if the character is a letter, and 0 if not.
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
