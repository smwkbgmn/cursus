/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 02:20:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 05:18:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Read line form STDIN
	1-1. Heredoc mode (Wherever if the Heredoc is, it has to do
	Heredoc first. If there is more than one Heredoc, do first
	one that first meet in the line.)
	1-2. Should be acceptable control input [Ctrl + C, D, \]
2. Parse (Look some functions like strtok or strsep)
	2-1. See if there is unclosed metacharacters [(), '', "", &&]
	2-2. AND, OR sign with parenthesis [&&, ||, ()]
	2-3. Pipe [|]
	2-4. Dollor sign (means need to invoke the env or exit status)
	2-5. Wildcard [*]
3. Execute entered command
	3-1. If there is AND, OR, do *whole commad line as many as
	the count of logical expressions.
	3-2. If there is pipe, redirect prior STD_OUT to
	following command's STD_IN
	3-3. Count quantity of parenthesis and keep it for nesting
	to send last exit status
	* whole commadn : one full command or commands that
	connected with pipes.
4. Send the signals
	4-1. While the shell doing things, the main should be available to do
	signaling to any process made from the shell.
*/

/* 
o - readline 
o - readline-history
o - handle $? o
o - parsing error (setting errno)
o - free data
o - check heredoc and $ > ft substr
o - move get_* files to init
o - signal (ctrl c, d, \)
- implement builtins
- check if it's builtin before executing and get_cmd
- builtin is to be executed on chiild process
o - modify get_path, free path variable
o - move the position of getting env
o - multiple wildcard 
- rl_replace_line on SIGINT
o - check removing heredoc tmp
- exit status  on SIGINT
o - does zshell need to be quit on EOF? (ctrl d)
- Gnu readline
- memory leaks 
- implement terminal attribute
*/

#include "minishell.h"

int	main(void)
{
	static t_list	*l_exe;

	init_terminal();
	init_signal(SHELL);
	while (LOOP)
	{
		printf("getting g_exit %d\n", g_exit);
		init_shell(&l_exe, readline("minishell$ "));
		if (l_exe)
		{
			execute(l_exe);
			free_data(&l_exe);
		}
	}
	return (g_exit);
}
