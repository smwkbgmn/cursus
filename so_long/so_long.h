/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:29:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 02:40:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>

# include "libft.h"
# include "mlx.h"

# define ON_DESTROY 17

# define FALSE 0
# define TRUE 1

# define EMTY '0'
# define WALL '1'
# define CLEC 'C'
# define EXIT 'E'
# define PLYR 'P'

# define W 13
# define A 0
# define S 1
# define D 2

typedef unsigned int	t_uint;
typedef short			t_bool;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
}	t_mlx;

typedef struct s_map
{
	char	**map;
	t_uint	x;
	t_uint	y;
}	t_map;

typedef struct s_img
{
	void	*ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_character
{
	t_img	cut[7];
	t_uint	frame;
}	t_character;

typedef struct s_asset
{
	t_img		tile[3];
	t_img		collect;
	t_character	walk;
}	t_asset;

typedef struct s_game
{
	t_uint	x;
	t_uint	y;
	t_uint	collected;
	t_uint	goal;
}	t_game;

typedef struct s_data
{
	t_mlx	mlx;
	t_map	map;
	t_asset	imgs;
	t_game	player;	
}	t_data;

/*    FOR TEST    */
void	test_print_map(t_map map);

#endif