/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:07:56 by mmalphit          #+#    #+#             */
/*   Updated: 2021/11/20 17:07:57 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_ul_length(unsigned long number)
{
	int	length;

	length = 0;
	if (!number)
		return (1);
	while (number)
	{
		number /= 16;
		length++;
	}
	return (length);
}

int	ft_puthex(unsigned long number, int is_pointer)
{
	char	*hex_string;
	int		length;
	int		counter;

	length = get_ul_length(number);
	counter = 0;
	hex_string = (char *) malloc(length + 1);
	if (!hex_string)
		return (0);
	hex_string[length--] = '\0';
	if (!number)
		hex_string[length--] = '0';
	while (number)
	{
		if (number % 16 < 10)
			hex_string[length--] = number % 16 + 48;
		else
			hex_string[length--] = number % 16 % 10 + 97;
		number /= 16;
	}
	if (is_pointer)
		counter += ft_putstr_fd("0x", 1);
	counter += ft_putstr_fd(hex_string, 1);
	free(hex_string);
	return (counter);
}

int	ft_puthex_up(unsigned long number, int is_pointer)
{
	char	*hex_string;
	int		length;
	int		counter;

	length = get_ul_length(number);
	counter = 0;
	hex_string = (char *) malloc(length + 1);
	if (!hex_string)
		return (0);
	hex_string[length--] = '\0';
	if (!number)
		hex_string[length--] = '0';
	while (number)
	{
		if (number % 16 < 10)
			hex_string[length--] = number % 16 + 48;
		else
			hex_string[length--] = number % 16 % 10 + 65;
		number /= 16;
	}
	if (is_pointer)
		counter += ft_putstr_fd("0x", 1);
	counter += ft_putstr_fd(hex_string, 1);
	free(hex_string);
	return (counter);
}
