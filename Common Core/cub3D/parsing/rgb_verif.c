/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:39:57 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/06 18:46:48 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int is_rgb(int n)
{
    if (n >= 0 && n <= 255)
        return (1);
    return (-1);
}

int rgb_verif(t_config *config)
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (is_rgb(config->floor[i]) == -1)
            return (-1);
        i++;
    }
    i = 0;
    while (i < 3)
    {
        if (is_rgb(config->ceiling[i]) == -1) 
            return (-1);    
        i++;
    }
    return (1);
}
