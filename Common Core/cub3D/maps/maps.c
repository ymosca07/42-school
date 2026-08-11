/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:18:38 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/09 18:20:18 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

int maps(t_config *config, t_player *data, t_map *map)
{   
    if (authorize_char(config->map) == -1)
        return (-1);
    if (count_positions(config->map) == -1)
        return (-1);
    if (player_struct(data, config->map) == -1)
        return (-1);
    config->map = conform_map(config->map);
    if (!config->map)
        return (-1);
    if (neighbor(config->map, map) == -1)
        return (-1);
    return (0);
}
