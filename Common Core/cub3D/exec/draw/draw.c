/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 18:12:11 by flortie           #+#    #+#             */
/*   Updated: 2026/08/11 18:24:49 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;
	
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_column(t_render *data, int x)
{
	int y;
	t_img *current;
	
	int tex_x;
	double tex_pos;
	double wall_x;
	double step;
	int tex_y;
	int color;

	y = 0;
	if (data->ray.side == 0)
	{
		if (data->ray.ray_dir_x > 0)
			current = &data->tex_we;
		else
			current = &data->tex_ea;
		wall_x = data->py + (data->ray.perp_wall_dist * data->ray.ray_dir_y);
	}
	else
	{
		if (data->ray.ray_dir_y > 0)
			current = &data->tex_no;
		else
			current = &data->tex_so;
		wall_x = data->px + (data->ray.perp_wall_dist * data->ray.ray_dir_x);
	}
	wall_x -= (int)wall_x;
	tex_x = wall_x * current->width;
	if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
		tex_x = current->width - tex_x - 1;
	else if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
		tex_x = current->width - tex_x - 1;
	step = 1.0 * current->height / data->ray.line_height;
	tex_pos = step * (data->ray.draw_start - WIN_HEIGHT / 2 + data->ray.line_height / 2);
	
	while (y < (WIN_HEIGHT))
	{
		if (data->ray.hit_door
			&& y >= data->ray.door_draw_start
			&& y <= data->ray.door_draw_end)
			ft_put_pixel(&data->screen, x, y, 0xFFFFFF);
		else if (y >= data->ray.draw_start && y <= data->ray.draw_end)
		{
			tex_y = (int)tex_pos & (current->height - 1);
			tex_pos += step;
			color = *(unsigned int *)(current->addr + (tex_y * current->line_len + tex_x * (current->bpp / 8)));
			ft_put_pixel(&data->screen, x, y, color);
		}
		else if (y < WIN_HEIGHT / 2)
			ft_put_pixel(&data->screen, x, y, data->sky_color);
		else
			ft_put_pixel(&data->screen, x, y, data->floor_color);
		y++;
	}
}
