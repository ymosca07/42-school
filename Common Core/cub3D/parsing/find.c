/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:37:56 by yamosca-          #+#    #+#             */
/*   Updated: 2026/07/21 18:15:52 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void incrementation(int *count, int *len)
{
    (*count)++;
    (*len)--;
}

int  find(char *str, char **input, int *n)
{
    int i;
    int count;
    int len;

    i = 0;
    count = 0;
    if (*n == -1)
        return (-1);
    while (input[i])
    {
        len = (int)ft_strlen(str);
        if (count == len)
            return (i - 1);
        count = 0;
        while (1)
        {
            if (len > 0 && str[len - 1] == input[i][len - 1])
                incrementation(&count, &len);
            else
                break ;
        }
        i++;
    }
    if (!input[i])
        return (i - 1);
    return (-1);
}
