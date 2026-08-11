/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <flortie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 18:02:26 by flortie           #+#    #+#             */
/*   Updated: 2026/08/06 18:09:57 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_init_ray(t_render *data, int x)
{
	data->ray.camera_x = 2 * x / (double)WIN_WIDTH - 1; // -1 a 1
	data->ray.ray_dir_x = data->dir_x + data->orientation_x * data->ray.camera_x;
	data->ray.ray_dir_y = data->dir_y + data->orientation_y * data->ray.camera_x;
	data->ray.map_x = (int)data->px;
	data->ray.map_y = (int)data->py;
	data->ray.hit_door = 0;
	if (data->ray.ray_dir_x == 0)
		data->ray.delta_dist_x = 1e30;
	else
		data->ray.delta_dist_x = fabs(1 / data->ray.ray_dir_x);
	if (data->ray.ray_dir_y == 0)
		data->ray.delta_dist_y = 1e30;
	else
		data->ray.delta_dist_y = fabs(1 / data->ray.ray_dir_y);
}

static void	ft_init_dda(t_render *data)
{
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->px - data->ray.map_x) * data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->px) * data->ray.delta_dist_x;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->py - data->ray.map_y) * data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->py) * data->ray.delta_dist_y;
	}
}

static void	ft_exec_dda(t_render *data)
{
	data->ray.hit = 0;
	ft_init_doors_stats(data);
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map[data->ray.map_y][data->ray.map_x] == '1')
			data->ray.hit = 1;
		else if (data->map[data->ray.map_y][data->ray.map_x] == TILE_DOOR
			&& !data->ray.hit_door)
		{
			data->ray.hit_door = 1;
			data->ray.door_map_x = data->ray.map_x;
			data->ray.door_map_y = data->ray.map_y;
			if (data->ray.side == 0)
				data->ray.perp_door_dist = data->ray.side_dist_x - data->ray.delta_dist_x;
			else
				data->ray.perp_door_dist = data->ray.side_dist_y - data->ray.delta_dist_y;
		}
	}
}

static void	ft_calculate_wall(t_render *data)
{
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = data->ray.side_dist_x
			- data->ray.delta_dist_x;
	else
		data->ray.perp_wall_dist = data->ray.side_dist_y
			- data->ray.delta_dist_y;
	if (data->ray.perp_wall_dist < 0.2)
		data->ray.perp_wall_dist = 0.2;
	data->ray.line_height = (int)(WIN_HEIGHT / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + WIN_HEIGHT / 2;
	data->ray.draw_end = data->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	if (data->ray.draw_end >= WIN_HEIGHT)
		data->ray.draw_end = WIN_HEIGHT - 1;
	ft_calculate_door_projection(data);
}

void	ft_raycasting_loop(t_render *data)
{
	int	x;
	
	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_init_ray(data, x);
		ft_init_dda(data);
		ft_exec_dda(data);
		ft_calculate_wall(data);
		ft_draw_column(data, x);
		x++;
	}
}
