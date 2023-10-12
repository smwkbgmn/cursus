/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:21:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 03:09:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

void	*calloc_erx(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
		exit_error("malloc");
	return (ptr);
}

void	set_error(char *msg, int exit)
{
	if (msg)
	{
		write_errmsg("minishell: ");
		write_errmsg(msg);
		write_errmsg("\n");
	}
	g_exit = exit;
}

void	exit_error(char *msg)
{
	if (msg)
	{
		write_errmsg("minishell: ");
		perror(msg);
	}
	exit(EXIT_FAILURE);
}

void	exit_error_usr(int status)
{
	if (status == 127)
		write_errmsg("minishell: command not found\n");
	exit(status);
}

void	write_errmsg(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
}
