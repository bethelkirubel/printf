#include "main.h"

/**
 * _printf - a new printf function
 * @format - string to print
 * Return: the length of the string
 */

int _printf(const char *format, ...)
{
int i = 0;
va_list list;
int len;
char c;
char *s;

if (format == NULL)
return (-1);

va_start(list, format);
while (*format)
{
if (*format != '%')
{
write (1, format, 1);
i++;
}
else
{
format++;

if(*format == '\0')
break;

if(*format == '%')
write(1, format, 1);
i++;

if(*format == 'c')
c = va_arg(list, int);
write(1, &c, 1);
i++;

if(*format == 's')
s = va_arg(list, char *);
len = 0;
while(s[len] != '\0')
{
len++;
}
write(1, s, len);
i = i + len;
}
format++;
va_end(list);
}
return(i);
}
