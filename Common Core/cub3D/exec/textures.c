/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:53:53 by flortie           #+#    #+#             */
/*   Updated: 2026/08/10 18:35:06 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_load_single_texture(t_render *data, t_img *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(data->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img_ptr)
		ft_error_exit("Error\nFailed to load XPM texture file\n", data);
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		ft_error_exit("Error\nFailed to get texture pixel address\n", data);
}

void	ft_load_textures(t_render *data)
{
	ft_load_single_texture(data, &data->tex_no, data->path_no);
	ft_load_single_texture(data, &data->tex_so, data->path_so);
	ft_load_single_texture(data, &data->tex_ea, data->path_ea);
	ft_load_single_texture(data, &data->tex_we, data->path_we);
	if (data->path_door)
		ft_load_single_texture(data, &data->tex_door, data->path_door);
}

void	ft_free_textures(t_render *data)
{
	if (data->tex_no.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_no.img_ptr);
	if (data->tex_so.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_so.img_ptr);
	if (data->tex_ea.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_ea.img_ptr);
	if (data->tex_we.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_we.img_ptr);
	if (data->tex_door.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_door.img_ptr);
}
