#include "main.h"

/**
 * _strlen - function that counts characters in string.
 *
 * @str: pointer to the string
 *
 * Return: the number of characters
 */

int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _printf - that produces output according to a format.
 *
 * @format: the format that needs to be procceced
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, char_count = 0, num;
	char *str;
	char c;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			char_count++;
		}
		else
		{
			i++;
			if (format[i] == '\n')
				return (-1);
			switch (format[i])
			{
				case 's':
					str = va_arg(args, char *);
					write(1, str, _strlen(str));
					char_count += _strlen(str);
					break;
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					char_count++;
					break;
				case 'i':
					num = va_arg(args, int);
					char_count += print_number(num);
					break;
				case 'd':
					num = va_arg(args, int);
					char_count += print_number(num);
					break;
				case '%':
					write(1, &format[i], 1);
					char_count++;
					break;
				default:
					break;
			}
		}
	}
	va_end(args);
	return (char_count);
}
