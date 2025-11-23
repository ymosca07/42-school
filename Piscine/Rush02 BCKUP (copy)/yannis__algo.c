/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yannis__algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:30:57 by yamosca-          #+#    #+#             */
/*   Updated: 2025/09/20 17:48:33 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void	units_search()
{
	
}

void	tens()
{}

void	hundreds()
{}

void	ft_algo(char *nb, struct s_stock_str *dict)
{
	int	len = strlen(nb - 1);
	int	div = 0;
	int	thousand = 30;
	int	line = 0;
	int	u = 0;

	while (len > 0)
	{
		if (unit == 0)
		{
			while (dict[line].values <= 9)
			{
				if (nb[len] == dict[line].values)
					ft_putstr(dict[line].name)
				line++;
			}
		}

		if (div % 3 == 0)
		{
			ft_putstr(dict[thousand].name);
			thousand++;
		}

		len--;
	}
}
