/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/02 11:48:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*new_sphere(t_point center, t_scl radius);
void	sky_sphere(void);

int	main(void)
{
	// static t_list	*data;
	// static t_win	win;

	// init(&win);
	// mlx_loop(win.mlx);

	sky_sphere();
	
	return (EXIT_SUCCESS);
}

void	sky_sphere(void)
{
	// OBJECTS
	t_list	*objs = NULL;

	ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(0, 0, -1), 0.5)));
	ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(0, -100.5, -1), 100)));

	// IMAGE
	t_scl	aspect = 16.0 / 9.0;
	int		w = 400;
	int		h = (int)(w / aspect);
	if (h < 1)
		h = 1;

	// CAMERA
	t_scl	fclen = 1.0;
	t_scl	view_h = 2.0;
	t_scl	view_w = view_h * ((t_scl)w / h);
	t_point	cam_center = point(0, 0, 0);

	// VIEWPORT
	t_vec	view_grid_w = vec(view_w, 0, 0);
	t_vec	view_grid_h = vec(0, -1 * view_h, 0);
	t_vec	view_delta_w = dv(view_grid_w, (t_scl)w);
	t_vec	view_delta_h = dv(view_grid_h, (t_scl)h);

	t_point	upleft;
	upleft = sb(cam_center, vec(0, 0, fclen));
	upleft = sb(upleft, dv(view_grid_w, 2));
	upleft = sb(upleft, dv(view_grid_h, 2));

	t_point	pxl00;
	pxl00 = ad(upleft, mt(ad(view_delta_w, view_delta_h), 0.5));

	// RENDER
	printf("P3\n%d %d\n%d\n", w, h, CLR_SCALE);

	int		x, y;
	
	t_point	pxl_center;
	t_vec	r_direc;
	t_ray	r;

	t_color	color;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			pxl_center = ad(pxl00, ad(mt(view_delta_w, (t_scl)x), mt(view_delta_h, (t_scl)y)));
			r_direc = sb(pxl_center, cam_center);
			r.origin = cam_center;
			r.direc = r_direc;
			
			color = ray_color(&r, objs);
			write_color(color);
			
			x++;
		}
		y++;
	}
}

t_obj	*new_sphere(t_point center, t_scl radius)
{
	t_obj	*sp = ft_calloc(1, sizeof(t_obj));

	sp->val.cir.center = center;
	sp->val.cir.radius = radius;
	return (sp);
}
