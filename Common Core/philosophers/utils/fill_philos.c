/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:15:33 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/07 20:17:05 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void fill_philos(t_data data, t_philo *philo)
{
    int j;
    
    j = 0;
    
    while (j < data.nb_philos)
    {
        philo[j].id = j + 1;
        philo[j].data = &data;
        philo[j].left_fork = &data.forks[j];
        philo[j].right_fork = &data.forks[(j + 1) % data.nb_philos];
        philo[j].last_meal_time = get_current_time();
        philo[j].meals_eaten = 0;
        pthread_mutex_init(&philo[j].meal_lock, NULL);
        j++;
    }
}
