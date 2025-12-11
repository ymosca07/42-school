/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_signs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:23:56 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/10 17:58:37 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pos_sign_more(char *tmp)
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
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
}

void    pos_sign_less(char *tmp)
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
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
}

void    verif_signs(char **tmp)
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
