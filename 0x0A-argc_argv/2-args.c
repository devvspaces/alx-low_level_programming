#include <stdlib.h>
#include <stdio.h>

/**
 * main - sweet main function
 *
 * @argc: number of arguments passed to command line
 * @argv: array of arguments as strings passed to command line
 *
 * Description: Prints argv
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	while (argc--)
		printf("%s\n", *argv++);

	return (0);
}
