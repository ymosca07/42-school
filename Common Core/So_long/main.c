/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:04:38 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/18 17:54:54 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  *game;
    
    
    if (argc != 2)
    {
        error_signal("Error: you must have 2 arguments\n");
        return (1);
    }
    
    if (ber_extension(argv[1]) == 1)
    {
        error_signal("Error: extension must be .ber\n");
        return (1);
    }
    
    game = ft_calloc(sizeof(t_game), 1);
    
    if (!game)
        return (0);

    /* Get map's height and read all map without verifications */
    read_map(argv[1], game);

    /* Map verification */
    map_len(game);
    check_stuff(game);
    wall_check(game);

    /* Player position */
    player_position(game);

    /* Init map copy */
    char **tmp_map;
    tmp_map = copy_map(game->map, game);
    
    /* Run flood fill for search if it's possible */
    flood_fill(game->player_y, game->player_x, 'F', tmp_map);
    end_possible(tmp_map);
    
    /* Display map testing */
    #include <stdio.h>
    
    int n = 0;

    while (game->map[n])
    {
        printf("%s\n", game->map[n]);
        n++;
    }

    return (0);
    
    /* Map's len verification */
    // map_len()

    // mlx_init();
    // mlx_new_window();
    // mlx_loop();
}
