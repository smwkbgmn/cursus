/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:13:34 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/11 16:13:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isalpha(int c);
static int	ft_isdigit(int c);

int	ft_isalnum(int c)
{
	return (ft_isalpha((unsigned char)c) == 1 || 
		ft_isdigit((unsigned char)c) == 1);
}

static int	ft_isalpha(int c)
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

static int	ft_isdigit(int c)
{
	return ('0' <= (unsigned char)c && (unsigned char)c <= '9');
}

