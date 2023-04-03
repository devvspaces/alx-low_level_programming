#include "lists.h"

/**
 * count_nodes - count nodes recursively
 *
 * @node: node
 * @count: current count
 *
 * Return: count
 */
size_t count_nodes(const listint_t *node, size_t count)
{
	if (node == NULL)
		return (count);

	return (count_nodes(node->next, ++count));
}

/**
 * listint_len - returns the number of elements
 * in a linked list
 *
 * @h: node
 *
 * Return: Number of nodes
 */
size_t listint_len(const listint_t *h)
{
	return (count_nodes(h, 0));
}
