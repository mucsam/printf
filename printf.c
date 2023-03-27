#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - produces output according to a format
 * @format: directives
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list pa;
	int length = 0;
	size_t j;
	char *string;

	va_start(pa, format);
	if (format != NULL)
	{
		while (*format != '\0')
		{
			if (*format == '%')
			{
				format++;
				if (*format == 'c')
				{
					putchar(va_arg(pa, int));
					length++;
				}
				else if (*format == 's')
				{
					string = va_arg(pa, char *);
					for (j = 0; j < strlen(string); j++)
					{
						putchar(string[j]);
						length++;
					}
				}
				else if (*format == '%')
				{
					putchar('%');
					length++;
				}
				format++;
			}
			else
			{
				putchar(*format);
				length++;
				format++;
			}
		}
	}
	else
	{
		length += length;
	}

	return (length);
}
