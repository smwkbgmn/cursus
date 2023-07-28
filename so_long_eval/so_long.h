/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:29:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 20:05:45 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define ON_DESTROY 17
# define ERROR -1

typedef unsigned int	t_uint;

typedef enum e_direc
{
	LEFT,
	RIGHT
}	t_direc;

typedef enum e_tile
{
	EMTY = '0',
	WALL = '1',
	CLEC = 'C',
	EXIT = 'E',
	PLYR = 'P',
	ENMY = 'M'
}	t_tile;

typedef enum e_key
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2
}	t_key;

typedef struct s_dfs
{
	t_list	*checked;
	t_list	*stack;
	t_bool	meet_exit;
	t_uint	cnt_collect;
}	t_dfs;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
}	t_mlx;

typedef struct s_map
{
	char	**map;
	t_uint	width;
	t_uint	height;
}	t_map;

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}	t_img;

typedef struct s_img_char
{
	t_img	**cut;
	t_uint	cnt_img;
}	t_img_char;

typedef struct s_asset
{
	t_img		tile[3];
	t_img		collect;
	t_img_char	player_walk;
	t_img_char	player_death;
	t_img_char	enemy;
}	t_asset;

typedef struct s_game
{
	t_uint	collected;
	t_uint	goal;
	t_bool	win;
}	t_game;

typedef struct s_coord
{
	t_uint	x;
	t_uint	y;
}	t_coord;

typedef struct s_char
{
	t_uint	frame;
	t_direc	direction;
	t_coord	coord;
	t_uint	move;
	t_bool	death;
}	t_char;

typedef struct s_data
{
	t_mlx	mlx;
	t_map	map;
	t_asset	imgs;
	t_game	game;
	t_char	player;
	t_char	enemy;
}	t_data;

void	init_data(t_data *data, char *filename);
void	init_map(t_map *map, char *filename);
void	init_mlx(t_map *map, t_mlx *mlx);
void	init_asset(void *mlx, t_asset *imgs);
t_game	init_game(t_map map);
t_char	init_character(t_map map, char target);

void	set_img(void *mlx, t_img *img, char *name);
void	set_img_char(void *mlx, t_img_char *img_char, char *prefix, t_uint cnt);

void	valid_map(t_map map);
void	check_valid_path(t_map map);

int		key_hook(int keycode, t_data *data);
int		loop_hook(t_data *data);

void	patrol_enemy(t_char *enemy, char **map);
void	check_nearby_enemy(t_char *player, t_char enemy);

void	draw_character(t_data *data, char tile, t_coord coord);

int		open_fd(char *name, int mode);
void	close_fd(int fd);

void	free_data(t_data *data);
void	free_map(t_map *map);

void	*catcher(void *ptr);
void	exit_with_error(char *msg);
void	exit_program(t_data *data);
void	write_error(char *msg);

int		window_closed(t_data *data);
void	exit_program(t_data *data);

void	put_image(t_mlx mlx, t_img img, t_coord coord);
void	put_string(t_data *data);

t_coord	get_coord_target(t_map map, char target);

char	ref_tile(char **map, t_coord coord);
void	swap_tile(char **map, t_char *chartr, t_coord moved, char target);

void	add_nearby(t_dfs *dfs, t_map map, t_coord curnt);
t_bool	is_nearby_enemy(t_map map, t_coord plyr);

t_coord	*new_coord(t_coord crd);
t_uint	game_goal(t_map map);

#endif