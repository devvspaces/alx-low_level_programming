#include "lists.h"

int pop_listint(listint_t **head)
{
	int data = 0;
	listint_t *next;

	if (*head == NULL)
		return (0);

	next = (*head)->next;
	data = (*head)->n;
	free(*head);
	*head = next;
	return (data);
}
