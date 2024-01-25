/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:02:33 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 09:29:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static int	count_arg(char **argv);

void	get_essential(t_element elem, char **argv, t_render *data, int *essential)
{
	if (elem == A && count_arg(argv) == 2)
	{
		if (essential[A]++)
			err_usr("multiple 'Ambient' has found");
		data->world.ambient = albedo_rgb(get_color(argv[1]),
			get_scl(argv[0], interval(0, 1)));
	}
	else if (elem == C && count_arg(argv) == 3)
	{
		if (essential[C]++)
			err_usr("multiple 'Camera' has found");
		data->scene.cam = camera(get_point(argv[0]), get_point(argv[1]),
			get_scl(argv[2], interval(0, 180)));
	}
	else if (elem == L && count_arg(argv) == 3)
	{
		essential[L]++;
		ft_lstadd_back(&data->world.lights, try(ft_lstnew(light(
			get_point(argv[0]), get_color(argv[2]),
			get_scl(argv[1], interval(0, 1))))));
	}
	else
		err_usr("element specification dosen't fit in as required");
}

void	get_object(t_element elem, char **argv, t_render *data)
{
	if (elem == SP && count_arg(argv) == 3)
		ft_lstadd_back(&data->world.objs, try(ft_lstnew(sphere(circle(
			get_point(argv[0]),
			get_scl(argv[1], interval(0, SCL_MAX))),
			texture(TX_SOLID, get_color(argv[2]), color(0, 0, 0), NONE)))));	
	else if (elem == PL && count_arg(argv) == 3)
		ft_lstadd_back(&data->world.objs, try(ft_lstnew(plane(
			get_point(argv[0]),
			get_vec(argv[1], interval(-1, 1)),
			texture(TX_SOLID, get_color(argv[2]), color(0, 0, 0), NONE)))));
	else if (elem == CY && count_arg(argv) == 4)
		ft_lstadd_back(&data->world.objs, try(ft_lstnew(cylinder(circle(
			get_point(argv[0]),
			get_scl(argv[2], interval(0, SCL_MAX))),
			get_scl(argv[3], interval(0, SCL_MAX)),
			get_vec(argv[1], interval(-1, 1)),
			texture(TX_SOLID, get_color(argv[2]), color(0, 0, 0), NONE)))));
	else
		err_usr("found missing parameter for the object element");
}

static int	count_arg(char **argv)
{
	int	cnt;

	cnt = 0;
	while (*argv)
	{
		cnt++;
		argv++;
	}
	return (cnt);
}
