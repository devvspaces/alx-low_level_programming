#include "main.h"

/**
 * get_binary - gets the binary
 * representation of a number.
 *
 * @n: number
 */
char *get_binary(unsigned long int n)
{
	int i = sizeof(long int) * 7;
	char *bin;
	int s = 0;
	int pointer = 0;

	bin = malloc(i);
	if (bin == NULL)
	{
		free(bin);
		exit(98);
	}

	for (; i >= 0; i--)
		if (((n & (1 << i)) >> i) == 1)
		{
			s = 1;
			bin[pointer] = '1';
			pointer++;
		}
		else if (s == 1)
		{
			bin[pointer] = '0';
			pointer++;
		}

	if (s == 0)
	{
		bin[pointer] = '0';
		pointer++;
	}

	bin[pointer] = '\0';

	return (bin);
}

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
	char *s;
	unsigned int len = 0;

	s = get_binary(n);

	while (s[len] != '\0')
		len++;

	free(s);

	if (index > (len - 1))
		return (-1);

	bit = n & (1 << index) ? 1 : 0;

	return (bit);
}
