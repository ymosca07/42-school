/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcotza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:12:43 by thcotza           #+#    #+#             */
/*   Updated: 2025/09/20 15:30:24 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_algo(char *nb, struct s_stock_str *dict)
{
	int	i;
	int	unit;
	int	k;
	int	m;
	int	p;
	
	p = 0;
	m = 30;
	unit = 0;
	k = 0;	
	i = ft_strlen(nb - 1);
	while (i > 0)
	{
		if (unit == 0)
		{
			while (dict[p].values < 10)
			{
				if (dict[p].values == nb[i])
					ft_putstr(dict[p].name);
				p++;
			}
			// Regarde entre 1 et 9;
		}
		if (unit == 1)
		{
			while (dict[p + 21].values < 100)
			{
				if (dict[p + 21]. values == nb[i])
					ft_putstr(dict[p + 21].name);
			}
			// Regarde entre 20 et 90;
		}
		if (unit == 2)
		{
			while (dict[p].values < 10)
			{
				if (dict[p].values == nb[i])
				{
					ft_putstr(dict[p].name);
					ft_putstr(dict[29].name);
				}
			}
			// Cent
			unit = 0;
		}
		if (k % 3 == 0)
		{
			ft_putstr(dict[m].name);
			m++;
		}
		unit++;
		i--;
		k++;
	}	
} 
