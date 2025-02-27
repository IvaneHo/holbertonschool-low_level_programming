#include "main.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if `s1` and `s2` are equal,
 *         a negative value if `s1` is less than `s2`,
 *         a positive value if `s1` is greater than `s2`.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	/* Comparer les caractères un par un */
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;

	/* Retourner la différence entre les premiers caractères différents */
	return (s1[i] - s2[i]);
}
