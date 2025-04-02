#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index in a dlistint_t
 * @head: Pointer to a pointer to the head of the list
 * @index: The index of the node to delete, starting from 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (!head || !*head) /* Vérifie si la liste est vide */
		return (-1);

	current = *head;

	/* Suppression du premier nœud */
	if (index == 0)
	{
		*head = current->next;
		if (*head)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Parcours jusqu'au nœud à supprimer */
	for (i = 0; current && i < index; i++)
		current = current->next;

	if (!current) /* Si l'index dépasse la taille de la liste */
		return (-1);

	/* Mise à jour des pointeurs pour enlever le nœud */
	if (current->prev)
		current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
