#include "main.h"

void handle_integer(va_list args, char *buffer, unsigned int *index)
{
	int num = va_arg(args, int);
	int digits = 0, temp = num, i;
	char num_string[1024];
	
	if (num < 0)
		buffer_fill(buffer, '-', index), temp = -temp;
	if (num == 0)
		buffer_fill(buffer, '0', index), digits = 1;
	else
	{
		while (temp != 0)
		{
			temp /= 10;
			digits++;
		}
	}
	
	num_string[digits] = '\0';
	temp = num;
	for (i = digits - 1; i >= 0; i--)
		num_string[i] = '0' + (num % 10), num /= 10;
	num_string[digits] = '\0';
	for (i = 0; i < digits; i++)
		buffer_fill(buffer, num_string[i], index);
	buffer_fill(buffer, '\0', index);
}
