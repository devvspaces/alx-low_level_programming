#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - check the code .
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;
	size_t n;

	head = NULL;
	n = free_listint_safe(&head);
	printf("%lu\n%p\n", n, (void *)head);
	return (0);
}
