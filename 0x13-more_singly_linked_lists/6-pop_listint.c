#include "lists.h"

/**
 * pop_listint - pop node in linked list
 *
 * @head: node
 *
 * Return: value of popped node
 */
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
