/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:18:46 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/07 20:17:39 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <limits.h>
#include <sys/time.h>
#include <unistd.h>

void    my_is_digit(char **argv);
int     ft_count_len(char **input);
void	ft_bzero(void *s, size_t n);
int check_input(int argc, long *tab);
char	*init_split_str(char **input);
char	**ft_split(char const *s, char c);
long	*parsing(char **argv, int *count);
void	last_verif(long *stack, int *count);
long	ft_atol(const char *str, int *error);
long	*get_long_tab(char **tmp, long *stack);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	error_signal();
void	tmp_error(char **tmp);
void    ltab_error(char **tmp, long *stack, int n);

long    get_current_time();
void    ft_usleep(long time);
int     dead_verif(t_philo *philo);
size_t	ft_strlen(const char *str);
void    *philo_routine(void  *arg);
t_data  fill_data(int argc, long *tab);
void    run_monitor(int argc, t_philo *philo);
void fill_philos(t_data data, t_philo *philo);
void	*ft_calloc(size_t nmemb, size_t size);
void    print_status(t_philo *philo, char *str);
