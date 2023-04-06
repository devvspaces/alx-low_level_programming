#include "lists.h"

/**
 * __free - free a node
 *
 * @h: node
 *
 * Return: size of node
 */
size_t __free(listint_t **h)
{
	size_t size = sizeof(*h);

	free(*h);
	*h = NULL;
	return (size);
}

/**
 * __f - free normal linked list
 *
 * @h: node
 *
 * Return: size of freed list
 */
size_t __f(listint_t **h)
{
	if (*h == NULL)
		return (0);

	return (__f(&((*h)->next)) + __free(h));
}

/**
 * __safe_free - free circular
 * linked list
 *
 * @h: node
 * @loop: node
 *
 * Return: size of freed list
 */
size_t __safe_free(listint_t **h, listint_t *loop, int count)
{
	if (*h == loop)
	{
		if (count == 2)
			return (0);
		count++;
	}

	return (__safe_free(&((*h)->next), loop, count) + __free(h));
}

/**
 * free_listint_safe - free linked list
 *
 * @h: node
 *
 * Return: size of freed list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow = *h;
	listint_t *fast = *h;
	int count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	if ((*h)->next == NULL)
		return (__f(h));

	do {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	} while (fast && fast->next);

	if (slow != fast)
		return (__f(h));

	slow = *h;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	if (slow == fast)
		count++;

	return (__safe_free(h, fast, count));
}
