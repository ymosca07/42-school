/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:25:12 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 20:01:42 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

typedef struct s_data
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				is_dead;
	time_t			timestamp;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	pthread_t		thread;
	long			last_meal_time;
	pthread_mutex_t	meal_lock;

	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	t_data			*data;
}					t_philo;
