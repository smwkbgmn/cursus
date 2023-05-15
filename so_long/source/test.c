/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:55:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/15 16:35:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_print_map(t_map map)
{
	t_uint	x;
	t_uint	y;

	system("clear");
	printf("\n\nReal-time mapping\n\n");
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
