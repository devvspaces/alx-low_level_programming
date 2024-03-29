#include "lists.h"

/**
 * print_dlistint - prints all the elements of
 * a dlistint_t list.
 *
 * @h: head
 *
 * Return: count
 */
size_t print_dlistint(const dlistint_t *h)
{
	dlistint_t *temp = (dlistint_t *)h;
	size_t count = 0;

	if (h == NULL)
		return (0);

	for (; temp->next != NULL; count++, temp = temp->next)
		printf("%d\n", temp->n);

	printf("%d\n", temp->n);
	return (++count);
}
