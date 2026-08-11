/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:18:02 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/09 16:50:43 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static void calcul_mesure(char **map, t_map *ptr)
{
    int i;
    int n;

    n = 0;
    while (map[n])
    {
        i = 0;
        while (map[n][i])
            i++;
        n++;
    }
    ptr->height = n;
    ptr->width = i;
}

static void is_border(int n, int i, int *x, t_map *ptr)
{
    if (n == 0 || i == 0)
        *x = -1;
    if (n == ptr->height - 1 || i == ptr->width - 1)
        *x = -1;
}

static void is_neighbor(char **map, int n, int i, int *x)
{
    if (map[n + 1][i] == ' ')
        *x = -1;
    if (map[n - 1][i] == ' ')
        *x = -1;
    if (map[n][i + 1] == ' ')
        *x = -1;
    if (map[n][i - 1] == ' ')
        *x = -1;
}


int neighbor(char **map, t_map *ptr)
{
    int n;
    int i;
    int x;
    
    n = -1;
    i = 0;
    x = 0;
    calcul_mesure(map, ptr);
    while (map[++n])
    {
        i = -1;
        while (map[n][++i])
        {
            if (map[n][i] != '1' && map[n][i] != ' ')
            {
                is_border(n, i, &x, ptr);
                is_neighbor(map, n, i, &x);
                if (x == -1)
                    return (-1);
            }
        }
    }
    return (0);
}
