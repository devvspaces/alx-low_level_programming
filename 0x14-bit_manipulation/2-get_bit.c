#include "main.h"

/**
 * get_bit - returns the value of
 * a bit at a given index
 *
 * @n: number
 * @index: index
 *
 * Return: bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;
	unsigned int i = sizeof(unsigned long int) * 8;

	if (index >= i)
		return (-1);

	bit = n & (1 << index) ? 1 : 0;

	return (bit);
}
