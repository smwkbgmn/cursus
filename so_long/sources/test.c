/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:55:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/11 12:17:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_print_map(t_map map)
{
	t_uint	cnt;

	cnt = 0;
	while (cnt < map.height)
	{
		printf("%s\n", map.map[cnt]);
		cnt++;
	}

}
