#include "main.h"

/**
 * puts_half - Prints the second half of a string.
 * @str: The input string.
 */
void puts_half(char *str)
{
int i, len = 0, start;

/* Calculer la longueur de la chaîne */
while (str[len] != '\0')
len++;

/* Déterminer le point de départ de l'affichage */
start = (len % 2 == 0) ? (len / 2) : ((len - 1) / 2 + 1);

/* Afficher la seconde moitié de la chaîne */
for (i = start; i < len; i++)
_putchar(str[i]);

_putchar('\n');
}
