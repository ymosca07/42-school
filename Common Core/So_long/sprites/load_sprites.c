/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:29:47 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/07 12:39:52 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    load_sprites(t_game *game, void *mlx, int *signal)
{
    int width;
    int height;
    
    game->img_collect = mlx_xpm_file_to_image(mlx, "./sprites/collectible.xpm", &width, &height);
    if (!game->img_collect)
        *signal = 1;
    game->img_exit = mlx_xpm_file_to_image(mlx, "./sprites/exit.xpm", &width, &height);
    if (!game->img_exit)
        *signal = 1;
    game->img_wall = mlx_xpm_file_to_image(mlx, "./sprites/wall.xpm", &width, &height);
    if (!game->img_wall)
        *signal = 1;
    game->img_floor = mlx_xpm_file_to_image(mlx, "./sprites/floor.xpm", &width, &height);
    if (!game->img_floor)
        *signal = 1;
    game->img_player = mlx_xpm_file_to_image(mlx, "./sprites/napolong.xpm", &width, &height);
    if (!game->img_player)
        *signal = 1;
    game->img_nocol = mlx_xpm_file_to_image(game->mlx, "./sprites/nocol.xpm", &width, &height);
    if (!game->img_nocol)
        *signal = 1;
}
