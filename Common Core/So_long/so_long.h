/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:23:29 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/18 17:39:19 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#   define SO_LONG_H

#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

typedef struct s_game
{
    void *mlx; // Pointeur vers l'env MLX
    void *window; // Fenetre (Window)
    char **map;

    /* Dimension de la map */
    int map_w; 
    int map_h;

    int player_x;
    int player_y;

    int collectibles; // Nombre total de 'C' a recup
    int steps; // Compteur de pas

    /* Sprites */
    void    *img_wall; // Mur
    void    *img_floor; // Sol
    void    *img_player; // Skin du joueur
    void    *img_collect; // Skin des collectibles
    void    *img_exit; // Le skin de la "sortie" -> Exit du jeu quand activé
} t_game;

/* Utils - Prototypage */
int     ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *str);
char    **copy_map(char **map, t_game *game);

/* Parsing - Prototypage */
int     get_height_map(char *file);
void    read_map(char *file, t_game *game);
void    player_position(t_game *game);

/* Verifications - Prototypage */
void    check_stuff(t_game *game);
void    wall_check(t_game *game);
void    error_signal(char *str);
int     ber_extension(char *argv);
void    map_len(t_game *game);
void    flood_fill(int y, int x, char f, char **map);
void    end_possible(char **map);

#endif