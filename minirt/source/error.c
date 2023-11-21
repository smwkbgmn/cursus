/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:06:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/11/03 14:30:34 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "minirt.h"

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
		ft_putstr(msg);
		ft_putchar('\n');
	}
	exit(EXIT_FAILURE);
}
