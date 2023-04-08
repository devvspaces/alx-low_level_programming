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
	unsigned long int set;

	if (index > (i - 1))
		return (-1);

	/* This makes sures the rightmost 1 and values are flipped*/
	set = 1 << index;

	/* Negate each bit to make 0 ready to remove */
	set = ~set;

	*n = *n & set;
	return (1);
}
