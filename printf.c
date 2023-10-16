#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* handle_char - Handle the %c format specifier
* @ch: Character to be printed
* Return: Number of characters printed
*/
static int handle_char(char ch)
{
write(1, &ch, 1);
return (1);
}

/**
* handle_string - Handle the %s format specifier
* @str: String to be printed
* Return: Number of characters printed
*/
static int handle_string(char *str)
{
int j = 0, printed = 0;
while (str && str[j])
{
write(1, &str[j], 1);
j++;
printed++;
}
return (printed);
}

/**
 * _printf - Custom implementation of the printf function
 * @format: The string that contains the text to be written to stdout.
 * It can optionally contain embedded format tags that are replaced
 * by the values specified in subsequent additional arguments and
 * formatted as requested.
 *
 * Description: This function writes output to stdout, the standard
 * output stream, under control of the string pointed to by format
 * that specifies how subsequent arguments are converted for output.
 *
 * Return: Number of characters printed excluding the null byte.
 */
int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list args;
int i;

va_start(args, format);

for (i = 0; format[i]; i++)
{
if (format[i] != '%' || (format[i] == '%' && format[i + 1] == '\0'))
{
write(1, &format[i], 1);
printed_chars++;
}
else
{
i++;
switch (format[i])
{
case 'c':
printed_chars += handle_char((char) va_arg(args, int));
break;
case 's':
printed_chars += handle_string(va_arg(args, char *));
break;
}
}
}
va_end(args);
return (printed_chars);
}
