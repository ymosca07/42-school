/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <flortie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:58:28 by flortie           #+#    #+#             */
/*   Updated: 2026/07/30 16:58:04 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	ft_destroy_images(t_render *data)
{
	if (data->screen.img_ptr)
		mlx_destroy_image(data->mlx, data->screen.img_ptr);
	if (data->tex_north.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_north.img_ptr);
	if (data->tex_south.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_south.img_ptr);
	if (data->tex_west.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_west.img_ptr);
	if (data->tex_east.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_east.img_ptr);
	if (data->tex_door.img_ptr)
		mlx_destroy_image(data->mlx, data->tex_door.img_ptr);
}

static void	ft_free_paths(t_render *data)
{
	if (data->path_no)
		free(data->path_no);
	if (data->path_so)
		free(data->path_so);
	if (data->path_ea)
		free(data->path_ea);
	if (data->path_we)
		free(data->path_we);
	if (data->path_door)
		free(data->path_door);
}

int	ft_close_game(t_render *data)
{
	if (!data)
		exit(0);
	ft_destroy_images(data);
	if (data->sprites)
		free(data->sprites);
	if (data->map)
		ft_free_map(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_paths(data);
	exit(0);
	return (0);
}

void ft_error_exit(char *text, t_render *data)
{
	printf("%s\n", text);	
	ft_close_game(data);
	exit(1);
}
