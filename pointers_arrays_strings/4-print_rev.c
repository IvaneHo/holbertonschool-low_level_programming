#include "main.h"

/**
 * print_rev - Prints a string in reverse, followed by a new line.
 * @s: The string to be printed in reverse.
 */
void print_rev(char *s)
{
    int len = 0;

    while (s[len] != '\0') /* Trouver la longueur de la chaîne */
        len++;

    while (len > 0) /* Imprimer la chaîne en sens inverse */
    {
        _putchar(s[len - 1]);
        len--;
    }
    _putchar('\n');
}
