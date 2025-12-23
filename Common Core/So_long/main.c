/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:04:38 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/23 17:51:37 by yamosca-         ###   ########.fr       */
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
        return (1);

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
    
    /* Display window */
    game->mlx = mlx_init();
    if (!game->mlx)
        return (1);
    game->window = mlx_new_window(game->mlx, 1920, 1080, "Napolong");
    
    /* Image */
    aff_sprites(game, game->mlx, game->window);

    mlx_hook(game->window, 2, 1L<<0, inputs_keycode, game);
    
    mlx_loop(game->mlx);

    /* Display map testing */
    #include <stdio.h>
    
    int n = 0;

    while (game->map[n])
    {
        printf("%s\n", game->map[n]);
        n++;
    }
    free_all(game->map);
    free(game);
    return (0);
}
