/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:07:59 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/20 09:08:02 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int		ft_str_is_numeric(char *str);
int		ft_str_is_alpha(char *str);
int		ft_puterror(char *str);
int		ft_putstr(char *str);
int		ftstrlen(char *str);

void	ft_sort_int_tab(int *tab, int size);

int		ft_existe_file(char *name);
char	*ft_file_to_str(const char *name);

typedef struct s_stock_str
{
	char	*key;
	char	*value;
}	t_stock_str;

#endif
