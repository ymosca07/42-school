/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_possible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:17:48 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/18 17:20:40 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    end_possible(char **map)
{
    int n;
    int i;

    n = -1;
    while (map[++n])
    {
        i = -1;
        while (map[n][++i])
        {
            if (map[n][i] == 'E' || map[n][i] == 'C')
                error_signal("Error: no possibilities of end");
        }
    }
}
