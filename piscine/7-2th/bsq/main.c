/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:14:57 by pji               #+#    #+#             */
/*   Updated: 2022/06/09 11:37:51 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "read_file.h"
#include "find_largest_square.h"
#include "square.h"
#include "read_input.h"
#include "check_print_validation.h"
#include "print_map.h"
#include <unistd.h>

int		map_error(void);
void	std_input(void);
void	file_input(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std_input();
	else
		file_input(argc, argv);
	return (0);
}

void	std_input(void)
{
	char		**map;
	char		structure[4];
	t_square	square;

	map = read_input(structure);
	if (map == 0 || check_print_validation(map, structure)
		|| check_printable(structure))
	{
		map_error();
		return ;
	}
	square = find_largest_square(map, structure);
	print_map(map, structure, square);
	map_free(map, FREE_MAP);
}

void	file_input(int argc, char *argv[])
{
	char		**map;
	char		structure[4];
	int			count;
	t_square	square;

	count = 1;
	while (count < argc)
	{
		map = read_file(argv[count], structure);
		if (map == NULL || check_print_validation(map, structure)
			|| check_printable(structure))
		{
			map_error();
			++count;
			continue ;
		}
		square = find_largest_square(map, structure);
		print_map(map, structure, square);
		map_free(map, FREE_MAP);
		++count;
	}
}

int	map_error(void)
{
	write(STDOUT_FILENO, "map error\n", 10);
	return (0);
}
