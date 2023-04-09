#include "main.h"

/**
 * p_magic - print magic line
 *
 * @e_indent: array  of  bytes  specifies
 * how  to interpret the file
 */
void p_magic(unsigned char e_indent[EI_NIDENT])
{
	int i;

	printf("  Magic:  ");
	for (i = 0; i < EI_PAD; i++)
		printf(" %02x", e_indent[i]);

	for (; i < 16; i++)
		printf(" %02x", e_indent[EI_PAD]);
	printf("\n");
}

/**
 * _pad - left justify pad a string
 *
 * @s: string to pad
 */
void _pad(char *s)
{
	printf("  %-35s", s);
}

/**
 * p_class - print class line
 *
 * @e_indent: array  of  bytes  specifies
 * how  to interpret the file
 */
void p_class(unsigned char e_indent[EI_NIDENT])
{
	_pad("Class:");
	if (e_indent[EI_CLASS] == ELFCLASS32)
		printf("ELF32");
	else
		printf("ELF64");
	printf("\n");
}

/**
 * p_data - print data line
 *
 * @e_indent: array  of  bytes  specifies
 * how  to interpret the file
 */
void p_data(unsigned char e_indent[EI_NIDENT])
{
	_pad("Data:");
	if (e_indent[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian");
	else
		printf("2's complement, big endian");
	printf("\n");
}

/**
 * p_version - print verstion line
 *
 * @e_indent: array  of  bytes  specifies
 * how  to interpret the file
 */
void p_version(unsigned char e_indent[EI_NIDENT])
{
	_pad("Version:");
	printf("%d (current)\n", e_indent[EI_VERSION]);
}
