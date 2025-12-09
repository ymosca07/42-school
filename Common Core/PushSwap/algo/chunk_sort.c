/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:27:16 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/09 16:59:40 by yamosca-         ###   ########.fr       */
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
        if ((*stack_a)->index <= i)
        {
            pb(stack_a, stack_b);
            if ((*stack_b)->index < i - (len / 2))
                rb(stack_b);
            i++;
        }
        else
            ra(stack_a);
    }
}

void B_to_A(t_list **stack_a, t_list **stack_b, int size)
{
    t_list *cursor;
    int i;
    
    i = 0;
    while(*stack_b)
    {
        i = 0;
        cursor = *stack_b;
        while (cursor->index != size - 1)
        {
            cursor = cursor->next;
            i++;
        }
        while (i--)
            rb(stack_b);
        pa(stack_a, stack_b);
        size--;
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
