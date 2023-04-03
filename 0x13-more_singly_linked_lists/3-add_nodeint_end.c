#include "lists.h"

/**
 * find_tail - find the tail of the
 * linked list.
 *
 * @node: node
 *
 * Return: address of the tail node
 */
listint_t *find_tail(listint_t *node)
{
	if (node->next == NULL)
		return (node);

	return (find_tail(node->next));
}

/**
 * add_node_end - add a new node to the
 * linked list (append)
 *
 * @head: node
 * @str: string
 *
 * Return: address of the new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
	{
		free(*head);
		return (NULL);
	}

	new->n = n;

	if (*head != NULL)
		find_tail(*head)->next = new;
	else
		*head = new;

	return (new);
}
