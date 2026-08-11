/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <flortie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:48:43 by flortie           #+#    #+#             */
/*   Updated: 2026/08/06 15:24:21 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_put_pixel_mm(t_render *data, int x, int y, int color)
{
	char	*dst;
	
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->screen.addr + (y * data->screen.line_len + x * (data->screen.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	ft_draw_tile(t_render *data, int map_x, int map_y, int color)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	start_x = MM_OFF_X + (map_x * MM_SCALE);
	start_y = MM_OFF_Y + (map_y * MM_SCALE);
	i = 0;
	while (i < MM_SCALE)
	{
		j = 0;
		while (j < MM_SCALE)
		{
			ft_put_pixel_mm(data, start_x + j, start_y + i, color);
			j++;
		}
		i++;
	}
}

static void	ft_draw_player_mm(t_render *data)
{
	int	center_x;
	int	center_y;
	int	i;
	int	j;

	center_x = MM_OFF_X + (int)(data->px * MM_SCALE);
	center_y = MM_OFF_Y + (int)(data->py * MM_SCALE);
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			ft_put_pixel_mm(data, center_x + j, center_y + i, 0x00FF00);
			j++;
		}
		i++;
	}
}

void	ft_draw_minimap(t_render *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width && data->map[y][x])
		{
			if (data->map[y][x] == '1')
				ft_draw_tile(data, x, y, MM_COLOR_WALL);
			else if (data->map[y][x] == TILE_DOOR)
				ft_draw_tile(data, x, y, MM_COLOR_PLAYER);
			else if (data->map[y][x] != ' ' && data->map[y][x] != '\0')
				ft_draw_tile(data, x, y, MM_COLOR_FLOOR);
			x++;
		}
		y++;
	}
	ft_draw_player_mm(data);
}
