#include "main.h"

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
			sum += (1 * (unsigned long int)_pow(2, i));

	*n = sum;
	return (1);
}
