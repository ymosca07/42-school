/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:45:18 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/24 18:01:31 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    int n;
    t_list *stack_a;
    int count;
    
    count = 0;
    i = 0;
    n = 0;
    // int et ' '
    if (argc < 2 || ft_is_in(argv) == 0)
    {
        write(2, "error\n", 6);
        return (1);
    }
    else
    {
        char *str = NULL;
        str = init_split_stack(argv);
        char **tmp = NULL;
        tmp = ft_split(str, ' ');
        while (tmp[count])
            count++;
        long *stack = NULL;
        stack = malloc(sizeof(long) * count);
        while (tmp[n])
        {
            stack[n] = ft_atol(tmp[n]);
            n++;
        }
        n = 0;
        while (stack[n])
        {
            stack_a = malloc(sizeof(t_list));
            stack_a->value = stack[n];
            printf("%ld\n", stack_a->value);
            stack_a = stack_a->next;
            n++;
        }
    }
    
}
