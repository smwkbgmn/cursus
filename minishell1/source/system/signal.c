/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 16:49:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

#include "minishell.h"

static void	handle_sigint_shell(int sig);
static void	handle_sigint_heredoc(int sig);
static void	handle_sigint_exe(int sig);

void	init_signal(t_mode mode)
{
	if (mode == SHELL)
	{
		signal(SIGINT, &handle_sigint_shell);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == HEREDOC)
		signal(SIGINT, &handle_sigint_heredoc);
	else if (mode == EXE)
		signal(SIGINT, &handle_sigint_exe);
}

static void	handle_sigint_shell(int sig)
{
	g_exit = EXIT_FAILURE;
	ft_putchar_fd('\n', STDIN_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}

static void	handle_sigint_heredoc(int sig)
{
	exit(EXIT_FAILURE);
	(void)sig;
}

static void	handle_sigint_exe(int sig)
{
	exit(130);
	(void)sig;
}
