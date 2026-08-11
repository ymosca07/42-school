/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:33:30 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 16:35:15 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int search_comma(char **input, int n, int count)
{
    int i;

    i = 0;
    while (input[n][i] && count > 0)
    {
        if (input[n][i] == ',')
            count--;
        i++;
    }
    if (count > 0)
        return (-1);
    return (i - 1);
}

static int first_step(char **input, int n)
{
    int i;
    int j;
    int ret;
    char *res;

    i = 2;
    j = 0;
    ret = -1;
    res = ft_calloc(4, sizeof(char));
    if (!res)
        return (-1);
    while (input[n][i] >= '0' && input[n][i] <= '9' && j < 3)
    {
        res[j] = input[n][i];
        i++;
        j++;
    }
    if (res[0])
    {
        ret = ft_atoi(res);
        free(res);
    }
    return (ret);
}

static int second_step(char **input, int n)
{
    int i;
    int j;
    int ret;
    char *res;

    i = search_comma(input, n, 1) + 1;
    j = 0;
    ret = -1;
    res = ft_calloc(4, sizeof(char));
    if (!res)
        return (-1);
    while ((input[n][i] >= '0' && input[n][i] <= '9') && i != -1 && j < 3)
    {
        res[j] = input[n][i];
        i++;
        j++;
    }
    if (res[0])
    {
        ret = ft_atoi(res);
        free(res);
    }
    return (ret);
}

static int third_step(char **input, int n)
{
    int i;
    int j;
    int ret;
    char *res;

    i = search_comma(input, n, 2) + 1;
    j = 0;
    ret = -1;
    res = ft_calloc(4, sizeof(char));
    if (!res)
        return (-1);
    while ((input[n][i] >= '0' && input[n][i] <= '9') && i != -1 && j < 3)
    {
        res[j] = input[n][i];
        i++;
        j++;
    }
    if (res[0])
    {
        ret = ft_atoi(res);
        free(res);
    }
    return (ret);
}


int fill_input(t_config *config, char **input)
{
    int n;
    int max_index;

    max_index = -1;
    n = 0;
    n = find("NO", input, &n);
    if (n != -1)
    {
        config->NO = &input[n][3];
        if (n > max_index)
            max_index = n;
    }
    n = find("SO", input, &n);
    if (n != -1)
    {
        config->SO = &input[n][3];
        if (n > max_index)
            max_index = n;
    }
    n = find("WE", input, &n);
    if (n != -1)
    {
        config->WE = &input[n][3];
        if (n > max_index)
            max_index = n;
    }
    n = find("EA", input, &n);
    if (n != -1)
    {
        config->EA = &input[n][3];
        if (n > max_index)
            max_index = n;
    }
    n = find("F", input, &n);
    if (n != -1)
    {
        config->floor[0] = first_step(input, n);
        config->floor[1] = second_step(input, n);
        config->floor[2] = third_step(input, n);
        if (n > max_index)
            max_index = n;
    }
    n = find("C", input, &n);
    if (n != -1)
    {
        config->ceiling[0] = first_step(input, n);
        config->ceiling[1] = second_step(input, n);
        config->ceiling[2] = third_step(input, n);
        if (n > max_index)
            max_index = n;
    }
    if (n != -1)
        config->map = fill_map(config, input, max_index + 1);
    if (n == -1)
        return (-1);
    return (0);
}
