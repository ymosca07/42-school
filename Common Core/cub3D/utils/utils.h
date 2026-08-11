/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:26:01 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 16:36:31 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "../cub3D.h"

#include <stddef.h>

int	            ft_atoi(const char *str);
unsigned int	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	        **ft_split(char const *s, char c);
char	        *ft_substr(char const *s, unsigned int start, size_t len);

#endif