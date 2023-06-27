#include "main.h"

void handle_string(va_list args, char *buffer, unsigned int *i)
{
	int j;
	char *value = va_arg(args, char *);

	for (j = 0; value[j] != '\0'; j++)
		buffer_fill(buffer, value[j], i);
}

void handle_char(va_list args, char *buffer, unsigned int *i)
{
	char c;

	c = va_arg(args, int);
	buffer_fill(buffer, c, i);
}
