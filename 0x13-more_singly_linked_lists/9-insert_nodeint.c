#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new
 * node at a given position
 *
 * @head: node
 * @idx: index to insert node at
 * @n: value of the new node
 *
 * Return: the sum
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{

	listint_t *point = *head;
	listint_t *new;

	if (point == NULL)
		return (NULL);

	while (idx > 1)
	{
		if (point->next == NULL)
			return (NULL);

		idx--;
		point = point->next;
	}

	new = malloc(sizeof(listint_t));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->n = n;

	new->next = point->next;
	point->next = new;

	return (new);
}
