/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 18:12:11 by flortie           #+#    #+#             */
/*   Updated: 2026/08/20 11:31:10 by flortie          ###   ########.fr       */
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

static t_img	*ft_select_texture(t_render *data, double *wall_x)
{
	t_img	*img;

	if (data->ray.side == 0)
	{
		if (data->ray.ray_dir_x > 0)
			img = &data->tex_ea;
		else
			img = &data->tex_we;
		*wall_x = data->py + data->ray.perp_wall_dist * data->ray.ray_dir_y;
	}
	else
	{
		if (data->ray.ray_dir_y > 0)
			img = &data->tex_so;
		else
			img = &data->tex_no;
		*wall_x = data->px + data->ray.perp_wall_dist * data->ray.ray_dir_x;
	}
	*wall_x -= floor(*wall_x);
	return (img);
}

static void	ft_init_tex(t_render *data, t_tex *tex)
{
	double	wall_x;

	tex->img = ft_select_texture(data, &wall_x);
	tex->x = (int)(wall_x * tex->img->width);
	if ((data->ray.side == 0 && data->ray.ray_dir_x > 0)
		|| (data->ray.side == 1 && data->ray.ray_dir_y < 0))
		tex->x = tex->img->width - tex->x - 1;
	if (tex->x < 0)
		tex->x = 0;
	if (tex->x >= tex->img->width)
		tex->x = tex->img->width - 1;
	tex->step = (double)tex->img->height / (double)data->ray.line_height;
	tex->pos = (data->ray.draw_start - WIN_HEIGHT / 2.0
			+ data->ray.line_height / 2.0) * tex->step;
}

static int	ft_tex_color(t_tex *tex)
{
	char	*pixel;
	int		y;

	y = (int)tex->pos;
	if (y < 0)
		y = 0;
	if (y >= tex->img->height)
		y = tex->img->height - 1;
	pixel = tex->img->addr + (y * tex->img->line_len
			+ tex->x * (tex->img->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	ft_draw_column(t_render *data, int x)
{
	t_tex	tex;
	int		y;
	int		color;

	ft_init_tex(data, &tex);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		color = data->sky_color;
		if (y > data->ray.draw_end)
			color = data->floor_color;
		if (y >= data->ray.draw_start && y <= data->ray.draw_end)
		{
			color = ft_tex_color(&tex);
			tex.pos += tex.step;
		}
		if (data->ray.hit_door && y >= data->ray.door_draw_start
			&& y <= data->ray.door_draw_end)
			color = 0xFFFFFF;
		ft_put_pixel(&data->screen, x, y, color);
		y++;
	}
}
