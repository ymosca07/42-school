/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:49:54 by flortie           #+#    #+#             */
/*   Updated: 2026/08/10 17:56:59 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3D.h"

# define WIN_WIDTH 1024
# define WIN_HEIGHT 1024

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.04

// BONUSES

// collisions
# define COLL_PLAYER_DIST 0.2

// crosshair
# define CROSSHAIR_ON 1

// minimap
# define MM_TILE_SIZE 12
# define MM_COLOR_WALL 0xFF0000
# define MM_COLOR_FLOOR 0x000000
# define MM_COLOR_PLAYER 0xFFFF00
# define MM_SCALE 10  // in pixel
# define MM_OFF_X 5
# define MM_OFF_Y 5

# define TILE_DOOR 'D'

// mouse
# define MOUSE_SENSITIVITY 0.001

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_raycast
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit; // ray is touching a wall? 0/1
	int			side; // 0 east west; 1 north south
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
	int			hit_door;
	double		perp_door_dist;
	int			door_map_x;
	int			door_map_y;
	int			door_draw_start;
	int			door_draw_end;
	int			door_line_height;
	int			door_raw_start;
}				t_raycast;

typedef struct s_tex
{
	t_img		*img;
	int			x;
	double		pos;
	double		step;
}				t_tex;

typedef struct s_sprite
{
	double		x;
	double		y;
	int			texture_id;
	t_img		*frames;
	int			total_frames;
	int			current_frame;
	int			loop_counter;
}				t_sprite;

typedef struct s_render
{
	void		*mlx;
	void		*win;

	t_img		tex_north;
	t_img		tex_south;
	t_img		tex_west;
	t_img		tex_east;
	t_img		tex_door;
	t_img		screen;

	int			sky_color;
	int			wall_color;
	int			floor_color;

	double		**doors;

	t_raycast	ray;

	int			k_w;
	int			k_s;
	int			k_a;
	int			k_d;
	int			k_left;
	int			k_right;

	double		px;
	double		py;
	double		dir_x;
	double		dir_y;
	double		orientation_x;
	double		orientation_y;

	char		**map;
	int			map_width;
	int			map_height;
	int			mouse_x;
	t_sprite	*sprites;
	int			sprite_count;
	
	t_img		tex_no;
	t_img		tex_so;
	t_img		tex_ea;
	t_img		tex_we;
	char		*path_no;
	char		*path_so;
	char		*path_ea;
	char		*path_we;
	char		*path_door;
}				t_render;

void			*ft_memset(void *s, int c, size_t n);

void			ft_mlx_game_init(t_render *data);

int				mouse_move_handler(int x, int y, t_render *data);

int				ft_key_press(int key, t_render *data);
int				ft_key_release(int key, t_render *data);

void			ft_load_textures(t_render *data);
void			ft_listen_keys(t_render *data);
void			ft_rotate_player(t_render *data, double angle);

void			ft_error_exit(char *text, t_render *data);
int				ft_close_game(t_render *data);

void			ft_draw_column(t_render *data, int x);
void			ft_put_pixel(t_img *img, int x, int y, int color);

void			ft_raycasting_loop(t_render *data);

void			ft_draw_crosshair(t_render *data);
void			ft_draw_minimap(t_render *data);

void			ft_init_doors(t_render *data);
void			ft_init_doors_stats(t_render *data);
void			ft_update_doors(t_render *data);
void			ft_free_doors(t_render *data);
void			ft_calculate_door_projection(t_render *data);

#endif
