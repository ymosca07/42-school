/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:45:26 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/17 19:18:37 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	search_type(const char i, va_list args)
{
	int	count;

	count = 0;
	if (i == 'c')
		count += ft_putchar(va_arg(args, int));
	if (i == 's')
		count += ft_putstr(args);
	if (i == 'p')
		count += ft_put_ptr(va_arg(args, void *));
	if (i == 'd' || i == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (i == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	if (i == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				count);
	if (i == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				count);
	if (i == '%')
	{
		ft_putchar('%');
		count += 1;
	}
	return (count);
}
