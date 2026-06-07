/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:56:19 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/07 19:38:09 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    ft_usleep(long time)
{
    long    start;
    long    remains;

    start = get_current_time();
    while (1)
    {
        remains = time - (get_current_time() - start);
        if (remains <= 0)
            break ;
        if (remains > 5)
            usleep(1000);
        else
            usleep(100);
    }
    
    // while ((get_current_time() - start) < time)
    //     usleep(1000);
}
