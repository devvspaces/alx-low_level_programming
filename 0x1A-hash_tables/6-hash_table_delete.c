#include "hash_tables.h"

/**
 * hash_table_delete - Frees a hash table.
 * 
 * @ht: A pointer to a hash table to be freed.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *h_head = ht;
	hash_node_t *hnode, *tmp_node;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
		if (ht->array[i] != NULL)
		{
			hnode = ht->array[i];
			while (hnode != NULL)
			{
				tmp_node = hnode->next;
				free(hnode->key);
				free(hnode->value);
				free(hnode);
				hnode = tmp_node;
			}
		}

	free(h_head->array);
	free(h_head);
}
