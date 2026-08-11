/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <flortie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:25:48 by flortie           #+#    #+#             */
/*   Updated: 2026/08/06 18:12:57 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_init_doors(t_render *data)
{
	int	y;

	data->doors = malloc(sizeof(double *) * data->map_height);
	if (!data->doors)
		return ;
	y = 0;
	while (y < data->map_height)
	{
		data->doors[y] = ft_calloc(data->map_width, sizeof(double));
		y++;
	}
}

void	ft_init_doors_stats(t_render *data)
{
	if (data->map[data->ray.map_y][data->ray.map_x] == TILE_DOOR
		&& !data->ray.hit_door)
	{
		data->ray.hit_door = 1;
		data->ray.door_map_x = data->ray.map_x;
		data->ray.door_map_y = data->ray.map_y;
		data->ray.perp_door_dist = 0.2;
	}
}
