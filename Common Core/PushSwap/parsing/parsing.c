/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:20:35 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 16:16:37 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long *parsing(char **argv, int *count)
{
    char *str = NULL;
    long *stack = NULL;
    char **tmp = NULL;
    int n;

    n = 0;
    str = init_split_stack(argv);
    tmp = ft_split(str, ' ');
    free(str);
    verif_signs(tmp);
    while (tmp[*count])
        (*count)++;
    stack = malloc(sizeof(long) * (*count));
    if (!stack)
        return (NULL);
    while (tmp[n])
    {
        stack[n] = ft_atol(tmp[n]);
        free(tmp[n]);
        n++;
    }
    last_verif(stack, count);
    return (stack);
}
