/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:42 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/20 00:01:55 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	idx_h;
	size_t	idx_n;

	if (!(*needle))
		return ((char *)haystack);
	idx_h = 0;
	idx_n = 0;
	while (haystack[idx_h] && needle[idx_n] && idx_h < n)
	{
		if (haystack[idx_h] == needle[idx_n])
			idx_n++;
		else
		{
			if (idx_n > 0)
			{
				idx_h -= idx_n;
				idx_n = 0;
			}
		}
		idx_h++;
	}
	if (needle[idx_n] == 0)
		return ((char *)&haystack[idx_h - idx_n]);
	else
		return (0);
}
