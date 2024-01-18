/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/18 19:31:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parsing
// Init MLX

// Ambient lighting (+color) > ray_color & see within light object
// Multiple light point
// Correct plane hit equation
// Implement cylinder
// Add one more object > Cone

#include "minirt.h"

void	test_plane(void);

int	main(void)
{
	// test_plane();

	t_world	world;

	world.objs = NULL;
	world.lights = NULL;
	world.ambient = albedo_rgb(color(255, 255, 255), 0.0);

	// ft_lstadd_back(&world.lights, ft_lstnew(light(point(-10, 5, 10), color(255, 255, 255), 1)));
	ft_lstadd_back(&world.lights, ft_lstnew(light(point(0, 7, 0), color(255, 255, 255), 1.0)));
	// ft_lstadd_back(&world.lights, ft_lstnew(light(point(0, 7, 0), color(255, 255, 255), 0.9)));
	// ft_lstadd_back(&world.lights, ft_lstnew(light(point(3, 3, 0), color(255, 255, 255), 0.3)));
	// ft_lstadd_back(&world.lights, ft_lstnew(light(point(-3, 3, 0), color(255, 255, 255), 0.6)));

	// ft_lstadd_back(&world.objs, ft_lstnew(sphere(point(0, 0, 0), 1,
	ft_lstadd_back(&world.objs, ft_lstnew(sphere(point(0, 0, -1), 0.5,
		material(MT_LMBRT, NONE, NONE,
		texture(TX_SOLID, color(0, 0, 1), color(0, 0, 0), NONE)))));

	// ft_lstadd_back(&world.objs, ft_lstnew(sphere(point(0, 0, -1), 0.5,
	// 	material(MT_DIELCT, NONE, NONE,
	// 	texture(TX_SOLID, color(1, 1, 1), color(0, 0, 0), NONE)))));

	// ft_lstadd_back(&world.objs, ft_lstnew(sphere(point(0, -100.5, -1), 100,
	ft_lstadd_back(&world.objs, ft_lstnew(sphere(point(0, -5.5, -1), 5,
		material(MT_LMBRT, NONE, NONE,
		texture(TX_SOLID, color(0, 1, 0), color(0, 0, 0), NONE)))));
		
	t_scene	scene;

	scene.img = image(16.0 / 9.0, 1200);
	scene.cam = camera(point(5, 5, 5), point(0, 0, -1), vec(0, 100, 0), 90);
	scene.view = viewport(&scene);

	render(&scene, &world);
	
	return (EXIT_SUCCESS);
}

void	test_plane(void)
{
	t_world	world;

	world.objs = NULL;
	world.lights = NULL;
	world.ambient = albedo_rgb(color(255, 255, 255), 0.0);
	
	t_color	nocolor = color(0, 0, 0);
	
	t_txtr	col1 = texture(TX_SOLID, color(1.0, 0.2, 0.2), nocolor, NONE);
	t_txtr	col2 = texture(TX_SOLID, color(0.2, 1.0, 0.2), nocolor, NONE);
	t_txtr	col3 = texture(TX_SOLID, color(0.2, 0.2, 1.0), nocolor, NONE);
	t_txtr	col4 = texture(TX_SOLID, color(1.0, 0.5, 0.0), nocolor, NONE);
	t_txtr	col5 = texture(TX_SOLID, color(0.2, 0.8, 0.8), nocolor, NONE);

	t_mtral	left_red	= material(MT_LMBRT, NONE, NONE, col1);
	t_mtral	back_green	= material(MT_LMBRT, NONE, NONE, col2);
	t_mtral	right_blue	= material(MT_LMBRT, NONE, NONE, col3);
	t_mtral	up_orange	= material(MT_LMBRT, NONE, NONE, col4);
	t_mtral	lo_teal		= material(MT_LMBRT, NONE, NONE, col5);

	ft_lstadd_back(&world.objs, ft_lstnew(plane(point(-3, -2,  5), vec( 0,  0, -4), vec( 0,  4,  0), left_red)));
	ft_lstadd_back(&world.objs, ft_lstnew(plane(point(-2, -2,  0), vec( 4,  0,  0), vec( 0,  4,  0), back_green)));
	ft_lstadd_back(&world.objs, ft_lstnew(plane(point( 3, -2,  1), vec( 0,  0,  4), vec( 0,  4,  0), right_blue)));
	ft_lstadd_back(&world.objs, ft_lstnew(plane(point(-2,  3,  1), vec( 4,  0,  0), vec( 0,  0,  4), up_orange)));
	ft_lstadd_back(&world.objs, ft_lstnew(plane(point(-2, -3,  5), vec( 4,  0,  0), vec( 0,  0, -4), lo_teal)));

	ft_lstadd_back(&world.lights, ft_lstnew(light(point(0, 0, 9), color(255, 255, 255), 0.7)));

	t_scene	scene;

	scene.cam = camera(point(0, 0, 9), point(0, 0, 0), vec(0, 1, 0), 80);
	scene.img = image(1.0, 1600);
	scene.view = viewport(&scene);

	render(&scene, &world);
}
