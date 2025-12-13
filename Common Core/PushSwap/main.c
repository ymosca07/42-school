/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:45:18 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/13 01:24:07 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a = NULL;
    int count;
    long *stack;
    t_list *stack_b = NULL;
    
    count = 0;
    if (argc == 1)
        return (1);
    if (argc < 2 || ft_is_in(argv) == 0)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    else
    {
        stack = parsing(argv, &count);
        stack_a = init_stack_a(stack_a, stack, &count);
        free(stack);
        ft_push_swap(&stack_a, &stack_b);
        ft_lstclear(stack_a);
    }
    
    // #include <stdio.h>
    // while (stack_a)
    // {
    //     dprintf(2, "%ld\n", stack_a->value);
    //     stack_a = stack_a->next;
    // }
    
    return (0);
}
