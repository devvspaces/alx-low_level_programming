#include "lists.h"

/**
 * __p - prints no looped list.
 *
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t __p(const listint_t *head)
{
	const listint_t *slow = head;
	size_t num = 0;

	while (slow != NULL)
	{
		num++;
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
	}
	return (num);
}

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	size_t num = 0;
	int count = 0;

	if (head == NULL)
		return (0);
	if (head->next == NULL)
		return (1);
	do {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	} while (fast && fast->next);
	if (slow != fast)
		return (__p(head));
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow = head;
	if (slow == fast)
		count++;
	while (count <= 1)
	{
		num++;
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		if (slow == fast)
			count++;
	}
	printf("-> [%p] %d\n", (void *)fast, fast->n);
	return (num);
}
