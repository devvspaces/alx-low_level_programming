#include "lists.h"

/**
 * free_listint_safe - free linked list
 *
 * @h: node
 *
 * Return: size of freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;

	if (*h == NULL)
		return (size);

	size = sizeof(*h);

	if ((*h)->next == NULL)
	{
		free(*h);
		return (size);
	}

	if ((*h)->next > (*h))
	{
		free(*h);
		return (size);
	}

	size += free_listint_safe(&(*h)->next);
	free(*h);
	*h = NULL;
	return (size);
}
