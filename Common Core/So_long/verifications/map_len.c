/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:10:57 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/17 17:28:11 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_len(t_game *game)
{
    int j;
    char *current;
    
    j = 1;
    current = game->map[0];
    while (game->map[j])
    {
        if (ft_strlen(current) != ft_strlen(game->map[j]))
        {
            free(game);
            error_signal("Error: bad map's size");
        }
        j++;
    }
}