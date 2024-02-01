/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:38 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/20 01:24:56 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_cast;
	const unsigned char	*s2_cast;
	size_t				idx;

	if (n > 0)
	{
		s1_cast = (const unsigned char *)s1;
		s2_cast = (const unsigned char *)s2;
		idx = 0;
		while (idx < n)
		{
			if (s1_cast[idx] != s2_cast[idx] || !(s1_cast[idx]))
				return (s1_cast[idx] - s2_cast[idx]);
			idx++;
		}
	}
	return (0);
}
