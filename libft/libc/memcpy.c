/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:41:10 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/15 00:38:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_c;
	char	*src_c;
	int		idx;

	if (n == 0 || dst == src)
		return (dst);

	dst_c = (char *)dst;
	src_c = (char *)src;
	idx = 0;
	while (src_c[idx] && n > 0)
	{
		dst_c[idx] = src_c[idx];
		idx++;
		n--;
	}
	return (dst);
}