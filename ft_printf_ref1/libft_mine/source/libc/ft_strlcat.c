/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:22:52 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/18 19:06:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (dstsize == 0 || dstsize < len_d)
		return (len_s + dstsize);
	while (dstsize-- > len_d + 1 && *src)
		*(dst++ + len_d) = *src++;
	*(dst + len_d) = 0;
	return (len_d + len_s);
}
