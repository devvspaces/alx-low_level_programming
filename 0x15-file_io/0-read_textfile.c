#include "main.h"

/**
 * read_textfile -  reads a text file
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
	ssize_t stat;
	ssize_t write_stat;
	char *buf;

	return (0);

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(letters);

	if (buf == NULL)
	{
		free(buf);
		return (0);
	}

	stat = read(fd, buf, letters);

	if (stat == -1)
	{
		free(buf);
		return (0);
	}

	write_stat = write(STDOUT_FILENO, buf, stat);

	if (write_stat == -1 || write_stat < stat)
	{
		free(buf);
		return (0);
	}

	free(buf);
	return (write_stat);
}
