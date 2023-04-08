#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _close_fd - close a file
 * descriptor
 *
 * @fd: file descriptor
 */
void _close_fd(int fd)
{
	ssize_t c_stat;

	c_stat = close(fd);
	if (c_stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * _check_read - check if a file
 * descriptor or read is success
 *
 * @fd: file descriptor or read byte count
 * @file: file_from name
 */
void _check_read(ssize_t fd, char *file)
{
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		_close_fd(fd);
		exit(98);
	}
}

/**
 * _check_write - check if a file
 * descriptor or write is success
 *
 * @fd: file descriptor or written byte count
 * @file: file_to name
 */
void _check_write(ssize_t fd, char *file)
{
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file);
		_close_fd(fd);
		exit(99);
	}
}

/**
 * _check_and_set - check if args
 * supplied to cp is valid, if true
 * set file names for a and b, else
 * exit with status 97.
 *
 * @ac: no of args
 * @av: args
 * @a: pointer to file_from
 * @b: pointer to file_to
 */
void _check_and_set(int ac, char **av, char **a, char **b)
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
		exit(97);
	}
	*a = av[1];
	*b = av[2];
}

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
	ssize_t r_stat, w_stat;
	size_t read_bytes = 1024;

	_check_and_set(ac, av, &file_from, &file_to);

	fd_r = open(file_from, O_RDONLY);
	_check_read(fd_r, file_from);
	fd_w = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	_check_write(fd_w, file_to);

	while (1)
	{
		/* Read bytes into buffer */
		r_stat = read(fd_r, buf, read_bytes);
		_check_read(r_stat, file_from);
		if (r_stat == 0)
			break;

		/* Write buffer into fd_w */
		w_stat = write(fd_w, buf, r_stat);
		_check_write(w_stat, file_to);
	}
	_close_fd(fd_r);
	_close_fd(fd_w);
	return (0);
}
