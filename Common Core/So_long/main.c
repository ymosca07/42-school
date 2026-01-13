/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:04:38 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/13 21:04:45 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void check_group(t_game *game)
{
    map_len(game);
	check_stuff(game);
	wall_check(game);
	player_position(game);
}

static void load(t_game *game, void *mlx)
{
    int signal;

    signal = 0;
    load_sprites(game, mlx, &signal);
    if (signal == 1)
    {
        free_struct(game);
        error_signal("Error: image error\n");
    }
}

static void tmp_map(t_game *game)
{
	char **tmp_map;
	
	tmp_map = copy_map(game->map, game);
	flood_fill(game->player_y, game->player_x, 'F', tmp_map);
	end_possible(tmp_map);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_signal("Error: you must have 2 arguments\n");
	if (ber_extension(argv[1]) == 1)
		error_signal("Error: extension must be .ber\n");
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		error_signal("Error: allocation crash\n");
	read_map(argv[1], game);
	check_group(game);
	tmp_map(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_struct(game);
		error_signal("Error: mlx initialization\n");
	}
	game->window = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * 64, game->map_h * 64, "Napolong");
    load(game, game->mlx);
	aff_sprites(game, game->mlx, game->window);
	mlx_hook(game->window, 2, 1L << 0, inputs_keycode, game);
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
