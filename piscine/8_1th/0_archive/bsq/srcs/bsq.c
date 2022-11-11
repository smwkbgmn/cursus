/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:49:07 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/15 10:58:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	get_print_answ(t_map *map, t_answ *answ, char *f_name);

void	from_file(int ac, char **av)
{
	t_map	*map;
	t_answ	*answ;
	int		loop;

	loop = 1;
	while (loop < ac)
	{
		get_print_answ(map, answ, av[loop]);
		if (loop != ac - 1)
			ft_putchar('\n');
		map = 0;
		answ = 0;
		loop++;
	}
}

void	from_std(void)
{
	t_map	*map;
	t_answ	*answ;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == 0)
		return ;
	map->valid = 1;
	get_map(map, 0);
	if (valid_map(map) == 0)
		map->valid = 0;
	answ = get_answ(map);
	print_map(map, answ);
	free_map(map);
	free(map);
	free(answ);
	map = 0;
	answ = 0;
}

void	get_print_answ(t_map *map, t_answ *answ, char *f_name)
{
	int	fd;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == 0)
		return ;
	map->valid = 1;
	fd = open(f_name, O_RDWR);
	if (fd < 0)
	{
		print_map_error();
		free(map);
		return ;
	}
	get_map(map, fd);
	if (valid_map(map) == 0)
		map->valid = 0;
	answ = get_answ(map);
	print_map(map, answ);
	free_map(map);
	free(map);
	free(answ);
	close(fd);
}
