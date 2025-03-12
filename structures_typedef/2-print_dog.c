#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the elements of a struct dog
 * @d: Pointer to the struct dog to print
 *
 * Description: If an element is NULL, prints (nil) instead.
 * If d is NULL, prints nothing.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	/* Print name, replace NULL with (nil) */
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	/* Print age */
	printf("Age: %f\n", d->age);

	/* Print owner, replace NULL with (nil) */
	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
