/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:17:56 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 19:25:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <fcntl.h>

# include "mlx.h"
# include "ray.h"
# include "error.h"

# define LOOP 1
# define MATCH 0	
# define SCL_MAX 10000000

// free.c
void		erase(const t_render *data);

// parse > parse.c
void		parse(int fd, t_render *data);
void		free_argv(char **argv);

// parse > get_data.c
void		get_essential(t_element elem, char **argv,
				t_render *data, int *essential);
void		get_object(t_element elem, char **argv, t_render *data);

// parse > get_value.c
t_vec		get_vec(char *arg, t_intvl intvl);
t_point		get_point(char *arg);
t_color		get_color(char *arg);
t_scl		get_scl(char *arg, t_intvl intvl);

// parse > strtod.c
t_scl		ft_strtod(char *arg);

// scene.c
t_camera	camera(t_point from, t_uvec at, t_scl fov);
t_image		image(t_scl aspect, t_scl width);
t_view		viewport(const t_scene *scene);
t_point		point(t_scl x, t_scl y, t_scl z);

// object.c
t_circle	circle(t_point center, t_scl diameter);
t_obj		*plane(t_point point_on_plane, t_uvec normal, t_txtr txtr);
t_obj		*sphere(t_circle cir, t_txtr txtr);
t_obj		*cylinder(t_circle cir, t_scl height, t_uvec axis, t_txtr txtr);
t_light		*light(t_point position, t_color rgb, t_scl bright);

// texture.c
t_txtr		texture(char **argv);

// utill.c
t_color		albedo_rgb(t_color rgb, t_scl bright);
t_uvec		valid_normal(t_uvec normal);
t_scl		valid_size(t_scl value);

#endif