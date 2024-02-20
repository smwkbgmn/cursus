/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:33:08 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 19:11:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	meet_light(const t_hit *rec,
					t_list *objs, const t_light *light, t_scl len);
static void		apply(t_phong phong, t_color *dim, t_color *high,
					t_scl len);
static t_color	light_attenuation(t_color light, t_scl len);

t_color	color(t_scl x, t_scl y, t_scl z)
{
	t_color	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}

t_color	color_at(const t_hit *rec, const t_world *world, t_uvec dir_view)
{
	t_list	*lights;
	t_scl	len;
	t_color	dim;
	t_color	high;

	lights = world->lights;
	dim = world->ambient;
	high = color(0, 0, 0);
	while (lights)
	{
		len = length(sb(((t_light *)lights->content)->point, rec->point));
		if (meet_light(rec, world->objs, lights->content, len))
			apply(phong(rec, lights->content, dir_view), &dim, &high, len);
		lights = lights->next;
	}
	return (ad(mtv(rec->txtr->value(rec), dim), high));
}

static t_bool	meet_light(const t_hit *rec,
	t_list *objs, const t_light *light, t_scl len)
{
	t_ray	ray_to_light;
	t_hit	rec_to_light;

	ft_memset(&rec_to_light, NONE, sizeof(t_hit));
	ray_to_light = ray(rec->point, direction(rec->point, light->point));
	if (hit(objs, &ray_to_light, interval(0.001, len), &rec_to_light))
		return (FALSE);
	return (TRUE);
}

static void	apply(t_phong phong, t_color *dim, t_color *high,
	t_scl len)
{
	*dim = ad(*dim,
			mt(light_attenuation(phong.light, len), phong.diffuse));
	*high = ad(*high,
			mt(mt(mt(light_attenuation(phong.light, len),
						phong.specular), SPEC_INTENS), phong.diffuse));
}

static t_color	light_attenuation(t_color light, t_scl len)
{
	return (mt(light, fmax(LIGHT_MAGNI / len, 0.0)));
}
