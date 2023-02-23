#include "main.h"


/**
 * print_alphabet - print a - z
 *
 * Description: loop through a - z
 */
void print_alphabet(void)
{
	char a = 'a';

	for (; a <= 'z'; a++)
		_putchar(a);
	_putchar('\n');
}
