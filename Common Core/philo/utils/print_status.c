/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:31:33 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:06:52 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (!philo->data->is_dead)
		printf("%ld %d %s\n", get_current_time() - philo->data->timestamp,
			philo->id, str);
	pthread_mutex_unlock(&philo->data->dead_lock);
	pthread_mutex_unlock(&philo->data->write_lock);
}
