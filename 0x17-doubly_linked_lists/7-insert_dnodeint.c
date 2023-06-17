#include "lists.h"

/**
 * insert_dnodeint_at_index -  inserts a
 * new node at a given position.
 *
 * @h: head
 * @idx: index
 * @n: new value
 *
 * Return: new head
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h, *prev, *new;

	prev = NULL;

	for (; temp != NULL; --idx, temp = temp->next)
	{
		if (idx == 0)
			break;
		prev = temp;
	}

	if (temp == NULL && idx != 0)
		return (NULL);

	if (prev == NULL)
		return (add_dnodeint(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (free(new), NULL);
	new->n = n;

	new->next = prev->next;
	new->prev = prev;
	prev->next = new;

	if (new->next != NULL)
		new->next->prev = new;
	return (new);
}
