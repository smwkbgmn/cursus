/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:21:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 18:50:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static void	*trycatch(void *ptr);
static void	write_msg(char *msg);

void	*calloc_erx(size_t count, size_t size)
{
	return (trycatch(ft_calloc(count, size)));
}

static void	*trycatch(void *ptr)
{
	if (!ptr)
		exit_error("malloc");
	return (ptr);
}

void	exit_error(char *msg)
{
	if (msg)
	{
		// write_msg("minishell: ");
		perror(msg);
	}
	exit(EXIT_FAILURE);
}

void	exit_error_usr(int status)
{
	if (status == 127)
	{
		write_msg("minishell: ");
		write_msg("command not found\n");
	}
	exit(status);
}

static void	write_msg(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
}
