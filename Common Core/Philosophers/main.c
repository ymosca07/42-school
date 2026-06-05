/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:14:43 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/05 20:53:48 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    int     count;
    int     check;
    long    *tab;
    t_data  data;
    t_philo *philo;
    
    count = 0;
    if (argc != 6 && argc != 5)
    {
        printf("Arguments must be 4 or 5\n");
        return (1);
    }
    tab = parsing(argv, &count);
    check = check_input(argc, tab);
    if (check == -1)
        return (1);
    data.nb_philos = (int)tab[0];
    data.time_to_die = (int)tab[1];
    data.time_to_eat = (int)tab[2];
    data.time_to_sleep = (int)tab[3];
    if (argc == 6)
        data.must_eat_count = (int)tab[4];
    else
        data.must_eat_count = -1;

    philo = malloc(sizeof(t_philo) * data.nb_philos);
    if (!philo)
    {
        free(tab);
        error_signal();
    }
    
    data.forks = malloc(sizeof(pthread_mutex_t) * data.nb_philos);
    if (!data.forks)
    {
        free(philo);
        free(tab);
        error_signal();
    }
    
    int k = 0;
    while (k < data.nb_philos)
    {
        pthread_mutex_init(&data.forks[k], NULL);
        k++;
    }
    pthread_mutex_init(&data.dead_lock, NULL);
    pthread_mutex_init(&data.write_lock, NULL);

    int j = 0;
    while (j < data.nb_philos)
    {
        philo[j].id = j + 1;
        philo[j].data = &data;
        philo[j].left_fork = &data.forks[j];
        philo[j].right_fork = &data.forks[(j + 1) % data.nb_philos];
        philo[j].last_meal_time = get_current_time();
        philo[j].meals_eaten = 0;
        pthread_mutex_init(&philo[j].meal_lock, NULL);
        j++;
    }
    
    int i;
    i = -1;
    while (++i < data.nb_philos)
        pthread_create(&philo[i].thread, NULL, &philo_routine, &philo[i]);

    run_monitor(argc, philo);

    i = 0;
    while (i < data.nb_philos)
    {
        pthread_join(philo[i].thread, NULL);
        i++;
    }
    return (0);
}
