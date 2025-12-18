/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:02:05 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/18 16:07:20 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    player_position(t_game *game)
{
    int i;
    int n;

    n = -1;
    while (game->map[++n])
    {
        i = -1;
        while (game->map[n][++i])
        {
            if (game->map[n][i] == 'P')
            {
                game->player_y = n;
                game->player_x = i;
                return ;
            }
        }
    }
}
