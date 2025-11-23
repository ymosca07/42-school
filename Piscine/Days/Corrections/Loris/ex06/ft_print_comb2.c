/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:59:07 by yamosca-          #+#    #+#             */
/*   Updated: 2025/09/03 20:35:00 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char a)
{
	ft_putchar(a / 10 + '0');
	ft_putchar(a % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print(i);
			ft_putchar(' ');
			ft_print(j);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
