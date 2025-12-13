/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:04:00 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:24:05 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    check_empty_string(char **argv)
{
    int n;
    int signal;
    int i;

    n = 1;
    while (argv[n])
    {
        if (!argv[n][0])
            error_signal();
        i = 0;
        signal = 0;
        while (argv[n][i])
        {
            if (argv[n][i] >= '0' && argv[n][i] <= '9')
                signal = 1;
            if (signal == 1)
                break ;
            i++;
            if (argv[n][i] == '\0')
                error_signal();
        }
        n++;
    }
}
