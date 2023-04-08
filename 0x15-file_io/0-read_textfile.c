#include "main.h"

/**
 * _free - free buffer
 *
 * @p: pointer to buffer
 *
 * Return: 0
 */
int _free(char **p)
{
	free(*p);
	return (0);
}

/**
 * read_textfile - reads a text file
 * and prints it to the POSIX standard output.
 *
 * @filename: filename
 * @letters: complete
 *
 * Return: ssize_t
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t stat, write_stat, c_stat;
	char *buf;

	if ((filename == NULL) || (letters == 0))
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	buf = malloc(letters);
	if (buf == NULL)
		return (_free(&buf));

	stat = read(fd, buf, letters);
	if (stat < 0)
		return (_free(&buf));

	c_stat = close(fd);
	if (c_stat < 0)
		return (_free(&buf));

	write_stat = write(STDOUT_FILENO, buf, stat);
	if (write_stat < 0 || write_stat < stat)
		return (_free(&buf));

	free(buf);
	return (write_stat);
}
