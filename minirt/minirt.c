/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/04 12:35:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*new_sphere(t_point center, t_scl radius);

int	main(void)
{
	// static t_list	*data;
	// static t_win	win;

	// init(&win);
	// mlx_loop(win.mlx);

	// sky_sphere();

	// t_scl	R = cos(PI / 4);

	t_list	*objs = NULL;

	ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(0, 0, -1), 0.5)));
	ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(0, -100.5, -1), 100)));

	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(-R, 0, -1), R)));
	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(R, 0, -1), R)));

	t_camera	cam = camera(16.0 / 9.0, 400, 90, 100, 50);

	render(objs, &cam);
	
	return (EXIT_SUCCESS);
}

t_obj	*new_sphere(t_point center, t_scl radius)
{
	t_obj	*sp = ft_calloc(1, sizeof(t_obj));

	sp->name = SPHERE;
	sp->val.cir.center = center;
	sp->val.cir.radius = radius;
	return (sp);
}
