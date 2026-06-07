/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 02:09:02 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/07 20:47:55 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data  *fill_data(int argc, long *tab)
{
    t_data data;
    
    data.nb_philos = (int)tab[0];
    data.time_to_die = (int)tab[1];
    data.time_to_eat = (int)tab[2];
    data.time_to_sleep = (int)tab[3];
    data.is_dead = 0;
    if (argc == 6)
        data.must_eat_count = (int)tab[4];
    else
        data.must_eat_count = -1;

    return (data);
}
