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
	int i = sizeof(long int) * 7;
	unsigned int len = 0;
	int s = 0;

	for (; i >= 0; i--)
		if (((n & (1 << i)) >> i) == 1)
		{
			s = 1;
			len++;
		}
		else if (s == 1)
			len++;

	if (s == 0)
		len++;

	if (index > (len - 1))
		return (-1);

	bit = n & (1 << index) ? 1 : 0;

	return (bit);
}
