/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:42:05 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/09 12:48:47 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static int is_pos(char c)
{
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (0);
    return (1);
}

int player_struct(t_player *data, char **map)
{
    int n;
    int i;

    n = 0;
    i = 0;
    while (map[n])
    {
        i = 0;
        while (map[n][i])
        {
            if (is_pos(map[n][i]) == 0)
            {
                data->position = map[n][i];
                data->y = n;
                data->x = i;
                return (0);
            }
            i++;
        }
        n++;
    }
    return (-1);
}
