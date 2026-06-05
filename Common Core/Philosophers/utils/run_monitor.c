/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 00:44:23 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/03 01:59:42 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    run_monitor(int argc, t_philo *philo)
{
    int i;
    int count;
    while (1)
    {
        i = 0;
        count = 0;
        while (i < philo->data->nb_philos)
        {
            pthread_mutex_lock(&philo[i].meal_lock);
            if ((get_current_time() - philo[i].last_meal_time) >= philo[i].data->time_to_die)
            {
                pthread_mutex_lock(&philo[i].data->write_lock);
                printf("%ld %d died\n", get_current_time(), philo[i].id);
                pthread_mutex_lock(&philo[i].data->dead_lock);
                philo[i].data->is_dead = 1;
                pthread_mutex_unlock(&philo[i].data->dead_lock);
                pthread_mutex_unlock(&philo[i].meal_lock);
                pthread_mutex_unlock(&philo[i].data->write_lock);
                return ;
            }
            if (argc == 6 && (philo[i].meals_eaten >= philo[i].data->must_eat_count))
                count++;
            pthread_mutex_unlock(&philo[i].meal_lock);
            i++;
        }
        if (count == philo[0].data->nb_philos)
        {
            pthread_mutex_lock(&philo[0].data->dead_lock);
            philo[0].data->is_dead = 1;
            pthread_mutex_unlock(&philo[0].data->dead_lock);
            return ;
        }
    }
}
