/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:08:14 by mmalphit          #+#    #+#             */
/*   Updated: 2021/11/20 17:08:26 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check(int *n, int fd)
{
	int	counter;

	counter = 0;
	if (*n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	else
	{
		*n *= -1;
		write(fd, "-", 1);
		return (0);
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	char	output;
	int		counter;

	counter = 0;
	if (n < 0)
	{
		if (check(&n, fd) == 1)
			return (11);
		else
			counter++;
	}
	if (n < 10 && n >= 0)
	{
		output = n + 48;
		write(fd, &output, 1);
		counter++;
		return (counter);
	}
	else
	{
		counter += ft_putnbr_fd(n / 10, fd);
		counter += ft_putnbr_fd(n % 10, fd);
	}
	return (counter);
}

int	ft_un_putnbr_fd(unsigned int n, int fd)
{
	char	output;
	int		counter;

	counter = 0;
	if (n < 10)
	{
		output = n + 48;
		write(fd, &output, 1);
		counter++;
		return (counter);
	}
	else
	{
		counter += ft_putnbr_fd(n / 10, fd);
		counter += ft_putnbr_fd(n % 10, fd);
	}
	return (counter);
}
