/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map->c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:29:54 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/17 15:52:04 by yamosca-         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void map_allocation(t_game *game, char *file)
{
    game->map_h = get_height_map(file);
    game->map = (char **)ft_calloc(sizeof(char *), game->map_h + 1);
    if (!game->map)
    {
        free_struct(game);
        error_signal("Error: allocation error\n");
    }
}

void read_map(char *file, t_game *game)
{
    int fd;
    int n;
    char *tmp;
    int line;

    n = 0;
    map_allocation(game, file);
    fd = open(file, O_RDONLY);
    line = game->map_h;
    while (line-- > 0)
    {
        tmp = get_next_line(fd);
        game->map[n] = tmp;
        if (!game->map[n])
        {
            free_struct(game);
            error_signal("Error: allocation error\n");
        }
        if (game->map[n][ft_strlen(game->map[n]) - 1] == '\n')
            game->map[n][ft_strlen(game->map[n]) - 1] = '\0';
        n++;
    }
}
