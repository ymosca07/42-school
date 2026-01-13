/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:23:54 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/17 19:15:38 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb, int count)
{
	if (nb > 9)
	{
		count += ft_putnbr_unsigned(nb / 10, count);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
	count++;
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	int				count;
	unsigned long	tmp;

	count = 0;
	tmp = (unsigned long)ptr;
	if (!tmp)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		count += ft_puthex(tmp, "0123456789abcdef");
	}
	return (count + 2);
}
