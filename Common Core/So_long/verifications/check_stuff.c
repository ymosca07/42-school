/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:20:26 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/07 13:07:58 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void check_count(int c, int e, int p, t_game *game)
{
    if (c == 0 || e != 1 || p != 1)
    {
        free_struct(game);
        error_signal("Error: incorrect map initialization\n");
    }
    game->collectibles = c;
}

static void valid_char_check(t_game *game)
{
    int n;
    int i;

    n = -1;
    while (game->map[++n])
    {
        i = -1;
        while (game->map[n][++i])
        {
            if (!(game->map[n][i] == 'C' || game->map[n][i] == '0' 
                || game->map[n][i] == '1' || game->map[n][i] == 'E' 
                || game->map[n][i] == 'P'))
            {
                free_struct(game);
                error_signal("Error: Forbidden char\n");
            }
        }
    }
}

void    check_stuff(t_game *game)
{
    int i;
    int n;
    int c;
    int p;
    int e;

    n = -1;
    c = 0;
    e = 0;
    p = 0;
    while (game->map[++n])
    {
        i = -1;
        while (game->map[n][++i])
        {
            if (game->map[n][i] == 'C')
                c++;
            else if (game->map[n][i] == 'P')
                p++;
            else if (game->map[n][i] == 'E')
                e++;
        }
    }
    valid_char_check(game);
    check_count(c, e, p, game);
}
