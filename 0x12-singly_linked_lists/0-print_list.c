#include "lists.h"

/**
 * _printf - print string
 *
 * @s: string to print
 */
void _printf(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

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
		_printf("[0] (nil)");
	else
	{
		_printf("[");
		_putchar(node->len + '0');
		_printf("] ");
		_printf(node->str);
	}

	_putchar('\n');

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
