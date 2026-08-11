/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <flortie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:04:11 by flortie           #+#    #+#             */
/*   Updated: 2026/07/25 17:13:18 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_key_press(int key, t_render *data)
{
	if (key == KEY_ESC)
		ft_close_game(data);
	else if (key == KEY_W)
		data->k_w = 1;
	else if (key == KEY_S)
		data->k_s = 1;
	else if (key == KEY_A)
		data->k_a = 1;
	else if (key == KEY_D)
		data->k_d = 1;
	else if (key == KEY_LEFT)
		data->k_left = 1;
	else if (key == KEY_RIGHT)
		data->k_right = 1;
	return (0);
}

int	ft_key_release(int key, t_render *data)
{
	if (key == KEY_W)
		data->k_w = 0;
	else if (key == KEY_S)
		data->k_s = 0;
	else if (key == KEY_A)
		data->k_a = 0;
	else if (key == KEY_D)
		data->k_d = 0;
	else if (key == KEY_LEFT)
		data->k_left = 0;
	else if (key == KEY_RIGHT)
		data->k_right = 0;
	return (0);
}
