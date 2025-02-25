#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _strlen - Counts the amount of char
 * @str: String
 * Return: Length of string
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}


/**
 * print_rev - Prints a string, in reverse
 * @str: String
 */
void print_rev(char *str)
{
	int i;
	int s_size = _strlen(str);

	for (i = s_size - 1; i >= 0; i--)
		_putchar(str[i]);
	_putchar('\n');
}
