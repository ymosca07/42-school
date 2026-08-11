/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:33:20 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 17:32:07 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../cub3D.h"

char **fill_data(char *file);
int	cub_extension(char *file);
int rgb_verif(t_config *config);
int  find(char *str, char **input, int *n);
int fill_input(t_config *config, char **input);
char **fill_map(t_config *config, char **input, int n);

#endif