#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the
 * end of a dlistint_t list.
 *
 * @head: head
 * @n: new value
 *
 * Return: new head
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *ptr;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (free(new), NULL);
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*head != NULL)
	{
		ptr = *head;
		for (; ptr->next != NULL; ptr = ptr->next)
			;

		ptr->next = new;
		new->prev = ptr;
	}
	else
		*head = new;

	return (new);
}
