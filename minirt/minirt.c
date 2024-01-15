/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/15 18:07:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parsing
// Init MLX

// Light source
// Consider Phong reflection model 

// Ambient lighting (+color) > ray_color & see within light object
// Multiple light point > light object
// Phong reflection model (currently Snell's law)
// Add one more object > Cone

// How to turning off antialiasing? > ray_color
// Correct way of light source > sctter in material

#include "minirt.h"

void	test_sphere(void);
void	test_checker(void);
void	test_sphere_world(void);
void	test_plane(void);
void	test_final(void);

int	main(void)
{
	// test_final();
	
	t_list	*objs = NULL;

	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, 0, -1), 0.5,
		material(MT_LMBRT, NONE, NONE,
		texture(TX_SOLID, color(0.0, 0.0, 1.0), color(0, 0, 0), NONE)))));

	// ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, 0, -1), 0.5,
	// 	material(MT_DIELCT, NONE, NONE,
	// 	texture(TX_SOLID, color(1, 1, 1), color(0, 0, 0), NONE)))));

	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, -100.5, -1), 100,
		material(MT_LMBRT, NONE, NONE,
		texture(TX_SOLID, color(0.0, 1.0, 0.0), color(0, 0, 0), NONE)))));
		
	t_scene	scene;

	scene.img = image(16.0 / 9.0, 1200);
	scene.cam = camera(point(0, 0, 0), point(0, 0, -1), vec(0, 1, 0), 90);
	scene.view = viewport(&scene);
	scene.sample = 15;
	scene.depth = 50;

	render(objs, &scene);
	
	return (EXIT_SUCCESS);
}

// void	test_sphere(void)
// {
// 	// SET MATERIAL
// 	// t_scl	R = cos(PI / 4);

// 	t_mtral	mtral_ground = material(MT_LMBRT, color(0.8, 0.8, 0.0), 0, 0);
// 	t_mtral	mtral_center = material(MT_LMBRT, color(0.1, 0.2, 0.5), 0, 0);
// 	t_mtral	mtral_left = material(MT_DIELCT, color(0, 0, 0), 0, 1.5);
// 	// t_mtral	mtral_center = material(MT_DIELCT, color(0, 0, 0), 0, 1.5);
// 	// t_mtral	mtral_left = material(MT_DIELCT, color(0, 0, 0), 0, 1.5);
// 	t_mtral	mtral_right = material(MT_METAL, color(0.8, 0.6, 0.2), 0.0, 0);

// 	// SET OBJECTS
// 	t_list	*objs = NULL;

// 	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(0, 0, -1), 0.5)));
// 	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(0, -100.5, -1), 100)));

// 	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(-R, 0, -1), R)));
// 	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(R, 0, -1), R)));

// 	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0.0	,-100.5	,-1.0	), 100.0	, mtral_ground)));
// 	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0.0	,0.0	,-1.0	), 0.5		, &mtral_center)));
// 	ft_lstadd_back(&objs, ft_lstnew(sphere(point(-1.0	,0.0	,-1.0	), 0.5		, &mtral_left)));
// 	ft_lstadd_back(&objs, ft_lstnew(sphere(point(-1.0	,0.0	,-1.0	), -0.4		, &mtral_left)));
// 	ft_lstadd_back(&objs, ft_lstnew(sphere(point(1.0	,0.0	,-1.0	), 0.5		, &mtral_right)));

// 	// SET SCENE
// 	// t_camera	cam = camera(16.0 / 9.0, 800, 120, 100, 50);
// 	t_scene	scene;

// 	scene.cam = camera(point(-2, 2, 1), point(0, 0, -1), vec(0, 1, 0), 20);
// 	scene.img = image(16.0 / 9.0, 1200);
// 	scene.view = viewport(&scene);
// 	scene.sample = 100;
// 	scene.depth = 50;

// 	render(objs, &scene);		
// }

void test_checker(void)
{
	t_list	*objs = NULL;

	t_txtr	tx_checker = texture(TX_CHKER, color(.2, .3, .1), color(.9, .9, .9), 0.8);
	t_mtral	mt_solid = material(MT_LMBRT, NONE, NONE, tx_checker);
	
	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, -10, 0), 10, mt_solid)));
	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, 10, 0), 10, mt_solid)));

	t_scene	scene;

	scene.cam = camera(point(13, 2, 3), point(0, 0, 0), vec(0, 1, 0), 20);
	scene.img = image(16.0 / 9.0, 400);
	scene.view = viewport(&scene);
	scene.sample = 100;
	scene.depth = 50;

	render(objs, &scene);
}

