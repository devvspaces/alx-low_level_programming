#include "lists.h"

/**
 * print_nodes_safe - print nodes recursively
 *
 * @node: node
 * @count: current count
 *
 * Return: count
 */
size_t print_nodes_safe(const listint_t *node, size_t count)
{
	if (node == NULL)
		return (count);

	if ((node->next != NULL) && (node->next > node))
	{
		printf("%d\n", node->n);
		return (++count);
	}

	printf("%d\n", node->n);

	return (print_nodes_safe(node->next, ++count));
}

/**
 * print_listint_safe - prints a list of nodes
 *
 * @head: node
 *
 * Return: Number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	if (head == NULL)
		exit(98);

	return (print_nodes_safe(head, 0));
}
