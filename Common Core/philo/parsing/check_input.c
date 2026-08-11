/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:35:01 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:05:28 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_input(int argc, long *tab)
{
	int	i;

	i = 0;
	if (argc == 6 && tab[4] == 0)
	{
		free(tab);
		return (-1);
	}
	while (i < argc - 1)
	{
		if (tab[i] == 0)
		{
			write(2, "Error\n", 6);
			free(tab);
			return (-1);
		}
		i++;
	}
	return (0);
}
