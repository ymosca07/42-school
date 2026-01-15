/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:10:57 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/15 17:40:42 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_len(t_game *game)
{
	int		j;
	char	*current;

	j = 0;
	current = game->map[0];
	while (game->map[j])
	{
		if (ft_strlen(current) != ft_strlen(game->map[j]))
		{
			free_struct(game);
			error_signal("Error\nBad map's size");
		}
		j++;
	}
}
