#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to modify.
 *
 * Return: A pointer to the modified string.
 */
char *cap_string(char *str)
{
	int i = 0;
	int capitalize = 1; /* 1 = Prochain caractère doit être en majuscule */

	/* Liste des séparateurs */
	char separators[] = " \t\n,;.!?\"(){}";
	int j;

	while (str[i] != '\0')
	{
		/* Vérifier si on doit mettre en majuscule */
		if (capitalize && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= ('a' - 'A');

		/* Vérifier si le caractère actuel est un séparateur */
		capitalize = 0;
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (str[i] == separators[j])
			{
				capitalize = 1; /* Le prochain caractère doit être en majuscule */
				break;
			}
		}

		i++;
	}

	return (str);
}
