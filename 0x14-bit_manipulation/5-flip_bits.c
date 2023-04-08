#include "main.h"

/**
 * flip_bits - find bits
 *
 * @n: number
 * @m: number
 *
 * Return: counts
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    int count = 0;
	unsigned long int i;
 
    for (i = 0; i < sizeof(unsigned long int) * 8; i++)
        if (((n >> i) & 1) != ((m >> i) & 1))
            count++;
 
    return (count);
}
