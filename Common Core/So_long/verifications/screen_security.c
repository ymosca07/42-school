/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_security.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:33:26 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/07 13:08:20 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    screen_security(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    mlx_get_screen_size(game->mlx, &x, &y);
    if (game->map_h * 64 > x || ft_strlen(game->map[0]) * 64 > y)
    {
        free_struct(game);
        error_signal("Error: the map is larger than the window\n");
    }
    game->window = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * 64,
            game->map_h * 64, "Napolong");
}
    