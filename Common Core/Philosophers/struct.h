/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:25:12 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/02 23:06:52 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

typedef struct s_data {
    int nb_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_count;

    int is_dead;
    pthread_mutex_t dead_lock;
    pthread_mutex_t write_lock;
    pthread_mutex_t *forks;
} t_data;

typedef struct s_philo {
    int id;
    pthread_t thread;
    int meals_eaten;
    long last_meal_time;
    pthread_mutex_t meal_lock;
    
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;

    t_data  *data;
} t_philo;