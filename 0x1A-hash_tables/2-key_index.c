#include "hash_tables.h"

/**
 * key_index - Get the index for the key in the hash table.
 *
 * Description: This makes use of djb2 algorithm as the
 * hash function.
 *
 * @key: The key to be calculated.
 * @size: The size of the hash table.
 *
 * Return: The index of the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
