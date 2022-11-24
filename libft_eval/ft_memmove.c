/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:51:56 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/24 19:50:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst_c;
	char	*src_c;

	if (n == 0 || dst == src)
		return (dst);
	dst_c = (char *)dst;
	src_c = (char *)src;
	if (dst < src)
	{
		while (n-- > 0)
			*dst_c++ = *src_c++;
	}
	else
	{
		while (n-- > 0)
			*(dst_c + n) = *(src_c + n);
	}
	return (dst);
}
