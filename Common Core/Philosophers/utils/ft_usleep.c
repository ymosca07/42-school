/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:56:19 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/03 00:48:47 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    ft_usleep(long time)
{
    long    start;

    start = get_current_time();
    while ((get_current_time() - start) < time)
        usleep(500);
}
