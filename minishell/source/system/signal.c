/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 18:04:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "minishell.h"

// SIGQUIT
// SIGINT

static void	handle_sig_int(int sig);

void	init_signal(void)
{
	signal(SIGINT, &handle_sig_int);
	signal(SIGQUIT, SIG_IGN);
}

static void	handle_sig_int(int sig)
{
	printf("\n");
	rl_on_new_line();
	// rl_replace_line("", 0);
	rl_redisplay();
	g_exit = 1;
	(void)sig;
}
