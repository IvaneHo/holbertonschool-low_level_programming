#ifndef DOG_H
#define DOG_H

#include <stddef.h>

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

/**
 * dog_t - Typedef for struct dog
 */
typedef struct dog dog_t;

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d); 

#endif /* DOG_H */
