#include "main.h"

/**
 * clear_bit - sets the value of a
 * bit to 0 at a given index
 *
 * @n: number
 * @index: index
 *
 * Return: bit
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i = sizeof(unsigned long int) * 8;
	unsigned long int sum = 0;
	int seen = 0;

	for (; (int)i >= 0; i--)
	{
		if (((*n & (1 << i)) >> i) == 1)
		{
			seen = 1;
			if (i != index)
				sum += (1 * _power(2, i));
		}

		if ((i == index) && (seen == 0))
			return (-1);
	}

	*n = sum;
	return (1);
}
