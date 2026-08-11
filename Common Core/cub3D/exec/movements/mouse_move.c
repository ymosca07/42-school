/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <flortie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:48:48 by flortie           #+#    #+#             */
/*   Updated: 2026/07/25 17:02:48 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	mouse_move_handler(int x, int y, t_render *data)
{
	int	delta_x;

	(void)y;
	if (!data->win)
		return (0);
	delta_x = x - (WIN_WIDTH / 2);
	if (delta_x != 0)
	{
		ft_rotate_player(data, delta_x * MOUSE_SENSITIVITY);
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	return (0);
}
