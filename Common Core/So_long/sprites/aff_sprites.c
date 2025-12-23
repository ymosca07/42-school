/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:46:48 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/22 17:51:45 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void aff_player(t_game *game, void *mlx, void *win)
{
    int n;
    int i;
    int width;
    int height;
    
    n = -1;
    game->img_player = mlx_xpm_file_to_image(mlx, "./sprites/napolong.xpm", &width, &height);
    if (!game->img_player)
    {
        write(2, "Error: phemin incorrect\n", 52);
        exit(1);
    }
    while (game->map[++n])
    {
        i = -1;
        while (game->map[n][++i])
        {
            if (game->map[n][i] == 'P')
                mlx_put_image_to_window(mlx, win, game->img_player, i * 64, n * 64);
        }
    }
}

static void aff_floor(t_game *game, void *mlx, void *win)
{
    int n;
    int i;
    int width;
    int height;
    
    n = -1;
    game->img_floor = mlx_xpm_file_to_image(mlx, "./sprites/floor.xpm", &width, &height);
    if (!game->img_floor)
    {
        write(2, "Error: sprite floor introuvable ou chemin incorrect\n", 52);
        exit(1);
    }
    while (game->map[++n])
    {
        i = -1;
        while (game->map[n][++i])
        {
            if (game->map[n][i] == '0')
                mlx_put_image_to_window(mlx, win, game->img_floor, i * 64, n * 64);
        }
    }
}

static void aff_wall(t_game *game, void *mlx, void *win)
{
    int n;
    int i;
    int width;
    int height;
    
    n = -1;
    game->img_wall = mlx_xpm_file_to_image(mlx, "./sprites/wall.xpm", &width, &height);
    if (!game->img_wall)
        error_signal("Wall's error");
    while (game->map[++n])
    {
        i = -1;
        while (game->map[n][++i])
        {
            if (game->map[n][i] == '1')
                mlx_put_image_to_window(mlx, win, game->img_wall, i * 64, n * 64);
        }
    }
}

static void aff_collectibles_and_exit(t_game *game, void *mlx, void *win)
{
    int n;
    int i;
    int width;
    int height;
    
    n = -1;
    game->img_collect = mlx_xpm_file_to_image(mlx, "./sprites/collectible.xpm", &width, &height);
    if (!game->img_collect)
        error_signal("Collectible's error");
    game->img_exit = mlx_xpm_file_to_image(mlx, "./sprites/exit.xpm", &width, &height);
        if (!game->img_exit)
        error_signal("Exit's error");
    while (game->map[++n])
    {
        i = -1;
        while (game->map[n][++i])
        {
            if (game->map[n][i] == 'C')
                mlx_put_image_to_window(mlx, win, game->img_collect, i * 64, n * 64);
            else if (game->map[n][i] == 'E')
                mlx_put_image_to_window(mlx, win, game->img_exit, i * 64, n * 64);
        }
    }
}

void    aff_sprites(t_game *game, void *mlx, void *win)
{
    aff_floor(game, mlx, win);
    aff_player(game, mlx, win);
    aff_wall(game, mlx, win);
    aff_collectibles_and_exit(game, mlx, win);
}