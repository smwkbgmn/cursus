/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:16:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 17:13:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "builtin.h"

void	*errext(void *ptr)
{
	if (!ptr)
		exit_error("malloc");
	return (ptr);
}

void	exit_error(char *msg)
{
	if (msg)
		perror(msg);
	exit(EXIT_FAILURE);
}
