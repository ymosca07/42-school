/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:14:43 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/07 20:47:47 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int forks_philo_allocation(t_philo *philo, t_data data, long *tab)
{
    philo = malloc(sizeof(t_philo) * data.nb_philos);
    if (!philo)
    {
        free(tab);
        printf("allocation error\n");
        return (-1);
    }
    data.forks = malloc(sizeof(pthread_mutex_t) * data.nb_philos);
    if (!data.forks)
    {
        free(philo);
        free(tab);
        printf("allocation error\n");
        return (-1);
    }
    return (0);
}

static void mutex_init(t_data data)
{
    int k;

    k = 0;
    while (k < data.nb_philos)
    {
        pthread_mutex_init(&data.forks[k], NULL);
        k++;
    }
    pthread_mutex_init(&data.dead_lock, NULL);
    pthread_mutex_init(&data.write_lock, NULL);
}

static void create_threads(t_data data, t_philo *philo)
{
    int i;
    
    i = -1;
    data.timestamp = get_current_time();
    while (++i < data.nb_philos)
        pthread_create(&philo[i].thread, NULL, &philo_routine, &philo[i]);
}

static void threads_join(t_data data, t_philo *philo)
{
    int i;
    
    i = 0;
    while (i < data.nb_philos)
    {
        pthread_join(philo[i].thread, NULL);
        i++;
    }
}

int main(int argc, char **argv)
{
    int     count;
    int     check;
    long    *tab;
    t_data  *data;
    t_philo *philo;
    
    philo = NULL;
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
    data = fill_data(argc, tab);
    check = forks_philo_allocation(philo, data, tab);
    if (check == -1)
        return (1);
    mutex_init(data);
    printf("ici le segfault juste en haut");
    return (0);
    create_threads(data, philo);
    run_monitor(argc, philo);
    threads_join(data, philo);
    return (0);
}
