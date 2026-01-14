/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:46:48 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/07 12:43:49 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	aff_player(t_game *game, void *mlx, void *win)
{
	int	n;
	int	i;

	n = -1;
	while (game->map[++n])
	{
		i = -1;
		while (game->map[n][++i])
		{
			if (game->map[n][i] == 'P')
				mlx_put_image_to_window(mlx, win, game->img_player, i * 64, n
					* 64);
		}
	}
}

static void	aff_floor(t_game *game, void *mlx, void *win)
{
	int	n;
	int	i;

	n = -1;
	while (game->map[++n])
	{
		i = -1;
		while (game->map[n][++i])
		{
			if (game->map[n][i] == '0')
				mlx_put_image_to_window(mlx, win, game->img_floor, i * 64, n
					* 64);
		}
	}
}

static void	aff_wall(t_game *game, void *mlx, void *win)
{
	int	n;
	int	i;

	n = -1;
	while (game->map[++n])
	{
		i = -1;
		while (game->map[n][++i])
		{
			if (game->map[n][i] == '1')
				mlx_put_image_to_window(mlx, win, game->img_wall, i * 64, n
					* 64);
		}
	}
}

static void	aff_collectibles_and_exit(t_game *game, void *mlx, void *win)
{
	int	n;
	int	i;

	n = -1;
	while (game->map[++n])
	{
		i = -1;
		while (game->map[n][++i])
		{
			if (game->map[n][i] == 'C')
				mlx_put_image_to_window(mlx, win, game->img_collect, i * 64, n
					* 64);
			else if (game->map[n][i] == 'E')
				mlx_put_image_to_window(mlx, win, game->img_exit, i * 64, n
					* 64);
		}
	}
}

void	aff_sprites(t_game *game, void *mlx, void *win)
{
	aff_floor(game, mlx, win);
	aff_player(game, mlx, win);
	aff_wall(game, mlx, win);
	aff_collectibles_and_exit(game, mlx, win);
}
