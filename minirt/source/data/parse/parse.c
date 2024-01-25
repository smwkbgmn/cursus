/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 07:43:24 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 09:39:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static void	set_value(char **argv, t_render *data, int *essential);
static void	remove_tail_nl(char *line);
static void	which_element(char *arg, t_element *elem);
static void	free_argv(char **argv);

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
		err_usr("ensure there are all essential elements\n"
			"(Ambient, Camera, Light) for rendering");
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

static void	free_argv(char **argv)
{
	int	ptr;

	ptr = 0;
	while (argv[ptr])
		ft_free(argv[ptr++]);
	ft_free(argv);
}