/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:27:16 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 16:50:24 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void append_all_index(t_list **stack_a, int size)
{
    t_list *tmp;
    int *tab;
    int i;

    tab = malloc(sizeof(int) * size);
    tmp = *stack_a;
    i = 0;
    while (tmp)
    {
        tab[i] = (tmp)->value;
        i++;
        tmp = (tmp)->next;
    }
    ft_sort_int_tab(tab, i);
    tmp = *stack_a;
    while (tmp)
    {
        i = 0;
        while ((tmp)->value != tab[i])
            i++;
        if ((tmp)->value == tab[i])
            tmp->index = i;
        tmp = tmp->next;
    }
    free(tab);
}

void    A_to_B(t_list **stack_a, t_list **stack_b, int len)
{
    int i;

    i = 0;
    
    while (*stack_a)
    {
        if ((*stack_a)->index <= i + len)
        {
            pb(stack_a, stack_b);
            if ((*stack_b)->index <= i)
                rb(stack_b);
            i++;
        }
        else
            ra(stack_a);
    }
}

void search_index_optimization(t_list **stack_b, int size_b, int target_index, int i)
{
    if (i <= size_b / 2)
    {
        while ((*stack_b)->index != target_index)
            rb(stack_b);
    }
    else
    {
        while ((*stack_b)->index != target_index)
            rrb(stack_b);
    }
}

void B_to_A(t_list **stack_a, t_list **stack_b, int size)
{
    t_list *cursor;
    
    int i;
    int size_b;
    int target_index;

    target_index = size - 1;
    size_b = 0;
    while(*stack_b)
    {
        cursor = *stack_b;
        i = 0;
        size_b = ft_lstsize(*stack_b);
        while (cursor->index != target_index && cursor)
        {
            i++;
            cursor = cursor->next;
        }
        search_index_optimization(stack_b, size_b, target_index, i);
        pa(stack_a, stack_b);
        target_index--;
    }
}

void chunk_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int len;
    
    len = chunk_size(size);
    
    append_all_index(stack_a, size);
    
    A_to_B(stack_a, stack_b, len);

    B_to_A(stack_a, stack_b, size);
    
    return ;
}
