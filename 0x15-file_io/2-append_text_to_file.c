#include "main.h"

/**
 * append_text_to_file - appends a file
 *
 * @filename: filename
 * @text_content: content
 *
 * Return: 1 if success else -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len;
	ssize_t stat;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

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
