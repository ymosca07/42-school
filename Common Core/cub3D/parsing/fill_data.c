/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 18:07:59 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 16:34:41 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char **fill_data(char *file)
{
    int i;
    int fd;
    char *line;
    char *all;
    char **tmp;

    all = NULL;
    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (NULL);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        all = ft_strjoin(all, line);
        free(line);
    }
    tmp = ft_split(all, '\n');
    free(all);
    if (!tmp)
        return (NULL);
    close(fd);
    return (tmp);
}
