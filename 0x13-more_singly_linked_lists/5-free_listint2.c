#include "lists.h"

/**
 * free_listint2 - free linked list
 *
 * @head: node
 */
void free_listint2(listint_t **head)
{
	if (*head == NULL)
	{
		free(*head);
		return;
	}

	if ((*head)->next == NULL)
	{
		free(*head);
		return;
	}

	free_listint2(&(*head)->next);
	free(*head);
	*head = NULL;
}
