#ifndef MAIN
#define MAIN
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int _pow(int a, int b);
unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);

#endif
