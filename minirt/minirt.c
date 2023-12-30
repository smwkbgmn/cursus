/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/30 14:20:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sky(void);

int	main(void)
{
	// static t_list	*data;
	// static t_win	win;

	// init(&win);
	// mlx_loop(win.mlx);

	sky();
	
	return (EXIT_SUCCESS);
}

void	sky(void)
{
	t_scl	w, h;

	t_canvas	cvs;
	t_camera	cam;
	t_view		view;
	
	t_ray		r;

	t_crd		pixel_center;
	t_vec		ray_direc;

	cvs = canvas();
	cam = camera();
	view = viewport(&cvs, &cam);

	printf("P3\n%d %d\n%d\n", (int)cvs.size.x, (int)cvs.size.y, CLR_SCALE);
	
	h = 0;
	while (h < cvs.size.y)
	{
		w = 0;
		while (w < cvs.size.x)
		{
			pixel_center = ad(view.pixel00_loc, ad(mt(view.delta.h, w), mt(view.delta.v, h)));
			ray_direc = sb(pixel_center, cam.pos);
			r = ray(cam.pos, ray_direc);

			put_pixel(ray_color(&r));
			w++;
		}
		h++;
	}
}
