#include "hash_tables.h"

/**
 * hash_table_print - Prints the values hash table.
 *
 * Description: Key/value pairs are printed in the order
 * in a hash table.
 *
 * @ht: A pointer to the hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *hnode;
	unsigned long int i;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
		if (ht->array[i] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			hnode = ht->array[i];
			while (hnode != NULL)
			{
				printf("'%s': '%s'", hnode->key, hnode->value);
				hnode = hnode->next;
				if (hnode != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}

	printf("}\n");
}
