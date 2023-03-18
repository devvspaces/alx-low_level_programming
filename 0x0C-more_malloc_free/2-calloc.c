#include "main.h"

int mul(unsigned int a, unsigned int b)
{
	unsigned int x = a * b;
	if ((a != 0 && x / a != b) || (a == 0) || (b == 0)) {
		return (-1);
	}
	return (x);
}

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
