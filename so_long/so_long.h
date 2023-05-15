/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:29:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/15 16:13:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>

# include "libft.h"
# include "mlx.h"

# define ON_DESTROY 17

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

// # define EMTY '0'
// # define WALL '1'
// # define CLEC 'C'
// # define EXIT 'E'
// # define PLYR 'P'
// # define ENMY 'M'

// # define ESC 53
// # define W 13
// # define A 0
// # define S 1
// # define D 2

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

void	exit_program(t_data *data);
void	swap_tile(char **map, t_char *chartr, t_coord moved, char target);
char	ref_tile(char **map, t_coord coord);
void	put_image(t_mlx mlx, t_img img, t_coord coord);

/*    FOR TEST    */
void	test_print_map(t_map map);

#endif