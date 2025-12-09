/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:43:43 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/09 19:03:05 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_is_double(char **tmp)
{
    int i;
    int n;
    int j;
    char *stock;
    int count;

    count = 0;
    i = 0;
    n = 0;
    j = 0;
    while (tmp[i])
    {
        while (tmp[i][n])
            stock[j++] = tmp[i][n];
        while (tmp[i])
        {
            if (ft_strcmp(stock[j], tmp[i]) == 0)
                count++;
            if (count
        }
        i = 0;
    }
}
