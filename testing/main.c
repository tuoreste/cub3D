#include "malloc.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *s;
	char *string = "hello world";
	size_t size = strlen(string);

	s = malloc(size + 1);
	s[size] = '\0';
	memcpy(s, string, size);
	printf("Malloc'd string: %s\n", s);
	free(s);
	show_alloc_mem_ex();
	print_leaks();
	return (0);
}