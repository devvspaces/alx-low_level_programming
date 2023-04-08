#include "main.h"

/**
 * _pow - a ^ b
 *
 * @a: a
 * @b: b
 *
 * Return: int
 */
int _pow(int a, int b)
{
	int i;
	int total = 1;

	if (b == 0)
		return (1);

	for (i = 0; i < b; i++)
		total *= a;

	return (total);
}

/**
 * binary_to_uint - convert bin to int
 *
 * @b: bin
 *
 * Return: int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int sum = 0;
	unsigned int curr = 0;
	int len = 0, i;

	if (b == NULL)
		return (0);

	while (b[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
	{
		if (b[i] == 49)
			curr = 1;
		else if (b[i] == 48)
			curr = 0;
		else
			return (0);

		sum += (curr * (unsigned int)_pow(2, (len - i - 1)));
	}

	return (sum);
}
