/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:13:41 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/11 16:13:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char	c_casted;

	c_casted = (unsigned char)c;
	if ('a' <= c_casted && c_casted <= 'z')
		return (1);
	else if ('A' <= c_casted && c_casted <= 'Z')
		return (1);
	else
		return (0);
}
