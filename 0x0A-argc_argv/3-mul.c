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

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));

	return (0);
}
