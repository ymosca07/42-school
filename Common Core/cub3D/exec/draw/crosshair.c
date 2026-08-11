/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <flortie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:03:43 by flortie           #+#    #+#             */
/*   Updated: 2026/07/30 17:04:25 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_draw_crosshair(t_render *data)
{
	int	center_x;
	int	center_y;
	int	size;
	int	i;

	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	size = 5;
	i = -size;
	while (i <= size && (CROSSHAIR_ON == 1))
	{
		ft_put_pixel(&data->screen, center_x + i, center_y, 0x00FF00);
		ft_put_pixel(&data->screen, center_x, center_y + i, 0x00FF00);
		i++;
	}
}
