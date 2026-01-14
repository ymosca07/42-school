/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:29:47 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/14 16:58:53 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*load_xpm(void *mlx, char *path, int *signal)
{
	int		height;
	int		width;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &height, &width);
	if (!img)
	{
		*signal = 1;
		return (NULL);
	}
	return (img);
}

void	load_sprites(t_game *game, void *mlx, int *signal)
{
	game->img_collect = load_xpm(mlx, "./sprites/collectible.xpm", signal);
	game->img_exit = load_xpm(mlx, "./sprites/exit.xpm", signal);
	game->img_wall = load_xpm(mlx, "./sprites/wall.xpm", signal);
	game->img_floor = load_xpm(mlx, "./sprites/floor.xpm", signal);
	game->img_player = load_xpm(mlx, "./sprites/napolong.xpm", signal);
	game->img_nocol = load_xpm(mlx, "./sprites/nocol.xpm", signal);
}
