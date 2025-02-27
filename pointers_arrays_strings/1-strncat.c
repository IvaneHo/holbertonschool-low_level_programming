#include "main.h"

/**
 * _strncat - Concatenates two strings using at most n bytes from src.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The number of bytes to use from src.
 *
 * Return: A pointer to the resulting string `dest`.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	/* Trouver la fin de `dest` */
	while (dest[i] != '\0')
		i++;

	/* Copier `n` caractères de `src` dans `dest` */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Ajouter le null terminator */
	dest[i] = '\0';

	return (dest);
}
