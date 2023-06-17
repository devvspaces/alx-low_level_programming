#include "lists.h"

/**
 * sum_dlistint - sum of all values of
 * a dlistint_t list.
 *
 * @head: head
 *
 * Return: sum of all values
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *temp = head;
	int sum = 0;

	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
