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
 * _calloc - allocates memory for an
 * array of nmemb of size bytes each
 *
 * Description: Check for integer overflow
 *
 * @nmemb: amount of contiguous memory blocks
 * @size: size of each block in bytes
 *
 * Return: memory address if success or
 * NULL if failed
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	int res = mul(nmemb, size);
	int *mem;

	if (res == -1)
		return (NULL);

	mem = malloc(res);

	if (mem == NULL)
		return (NULL);

	*mem = 0;

	return (mem);
}
