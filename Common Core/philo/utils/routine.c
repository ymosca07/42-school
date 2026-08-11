/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:39:39 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 22:02:55 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	one_philo_case(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_status(philo, "has taken a fork");
	ft_usleep(philo->data->time_to_die);
	pthread_mutex_unlock(philo->first_fork);
}

static void	impair_thinking_case(t_data *data)
{
	long	remains;

	if (data->nb_philos % 2 == 0)
		return ;
	else
	{
		remains = data->time_to_die - data->time_to_eat - data->time_to_sleep;
		if (remains <= 1)
			ft_usleep(1);
		else
			ft_usleep(remains / 2);
	}
}

static void	routine_content(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->second_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	print_status(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->second_fork);
	pthread_mutex_unlock(philo->first_fork);
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	print_status(philo, "is thinking");
	impair_thinking_case(philo->data);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philos == 1)
	{
		one_philo_case(philo);
		return (NULL);
	}
	while (dead_verif(philo) == 0)
		routine_content(philo);
	return (NULL);
}
