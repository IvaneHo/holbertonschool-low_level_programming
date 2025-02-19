#include "main.h"
**
 * print_alphabet_x10 - print the alphabet x10
 *
 */
void print_alphabet_x10(void)
{
	int abc, cou;

	/* This count the amount of time. The alphabet is printed*/
	cou = 0;
	while (cou < 10)
	{
		/* This print the alphabet with a newline*/
		for (abc = 'a'; abc <= 'z'; abc++)
			_putchar(abc);
		_putchar('\n');
		cou++;
	}
}
