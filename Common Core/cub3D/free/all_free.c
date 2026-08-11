/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:24:49 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/09 18:50:01 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void all_free(char **input, t_config *config, t_map *map, t_player *player)
{
        if (input)
                double_tab(input);
        if (map)
                free(map);
        if (config->map)
                double_tab(config->map);
        if (config)
                free(config);
        if (player)
                free(player);
        exit (1);
}