#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Pointer to the head of the list.
 * @str: The string to be added to the new node (needs to be duplicated).
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);  /* Return NULL if memory allocation fails */
	}

	/* Duplicate the string and assign it to the new node */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);  /* Free the node if string duplication fails */
		return (NULL);
	}

	/* Set the length of the string */
	new_node->len = strlen(str);

	/* Make the new node point to the current head of the list */
	new_node->next = *head;

	/* Update the head of the list to the new node */
	*head = new_node;

	return (new_node);
}
