#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * 
 * @ht: A pointer to the hash table.
 * @value: The value of the key.
 * @key: The key to add.
 *
 * Return: Upon failure - 0. else - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_hash_node;
	char *dup_value;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	dup_value = strdup(value);
	if (dup_value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = dup_value;
			return (1);
		}

	new_hash_node = malloc(sizeof(hash_node_t));
	if (new_hash_node == NULL)
		return (free(dup_value), 0);

	new_hash_node->key = strdup(key);
	if (new_hash_node->key == NULL)
		return (free(new_hash_node), 0);

	new_hash_node->value = dup_value;
	new_hash_node->next = ht->array[index];
	ht->array[index] = new_hash_node;

	return (1);
}
