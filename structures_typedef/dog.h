#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure defining a dog
 * @name: Pointer to the dog's name
 * @age: Dog's age
 * @owner: Pointer to the owner's name
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */