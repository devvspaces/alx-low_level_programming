#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of
 * a listint_t linked list.
 *
 * @head: node
 * @index: index of the node to return
 *
 * Return: the nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *point = head;

	while (index > 0)
	{
		if (point->next == NULL)
			return (NULL);
		index--;
		point = point->next;
	}

	return (point);
}
