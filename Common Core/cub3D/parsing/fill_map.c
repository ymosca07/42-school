/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:25:05 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/06 17:46:32 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char **fill_map(t_config *config, char **input, int n)
{
    int i;
    int j;

    j = 0;
    while(input[n] && !input[n][0])
        n++;
    i = n;
    while (input[i])
        i++;
    config->map = ft_calloc(i - n + 1, sizeof(char *));
    if (!config->map)
        return (NULL);
    while (n < i)
    {
        config->map[j] = ft_strdup(input[n]);
        n++;
        j++;
    }
    return (config->map);
}
