#include "main.h"

/**
 * print_binary - prints the binary
 * representation of a number.
 *
 * @n: number
 */
void print_binary(unsigned long int n)
{
	int i = sizeof(long int) * 7;
	int s = 0;

	for (; i >= 0; i--)
		if (((n & (1 << i)) >> i) == 1)
		{
			s = 1;
			printf("1");
		}
		else if (s == 1)
			printf("0");

	if (s == 0)
		printf("0");
}
