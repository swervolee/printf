#include "main.h"


void buffer_fill(char *buffer, char c, unsigned int *i)
{
	if (*i == 1024)
		empty_buffer(buffer, i);
	else
	{
		buffer[*i] = c;
		(*i)++;
	}
}


void empty_buffer(char *buffer, unsigned int *i)
{
	write (1, buffer, *i);
	*i = 0;
}
