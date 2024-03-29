#include "lists.h"

/**
 * free_node - free a linked list
 * node
 *
 * @node: node
 */
void free_node(listint_t *node)
{
	free(node);
}

/**
 * free_listint - free linked list
 *
 * @head: node
 */
void free_listint(listint_t *head)
{
	if (head == NULL)
		return;

	if (head->next == NULL)
	{
		free_node(head);
		return;
	}

	free_listint(head->next);
	free_node(head);
}
