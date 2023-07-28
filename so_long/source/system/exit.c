/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:04:51 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 20:05:55 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

int	window_closed(t_data *data)
{
	exit_program(data);
	return (0);
}

void	exit_program(t_data *data)
{
	free_data(data);
	system("leaks so_long");
	exit(EXIT_SUCCESS);
}
