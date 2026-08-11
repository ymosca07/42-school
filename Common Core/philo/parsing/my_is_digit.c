/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_is_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:18:25 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:05:57 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	my_is_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j] && argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '+')
			j++;
		if (argv[i][j] < '0' || argv[i][j] > '9')
			return (-1);
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			j++;
		}
		while (argv[i][j] && argv[i][j] == ' ')
			j++;
		if (argv[i][j] != '\0')
			return (-1);
	}
	return (0);
}
