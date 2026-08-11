/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:53:44 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/09 18:20:12 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

#include "../cub3D.h"

char    **conform_map(char **old);
int     authorize_char(char **map);
int     count_positions(char **map);
int     neighbor(char **map, t_map *ptr);
int     player_struct(t_player *data, char **map);
int maps(t_config *config, t_player *data, t_map *map);

#endif