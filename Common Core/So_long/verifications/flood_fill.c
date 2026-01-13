/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:15:37 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/18 17:21:05 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    flood_fill(int y, int x, char f, char **map)
{
    if (map[y][x] == '1' || map[y][x] == f)
        return ;
    
    map[y][x] = f;

    flood_fill(y - 1, x, f, map);
    flood_fill(y + 1, x, f, map);
    flood_fill(y, x - 1, f, map);
    flood_fill(y, x + 1, f, map);
}
