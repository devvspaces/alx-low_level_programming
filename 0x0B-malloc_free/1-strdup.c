#include <stdlib.h>

/**
 * *_strdup - return a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 *
 * @str: string
 *
 * Description: Copies a string to a pointer
 *
 * Return: 0
 */
char *_strdup(char *str)
{
	char *s;
	int i = 0, size = 0;

	if (str == NULL)
		return (NULL);

	for (; str[size] != '\0'; size++)
		;

	s = malloc(size * sizeof(*str) + 1);

	if (s == 0)
		return (NULL);

	while (i < size)
	{
		s[i] = str[i];
		i++;
	}

	return (s);
}
