/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:05:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/22 14:51:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Remove includes in c files */
/* Remove all comments in c files */
/* Check about the exit function */
/* Check the way of parsing parameters for cmds again to
know whether spliting input by space is the right way or not */
/* What would happen when the env comes as unset */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	static t_data	input;

	if (ac > 4)
	{
		init_data(&input, ac, av, env);
		execute(&input);
		free_data(&input);
	}
	return (0);
}
