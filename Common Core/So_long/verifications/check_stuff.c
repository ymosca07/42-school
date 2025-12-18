/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:20:26 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/18 15:59:49 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void check_count(int c, int e, int p)
{
    if (c == 0)
        error_signal("Error: ");
    if (e != 1)
        error_signal("Error: ");
    if (p != 1)
        error_signal("Error: ");
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
    check_count(c, e, p);
}
