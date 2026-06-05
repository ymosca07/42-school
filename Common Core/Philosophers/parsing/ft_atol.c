/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:31:00 by yamosca-          #+#    #+#             */
/*   Updated: 2026/05/31 11:24:16 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_atol(const char *str, int *error)
{
	long	i;
	long	sum;

	i = 0;
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sum > sum * 10)
			*error = -1;
		sum = (sum * 10) + str[i] - 48;
		i++;
	}
	return (sum);
}
