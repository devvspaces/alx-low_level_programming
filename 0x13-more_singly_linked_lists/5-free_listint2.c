#include "lists.h"

/**
 * free_listint2 - free linked list
 *
 * @head: node
 */
void free_listint2(listint_t **head)
{

	listint_t *point = *head;
	listint_t *next = NULL;

	while (point->next != NULL)
	{
		next = point->next;
		free(point);
		point = next;
	}

	if (next != NULL)
	{
		free(next);
		next = NULL;
	}

	*head = NULL;
}
