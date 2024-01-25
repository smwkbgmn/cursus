/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 22:11:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TO DO */
// Implement cylinder
// Add one more object > Cone
// If you add checker texture,
// - change input file form and parsing.c
// - adjust texture at get_data.c

// Remove function not allowed
// Check headers and macro
// See evaluation sheet 

#include "minirt.h"

void	print_data(t_render *data);

int	main(int argc, char *argv[])
{
	t_render	data;

	if (argc == 2)
	{
		init(argv[1], &data);
		print_data(&data);
		render(&data);
	}
	else if (argc == 1)
		err_usr("please enter a file for rendering");
	else
		err_usr("only a file is allowed");
	return (EXIT_SUCCESS);
}
