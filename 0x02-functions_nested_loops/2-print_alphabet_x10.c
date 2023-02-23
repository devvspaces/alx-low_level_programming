#include "main.h"

/**
 * print_alphabet - print a - z 10x
 *
 * Description: loop through a - z
 */
void print_alphabet_x10(void)
{
	char a;

	int i;

	for (i = 0; i < 10; i++)
	{
		a = 'a';

		for (; a <= 'z'; a++)
			_putchar(a);

		_putchar('\n');
	}

}
