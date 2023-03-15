/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:53:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/20 00:15:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_c;
	const unsigned char	*s2_c;

	if (n > 0)
	{
		s1_c = (const unsigned char *)s1;
		s2_c = (const unsigned char *)s2;
		while (n > 0)
		{
			if (*s1_c != *s2_c)
				return (*s1_c - *s2_c);
			else
			{
				s1_c++;
				s2_c++;
			}
			n--;
		}
	}
	return (0);
}
