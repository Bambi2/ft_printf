#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int	i;
	int	counter;
	va_list args;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				ft_putchar(va_arg(args, char));
			else if (format[i + 1] == 's')
				ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == 'p')
				ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == 'd')
				ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == 'i')
				ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == 'u')
				ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == 'x')
				ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == 'X')
				ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == '%')
				ft_putchar("%");
		}
		ft_putchar(format[i]);
	}
	va_end(args);
	return (i);
}

int main()
{
	printf("%d", ft_printf("a", 5, 1));
}