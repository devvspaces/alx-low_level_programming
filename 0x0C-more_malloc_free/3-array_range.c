#include "main.h"

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
	int i, len;
	int *mem;

	if (min > max)
		return (NULL);

	len = (max - min) + 1;
	mem = malloc(sizeof(int) * len);

	if (!mem)
		return (NULL);

	for (i = 0; i < len; i++)
		mem[i] = min++;

	return (mem);
}
