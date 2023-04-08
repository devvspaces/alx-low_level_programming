#include "main.h"

/**
 * get_endianness - checks the endianness
 * of a system
 *
 * Return: 0 if it's big endian
 * and return 1 if little endian
 */
int get_endianness(void)
{
	int x = 1;
	char *c = (char *)&x;

	return (*c);
}
