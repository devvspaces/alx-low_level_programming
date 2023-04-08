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
	unsigned long int sum = 0;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	*n = sum;
	return (1);
}
