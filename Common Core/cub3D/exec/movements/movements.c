/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <flortie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:48:52 by flortie           #+#    #+#             */
/*   Updated: 2026/07/25 18:31:46 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

//rotation vectorielle
void	ft_rotate_player(t_render *data, double angle)
{
	double	old_dir_x;
	double	old_orientation_x;

	old_dir_x = data->dir_x;
	old_orientation_x = data->orientation_x;
	
	data->dir_x = data->dir_x * cos(angle) - data->dir_y * sin(angle);
	data->dir_y = old_dir_x * sin(angle) + data->dir_y * cos(angle);
	data->orientation_x = data->orientation_x * cos(angle) - data->orientation_y * sin(angle);
	data->orientation_y = old_orientation_x * sin(angle) + data->orientation_y * cos(angle);
}

static int	is_wall(t_render *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= data->map_width
		|| map_y < 0 || map_y >= data->map_height)
		return (1);
	if (data->map[map_y] && data->map[map_y][map_x] == '1')
		return (1);
	if (data->map[map_y][map_x] == TILE_DOOR
		&& data->doors[map_y][map_x] < 0.75)
		return (0);
	return (0);
}

static void	apply_move(t_render *data, double move_x, double move_y)
{
	double	margin_x;
	double	margin_y;

	margin_x = COLL_PLAYER_DIST;
	if (move_x < 0)
		margin_x = -COLL_PLAYER_DIST;
	margin_y = COLL_PLAYER_DIST;
	if (move_y < 0)
		margin_y = -COLL_PLAYER_DIST;
	if (!is_wall(data, data->px + move_x + margin_x, data->py))
		data->px += move_x;
	if (!is_wall(data, data->px, data->py + move_y + margin_y))
		data->py += move_y;
}

void	ft_listen_keys(t_render *data)
{
	if (data->k_w)
		apply_move(data, data->dir_x * MOVE_SPEED,
			data->dir_y * MOVE_SPEED);
	if (data->k_s)
		apply_move(data, -data->dir_x * MOVE_SPEED,
			-data->dir_y * MOVE_SPEED);
	if (data->k_a)
		apply_move(data, data->dir_y * MOVE_SPEED,
			-data->dir_x * MOVE_SPEED);
	if (data->k_d)
		apply_move(data, -data->dir_y * MOVE_SPEED,
			data->dir_x * MOVE_SPEED);
	if (data->k_left)
		ft_rotate_player(data, -ROT_SPEED);
	if (data->k_right)
		ft_rotate_player(data, ROT_SPEED);
}
