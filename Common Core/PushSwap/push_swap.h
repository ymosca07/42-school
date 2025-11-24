/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:16:59 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/24 17:45:27 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int ft_is_in(char **input);
char *init_split_stack(char **input);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int ft_count_len(char **input);
long	ft_atol(const char *str);

typedef struct s_list
{
    long value;
    struct s_list *next;
} t_list;

#endif
