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
		*head = NULL;
		free(*head);
		return;
	}

	free_listint2(&(*head)->next);
	*head = NULL;
	free(*head);
}
