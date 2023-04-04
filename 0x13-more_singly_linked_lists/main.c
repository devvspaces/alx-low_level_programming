#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;
	int sum;

	head = NULL;
	add_nodeint_end(&head, 1);
	sum = sum_listint(head);
	printf("sum = %d\n", sum);
	free_listint2(&head);
	return (0);
}
