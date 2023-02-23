#include "main.h"

/**
 * main - Entry point
 *
 * Description: Print the word putchar
 *
 * Return: 0
 */
int main(void)
{
	char s[9] = "_putchar";

	int i;

	for (; i < 8; i++)
		_putchar(&s[i]);

	_putchar('\n');

	return (0);
}
