#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 *
 * @head: head
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp = head;

	if (temp == NULL)
		return;

	while (temp != NULL)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}
