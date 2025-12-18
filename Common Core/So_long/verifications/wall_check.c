/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:09:06 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/18 14:34:46 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void first_line(t_game *game)
{
    int i;

    i = 0;
    while (game->map[0][i])
    {
        if (game->map[0][i] != '1')
            error_signal("Error: the map must be surrounded by walls");
        i++;
    }
}

static void first_char(t_game *game)
{
    int n;

    n = 0;
    while (game->map[n])
    {
        if (game->map[n][0] != '1')
            error_signal("Error: the map must be surrounded by walls");
        n++;
    }
}

static void last_char(t_game *game)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (game->map[n])
    {
        i = 0;
        while (game->map[n][i])
        {
            if (game->map[n][ft_strlen(game->map[n]) - 1] != '1')
                error_signal("Error: the map must be surrounded by walls");
            i++;
        }
        n++;
    }
}

static void last_line(t_game *game)
{
    int i;
    int n;

    n = game->map_h - 1;
    i = 0;
    while (game->map[n][i])
    {
        if (game->map[n][i] != '1')
            error_signal("Error: the map must be surrounded by walls");
        i++;
    }
}

void    wall_check(t_game *game)
{
    first_line(game);
    last_line(game);
    first_char(game);
    last_char(game);
}