void	test_sphere_world(void)
{
	// t_color	none = color(0, 0, 0);
	t_list	*objs = NULL;

	
	// t_mtral	mtral_ground = material(MT_LMBRT, color(0.5, 0.5, 0.5), 0, 0);
	t_mtral	mtral_ground = material(MT_LMBRT, NONE, NONE, texture(TX_CHKER, color(.2, .3, .1), color(.9, .9, .9), 0.32));
	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, -1000, 0), 1000, mtral_ground)));

	// t_mtral	mtral_sphere[500];
	// int		mtral_idx = 0;
	
	// int	a = -11;
	// while (a++ < 11)
	// {
	// 	int b = -11;
	// 	while (b++ < 11)
	// 	{
	// 		t_scl	choose_mtral = randn();
	// 		t_point	center = point(a + 0.9 * randn(), 0.2, b + 0.9 * randn());
			
	// 		if (length(sb(center, point(4, 0.2, 0))) > 0.9)
	// 		{

	// 			if (choose_mtral < 0.8)
	// 			{
	// 				t_color	albedo = mtv(randv(), randv());

	// 				mtral_sphere[mtral_idx] = material(MT_LMBRT, NONE, NONE, texture(TX_SOLID, albedo, none, NONE));
	// 				ft_lstadd_back(&objs, ft_lstnew(sphere(center, 0.2, mtral_sphere[mtral_idx++])));
	// 			}
	// 			else if (choose_mtral < 0.95)
	// 			{
	// 				t_color	albedo = randv_range(0.5, 1);
	// 				t_scl	fuzz = randn_range(0, 0.5);
	// 				mtral_sphere[mtral_idx] = material(MT_METAL, fuzz, NONE, texture(TX_SOLID, albedo, none, NONE));
	// 				ft_lstadd_back(&objs, ft_lstnew(sphere(center, 0.2, mtral_sphere[mtral_idx++])));
	// 			}
	// 			else
	// 			{
	// 				mtral_sphere[mtral_idx] = material(MT_DIELCT, NONE, 1.5, texture(TX_SOLID, none, none, NONE));
	// 				ft_lstadd_back(&objs, ft_lstnew(sphere(center, 0.2, mtral_sphere[mtral_idx++])));
	// 			}
	// 		}
	// 	}
	// }
	
	// // t_mtral	mtral1 = material(MT_DIELCT, color(NONE, NONE, NONE), NONE, 1.5);
	// t_mtral	mtral1 = material(MT_DIELCT, NONE, 1.5, texture(TX_SOLID, none, none, NONE));
	// ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, 1, 0), 1.0, &mtral1)));

	// t_mtral	mtral2 = material(MT_LMBRT, NONE, NONE, texture(TX_SOLID, color(0.4, 0.2, 0.1), none, NONE));
	// ft_lstadd_back(&objs, ft_lstnew(sphere(point(-4, 1, 0), 1.0, &mtral2)));

	// t_mtral	mtral3 = material(MT_METAL, 0.0, NONE, texture(TX_SOLID, color(0.7, 0.6, 0.5), none, NONE));
	// ft_lstadd_back(&objs, ft_lstnew(sphere(point(4, 1, 0), 1.0, &mtral3)));

	t_scene	scene;

	scene.img = image(16.0 / 9.0, 600);
	scene.sample = 50;
	scene.depth = 50;
	scene.cam = camera(point(13, 2, 3), point(0, 0, 0), vec(0, 1, 0), 20);
	scene.view = viewport(&scene);

	render(objs, &scene);
}

// void	test_sphere_world(void)
// {
// 	t_list	*objs = NULL;

// 	t_mtral	mtral_ground = material(MT_LMBRT, color(0.5, 0.5, 0.5), 0, 0);
// 	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, -1000, 0), 1000, mtral_ground)));

// 	t_mtral	mtral_sphere[500];
// 	int		mtral_idx = 0;
	
// 	int	a = -11;
// 	while (a++ < 11)
// 	{
// 		int b = -11;
// 		while (b++ < 11)
// 		{
// 			t_scl	choose_mtral = randn();
// 			t_point	center = point(a + 0.9 * randn(), 0.2, b + 0.9 * randn());

			
// 			if (length(sb(center, point(4, 0.2, 0))) > 0.9)
// 			{

// 				if (choose_mtral < 0.8)
// 				{
// 					t_color	albedo = mtv(randv(), randv());
// 					mtral_sphere[mtral_idx] = material(MT_LMBRT, albedo, NONE, NONE);
// 					ft_lstadd_back(&objs, ft_lstnew(sphere(center, 0.2, mtral_sphere[mtral_idx++])));
// 				}
// 				else if (choose_mtral < 0.95)
// 				{
// 					t_color	albedo = randv_range(0.5, 1);
// 					t_scl	fuzz = randn_range(0, 0.5);
// 					mtral_sphere[mtral_idx] = material(MT_METAL, albedo, fuzz, NONE);
// 					ft_lstadd_back(&objs, ft_lstnew(sphere(center, 0.2, mtral_sphere[mtral_idx++])));
// 				}
// 				else
// 				{
// 					mtral_sphere[mtral_idx] = material(MT_DIELCT, color(NONE, NONE, NONE), NONE, 1.5);
// 					ft_lstadd_back(&objs, ft_lstnew(sphere(center, 0.2, mtral_sphere[mtral_idx++])));
// 				}
// 			}
// 		}
// 	}
	
