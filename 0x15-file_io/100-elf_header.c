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
	switch (e_indent[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		break;
	}
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
	switch (e_indent[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		break;
	}
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

/**
 * l_b_endian - this converts little
 * endian number hex to big endian
 *
 * @x: input number
 *
 * Return: output number
 */
unsigned int l_b_endian(unsigned int x)
{
	return (((x & 0xFF000000) >> 24) |
			((x & 0x00FF0000) >> 8) |
			((x & 0x0000FF00) << 8) |
			((x & 0x000000FF) << 24));
}

/**
 * p_os_abi - print os/abi line
 *
 * @e_indent: array  of  bytes  specifies
 * how  to interpret the file
 */
void p_os_abi(unsigned char e_indent[EI_NIDENT])
{
	char *name;

	_pad("OS/ABI:");
	switch (e_indent[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		name = "System V";
		break;
	case ELFOSABI_HPUX:
		name = "HP-UX";
		break;
	case ELFOSABI_NETBSD:
		name = "NetBSD";
		break;
	case ELFOSABI_LINUX:
		name = "Linux";
		break;
	case ELFOSABI_SOLARIS:
		name = "Solaris";
		break;
	case ELFOSABI_IRIX:
		name = "IRIX";
		break;
	case ELFOSABI_FREEBSD:
		name = "FreeBSD";
		break;
	case ELFOSABI_TRU64:
		name = "TRU64";
		break;
	case ELFOSABI_ARM:
		name = "ARM";
		break;
	case ELFOSABI_STANDALONE:
		name = "Stand-alone";
		break;
	default:
		printf("<unknown: %x>\n", e_indent[EI_OSABI]);
		return;
	}
	printf("UNIX - %s\n", name);
}

/**
 * p_abi_version - print abi version
 *
 * @e_indent: array  of  bytes  specifies
 * how  to interpret the file
 */
void p_abi_version(unsigned char e_indent[EI_NIDENT])
{
	_pad("ABI Version:");
	printf("%d\n", e_indent[EI_ABIVERSION]);
}

/**
 * p_type - print type line
 *
 * @type: member of the structure
 * identifies the object file type
 */
void p_type(unsigned int type, unsigned char e_indent[EI_NIDENT])
{
	char *name;

	if (e_indent[EI_DATA] == ELFDATA2MSB)
		type = type >> 8;

	_pad("Type:");
	switch (type)
	{
	case ET_REL:
		name = "REL (Relocatable file)";
		break;
	case ET_EXEC:
		name = "EXEC (Executable file)";
		break;
	case ET_DYN:
		name = "DYN (Shared object file)";
		break;
	case ET_CORE:
		name = "CORE (Core file)";
		break;
	default:
		printf("<unknown: %x>\n", type);
		break;
	}
	printf("%s\n", name);
}

/**
 * p_entry - print entry address line
 *
 * @addr: address
 * @e_indent: e_indent
 */
void p_entry(unsigned int addr, unsigned char e_indent[EI_NIDENT])
{
	_pad("Entry point address:");
	if (e_indent[EI_DATA] != ELFDATA2LSB)
		addr = l_b_endian(addr);
	printf("%#x\n", addr);
}

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
	p_type(header.e_type, header.e_ident);
	p_entry(header.e_entry, header.e_ident);

	return (0);
}
