/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:29:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/14 21:12:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>

t_bool		init_data(t_data *data, char *filename);
int			key_hook(int keycode, t_data *data);
int			loop_hook(t_data *data);
static int	window_closed(t_data *data);

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2 && init_data(&data, *(av + 1)))
	{
		mlx_hook(data.mlx.window, ON_DESTROY, 0, window_closed, &data);
		mlx_key_hook(data.mlx.window, key_hook, &data);
		mlx_loop_hook(data.mlx.ptr, loop_hook, &data);
		mlx_loop(data.mlx.ptr);
	}
	system("leaks so_long");
	return (0);
}

static int	window_closed(t_data *data)
{
	exit_program(data);
	return (0);
}

void	exit_program(t_data *data)
{
	free_data(data);
	exit(0);
}
