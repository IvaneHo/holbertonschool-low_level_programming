#include "main.h"

/**
 * _strncpy - Copies a string up to n characters.
 * @dest: The destination buffer.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the resulting string `dest`.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copier jusqu'à `n` caractères ou jusqu'à la fin de `src` */
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	/* Compléter avec des `\0` si `src` est plus court que `n` */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
