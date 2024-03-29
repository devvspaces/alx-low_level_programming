#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of
 * a dlistint_t linked list.
 *
 * @head: head
 * @index: index
 *
 * Return: nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp = head;

	for (; temp != NULL; --index, temp = temp->next)
		if (index == 0)
			return (temp);
	return (NULL);
}
