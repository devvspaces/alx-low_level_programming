#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new
 * node at a given position
 *
 * @head: node
 * @idx: index to insert node at
 * @n: value of the new node
 *
 * Return: address of the new pointer
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *point = *head;
	listint_t *new;

	while (idx > 1)
	{
		idx--;
		point = point->next;
		if (point == NULL)
			return (NULL);
	}

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = point->next;
		point->next = new;
	}

	return (new);
}
