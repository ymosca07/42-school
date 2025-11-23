/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:45:18 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/21 21:15:53 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    char *stack_a;
    int n;
    int j;

    j = 0;
    n = 0;
    i = 0;
    if (argc < 2)
        return (0);
    while (n < argc - 1)
    {
        if (argv[n][i] == '\0')
            argv[n][i] = ' ';
        stack_a[j] = argv[n][i];
        n++;
        i++;
    }
}
