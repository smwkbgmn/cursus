/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 07:43:24 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/24 07:07:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>

#include "minirt.h"

static void	set_value(char **argv, t_render *data, int *essential);
static void	which_element(char *arg, t_element *elem);
static void	get_essential(t_element elem, char **argv, t_render *data, int *essential);
static void	get_object(t_element elem, char **argv, t_render *data);
static int	count_arg(char **argv);
static void	free_argv(char **argv);

static void	remove_tail_nl(char *line);

void	parse(int fd, t_render *data)
{
	char	*line;
	int		essential[3];

	ft_memset(&essential, NONE, sizeof(int) * 3);
	while (LOOP)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (*line != '\n')
			{
				remove_tail_nl(line);
				// dprintf(2, "got a line [%s]\n", line);
				set_value(try(ft_split(line, ' ')), data, &essential[0]);
			}
			ft_free(line);
			continue ;
		}
		break ;
	}
	if (!essential[A] || !essential[C] || !essential[L])
		err_usr("ensure there are all essential elements(Ambient, Camera, Light) for rendering");
}

static void	remove_tail_nl(char *line)
{
	char	*nl;

	nl = ft_strrchr(line, '\n');
	if (nl)
		*nl = '\0';
}

// void	print_argv(char **argv)
// {
// 	while (*argv)
// 		dprintf(2, "arg[%s]\n", *(argv++));
// }

static void	set_value(char **argv, t_render *data, int *essential)
{
	t_element	elem;
	
	// print_argv(argv);
	which_element(*argv, &elem);
	if (elem < SP)
		get_essential(elem, argv + 1, data, essential);
	else
		get_object(elem, argv + 1, data);
	free_argv(argv);
}


static void	which_element(char *arg, t_element *elem)
{
	// dprintf(2, "now arg [%s]\n", arg);
	// dprintf(2, "which_element\n");
	if (arg)
	{	
		if (ft_strncmp(arg, "A", 2) == MATCH)
			*elem = A;
		else if (ft_strncmp(arg, "C", 2) == MATCH)
			*elem = C;
		else if (ft_strncmp(arg, "L", 2) == MATCH)
			*elem = L;
		else if (ft_strncmp(arg, "sp", 3) == MATCH)
			*elem = SP;
		else if (ft_strncmp(arg, "pl", 3) == MATCH)
			*elem = PL;
		else if (ft_strncmp(arg, "cy", 3) == MATCH)
			*elem = CY;
		else
			err_usr("unspecified element has found");
	}
	else
		err_usr("empty line has found");
}

static void	get_essential(t_element elem, char **argv, t_render *data, int *essential)
{
	if (elem == A && count_arg(argv) == 2)
	{
		if (essential[A]++)
			err_usr("multiple 'ambient' has found");
		data->world.ambient = albedo_rgb(get_color(argv[1]),
			get_scl(argv[0], interval_set(0, 1)));
	}
	else if (elem == C && count_arg(argv) == 3)
	{
		if (essential[C]++)
			err_usr("multiple 'camera' has found");
		data->scene.cam = camera(get_point(argv[0]),
			get_point(argv[1]),
			get_scl(argv[2], interval_set(0, 180)));
	}
	else if (elem == L && count_arg(argv) == 3)
	{
		essential[L]++;
		ft_lstadd_back(&data->world.lights,
			try(ft_lstnew(light(get_point(argv[0]),
				get_color(argv[2]),
				get_scl(argv[1], interval_set(0, 1))))));
	}
	else
		err_usr("found missing parameter for the essential element");
}

static void	get_object(t_element elem, char **argv, t_render *data)
{
	if (elem == SP && count_arg(argv) == 3)
		ft_lstadd_back(&data->world.objs, try(ft_lstnew(sphere(circle(get_point(argv[0]),
			get_scl(argv[1], interval_set(0, DBL_MAX))),
			texture(TX_SOLID, get_color(argv[2]), color(0, 0, 0), NONE)))));	
	else if (elem == PL && count_arg(argv) == 3)
		ft_lstadd_back(&data->world.objs, try(ft_lstnew(plane(get_point(argv[0]),
			get_vec(argv[1], interval_set(-1, 1)),
			texture(TX_SOLID, get_color(argv[2]), color(0, 0, 0), NONE)))));
	else if (elem == CY && count_arg(argv) == 4)
		ft_lstadd_back(&data->world.objs, try(ft_lstnew(cylinder(circle(get_point(argv[0]), get_scl(argv[2], interval_set(0, DBL_MAX)) / 2),
			get_scl(argv[3], interval_set(0, DBL_MAX)), get_vec(argv[1], interval_set(-1, 1)),
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

static void	free_argv(char **argv)
{
	int	ptr;

	ptr = 0;
	while (argv[ptr])
		ft_free(argv[ptr++]);
	ft_free(argv);
}