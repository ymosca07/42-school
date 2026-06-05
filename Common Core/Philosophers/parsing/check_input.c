/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:35:01 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/05 20:57:05 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int check_input(int argc, long *tab)
{
    int i;

    i = 0;
    if (argc == 6 && tab[4] == 0)
    {
        free(tab);
        return (-1);
    }
    
    while (i < argc)
    {
        if (tab[i] == 0)
        {
            printf("Input error, value must be superior at 0\n");
            free(tab);
            return (-1);
        }
        i++;
    }
    return (0);
}
