#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given index
 * in a doubly linked list.
 * @h: Pointer to the head of the list.
 * @idx: Index where the new node should be added (starting from 0).
 * @n: Data for the new node.
 *
 * Return: Address of the new node, or NULL if it fails or index is invalid.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int i = 0;

	if (h == NULL || *h == NULL) /* Vérification de la liste */
		return (NULL);
	if (idx == 0) /* Insertion au début */
		return (add_dnodeint(h, n));

	temp = *h;
	while (temp && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL) /* Index hors de portée */
		return (NULL);
	if (temp->next == NULL) /* Insertion en fin de liste */
		return (add_dnodeint_end(h, n));

	/* Création du nouveau nœud */
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
