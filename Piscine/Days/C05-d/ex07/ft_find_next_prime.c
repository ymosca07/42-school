/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:55:18 by yamosca-          #+#    #+#             */
/*   Updated: 2025/09/16 13:06:24 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 1;
	if (nb < 2)
		return (0);
	while (i <= nb)
	{
		if ((nb % i == 0) && (i != 1) && (i != nb))
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	while (i)
	{
		if (ft_is_prime(i) == 1)
			return (i);
		i++;
	}
	return (0);
}
