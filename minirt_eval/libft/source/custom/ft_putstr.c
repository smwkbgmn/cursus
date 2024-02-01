/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:02:05 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/17 21:03:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putstr(char *str)
{
	if (str)
	{
		if (*str)
		{
			write(STDIN_FILENO, str, 1);
			ft_putstr(str + 1);
		}
	}
}
