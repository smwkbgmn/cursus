/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:22:13 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/19 23:02:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cast;
	unsigned char	c_cast;

	if (n > 0)
	{
		s_cast = (unsigned char *)s;
		c_cast = (unsigned char)c;
		while (n > 0)
		{
			if (*s_cast == c_cast)
				return ((void *)s_cast);
			s_cast++;
			n--;
		}
	}
	return (0);
}
