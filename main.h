#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct
{
	char specifier;
	void (*handler)(va_list args, char *buffer, unsigned int *i);
} format_specs;

void handle_char(va_list args, char *buffer, unsigned int *i);
void handle_integer(va_list args, char *buffer, unsigned int *index);
void buffer_fill(char *buffer, char c, unsigned int *i);
void empty_buffer(char *buffer, unsigned int *i);
int _putchar(char c);
void handle_string(va_list args, char *buffer, unsigned int *i);
int _printf(const char *format, ...);
#endif
