/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 02:20:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 02:30:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
To do 
o - readline 
o - readline-history
o - handle $? o
o - parsing error (setting errno)
o - free data
o - check heredoc and $ > ft substr
o - move get_* files to init
o - signal (ctrl c, d, \)
- implement builtins
o - check if it's builtin before executing and get_cmd
o - builtin is to be executed on chiild process
o - modify get_path, free path variable
o - move the position of getting env
o - multiple wildcard 
o - rl_replace_line on SIGINT
o - check removing heredoc tmp
- exit status  on SIGINT (SIGINT on sleep 10)
o - does zshell need to be quit on EOF? (ctrl d)
- memory leaks 
- implement terminal attribute
*/

/*
Test
- redirection without cmd 
- outfile > 
- minishell without env
- cat << a | cat 
- ctrl+c history check at cluster
- export aaaaa check
- echo -nnnnnn
- check one cycle leak on builtins
- exit > int overflow 
- showing av on error
- input ./
- env save position rule
- use env after copy
- ulimit -u > max process
*/

#include "minishell.h"

int	main(void)
{
	static t_list	*l_exe;

	init_terminal();
	init_signal(SHELL);
	while (LOOP)
	{
		// printf("getting g_exit [%d]\n", g_exit);
		init_shell(&l_exe, readline("minishell$ "));
		if (l_exe)
		{
			execute(l_exe);
			free_data(&l_exe);
		}
	}
	return (g_exit);
}
