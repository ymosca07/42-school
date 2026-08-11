/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:27:23 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/09 18:25:11 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

#include "../cub3D.h"

void double_tab(char **tab);
void all_free(char **input, t_config *config, t_map *map, t_player *player);
void all_free_error(char **input, t_config *config, t_map *map, t_player *player);

#endif