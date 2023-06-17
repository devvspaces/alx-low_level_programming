#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for the crackme5 executable.
 * @argc: args count
 * @argv: null terminated array of args
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char key[7], *secret;
	int ph_len = strlen(argv[1]), i, temp;

	secret = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	temp = (ph_len ^ 59) & 63;
	key[0] = secret[temp];

	temp = 0;
	for (i = 0; i < ph_len; i++)
		temp += argv[1][i];
	key[1] = secret[(temp ^ 79) & 63];

	temp = 1;
	for (i = 0; i < ph_len; i++)
		temp *= argv[1][i];
	key[2] = secret[(temp ^ 85) & 63];

	temp = 0;
	for (i = 0; i < ph_len; i++)
	{
		if (argv[1][i] > temp)
			temp = argv[1][i];
	}
	srand(temp ^ 14);
	key[3] = secret[rand() & 63];

	temp = 0;
	for (i = 0; i < ph_len; i++)
		temp += (argv[1][i] * argv[1][i]);
	key[4] = secret[(temp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		temp = rand();
	key[5] = secret[(temp ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}