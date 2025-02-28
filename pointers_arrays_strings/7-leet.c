#include "main.h"

/**
 * leet - Encodes a string into 1337 (leet).
 * @str: The string to encode.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *str)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	/* Parcourir la chaîne */
	for (i = 0; str[i] != '\0'; i++)
	{
		/* Comparer avec les lettres à remplacer */
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = numbers[j]; /* Remplacement par le chiffre correspondant */
				break;
			}
		}
	}

	return (str);
}
