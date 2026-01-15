/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:36:24 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/15 16:49:30 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_game(t_game *game)
{
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_nocol)
		mlx_destroy_image(game->mlx, game->img_nocol);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_all(game->map);
	free(game);
	exit(0);
}

static int	exit_case(int y, int x, t_game *game)
{
	if (game->collectibles == 0)
		close_game(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img_nocol, x * 64, y
		* 64);
	game->steps++;
	ft_printf("Step's counter: %d\n", game->steps);
	game->map[game->player_y][game->player_x] = '0';
	mlx_put_image_to_window(game->mlx, game->window, game->img_floor,
		game->player_x * 64, game->player_y * 64);
	game->player_y = y;
	game->player_x = x;
	game->map[game->player_y][game->player_x] = 'P';
	return (1);
}

static void	after_exit(int y, int x, int *signal, t_game *game)
{
	game->map[game->player_y][game->player_x] = 'E';
	game->player_y = y;
	game->player_x = x;
	game->map[game->player_y][game->player_x] = 'P';
	*signal = 0;
	aff_sprites(game, game->mlx, game->window);
}

static void	move_player(int y, int x, t_game *game)
{
	static int	signal;

	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->collectibles--;
		game->map[y][x] = '0';
	}
	if (game->map[y][x] == 'E')
	{
		signal = exit_case(y, x, game);
		return ;
	}
	ft_printf("Step's counter: %d\n", ++game->steps);
	if (signal == 1)
	{
		after_exit(y, x, &signal, game);
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_y = y;
	game->player_x = x;
	game->map[game->player_y][game->player_x] = 'P';
	aff_sprites(game, game->mlx, game->window);
}

int	inputs_keycode(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 97)
		move_player(game->player_y, game->player_x - 1, game);
	if (keycode == 115)
		move_player(game->player_y + 1, game->player_x, game);
	if (keycode == 119)
		move_player(game->player_y - 1, game->player_x, game);
	if (keycode == 100)
		move_player(game->player_y, game->player_x + 1, game);
	return (0);
}
