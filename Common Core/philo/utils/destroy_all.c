/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:37:10 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:06:30 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_all(t_philo **philo, t_data *data)
{
	int	k;

	k = 0;
	while (k < data->nb_philos)
	{
		pthread_mutex_destroy(&data->forks[k]);
		pthread_mutex_init(&(*philo)[k].meal_lock, NULL);
		k++;
	}
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->write_lock);
	free(data->forks);
	free(data);
	free(*philo);
}
