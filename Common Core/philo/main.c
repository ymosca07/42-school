/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:14:43 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:04:35 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	forks_philo_allocation(t_philo **philo, t_data *data, long *tab)
{
	*philo = ft_calloc(sizeof(t_philo), data->nb_philos);
	if (!*philo)
	{
		free(tab);
		free(data);
		write(2, "Error\n", 6);
		return (-1);
	}
	data->forks = ft_calloc(sizeof(pthread_mutex_t), data->nb_philos);
	if (!data->forks)
	{
		free(*philo);
		free(data);
		free(tab);
		write(2, "Error\n", 6);
		return (-1);
	}
	free(tab);
	return (0);
}

static void	mutex_init(t_data *data)
{
	int	k;

	k = 0;
	while (k < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[k], NULL);
		k++;
	}
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
}

static void	create_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	data->timestamp = get_current_time();
	while (++i < data->nb_philos)
	{
		philo[i].last_meal_time = data->timestamp;
		pthread_create(&philo[i].thread, NULL, &philo_routine, &philo[i]);
	}
}

static void	threads_join(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	long	*tab;
	t_data	*data;
	t_philo	*philo;

	tab = NULL;
	philo = NULL;
	if ((argc != 6 && argc != 5) || parsing(argv, &tab) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_input(argc, tab) == -1)
		return (1);
	data = fill_data(argc, tab);
	if (!data)
		return (1);
	if (forks_philo_allocation(&philo, data, tab) == -1)
		return (1);
	mutex_init(data);
	fill_philos(data, philo);
	create_threads(data, philo);
	run_monitor(argc, philo);
	threads_join(data, philo);
	destroy_all(&philo, data);
	return (0);
}
