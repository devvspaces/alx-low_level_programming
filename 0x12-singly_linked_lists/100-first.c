#include "lists.h"

void before_func(void) __attribute__((constructor));

/**
 * before_func - print text before
 * the main function
 */
void before_func(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
