/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:23:32 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/17 13:28:25 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_height_map(char *file)
{
    int fd;
    char *tmp;
    int count;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    count = 0;
    tmp = get_next_line(fd);
    while (tmp != NULL)
    {
        free(tmp);
        count++;
        tmp = get_next_line(fd);
    }
    close(fd);
    return (count);
}
