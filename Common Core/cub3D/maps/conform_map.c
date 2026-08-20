/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conform_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:33:17 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/09 18:06:55 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static int max_len(char **old)
{
    int n;
    int i;
    int max;

    max = -1;
    n = 0;
    while (old[n])
    {
        i = 0;
        while(old[n][i])
            i++;
        if (i > max)
            max = i;
        n++;
    }
    return (max);
}

static int map_height(char **old)
{
    int n;

    n = 0;
    while (old[n])
        n++;
    return (n);
}

static void fill_line(char *new, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (new[i] == '\0')
            new[i] = ' ';
        i++;
    }
}

static char	*my_strdup(char *str, int len)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	new = ft_calloc(len + 1, 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

char **conform_map(char **old)
{
    int n;
    int len;
    char **new;

    n = 0;
    len = max_len(old);
    new = ft_calloc(sizeof(char *), map_height(old) + 1);
    if (!new)
        return (NULL);
    while (old[n])
    {
        new[n] = my_strdup(old[n], len);
        if (!new[n])
            return (NULL);
        fill_line(new[n], len);
        n++;
    }
    double_tab(old);
    return (new);
}
