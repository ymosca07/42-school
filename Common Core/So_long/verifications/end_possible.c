/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_possible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:17:48 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/15 17:21:05 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	end_possible(char **map)
{
	int	n;
	int	i;

	n = -1;
	while (map[++n])
	{
		i = -1;
		while (map[n][++i])
		{
			if (map[n][i] == 'E' || map[n][i] == 'C')
				return (1);
		}
	}
	free_all(map);
	return (0);
}
