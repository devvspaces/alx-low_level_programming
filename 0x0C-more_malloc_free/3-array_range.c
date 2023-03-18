#include "main.h"

/**
 * mul - Multiply a and b
 *
 * Description: Performs Overflow and zero checks
 *
 * @a: first value
 * @b: second value
 *
 * Return: multiplication result or -1 when it
 * fails check
 */
int mul(unsigned int a, unsigned int b)
{
	unsigned int x = a * b;

	if ((a != 0 && x / a != b) || (a == 0) || (b == 0))
	{
		return (-1);
	}
	return (x);
}

/**
 * array_range - creates an array of integers
 *
 * Description: creates range of integers from
 * min to max (included)
 *
 * @min: min number (included)
 * @max: max number (included)
 *
 * Return: memory address if success or
 * NULL if failed
 */
int *array_range(int min, int max)
{
	int res;
	void *mem;
	char *ptr;

	if (min > max)
		return (NULL);

	res = mul((max - min) + 1, sizeof(min));

	if (res == -1)
		return (NULL);

	mem = malloc(res);

	if (mem == NULL)
		return (NULL);

	ptr = mem;

	while (min <= max)
	{
		*ptr = min++;
		ptr = sizeof(min) + ptr;
	}

	return (mem);
}
