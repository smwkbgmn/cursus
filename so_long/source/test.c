/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:55:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/13 17:02:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_print_map(t_map map)
{
	t_uint	x;
	t_uint	y;

	// system("clear");
	// printf("\n\nReal-time mapping\n\n");
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{	
			printf("%c", map.map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	test_print_lists(t_list *checked, t_list *near, t_bool valid)
{
	ft_printf("current %d, %d / valid %d\n",
		((t_coord *)near->content)->x, ((t_coord *)near->content)->y, valid);
	test_print_checked(checked);
	test_print_near(near);
}

void	test_print_checked(t_list *checked)
{
	ft_printf("\tcheckd crds\n");
	while (checked)
	{
		ft_printf("\tcrd %d, %d\n",
			((t_coord *)checked->content)->x, ((t_coord *)checked->content)->y);
		checked = checked->next;
	}
}

void	test_print_near(t_list *near)
{
	ft_printf("\t\tnear list\n");
	if (near == NULL)
		ft_printf("\t\t[EMPTY]\n");
	else
	{
		while (near)
		{
			ft_printf("\t\tcrd %d, %d\n",
				((t_coord *)near->content)->x, ((t_coord *)near->content)->y);
			near = near->next;
		}
	}
	ft_printf("\n");
}
