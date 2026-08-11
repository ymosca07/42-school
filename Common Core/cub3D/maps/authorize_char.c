/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   authorize_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 13:38:41 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/09 12:40:01 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static int is_char(char c)
{
    if (c == 'D' || c == 'N' || c == ' ')
        return (1);
    if (c == 'E' || c == 'T' || c == 'S')
        return (1);
    if (c == 'W' || c == '1' || c == '0')
        return (1);
    return (-1);
}

int authorize_char(char **map)
{
    int n;
    int i;

    n = 0;
    while (map[n])
    {
        i = 0;
        while (map[n][i])
        {
            if (is_char(map[n][i]) == -1)
                return (-1);
            i++;
        }
        n++;
    }
    return (0);
}
