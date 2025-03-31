#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: Double pointer to the head of the list.
 * @n: Value to insert in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *temp;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL) /* Liste vide, on ajoute en tête */
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	/* Parcours jusqu'au dernier élément */
	temp = *head;
	while (temp->next)
		temp = temp->next;

	/* Ajout du nouveau nœud à la fin */
	temp->next = new;
	new->prev = temp;

	return (new);
}
