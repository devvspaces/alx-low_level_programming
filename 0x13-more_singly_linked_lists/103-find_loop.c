#include "lists.h"

/**
 * find_listint_loop - finds the loop
 * in a linked list
 *
 * @h: node
 *
 * Return: The address of the node where
 * the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL)
		return (NULL);

	if (head->next == NULL)
		return (NULL);


	return (find_listint_loop(head->next));
}
