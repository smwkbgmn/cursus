/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 12:38:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

#include "minishell.h"

static void	handle_sigint_shell(int sig);
static void	handle_sigint_heredoc(int sig);
static void	handle_sigint_exe(int sig);
static void	handle_sigterm(int sig);

// SIGQUIT : ctrl + "\"
// SIGINT : crtl + d

void	init_signal(t_mode mode)
{
	if (mode == SHELL)
	{
		signal(SIGINT, &handle_sigint_shell);
		signal(SIGTERM, &handle_sigterm);
	}
	else if (mode == HEREDOC)
		signal(SIGINT, &handle_sigint_heredoc);
	else
		signal(SIGINT, &handle_sigint_exe);
	signal(SIGQUIT, SIG_IGN);
}

static void	handle_sigint_shell(int sig)
{
	if (sig)
	{
		// printf("handle shell\n");
		g_exit = EXIT_FAILURE;
		ft_putchar_fd('\n', STDIN_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	handle_sigint_heredoc(int sig)
{
	// printf("handle heredoc\n");
	if (sig)
		exit(EXIT_FAILURE);
}

static void	handle_sigint_exe(int sig)
{
	// printf("handle exe\n");
	if (sig)
		exit(130);
}

static void	handle_sigterm(int sig)
{
	if (sig)
		exit(g_exit);
}
