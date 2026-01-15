/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:04:38 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/15 17:48:51 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_group(t_game *game)
{
	map_len(game);
	check_stuff(game);
	wall_check(game);
	player_position(game);
}

static void	load(t_game *game, void *mlx)
{
	int	signal;

	signal = 0;
	load_sprites(game, mlx, &signal);
	if (signal == 1)
	{
		free_struct(game);
		error_signal("Error\nImage error");
	}
}

static void	tmp_map(t_game *game)
{
	char	**tmp_map;
	int		signal;

	tmp_map = copy_map(game->map, game);
	if (!tmp_map)
	{
		free_struct(game);
		error_signal("Error\nMemory allocation");
	}
	flood_fill(game->player_y, game->player_x, 'F', tmp_map);
	signal = end_possible(tmp_map);
	if (signal == 1)
	{
		free_all(tmp_map);
		free_struct(game);
		error_signal("Error\nInvalid path");
	}
}

static void	mlx_action(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, inputs_keycode, game);
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_signal("Error\nYou must have 2 arguments");
	if (ber_extension(argv[1]) == 1)
		error_signal("Error\nExtension must be .ber");
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		error_signal("Error\nAllocation crash");
	read_map(argv[1], game);
	check_group(game);
	tmp_map(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_struct(game);
		error_signal("Error\nMlx initialization");
	}
	game->window = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * 64,
			game->map_h * 64, "Napolong");
	load(game, game->mlx);
	aff_sprites(game, game->mlx, game->window);
	mlx_action(game);
	return (0);
}
