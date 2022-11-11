/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:41:10 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/11 16:16:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_casted;
	char	*src_casted;
	int		idx;

	dst_casted = (char *)dst;
	src_casted = (char *)src;
	idx = 0;
	while (src_casted[idx])
	{
		dst_casted[idx] = src_casted[idx];
		idx++;
	}
	return (dst);
}