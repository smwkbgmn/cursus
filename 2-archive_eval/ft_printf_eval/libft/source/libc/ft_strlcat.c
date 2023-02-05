/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:22:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/03 20:34:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l_dst;
	size_t	l_src;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (dstsize == 0 || dstsize < l_dst)
		return (l_src + dstsize);
	while (dstsize-- > l_dst + 1 && *src)
		*(dst++ + l_dst) = *src++;
	*(dst + l_dst) = 0;
	return (l_dst + l_src);
}
