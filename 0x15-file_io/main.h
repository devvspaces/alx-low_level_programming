#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <elf.h>

#if defined(__LP64__)
#define ElfW(type) Elf64_##type
#else
#define ElfW(type) Elf32_##type
#endif

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void p_magic(unsigned char e_indent[EI_NIDENT]);
void _pad(char *s);
void p_class(unsigned char e_indent[EI_NIDENT]);
void p_data(unsigned char e_indent[EI_NIDENT]);
void p_version(unsigned char e_indent[EI_NIDENT]);
unsigned int l_b_endian(unsigned int x);
void p_os_abi(unsigned char e_indent[EI_NIDENT]);
void p_abi_version(unsigned char e_indent[EI_NIDENT]);
void p_type(uint16_t type);
void p_entry(unsigned int addr, unsigned char e_indent[EI_NIDENT]);

#endif
