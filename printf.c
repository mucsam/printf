#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: directives
 *
 * Return: prints the output
 */
int _printf(const char *format, ...)
{
	va_list pa;

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
				}
				else if (*format == 's')
				{
					printf("%s", va_arg(pa, char *));
				}
				else if (*format == '%')
				{
					putchar('%');
				}
				format++;
			}
			else
			{
				putchar(*format);
				format++;
			}
		}
	}
	return (0);
}
