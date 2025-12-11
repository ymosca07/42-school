/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:45:18 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/10 15:47:48 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list *stack_a = NULL;
    int count;
    long *stack;
    t_list *stack_b = NULL;
    
    count = 0;
    if (argc < 2 || ft_is_in(argv) == 0)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    else
    {
        stack = parsing(argv, &count);
        stack_a = init_stack_a(stack_a, stack, &count);
        ft_push_swap(&stack_a, &stack_b);
        // while (stack_a->next)
        // {
        //     printf("%ld est à l'index %d\n", stack_a->value, stack_a->index);
        //     stack_a = stack_a->next;
        // }
        // printf("%ld est à l'index %d\n", stack_a->value, stack_a->index);
    }
}
