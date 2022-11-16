/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:38 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/17 01:39:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_cast;
	const unsigned char	*s2_cast;

	if (n == 0)
		return (0);
	s1_cast = (const unsigned char *)s1;
	s2_cast = (const unsigned char *)s2;
	while (n-- > 0 && *s1_cast == *s2_cast)
	{
		if (*s1_cast == 0)
			return (0);
		s1_cast++;
		s2_cast++;
	}
	return (*s1_cast - *s2_cast);
} 
