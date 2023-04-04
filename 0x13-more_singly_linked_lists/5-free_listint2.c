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
		*head = NULL;
		return;
	}

	free_listint2(&((*head)->next));
	free(*head);
	*head = NULL;
}
