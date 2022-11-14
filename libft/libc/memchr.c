/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:22:13 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/15 00:18:34 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*memchr(const void *s, int c, size_t n)
{
	char	*s_c;
	char	c_c;

	s_c = (char *)s;
	c_c = (char)c;
	
	while (*s_c != c_c && n > 0 && *s_c)
	{
		s_c++;
		n--;
	}
	if (s_c != 0)
		return ((void *)s_c);
	else
		return (0);
}