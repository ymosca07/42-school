/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signs_and_long_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:23:56 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 19:01:59 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    pos_sign_more(char *tmp)
{
    int i;
    
    i = 0;
    
    while (tmp[i])
    {
        if (tmp[i] == '+' && i != 0)
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        if (tmp[i] == '+' && ft_strlen(tmp) == 1)
            error_signal();
        i++;
    }
}

static void    pos_sign_less(char *tmp)
{
    int i;
    
    i = 0;
    
    while (tmp[i])
    {
        if (tmp[i] == '-' && i != 0)
        {
        
            write(2, "Error\n", 6);
            exit(1);
        }
        if (tmp[i] == '-' && ft_strlen(tmp) == 1)
            error_signal();
        i++;
    }
}

static void    verif_signs(char **tmp)
{
    int n;
    int i;

    i = 0;
    
    while (tmp[i])
    {
        n = 0;
        while (tmp[i][n])
        {
            if (tmp[i][n] == '+')
                pos_sign_more(tmp[i]);
            if (tmp[i][n] == '-')
                pos_sign_less(tmp[i]);
            n++;
        }
        i++;
    }
}

void long_max_signs(char **tmp)
{
    int n;

    n = 0;
    while (tmp[n])
    {
        if (ft_strlen(tmp[n]) > 12)
            error_signal();
        n++;
    }
    verif_signs(tmp);
}
