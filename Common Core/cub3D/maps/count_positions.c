/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 13:50:51 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/07 13:58:01 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static int is_pos(char c, int *count)
{
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        (*count)++;
    return (1);
}

int count_positions(char **map)
{
    int n;
    int i;
    int count;

    count = 0;
    n = 0;
    i = 0;
    while (map[n])
    {
        i = 0;
        while (map[n][i])
        {
            is_pos(map[n][i], &count);
            i++;
        }
        n++;
    }
    if (count != 1)
        return (-1);
    return (0);
}
