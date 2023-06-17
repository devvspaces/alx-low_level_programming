#include "lists.h"

/**
 * delete_dnodeint_at_index -  inserts a
 * new node at a given position.
 *
 * @head: head
 * @index: index
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;

	temp = *head;

	for (; temp != NULL; --index, temp = temp->next)
		if (index == 0)
			break;

	if (temp == NULL)
		return (-1);

	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	else
		*head = temp->next;

	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
