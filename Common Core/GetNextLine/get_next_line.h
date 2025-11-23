/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:53:02 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/09 17:56:57 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
int		ft_is_in(char *stock);
int		ft_strlen(const char *str);
int		ft_strlcpy(char *dest, const char *src, int size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *str);
char	*read_file(int fd, int byte, char *buffer, char *stock);
char	*stock_line(char *stock, char *buffer);
char	*result_line(char *stock);
char	*trim_line(char *stock);

#endif
