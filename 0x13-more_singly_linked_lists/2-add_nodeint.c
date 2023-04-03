#include "lists.h"

/**
 * add_node - add a new node to the
 * linked list (prepend)
 *
 * @head: node
 * @str: string
 *
 * Return: address of the new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
