#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct dlistint_s - Doubly linked list node structure
 * @n: Integer stored in the node
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 *
 * Description: A node structure for a doubly linked list.
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;

/* Function prototypes */
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);

#endif /* LISTS_H */
