#include "main.h"
#include <stdio.h>

/**
* _isupper - Checks for uppercase character
*
* Description: Checks for uppercase character.
*
* @c: if uppercase
*
* Return: 0 or 1
*
*/

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
