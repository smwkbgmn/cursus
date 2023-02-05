/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:22:13 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/24 19:14:41 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_c;
	unsigned char	c_c;

	if (n == 0)
		return (0);
	s_c = (unsigned char *)s;
	c_c = (unsigned char)c;
	while (*s_c != c_c && n-- > 1)
		s_c++;
	if (*s_c == c_c)
		return ((void *)s_c);
	else
		return (0);
}
