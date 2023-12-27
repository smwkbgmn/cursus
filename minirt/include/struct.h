/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:30:19 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 07:08:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef double			t_bias;
typedef double			t_scl;

typedef struct s_bias3	t_crd;
typedef struct s_bias3	t_vec;
typedef struct s_bias3	t_uvec;
typedef struct s_bias3	t_color;
typedef struct s_bias2	t_size;

typedef struct s_ray	t_ray;
typedef struct s_window	t_win;
typedef struct s_canvas	t_canvas;
typedef struct s_camera	t_camera;

typedef struct s_plane		t_plane;
typedef struct s_circle		t_circle;
typedef struct s_sphere		t_sphere;
typedef struct s_cylinder	t_cylinder;

struct s_bias3
{
	t_bias	x;
	t_bias	y;
	t_bias	z;
};

struct s_bias2
{
	t_bias	x;
	t_bias	y;
};

struct s_ray
{
	t_crd	org;
	t_uvec	unit;
};

struct s_window
{
	void	*mlx;
	void	*ptr;
};

struct s_canvas
{
	t_size	size;
	t_scl	aspect;
};

struct s_camera
{
	t_crd	crd;
	t_size	view;
	t_vec	horizon;
	t_vec	vertical;
	t_scl	len_focal;
	t_crd	left_bottom;
};

struct s_plane
{
	t_crd	point;
	t_uvec	normal;
	t_color	color;
};

struct s_circle
{
	t_crd	center;
	t_scl	dia;
};

struct s_sphere
{
	t_circle	circle;
	t_color		color;
};

struct s_cylinder
{
	t_circle	circle;
	t_uvec		axis;
	t_scl		height;
	t_color		color;
}

#endif