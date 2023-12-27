/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 05:10:50 by donghyu2         ###   ########.fr       */
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
	t_scl	u, v;

	t_color		color;
	t_canvas	cvs;
	t_camera	cam;
	t_ray		ray;

	cvs = canvas(400, 300);
	cam = camera(&cvs, coordi(0, 0, 0));

	printf("P3\n%d %d\n%d\n", (int)cvs.size.x, (int)cvs.size.y, CLR_SCALE);
	
	h = cvs.size.y - 1;
	while (h >= 0)
	{
		w = 0;
		while (w < cvs.size.x)
		{
			u = w / cvs.size.x - 1;
			v = h / cvs.size.y - 1;
			ray = ray_primary(&cam, u, v);
			color = ray_color(&ray);
			
			put_pixel(color);
			w++;
		}
		h--;
	}
}
