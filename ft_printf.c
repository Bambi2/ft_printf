/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:06:09 by mmalphit          #+#    #+#             */
/*   Updated: 2021/11/20 17:06:12 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_helper(va_list *args, const char *format,
int *i, int *counter)
{
	if (format[*i + 1] == 'c')
		*counter += ft_putchar_fd(va_arg(*args, int), 1);
	else if (format[*i + 1] == 's')
		*counter += ft_putstr_fd(va_arg(*args, char *), 1);
	else if (format[*i + 1] == 'p')
		*counter += ft_puthex((unsigned long)va_arg(*args, void *), 1);
	else if (format[*i + 1] == 'd')
		*counter += ft_putnbr_fd(va_arg(*args, int), 1);
	else if (format[*i + 1] == 'i')
		*counter += ft_putnbr_fd(va_arg(*args, int), 1);
	else if (format[*i + 1] == 'u')
		*counter += ft_un_putnbr_fd(va_arg(*args, unsigned int), 1);
	else if (format[*i + 1] == 'x')
		*counter += ft_puthex(va_arg(*args, unsigned int), 0);
	else if (format[*i + 1] == 'X')
		*counter += ft_puthex_up(va_arg(*args, unsigned int), 0);
	else if (format[*i + 1] == '%')
		*counter += ft_putchar_fd('%', 1);
	*i += 2;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_printf_helper(&args, format, &i, &counter);
			if (!format[i])
				break ;
		}
		else
			counter += ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return (counter);
}
