/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:39:39 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/03 01:03:13 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    *philo_routine(void  *arg)
{
    t_philo *philo;
 
    philo = (t_philo*)arg;

    if (philo->data->nb_philos == 1)
    {
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
        ft_usleep(philo->data->time_to_die);
        pthread_mutex_unlock(philo->left_fork);
        return (NULL);
    }

    if (philo->id % 2 == 0)
        ft_usleep(50);

    while (dead_verif(philo) == 0)
    {
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");

        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");

        pthread_mutex_lock(&philo->meal_lock);
        philo->last_meal_time = get_current_time();
        philo->meals_eaten++;
        pthread_mutex_unlock(&philo->meal_lock);

        print_status(philo, "is eating");
        ft_usleep(philo->data->time_to_eat);

        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);

        print_status(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep);
        print_status(philo, "is thinking");
    }
    return (NULL);
}
