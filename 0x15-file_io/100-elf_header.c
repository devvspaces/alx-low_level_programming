#include "main.h"

/**
 * check_valid_elf - checks
 * if an elf file is valid
 *
 * @header: header struct
 * @filename: file name
 */
void check_valid_elf(ElfW(Ehdr) header, char *filename)
{
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(
			STDERR_FILENO, "Error: %s is not a valid ELF file\n",
			filename);
		exit(98);
	}
}

/**
 * main - displays the information
 * contained in the ELF header at
 * the start of an ELF file.
 *
 * @ac: no of args
 * @av: args
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	ElfW(Ehdr) header;
	ssize_t r_stat;

	void (*p_fp[])(unsigned char[EI_NIDENT]) = {
		p_magic, p_class, p_data, p_version,
		p_os_abi, p_abi_version};
	int fd, i, c_fp = 6;

	if (ac != 2)
	{
		dprintf(2, "Usage: %s filename\n", av[0]);
		return (1);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Failed to open");
		return (1);
	}

	r_stat = read(fd, &header, sizeof(header));
	if (r_stat == -1)
	{
		dprintf(2, "Failed to read");
		return (1);
	}

	check_valid_elf(header, av[1]);

	printf("ELF Header:\n");
	for (i = 0; i < c_fp; i++)
		p_fp[i](header.e_ident);
	p_type(header.e_type);
	p_entry(header.e_entry, header.e_ident);

	return (0);
}
