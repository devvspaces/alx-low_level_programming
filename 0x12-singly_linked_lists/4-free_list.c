#include "lists.h"

/**
 * free_node - free a linked list
 * node
 *
 * @node: node
 */
void free_node(list_t *node)
{
	free(node->str);
	free(node);
}

/**
 * free_list - free linked list
 *
 * @head: node
 */
void free_list(list_t *head)
{
	if (head->next == NULL)
	{
		free_node(head);
		return;
	}

	free_list(head->next);
	free_node(head);
}
