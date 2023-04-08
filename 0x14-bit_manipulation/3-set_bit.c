#include "main.h"

/**
 * _power - a ^ b
 *
 * @a: a
 * @b: b
 *
 * Return: a raise to power b
 */
unsigned long int _power(unsigned long int a, unsigned long int b)
{
	unsigned long int i;
	unsigned long int total = 1;

	if (b == 0)
		return (1);

	for (i = 0; i < b; i++)
		total *= a;

	return (total);
}

/**
 * set_bit - sets the value of a
 * bit to 1 at a given index
 *
 * @n: number
 * @index: index
 *
 * Return: bit
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i = sizeof(unsigned long int) * 8;
	unsigned long int sum = 0;

	if (index >= i)
		return (-1);

	for (; (int)i >= 0; i--)
		if ((((*n & (1 << i)) >> i) == 1) || (i == index))
			sum += (1 * _power(2, i));

	*n = sum;
	return (1);
}
