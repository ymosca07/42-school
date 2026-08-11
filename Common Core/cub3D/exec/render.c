/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:13:54 by flortie           #+#    #+#             */
/*   Updated: 2026/08/10 17:44:05 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	render_frame(t_render *data)
{
	ft_listen_keys(data);
	ft_update_doors(data);
	ft_raycasting_loop(data);
	ft_draw_crosshair(data);
	ft_draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img_ptr, 0, 0);
	return (1);
}

void	ft_mlx_game_init(t_render *data)
{
    data->mlx = mlx_init();
	if (!data->mlx)
		ft_error_exit("Error\nMLX initialization failed\n", data);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	ft_load_textures(data);
	data->screen.img_ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->screen.img_ptr)
		ft_error_exit("Error\nMain image creation failed", data);
    data->screen.addr = mlx_get_data_addr(data->screen.img_ptr, &data->screen.bpp, &data->screen.line_len, &data->screen.endian);
	ft_init_doors(data);
	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_mouse_hide(data->mlx, data->win);
	mlx_hook(data->win, 17, 0L, &ft_close_game, data); // croix
	mlx_hook(data->win, 2, 1L << 0, &ft_key_press, data); // keys
	mlx_hook(data->win, 3, 1L << 1, &ft_key_release, data); // keys
	mlx_hook(data->win, 6, (1L << 6) | (1L << 13), &mouse_move_handler, data); // mouse
	mlx_loop_hook(data->mlx, &render_frame, data);
	mlx_loop(data->mlx);
}
