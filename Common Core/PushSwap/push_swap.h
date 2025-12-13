/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:16:59 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/13 01:33:49 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_list
{
    long value;
    int index;
    struct s_list *next;
} t_list;

t_list *init_stack_a(t_list *stack_a, long *stack, int *count);
int ft_is_in(char **input);
char *init_split_stack(char **input);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int ft_count_len(char **input);
long	ft_atol(const char *str);
t_list *ft_lstnew(long content);
void ft_lstadd_back(t_list **lst, t_list *new);
long *parsing(char **argv, int *count);
void    sa(t_list **stack_a);
void    sb(t_list **stack_b);
void    ft_push_swap(t_list **stack_a, t_list **stack_b);
void ft_lstadd_front(t_list **lst, t_list *new);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    _ra(t_list **stack_a);
void    _rb(t_list **stack_b);
void    _rra(t_list **stack_a);
void    _rrb(t_list **stack_b);
void _sa(t_list **stack_a);
void _sb(t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    rr(t_list **stack_a ,t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);
void sa(t_list **stack_a);
void sb(t_list **stack_b);
void ss(t_list **stack_a, t_list **stack_b);
void sort_2(t_list **stack_a);
void sort_3(t_list **stack_a);
void sort_5(t_list **stack_a, t_list **stack_b);
int ft_lstsize(t_list *lst);
void    push_max(t_list **stack_a, t_list **stack_b, long max, int max_position);
void    push_min(t_list **stack_a, t_list **stack_b, long min, int min_position);
void    search_min_max(t_list **stack_a, t_list **stack_b);
void chunk_sort(t_list **stack_a, t_list **stack_b, int size);
int chunk_size(int size);
void append_all_index(t_list **stack_a, int size);
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);
void    A_to_B(t_list **stack_a, t_list **stack_b, int len);
void B_to_A(t_list **stack_a, t_list **stack_b, int size);
void    verif_double(long *stack, int count, int *error);
void    last_verif(long *stack, int *count);
void    verif_max_min(long *stack, int count, int *error);
void    error_signal();
int	ft_strcmp(char *s1, char *s2);
void ft_lstclear(t_list *node);
void    check_empty_string(char **argv);
void long_max_signs(char **tmp);
size_t	ft_strlen_skip(const char *str);

#endif
