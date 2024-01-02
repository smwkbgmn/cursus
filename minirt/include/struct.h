/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:30:19 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/02 14:47:41 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

# define MIN 0
# define MAX 1

/* ELEMENT */
typedef double			t_scl;
typedef struct s_bias3	t_vec;
typedef struct s_bias3	t_uvec;
typedef struct s_bias3	t_point;
typedef struct s_bias3	t_color;
typedef struct s_bias2	t_size;

struct s_bias3
{
	t_scl	x;
	t_scl	y;
	t_scl	z;
};

struct s_bias2
{
	t_scl	x;
	t_scl	y;
};

/* MLX */
typedef struct s_window	t_win;

struct s_window
{
	t_size	size;
	void	*mlx;
	void	*ptr;
};

/* VIEW */
typedef struct s_canvas	t_canvas;
typedef struct s_camera	t_camera;
typedef struct s_grid	t_grid;
typedef struct s_view	t_view;

struct s_canvas
{
	t_size	size;
	t_scl	aspect;
};

struct s_camera
{
	t_point	origin;
	t_scl	fclen;
};

struct s_grid
{
	t_vec	w;
	t_vec	h;
};

struct s_view
{
	t_size	size;
	t_grid	unit;
	t_grid	delta;
	t_point	upper_left;
	t_point	pixel00_loc;
};

/* RAY */
typedef enum e_face			t_face;
typedef struct s_ray		t_ray;
typedef struct s_hit		t_hit;
typedef struct s_equation	t_eqa;

enum e_face
{
	BACK,
	FRONT
};

struct s_ray
{
	t_point	origin;
	t_vec	direc;
};

struct s_hit
{
	t_point	point;
	t_uvec	normal;
	t_scl	t;
	t_face	face;
};

struct s_equation
{
	t_vec	oc;
	t_scl	a;
	t_scl	b_half;
	t_scl	c;
	t_scl	dscr;
};

/* OBJECTS */
typedef enum e_name		t_name;
typedef struct s_circle	t_circle;
typedef struct s_square	t_square;
typedef struct s_value	t_value;
// typedef struct s_sphere	t_sphere;
// typedef struct s_cylndr	t_cylndr;
// typedef struct s_plane	t_plane;

typedef struct s_obj		t_obj;
typedef struct s_hittable	t_hitbl;

enum e_name
{
	SPHERE,
	CYLNDR,
	PLANE
};

struct s_circle
{
	t_point	center;
	t_scl	radius;
};

struct s_square
{
	t_point	point;
	t_uvec	normal;
};

// struct s_sphere
// {
// 	t_circle	circle;
// };

// struct s_cylndr
// {
// 	t_circle	circle;
// 	t_uvec		axis;
// 	t_scl		height;
// };

// struct s_plane
// {
// 	t_square	square;
// };

struct s_value
{
	t_circle	cir;
	t_square	sqr;
	t_uvec		axis;
	t_scl		height;
};

struct s_obj
{
	// void		*shape;
	t_name		name;
	t_value		val;
	t_hit		hit;
};

struct s_hittable
{
	const t_ray	*r;
	t_scl		t[2];
	t_list		*objs;
};

#endif