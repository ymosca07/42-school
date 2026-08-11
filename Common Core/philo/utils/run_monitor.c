/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 00:44:23 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:13:32 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	case_must_eat(t_philo *philo, int count)
{
	int	signal;

	signal = 0;
	if (count == philo[0].data->nb_philos)
	{
		signal = 1;
		pthread_mutex_lock(&philo[0].data->dead_lock);
		philo[0].data->is_dead = 1;
		pthread_mutex_unlock(&philo[0].data->dead_lock);
	}
	return (signal);
}

static void	case_time_to_die(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo[i].data->write_lock);
	printf("%ld %d died\n", get_current_time() - philo->data->timestamp,
		philo[i].id);
	pthread_mutex_lock(&philo[i].data->dead_lock);
	philo[i].data->is_dead = 1;
	pthread_mutex_unlock(&philo[i].data->dead_lock);
	pthread_mutex_unlock(&philo[i].data->write_lock);
	pthread_mutex_unlock(&philo[i].meal_lock);
}

void	run_monitor(int argc, t_philo *philo)
{
	int	i;
	int	count;

	while (1)
	{
		i = -1;
		count = 0;
		while (++i < philo->data->nb_philos)
		{
			pthread_mutex_lock(&philo[i].meal_lock);
			if ((get_current_time()
					- philo[i].last_meal_time) >= philo[i].data->time_to_die)
			{
				case_time_to_die(philo, i);
				return ;
			}
			if (argc == 6
				&& (philo[i].meals_eaten >= philo[i].data->must_eat_count))
				count++;
			pthread_mutex_unlock(&philo[i].meal_lock);
		}
		if (case_must_eat(philo, count) == 1)
			return ;
	}
}
