#include "lists.h"

/**
 * print_nodes - print nodes recursively
 *
 * @node: node
 * @count: current count
 *
 * Return: count
 */
size_t print_nodes(const listint_t *node, size_t count)
{
	if (node == NULL)
		return (count);

	printf("%d\n", node->n);

	return (print_nodes(node->next, ++count));
}

/**
 * print_listint - prints a list of nodes
 *
 * @h: node
 *
 * Return: Number of nodes
 */
size_t print_listint(const listint_t *h)
{
	return (print_nodes(h, 0));
}
