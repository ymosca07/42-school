/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <flortie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:52:31 by flortie           #+#    #+#             */
/*   Updated: 2026/08/07 12:49:14 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_update_doors(t_render *data)
{
	int		y;
	int		x;
	double	dist;

	y = 0;
	while (y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
		{
			if (data->map[y][x] == TILE_DOOR)
			{
				dist = sqrt(pow(data->px - (x + 0.5), 2)
						+ pow(data->py - (y + 0.5), 2));
				if (dist < 2.5 && data->doors[y][x] < 1.0)
				{
					data->doors[y][x] += 0.03;
					if (data->doors[y][x] > 1.0)
						data->doors[y][x] = 1.0;
				}
				else if (dist >= 2.5 && data->doors[y][x] > 0.0)
				{
					data->doors[y][x] -= 0.03;
					if (data->doors[y][x] < 0.0)
						data->doors[y][x] = 0.0;
				}
			}
		}
		y++;
	}
}

void    ft_calculate_door_projection(t_render *data)
{
    int door_height;
    int unshifted_start;
    int shift;

    if (!data->ray.hit_door)
        return ;
    if (data->ray.perp_door_dist < 0.2)
        data->ray.perp_door_dist = 0.2;
    door_height = (int)(WIN_HEIGHT / data->ray.perp_door_dist);
    data->ray.door_line_height = door_height;
    
    unshifted_start = -door_height / 2 + WIN_HEIGHT / 2;

    shift = (int)(door_height
            * data->doors[data->ray.door_map_y][data->ray.door_map_x]);
    
    data->ray.door_draw_start = unshifted_start - shift;
    data->ray.door_draw_end = (door_height / 2 + WIN_HEIGHT / 2) - shift;

    if (data->ray.door_draw_start < unshifted_start)
        data->ray.door_draw_start = unshifted_start;

    if (data->ray.door_draw_start < 0)
        data->ray.door_draw_start = 0;
    if (data->ray.door_draw_end >= WIN_HEIGHT)
        data->ray.door_draw_end = WIN_HEIGHT - 1;
}

void	ft_free_doors(t_render *data)
{
	int	y;

	if (!data->doors)
		return ;
	y = 0;
	while (y < data->map_height)
	{
		if (data->doors[y])
			free(data->doors[y]);
		y++;
	}
	free(data->doors);
	data->doors = NULL;
}
