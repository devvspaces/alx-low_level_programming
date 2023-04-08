#include "main.h"

/**
 * create_file - creates a file
 *
 * @filename: filename
 * @text_content: content
 *
 * Return: ssize_t
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t stat;
	int len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd < 0)
		return (-1);

	if (text_content == NULL)
		return (1);

	for (len = 0; text_content[len] != '\0'; len++)
		;

	stat = write(fd, text_content, len);
	if (stat < 0)
		return (-1);

	return (1);
}
