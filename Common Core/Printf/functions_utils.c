/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:03:42 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/17 19:24:00 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(va_list args)
{
	int		i;
	int		count;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base(unsigned int nb, char *base, int count)
{
	if (nb >= 16)
	{
		count += ft_putnbr_base(nb / 16, base, count);
		write(1, &base[nb % 16], 1);
		count++;
	}
	else if (nb >= 0 && nb <= 15)
	{
		write(1, &base[nb % 16], 1);
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_puthex(nb / 16, base);
		write(1, &base[nb % 16], 1);
		count++;
	}
	else if (nb >= 0 && nb <= 15)
	{
		write(1, &base[nb % 16], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb = -nb;
		count += write(1, "-", 1);
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += write(1, &"0123456789"[nb % 10], 1);
	return (count);
}
