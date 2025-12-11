/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:00:08 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 16:19:54 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_signal()
{
    write(2, "Error\n", 6);
    exit(1);
}

void    verif_double(long *stack, int count, int *error)
{
    int n;
    int i;

    i = 0;
    n = 0;
    while (i < count)
    {
        n = 0;
        count = 0;
        while(n < count)
        {
            if (stack[i] == stack[n])
                count++;
            if (count > 1)
                *error = -1;
            n++;
        }
        i++;
    }
}


void    verif_max_min(long *stack, int count, int *error)
{
    int n;

    n = 0;
    while (n < count)
    {
        if (stack[n] < INT_MIN || stack[n] > INT_MAX)
            *error = -1;
        n++;
    }
}

void    last_verif(long *stack, int *count)
{
    int error;
    
    error = 1;
    verif_double(stack, (*count), &error);
    if (error == -1)
        error_signal();
    verif_max_min(stack, (*count), &error);
    if (error == -1)
        error_signal();
    return ;
}
