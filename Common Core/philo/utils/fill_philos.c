/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:15:33 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 22:02:48 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	assign_forks(t_philo *philo, t_data *data, int j)
{
	if (philo[j].id % 2 == 0)
	{
		philo[j].first_fork = &data->forks[(j + 1) % data->nb_philos];
		philo[j].second_fork = &data->forks[j];
	}
	else
	{
		philo[j].first_fork = &data->forks[j];
		philo[j].second_fork = &data->forks[(j + 1) % data->nb_philos];
	}
}

void	fill_philos(t_data *data, t_philo *philo)
{
	int	j;

	j = 0;
	while (j < data->nb_philos)
	{
		philo[j].id = j + 1;
		philo[j].data = data;
		assign_forks(philo, data, j);
		philo[j].meals_eaten = 0;
		pthread_mutex_init(&philo[j].meal_lock, NULL);
		j++;
	}
}
