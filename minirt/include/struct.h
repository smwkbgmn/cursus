/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:30:19 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/26 07:22:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

# define NONE 0

typedef double				t_scl;
typedef unsigned int		t_argb;

/* ELEMENT */
typedef enum e_name			t_name;

typedef struct s_bias3		t_vec;
typedef struct s_bias3		t_uvec;
typedef struct s_bias3		t_point;
typedef struct s_bias3		t_color;

typedef struct s_bias2		t_map;
typedef struct s_bias2		t_size;

typedef struct s_vbias3		t_frame;
typedef struct s_vbias2		t_grid;

enum e_name
{
	SPHERE,
	CYLNDR,
	PLANE,
	TX_SOLID,
	TX_CHKER,
	TX_BUMP
};

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

struct s_vbias3
{
	t_vec	u;
	t_vec	v;
	t_vec	w;
};

struct s_vbias2
{
	t_vec	u;
	t_vec	v;
};

/* RAY */
typedef struct s_ray		t_ray;
typedef struct s_interval	t_intvl;
typedef struct s_material	t_mtral;
typedef struct s_texture	t_txtr;
typedef struct s_hit		t_hit;
typedef struct s_equation	t_eqa;
typedef struct s_phong		t_phong;

struct s_ray
{
	t_point	org;
	t_vec	dir;
};

struct s_interval
{
	t_scl	min;
	t_scl	max;
};

struct s_hit
{
	t_point			point;
	t_scl			t;
	t_uvec			normal;
	t_bool			face;
	t_map			map;
	const t_txtr	*txtr;
};

struct s_equation
{
	t_vec	oc;
	t_scl	a;
	t_scl	b_half;
	t_scl	c;
	t_scl	dscr;
};

struct s_phong
{
	t_color	light;
	t_scl	diffuse;
	t_scl	specular;
};

/* OBJECTS */
typedef struct s_light		t_light;
typedef struct s_circle		t_circle;
typedef struct s_square		t_square;
typedef struct s_value		t_value;
typedef struct s_obj		t_obj;
typedef struct s_world		t_world;

typedef t_bool				(*t_fp_hit)(const t_obj *obj, const t_ray *r,
	t_intvl intvl, t_hit *rec);
typedef t_color				(*t_fp_value)(const t_hit *rec);

struct s_light
{
	t_point	point;
	t_color	albedo;
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

struct s_value
{
	t_circle	cir;
	t_square	sqr;
	t_uvec		axis;
	t_scl		height;
};

struct s_texture
{
	t_fp_value	value;
	t_color		albedo1;
	t_color		albedo2;
	t_scl		scale;
};

struct s_obj
{
	t_name		name;
	t_value		val;
	t_fp_hit	hit;
	t_txtr		txtr;
};

struct s_world
{
	t_list	*objs;
	t_list	*lights;
	t_color	ambient;
};

/* SCENE */
typedef struct s_image		t_image;
typedef struct s_camera		t_camera;
typedef struct s_view		t_view;
typedef struct s_scene		t_scene;

struct s_image
{
	t_size	size;
	t_scl	aspect;
};

struct s_view
{
	t_point	pxl00;
	t_grid	pxl;
};

struct s_camera
{
	t_point	from;
	t_point	at;
	t_scl	fov;
	t_frame	frame;
};

struct s_scene
{
	t_camera	cam;
	t_image		img;
	t_view		view;
};

/* MLX */
typedef struct s_window		t_win;

enum e_key
{
	ESC = 53
};

struct s_window
{
	t_size	size;
	void	*mlx;
	void	*ptr;
};

/* DATA */
typedef enum e_element		t_element;
typedef struct s_render		t_render;

enum e_element
{
	A,
	C,
	L,
	SP,
	PL,
	CY
};

struct s_render
{
	t_win	window;
	t_scene	scene;
	t_world	world;
};

#endif