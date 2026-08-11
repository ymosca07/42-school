/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:18:46 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:07:32 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

long	ft_atol(const char *str);
int		my_is_digit(char **argv);
int		ft_count_len(char **input);
void	ft_bzero(void *s, size_t n);
char	*init_split_str(char **input);
int		parsing(char **argv, long **tab);
int		check_input(int argc, long *tab);
char	**ft_split(char const *s, char c);
int		last_verif(long *stack, int count, char **tmp);
long	*get_long_tab(char **tmp, long *stack);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	error_signal(void);
void	ltab_error(char **tmp, long *stack);

long	get_current_time(void);
void	ft_usleep(long time);
int		dead_verif(t_philo *philo);
size_t	ft_strlen(const char *str);
void	*philo_routine(void *arg);
t_data	*fill_data(int argc, long *tab);
void	run_monitor(int argc, t_philo *philo);
void	*ft_calloc(size_t nmemb, size_t size);
void	print_status(t_philo *philo, char *str);
void	fill_philos(t_data *data, t_philo *philo);
void	destroy_all(t_philo **philo, t_data *data);
