#include "lists.h"

/**
 * reverse_nodes - inserts a new
 * node at a given position
 *
 * @a: node
 * @b: index to insert node at
 * @head: pointer to the head
 *
 * Return: previous head node
 */
listint_t *reverse_nodes(listint_t *a, listint_t *b, listint_t **head)
{
	if (b->next == NULL)
	{
		b->next = a;
		a->next = NULL;
		*head = b;
		return (a);
	}

	(reverse_nodes(b, b->next, head))->next = a;
	a->next = NULL;
	return (a);
}

/**
 * reverse_listint - reverses a linked list
 *
 * @head: node
 *
 * Return: the new head
 */
listint_t *reverse_listint(listint_t **head)
{
	if (*head == NULL)
		return (NULL);

	if ((*head)->next == NULL)
		return (*head);

	reverse_nodes(*head, (*head)->next, head);
	return (*head);
}
