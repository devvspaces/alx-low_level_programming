#include "lists.h"

/**
 * delete_nodeint_at_index - delete a node
 * at an index
 *
 * @head: node
 * @idx: index to insert node at
 *
 * Return: 1 if successful otherwise -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int idx)
{

	listint_t *point = *head;
	listint_t *oldPoint;

	if (point == NULL)
		return (-1);

	while (idx > 1)
	{
		if (point->next == NULL)
			return (-1);

		idx--;
		point = point->next;
	}

	if (idx == 0)
	{
		*head = point->next;
		free(point);
		return (1);
	}

	oldPoint = point->next;
	point->next = oldPoint->next;
	free(oldPoint);

	return (1);
}
