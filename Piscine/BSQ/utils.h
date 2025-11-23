/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:50:11 by adarolla          #+#    #+#             */
/*   Updated: 2025/09/24 01:48:56 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "utils.c"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_strcat(char *dest, char *src);
int	ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char *s, char c);

#endif

