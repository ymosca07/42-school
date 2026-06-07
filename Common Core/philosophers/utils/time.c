/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:27:31 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/03 00:49:03 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long    get_current_time()
{
    long    res; 
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
        return (-1);

    res = ((time.tv_sec * 1000) + (time.tv_usec / 1000));

    return (res);
}
