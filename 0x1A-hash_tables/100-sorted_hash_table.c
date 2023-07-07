#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * 
 * @size: The size of the sorted hash table.
 *
 * Return: NULL, If an error occurs, else
 * a pointer to the created sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shnode *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an new_node element to
 * a sorted hash table.
 * 
 * @ht: A pointer to the sorted hash table.
 * @value: The value of the key.
 * @key: The key to be added.
 *
 * Return: 0 if failed, else - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shnode *new_node, *tmp_node;
	char *dup_value;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	dup_value = strdup(value);
	if (dup_value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp_node = ht->shead;
	while (tmp_node)
	{
		if (strcmp(tmp_node->key, key) == 0)
		{
			free(tmp_node->value);
			tmp_node->value = dup_value;
			return (1);
		}
		tmp_node = tmp_node->snext;
	}

	new_node = malloc(sizeof(shnode));
	if (new_node == NULL)
		return (free(dup_value), 0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(dup_value);
		free(new_node);
		return (0);
	}

	new_node->value = dup_value;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		tmp_node = ht->shead;
		while (tmp_node->snext != NULL && strcmp(tmp_node->snext->key, key) < 0)
			tmp_node = tmp_node->snext;
		new_node->sprev = tmp_node;
		new_node->snext = tmp_node->snext;
		if (tmp_node->snext == NULL)
			ht->stail = new_node;
		else
			tmp_node->snext->sprev = new_node;
		tmp_node->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value in a sorted hash table.
 * 
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: NULL, If the key is not found, else
 * the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shnode *hnode;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	hnode = ht->shead;
	while (hnode != NULL && strcmp(hnode->key, key) != 0)
		hnode = hnode->snext;

	return ((hnode == NULL) ? NULL : hnode->value);
}

/**
 * shash_table_print - Prints the key - value in a sorted
 * hash table in order.
 * 
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shnode *hnode;

	if (ht == NULL)
		return;

	hnode = ht->shead;
	printf("{");
	while (hnode != NULL)
	{
		printf("'%s': '%s'", hnode->key, hnode->value);
		hnode = hnode->snext;
		if (hnode != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the key - value in a sorted hash
 * table in reverse order.
 * 
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shnode *hnode;

	if (ht == NULL)
		return;

	hnode = ht->stail;
	printf("{");
	while (hnode != NULL)
	{
		printf("'%s': '%s'", hnode->key, hnode->value);
		hnode = hnode->sprev;
		if (hnode != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Frees a sorted hash table.
 * 
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *h_head = ht;
	shnode *hnode, *tmp_node;

	if (ht == NULL)
		return;

	hnode = ht->shead;
	while (hnode)
	{
		tmp_node = hnode->snext;
		free(hnode->key);
		free(hnode->value);
		free(hnode);
		hnode = tmp_node;
	}

	free(h_head->array);
	free(h_head);
}
