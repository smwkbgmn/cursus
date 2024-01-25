/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 09:24:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implement cylinder
// Add one more object > Cone
// Test min, max of point and sclar value

// Remove function not allowed
// See including headers
// Check diameter

#include "minirt.h"

void	test_box(t_render *data);
void	test_sphere(t_render *data);
// void	test_plane_lightatnu(void);
void	print_data(t_render *data);

void	set_window(t_win *win, t_size size);

int	main(void)
{
	t_render	data;
	
	char		fname[50] = "test.rt";
	init(fname, &data);
	print_data(&data);

	// test_box(&data);
	// test_sphere(&data);

	render(&data);
	
	return (EXIT_SUCCESS);
}


void	test_sphere(t_render *data)
{
	data->world.objs = NULL;
	data->world.lights = NULL;
	data->world.ambient = albedo_rgb(color(255, 255, 255), 0.0015);

	// ft_lstadd_back(&data->world.lights, ft_lstnew(light(point(-10, 5, 10), color(255, 255, 255), 1)));
	// ft_lstadd_back(&data->world.lights, ft_lstnew(light(point(0, 7, 0), color(255, 255, 255), 1.0)));
	// ft_lstadd_back(&data->world.lights, ft_lstnew(light(point(0, 7, 0), color(255, 255, 255), 0.9)));
	ft_lstadd_back(&data->world.lights, ft_lstnew(light(point(5, 5, 0), color(255, 255, 255), 1)));
	// ft_lstadd_back(&data->world.lights, ft_lstnew(light(point(-3, 3, 0), color(255, 255, 255), 0.6)));

	// ft_lstadd_back(&data->world.objs, ft_lstnew(sphere(point(0, 0, 0), 1,
	ft_lstadd_back(&data->world.objs, ft_lstnew(sphere(circle(point(0, 0, -1), 0.5),
		texture(TX_SOLID, color(0, 0, 255), color(0, 0, 0), NONE))));

	// ft_lstadd_back(&data->world.objs, ft_lstnew(sphere(point(0, 0, -1), 0.5,
	// 	texture(TX_SOLID, color(1, 1, 1), color(0, 0, 0), NONE))));

	// ft_lstadd_back(&data->world.objs, ft_lstnew(sphere(point(0, -100.5, -1), 100,
	ft_lstadd_back(&data->world.objs, ft_lstnew(sphere(circle(point(0, -100.5, -1), 100),
		texture(TX_CHKER, color(200, 0, 0), color(0, 200, 0), 1.5))));
		
	data->scene.img = image(16.0 / 9.0, 1200);
	data->scene.cam = camera(point(0, 0, 1), point(0, 0, -1), 90);
	data->scene.view = viewport(&data->scene);

	set_window(&data->window, data->scene.img.size);
	print_data(data);
}

void	test_box(t_render *data)
{	
	data->world.objs = NULL;
	data->world.lights = NULL;
	data->world.ambient = albedo_rgb(color(255, 255, 255), 0);
	
	t_color	nocolor = color(0, 0, 0);
	
	// t_txtr	col1 = texture(TX_SOLID, color(0.5, 0.5, 0.5), nocolor, NONE);
	// t_txtr	col2 = texture(TX_SOLID, color(1.0, 0.2, 0.2), nocolor, NONE);
	// t_txtr	col3 = texture(TX_SOLID, color(0.2, 0.2, 1.0), nocolor, NONE);
	// t_txtr	col4 = texture(TX_SOLID, color(1.0, 0.5, 0.0), nocolor, NONE);
	// t_txtr	col5 = texture(TX_SOLID, color(0.2, 0.8, 0.8), nocolor, NONE);

	t_txtr	col1 = texture(TX_SOLID, color(130, 130, 130), nocolor, NONE);
	t_txtr	col2 = texture(TX_SOLID, color(255, 70, 70), nocolor, NONE);
	t_txtr	col3 = texture(TX_SOLID, color(70, 70, 255), nocolor, NONE);
	t_txtr	col4 = texture(TX_SOLID, color(70, 230, 230), nocolor, NONE);
	t_txtr	col5 = texture(TX_SOLID, color(230, 130, 0), nocolor, NONE);

	// t_txtr	col1 = texture(TX_SOLID, color(0.5, 0.5, 0.5), nocolor, NONE);
	// t_txtr	col2 = texture(TX_SOLID, color(0.5, 0.5, 0.5), nocolor, NONE);
	// t_txtr	col3 = texture(TX_SOLID, color(0.5, 0.5, 0.5), nocolor, NONE);
	// t_txtr	col4 = texture(TX_SOLID, color(0.5, 0.5, 0.5), nocolor, NONE);
	// t_txtr	col5 = texture(TX_SOLID, color(0.5, 0.5, 0.5), nocolor, NONE);

	ft_lstadd_back(&data->world.objs, ft_lstnew(plane(point(  0,   0,  0), vec( 0,  0,  1), col1)));
	ft_lstadd_back(&data->world.objs, ft_lstnew(plane(point(-10,   0,  0), vec( 1,  0,  0), col2)));
	ft_lstadd_back(&data->world.objs, ft_lstnew(plane(point( 10,   0,  0), vec(-1,  0,  0), col3)));
	ft_lstadd_back(&data->world.objs, ft_lstnew(plane(point(  0,  10,  0), vec( 0, -1,  0), col4)));
	ft_lstadd_back(&data->world.objs, ft_lstnew(plane(point(  0, -10,  0), vec( 0,  1,  0), col5)));

	// ft_lstadd_back(&data->world.objs, ft_lstnew(
	// 	sphere(point(0, 0, 0), 0.5,
	// 		material(MT_LMBRT, NONE, NONE,
	// 			texture(TX_SOLID, color(0.5, 0.5, 0.5), color(0, 0, 0), NONE)))));

	// ft_lstadd_back(&data->world.lights, ft_lstnew(light(point(0, 0, 5), color(255, 255, 255), 1)));
	// ft_lstadd_back(&data->world.lights, ft_lstnew(light(point(0, 0, 10), color(255, 255, 255), 1)));
	ft_lstadd_back(&data->world.lights, ft_lstnew(light(point(0, 0, 50), color(255, 255, 255), 1)));

	data->scene.cam = camera(point(0, 0, 50), point(0, 0, 0), 80);
	data->scene.img = image(16.0 / 9.0, 1000);
	data->scene.view = viewport(&data->scene);

	set_window(&data->window, data->scene.img.size);
	print_data(data);
}

// void	test_plane_lightatnu(void)
// {
// 	t_world	data->world;

// 	data->world.objs = NULL;
// 	data->world.lights = NULL;
// 	data->world.ambient = albedo_rgb(0.0, color(0, 0, 0));

// 	ft_lstadd_back(&data->world.objs, ft_lstnew(
// 		plane(point(0, 0, -10), point(0, 0, 1),
// 			material(MT_LMBRT, NONE, NONE,
// 				texture(TX_SOLID, color(0.2, 0.5, 0.8), color(0, 0, 0), NONE)))));
	
// 	ft_lstadd_back(&data->world.lights, ft_lstnew(light(point(0, 0, 10), color(255, 255, 255), 1.0)));

// 	t_scene	scene;

// 	scene.cam = camera(point(0, 0, 0), point(0, 0, -1), point(0, 1, 0), 90);
// 	scene.img = image(16 / 9, 1200);
// 	scene.view = viewport(&scene);
	
// 	render(&scene, &data->world);
// }
