/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 18:46:51 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TO DO */
// Norminette
// See subject

#include "render.h"

int	main(int argc, char *argv[])
{
	t_render	data;

	if (argc == 2)
	{
		init(argv[1], &data);
		render(&data);
	}
	else if (argc == 1)
		err_usr("please enter a file for rendering");
	else
		err_usr("only a file is allowed");
	return (EXIT_SUCCESS);
}
