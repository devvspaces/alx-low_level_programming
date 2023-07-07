#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value of 
 * a key from a hash table.
 * 
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key can't be found - NULL.
 * else - the value of the key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *hnode;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	hnode = ht->array[index];
	while (hnode && strcmp(hnode->key, key) != 0)
		hnode = hnode->next;
	
	if (hnode == NULL)
		return (NULL);

	return (hnode->value);
}
