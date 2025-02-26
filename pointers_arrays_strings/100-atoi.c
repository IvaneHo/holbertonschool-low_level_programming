#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    int found_number = 0;

    /* Parcourir la chaîne */
    while (s[i] != '\0')
    {
        /* Gérer les signes '+' et '-' */
        if (s[i] == '-')
            sign *= -1;
        else if (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + (s[i] - '0');
            found_number = 1;
        }
        else if (found_number) /* Arrêter dès qu'on a trouvé un nombre */
            break;

i++;
}

return (result * sign);
}