// 	t_mtral	mtral1 = material(MT_DIELCT, color(NONE, NONE, NONE), NONE, 1.5);
// 	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, 1, 0), 1.0, &mtral1)));

// 	t_mtral	mtral2 = material(MT_LMBRT, color(0.4, 0.2, 0.1), NONE, NONE);
// 	ft_lstadd_back(&objs, ft_lstnew(sphere(point(-4, 1, 0), 1.0, &mtral2)));

// 	t_mtral	mtral3 = material(MT_METAL, color(0.7, 0.6, 0.5), 0.0, NONE);
// 	ft_lstadd_back(&objs, ft_lstnew(sphere(point(4, 1, 0), 1.0, &mtral3)));

// 	t_scene	scene;

// 	scene.img = image(16.0 / 9.0, 600);
// 	scene.sample = 50;
// 	scene.depth = 50;
// 	scene.cam = camera(point(13, 2, 3), point(0, 0, 0), vec(0, 1, 0), 20);
// 	scene.view = viewport(&scene);

// 	render(objs, &scene);
// }

// void	test_plane(void)
// {
// 	t_mtral	left_red	= material(MT_LMBRT, color(1.0, 0.2, 0.2), NONE, NONE);
// 	t_mtral	back_green	= material(MT_LMBRT, color(0.2, 1.0, 0.2), NONE, NONE);
// 	t_mtral	right_blue	= material(MT_LMBRT, color(0.2, 0.2, 1.0), NONE, NONE);
// 	t_mtral	up_orange	= material(MT_LMBRT, color(1.0, 0.5, 0.0), NONE, NONE);
// 	t_mtral	lo_teal		= material(MT_LMBRT, color(0.2, 0.8, 0.8), NONE, NONE);

// 	t_list	*objs = NULL;

// 	ft_lstadd_back(&objs, ft_lstnew(plane(point(-3, -2,  5), vec( 0,  0, -4), vec( 0,  4,  0), &left_red)));
// 	ft_lstadd_back(&objs, ft_lstnew(plane(point(-2, -2,  0), vec( 4,  0,  0), vec( 0,  4,  0), &back_green)));
// 	ft_lstadd_back(&objs, ft_lstnew(plane(point( 3, -2,  1), vec( 0,  0,  4), vec( 0,  4,  0), &right_blue)));
// 	ft_lstadd_back(&objs, ft_lstnew(plane(point(-2,  3,  1), vec( 4,  0,  0), vec( 0,  0,  4), &up_orange)));
// 	ft_lstadd_back(&objs, ft_lstnew(plane(point(-2, -3,  5), vec( 4,  0,  0), vec( 0,  0, -4), &lo_teal)));

// 	t_scene	scene;

// 	scene.cam = camera(point(0, 0, 9), point(0, 0, 0), vec(0, 1, 0), 80);
// 	scene.img = image(1.0, 400);
// 	scene.view = viewport(&scene);
// 	scene.sample = 100;
// 	scene.depth = 50;

// 	render(objs, &scene);

// }

void	test_final(void)
{
	t_list	*objs = NULL;
	
	t_color	nocolor = color(0, 0, 0);

	t_txtr	tx_solid1 = texture(TX_SOLID, color(0.0, 1.0, 0.0), nocolor, NONE);
	t_txtr	tx_solid2 = texture(TX_SOLID, color(0.0, 0.0, 1.0), nocolor, NONE);
	// t_txtr	tx_chker = texture(TX_CHKER, color(.2, .3, .1), color(.9, .9, .9), 0.8);

	t_mtral	mt_lmbrt1 = material(MT_LMBRT, NONE, NONE, tx_solid1);
	t_mtral	mt_lmbrt2 = material(MT_LMBRT, NONE, NONE, tx_solid2);
	// t_mtral	mt_dielct = material(MT_DIELCT, NONE, NONE, tx_solid1);
	// t_mtral	mt_metal = material(MT_METAL, 0.8, NONE, tx_chker);

	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, -1000, 0), 1000, mt_lmbrt1)));
	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0,     2, 0),    2, mt_lmbrt2)));

	// t_txtr	tx_solid3 = texture(TX_SOLID, color(1, 1, 1), nocolor, NONE);
	// t_mtral	mt_light = material(MT_LIGHT, NONE, NONE, tx_solid3);
	
	// ft_lstadd_back(&objs, ft_lstnew(sphere(point(0, 7, 0), 1, mt_light)));
	// ft_lstadd_back(&objs, ft_lstnew(plane(point(3, 1, -2), vec(2, 0, 0), vec(0, 2, 0), mt_light)));

	t_scene	scene;

	scene.cam = camera(point(26, 3, 6), point(0, 2, 0), vec(0, 1, 0), 20);
	scene.img = image(16.0 / 9.0, 1200);
	scene.view = viewport(&scene);
	scene.sample = 100;
	scene.depth = 50;

	render(objs, &scene);
}