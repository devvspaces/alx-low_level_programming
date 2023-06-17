#include "lists.h"

/**
 * dlistint_len - number of elements in a
 * linked dlistint_t list.
 *
 * @h: head
 *
 * Return: count
 */
size_t dlistint_len(const dlistint_t *h)
{
	dlistint_t *temp = (dlistint_t *)h;
	size_t count = 0;

	if (h == NULL)
		return (0);

	for (; temp->next != NULL; count++, temp = temp->next)
		;
	return (++count);
}
