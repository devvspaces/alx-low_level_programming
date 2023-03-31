#include "lists.h"

/**
 * find_tail - find the tail of the
 * linked list.
 *
 * @node: node
 *
 * Return: address of the tail node
 */
list_t *find_tail(list_t *node)
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
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));
	int len = 0;

	if (new == NULL)
		return (NULL);

	for (; str[len] != '\0'; len++)
		;

	new->str = strdup(str);
	new->len = len;

	if (*head != NULL)
		find_tail(*head)->next = new;
	else
		*head = new;

	return (new);
}
