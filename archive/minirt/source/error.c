/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:06:47 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 17:29:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	*try(void *ptr)
{
	if (!ptr)
		err_sys("malloc");
	return (ptr);
}

void	err_sys(char *msg)
{
	if (msg)
		perror(msg);
	exit(EXIT_FAILURE);
}

void	err_usr(char *msg)
{
	if (msg)
	{
		ft_putstr("Error\n");
		ft_putstr(msg);
		ft_putchar('\n');
	}
	exit(EXIT_FAILURE);
}
