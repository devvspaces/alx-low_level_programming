#include "lists.h"

/**
 * detectLoop - detect loop point
 * in linked list
 *
 * @head: node
 *
 * Return: pointer to loop cause
 */
const listint_t *detectLoop(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	const listint_t *prev;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow = slow->next;
	fast = fast->next->next;

	while (fast && fast->next)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		return (NULL);

	slow = head;
	prev = fast;

	do {
		slow = slow->next;
		fast = fast->next;
		prev = fast;
	} while (slow != fast);

	return (prev);
}

/**
 * print_nodes_safe - print nodes recursively
 *
 * @node: node
 * @count: current count
 * @loop: current loop
 *
 * Return: count
 */
size_t print_nodes_safe(
	const listint_t *node, size_t count, const listint_t *loop)
{
	if (node == NULL)
		return (count);

	if (node == loop && loop != NULL)
	{
		printf("[%p] %d\n", (void *)node, node->n);
		printf("-> [%p] %d\n", (void *)node->next, node->next->n);
		return (++count);
	}

	printf("[%p] %d\n", (void *)node, node->n);

	return (print_nodes_safe(node->next, ++count, loop));
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
	return (print_nodes_safe(head, 0, detectLoop(head)));
}
