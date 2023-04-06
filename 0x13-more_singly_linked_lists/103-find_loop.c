#include "lists.h"

/**
 * find_listint_loop - finds the point
 * of loop in a linked list
 *
 * @head: pointer to the start of the list
 *
 * Return: the loop node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (head == NULL)
		return (NULL);
	if (head->next == NULL)
		return (NULL);
	do {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	} while (fast && fast->next);
	if (slow != fast)
		return (NULL);

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return (fast);
}
