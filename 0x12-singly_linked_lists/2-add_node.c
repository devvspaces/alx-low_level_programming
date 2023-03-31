#include "lists.h"

/**
 * add_node - add a new node to the
 * linked list
 *
 * @head: node
 * @str: string
 *
 * Return: address of the new node
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));
	int len = 0;

	if (new == NULL)
		return (NULL);

	for (; str[len] != '\0'; len++)
		;

	new->str = strdup(str);
	new->len = len;
	new->next = *head;
	*head = new;

	return (new);
}
