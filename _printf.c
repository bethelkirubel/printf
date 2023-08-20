#include "main.h"

/**
 * _printf - a new printf function
 * @format - string to print
 * Return: the length of the string
 */

int _printf(const char *format, ...)
{
int i = 0;
va_list val;
int len, len2;
char *s;
char c;

if (format == NULL)
return (-1);
va_start(val, format);
while (*format)
{
if (*format != '%')
{
write(1, format, 1);
i++;
}
else
{
format++;
if (*format == '\0')
break;
len2 = 0;
if (*format == '%')
{
_putchar('%');
i++;
i = i + len2;
}
if (*format == 'c')
{
c = va_arg(val, int);
write(1, &c, 1);
i++;
}
if (*format == 's')
{
s = va_arg(val, char *);
len = 0;
while (s[len] != '\0')
{
len++;
}
write(1, s, len);
i = i + len;
}
}
format++;
}
va_end(val);
return (i);
}

