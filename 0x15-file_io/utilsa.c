#include "main.h"

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
		exit(98);
		break;
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
void p_type(uint16_t type)
{
	char *name;

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
		exit(98);
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
