/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:05:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/21 02:03:04 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Get to know about wait(), waitpid */
/* Handle the errors : 
access / perror, strerror / fork, execve, pipe / write, open, close */
/* Remove includes in c files */
/* Check the open() permission */

#include <unistd.h>

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	static t_data	input;

	dbg_print_av(av);
	if (ac > 4 && init_data(&input, ac, av, env))
	{
		dbg_print_input(&input);
		execute(&input);
	}
	free_data(&input);
	// system("leaks pipex");
	return (0);
}
