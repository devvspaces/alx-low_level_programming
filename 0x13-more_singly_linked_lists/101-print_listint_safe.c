#include "lists.h"

/**
 * print_listint_safe - prints a list of nodes
 *
 * @head: node
 *
 * Return: Number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;

	if (head == NULL || head->next == NULL)
		exit(98);

	printf("[%p] %d\n", (void *)slow, slow->n);
	count++;

	slow = slow->next;
	fast = fast->next->next;

	while (slow != NULL)
	{
		if (slow == fast)
		{
			printf("\n\nThe number before: %d\n\n", fast->n);
			break;
		}

		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
		
		if (fast && fast->next)
			fast = fast->next->next;
	}

	if (slow == NULL)
		return (count);

	if (slow != slow->next->next)
	{
		count += 2;
		printf("[%p] %d\n", (void *)slow, slow->n);
		printf("[%p] %d\n", (void *)slow->next, slow->next->n);
	}

	printf("-> [%p] %d\n", (void *)slow->next->next, slow->next->next->n);

	return (count);
}
