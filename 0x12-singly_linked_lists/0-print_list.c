#include "lists.h"

/**
 * print_nodes - print nodes recursively
 *
 * @node: node
 * @count: current count
 *
 * Return: count
 */
size_t print_nodes(const list_t *node, size_t count)
{
	if (node == NULL)
		return (count);

	if (node->str == NULL)
		printf("[0] (nil)\n");
	else
	{
		printf("[%d] %s\n", node->len, node->str);
	}

	return (print_nodes(node->next, ++count));
}

/**
 * print_list - prints a list of nodes
 *
 * @h: node
 *
 * Return: Number of nodes
 */
size_t print_list(const list_t *h)
{
	return (print_nodes(h, 0));
}
