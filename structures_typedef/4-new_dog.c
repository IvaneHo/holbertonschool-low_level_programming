#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - Duplicates a string using malloc.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string or NULL if malloc fails.
 */
char *_strdup(char *str)
{
	char *copy;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = str[i];

	return (copy);
}

/**
 * new_dog - Creates a new dog_t and stores copies of name and owner.
 * @name: Pointer to the dog's name.
 * @age: The dog's age.
 * @owner: Pointer to the owner's name.
 *
 * Return: Pointer to the new dog_t, or NULL if allocation fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *name_copy, *owner_copy;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	name_copy = _strdup(name);
	if (name_copy == NULL)
	{
		free(dog);
		return (NULL);
	}

	owner_copy = _strdup(owner);
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(dog);
		return (NULL);
	}

	dog->name = name_copy;
	dog->age = age;
	dog->owner = owner_copy;

	return (dog);
}
