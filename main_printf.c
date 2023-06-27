#include "main.h"

format_specs specifiers[] =
{
	 {'d', handle_integer},
	 {'s', handle_string},
	 {'c', handle_char}
};

int _printf(const char *format, ...)
{
	char *buffer = malloc(1024 * sizeof(char));
	long unsigned int i;
	unsigned int index = 0/*printed = 0;*/;
	format_specs *specifier = NULL;
	va_list args;
	va_start(args, format);

	if (!buffer)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			specifier = NULL;
			for (i = 0; i < sizeof(specifiers) / sizeof(specifiers[0]); i++)
			{
				if (specifiers[i].specifier == *format)
				{
					specifier = &specifiers[i];
					break;
				}
			}
			if (specifier)
				specifier->handler(args, buffer, &index);
		}
		else
			buffer_fill(buffer, *format, &index);
		format++;
	}
	va_end(args);
	write(1, buffer, index);
	free(buffer);
	return (0);
}
