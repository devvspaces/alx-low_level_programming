#include "lists.h"

/**
 * sum_listint - sum of all the data (n)
 *
 * @head: node
 *
 * Return: the sum
 */
int sum_listint(listint_t *head)
{
	listint_t *point = head;
	int sum = 0;

	while (point != NULL)
	{
		sum += point->n;
		point = point->next;
	}

	return (sum);
}
