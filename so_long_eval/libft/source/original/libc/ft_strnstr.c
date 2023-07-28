/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:42 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/30 13:42:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i_hay;
	size_t	i_ndl;

	if (!(*needle))
		return ((char *)haystack);
	i_hay = 0;
	i_ndl = 0;
	while (haystack[i_hay] && needle[i_ndl] && i_hay < n)
	{
		if (haystack[i_hay] == needle[i_ndl])
			i_ndl++;
		else
		{
			if (i_ndl > 0)
			{
				i_hay -= i_ndl;
				i_ndl = 0;
			}
		}
		i_hay++;
	}
	if (needle[i_ndl] == 0)
		return ((char *)&haystack[i_hay - i_ndl]);
	else
		return (NULL);
}
