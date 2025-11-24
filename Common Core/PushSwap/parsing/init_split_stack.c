/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_split_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:17:52 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/24 17:24:25 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *init_split_stack(char **input)
{
    int i;
    int n;
    char *str;
    int j;
    int len;

    str = NULL;
    j = 0;
    i = 0;
    len = ft_count_len(input);
    str = malloc(sizeof(char) * len + 1);
    if (!str)
        return (NULL);
    n = 1;
    while (input[n])
    {
        i = 0;
        while (input[n][i])
            str[j++] = input[n][i++];
        if (input[n + 1])
            str[j++] = ' ';
        n++;
    }
    str[j] = '\0';
    return (str);
}
