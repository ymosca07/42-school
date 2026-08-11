/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:53:02 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 16:34:18 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../utils/utils.h"

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_strdup(char *str);
int		ft_is_in(char *stock);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlcpy(char *dest, const char *src, int size);

#endif
