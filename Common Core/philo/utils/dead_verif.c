/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:58:33 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:06:20 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dead_verif(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->is_dead == 0)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (1);
	}
}
