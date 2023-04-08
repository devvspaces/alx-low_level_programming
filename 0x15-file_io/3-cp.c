#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - copy text content from
 * one file to another
 *
 * @ac: no of args
 * @av: args
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	int fd_r, fd_w;
	char *file_from, *file_to, buf[1024];
	ssize_t r_stat, w_stat, c_stat, read_bytes = 1024;

	if (ac != 3)
	{ dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97); }
	file_from = av[1];
	file_to = av[2];
	fd_r = open(file_from, O_RDONLY);
	if (fd_r == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from),
		exit(98); }
	fd_w = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_w == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99); }

	while (1)
	{
		r_stat = read(fd_r, buf, read_bytes);
		if (r_stat == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
			exit(98); }
		if (r_stat == 0)
			break;
		w_stat = write(fd_w, buf, r_stat);
		if (w_stat == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99); }
	}
	c_stat = close(fd_r);
	if (c_stat == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", fd_r);
		exit(100); }
	c_stat = close(fd_w);
	if (c_stat == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", fd_w);
		exit(100); }
	return (0);
}
