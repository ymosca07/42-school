/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:07:40 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/07 11:30:23 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_tab(t_game *game)
{
	int		n;
	char	**map;

	map = game->map;
	n = -1;
	while (map[++n])
		free(map[n]);
	free(map);
}

void	free_struct(t_game *game)
{
	free_tab(game);
	free(game->window);
	free(game->mlx);
	free(game->img_collect);
	free(game->img_exit);
	free(game->img_player);
	free(game->img_nocol);
	free(game->img_wall);
	free(game->img_floor);
	free(game);
}
